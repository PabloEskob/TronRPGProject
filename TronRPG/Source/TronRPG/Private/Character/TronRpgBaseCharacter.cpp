#include "Character/TronRpgBaseCharacter.h"

#include "Animation/Character/CharacterAnimInstance.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "GAS/TronRpgAttributeSet.h"
#include "Component/TronRpgComboComponent.h"
#include "Component/Animation/AnimationComponent.h"
#include "Component/DI/DependencyInjectorComponent.h"
#include "Component/Input/AbilityInputComponent.h"
#include "Data/Weapon/WeaponDataAsset.h"
#include "Engine/AssetManager.h"
#include "GameInstanceSubsystem/WeaponAsset/TronRpgWeaponAssetManager.h"
#include "Net/UnrealNetwork.h"

ATronRpgBaseCharacter::ATronRpgBaseCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UTronRpgAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<UTronRpgAttributeSet>(TEXT("AttributeSet"));
	ComboComponent = CreateDefaultSubobject<UTronRpgComboComponent>(TEXT("ComboComponent"));
	AnimationComponent = CreateDefaultSubobject<UAnimationComponent>(TEXT("AnimationComponent"));
	DependencyInjector = CreateDefaultSubobject<UDependencyInjectorComponent>(TEXT("DependencyInjector"));
	AbilityInputComponent = CreateDefaultSubobject<UAbilityInputComponent>(TEXT("AbilityInputComponent"));

	LastWeaponSwitchTime = 0.0f;
	IsSwitchingWeapon = false;
	PendingWeapon = nullptr;
}

void ATronRpgBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	CharacterAnimInstance = Cast<UCharacterAnimInstance>(GetMesh()->GetAnimInstance());

	if (UTronRpgAbilitySystemComponent* ASC = Cast<UTronRpgAbilitySystemComponent>(GetAbilitySystemComponent()))
	{
		ASC->InitAbilityActorInfo(this, this);
	}

	UTronRpgWeaponAssetManager* WeaponManager = UTronRpgWeaponAssetManager::Get(this);
	if (WeaponManager)
	{
		FOnPreloadComplete OnComplete;
		OnComplete.BindUFunction(this, FName("OnWeaponAssetsPreloadComplete"));
		WeaponManager->PreloadAllWeaponAssets(OnComplete);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("BeginPlay: Failed to get WeaponAssetManager."));
	}
}

void ATronRpgBaseCharacter::OnWeaponAssetsPreloadComplete()
{
	UTronRpgWeaponAssetManager* WeaponManager = UTronRpgWeaponAssetManager::Get(this);
	if (WeaponManager)
	{
		UWeaponDataAsset* DefaultWeapon = WeaponManager->GetDefaultWeapon();
		if (DefaultWeapon)
		{
			EquipWeapon(DefaultWeapon);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("BeginPlay: Default weapon not found."));
		}
	}
}

UAbilitySystemComponent* ATronRpgBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ATronRpgBaseCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(ATronRpgBaseCharacter, CurrentWeapon, COND_OwnerOnly);
	DOREPLIFETIME(ATronRpgBaseCharacter, AbilitySystemComponent);
}



void ATronRpgBaseCharacter::EquipWeapon(UWeaponDataAsset* WeaponAsset)
{
	if (!WeaponAsset || !AbilitySystemComponent || !CharacterAnimInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("EquipWeapon: Invalid parameters or weapon switch on cooldown."));
		return;
	}

	PendingWeapon = WeaponAsset;
	if (!IsSwitchingWeapon)
	{
		ProcessWeaponSwitch();
	}
}

void ATronRpgBaseCharacter::ProcessWeaponSwitch()
{
    IsSwitchingWeapon = true;

    if (CurrentWeapon)
    {
        AbilitySystemComponent->RemoveLooseGameplayTags(CurrentWeapon->WeaponStateTags);
    }

    CurrentWeapon = PendingWeapon;
    LastWeaponSwitchTime = GetWorld()->GetTimeSeconds();

    TArray<FSoftObjectPath> AssetsToLoad;
    AssetsToLoad.Add(CurrentWeapon->EquipMontage.ToSoftObjectPath());
    AssetsToLoad.Add(CurrentWeapon->AttackMontage.ToSoftObjectPath());
    AssetsToLoad.Add(CurrentWeapon->WeaponMesh.ToSoftObjectPath());
    AssetsToLoad.Add(CurrentWeapon->WalkForwardBlendSpace.ToSoftObjectPath());
    AssetsToLoad.Add(CurrentWeapon->WalkBackwardBlendSpace.ToSoftObjectPath());

    UAssetManager::GetStreamableManager().RequestAsyncLoad(
        AssetsToLoad,
        [this]()
        {
            UAnimMontage* EquipMontage = CurrentWeapon->EquipMontage.Get();
            UAnimMontage* AttackMontage = CurrentWeapon->AttackMontage.Get();
            USkeletalMesh* WeaponMesh = CurrentWeapon->WeaponMesh.Get();
            UBlendSpace* WalkForwardBlendSpace = CurrentWeapon->WalkForwardBlendSpace.Get();
            UBlendSpace* WalkBackwardBlendSpace = CurrentWeapon->WalkBackwardBlendSpace.Get();

            if (!EquipMontage || !AttackMontage || !WeaponMesh || !WalkForwardBlendSpace || !WalkBackwardBlendSpace)
            {
                UE_LOG(LogTemp, Error, TEXT("EquipWeapon: Failed to load resources for weapon %s."), *CurrentWeapon->WeaponName.ToString());
                IsSwitchingWeapon = false;
                return;
            }

            AbilitySystemComponent->AddLooseGameplayTags(CurrentWeapon->WeaponStateTags);

            CharacterAnimInstance->UpdateWeaponAnimations(CurrentWeapon);
            CharacterAnimInstance->UpdateStateTags(AbilitySystemComponent->GetOwnedGameplayTags());

            PlayAnimMontage(EquipMontage);

            TArray<USkeletalMeshComponent*> WeaponMeshes;
            GetComponents<USkeletalMeshComponent>(WeaponMeshes);
            for (USkeletalMeshComponent* SkeletalMeshComponent : WeaponMeshes)
            {
                if (SkeletalMeshComponent->GetName().Contains(TEXT("WeaponMesh")))
                {
                    SkeletalMeshComponent->DestroyComponent();
                }
            }

            USkeletalMeshComponent* WeaponMeshComponent = NewObject<USkeletalMeshComponent>(this, TEXT("WeaponMesh"));
            WeaponMeshComponent->RegisterComponent();
            WeaponMeshComponent->SetSkeletalMesh(WeaponMesh);
            WeaponMeshComponent->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("WeaponSocket"));

            if (HasAuthority())
            {
                OnRep_CurrentWeapon();
            }

            UE_LOG(LogTemp, Log, TEXT("Weapon %s equipped."), *CurrentWeapon->WeaponName.ToString());

            IsSwitchingWeapon = false;
            if (PendingWeapon != CurrentWeapon)
            {
                ProcessWeaponSwitch();
            }
        },
        FStreamableManager::AsyncLoadHighPriority
    );
}

void ATronRpgBaseCharacter::UnequipWeapon()
{
	if (!CurrentWeapon || !AbilitySystemComponent || !CharacterAnimInstance)
	{
		return;
	}

	// Удаляем теги текущего оружия
	AbilitySystemComponent->RemoveLooseGameplayTags(CurrentWeapon->WeaponStateTags);

	// Очищаем анимации
	CharacterAnimInstance->UpdateWeaponAnimations(nullptr);
	CharacterAnimInstance->UpdateStateTags(AbilitySystemComponent->GetOwnedGameplayTags());

	// Удаляем меш оружия
	TArray<USkeletalMeshComponent*> WeaponMeshes;
	GetComponents<USkeletalMeshComponent>(WeaponMeshes);
	for (USkeletalMeshComponent* WeaponMesh : WeaponMeshes)
	{
		if (WeaponMesh->GetName().Contains(TEXT("WeaponMesh")))
		{
			WeaponMesh->DestroyComponent();
		}
	}

	// Реплицируем изменения
	if (HasAuthority())
	{
		OnRep_CurrentWeapon();
	}

	UE_LOG(LogTemp, Log, TEXT("Weapon %s unequipped."), *CurrentWeapon->WeaponName.ToString());
	CurrentWeapon = nullptr;
}

void ATronRpgBaseCharacter::OnRep_CurrentWeapon()
{
	if (CurrentWeapon && CharacterAnimInstance && AbilitySystemComponent)
	{
		AbilitySystemComponent->AddLooseGameplayTags(CurrentWeapon->WeaponStateTags);
		CharacterAnimInstance->UpdateWeaponAnimations(CurrentWeapon);
		CharacterAnimInstance->UpdateStateTags(AbilitySystemComponent->GetOwnedGameplayTags());

		// Обновляем меш оружия на клиентской стороне
		TArray<USkeletalMeshComponent*> WeaponMeshes;
		GetComponents<USkeletalMeshComponent>(WeaponMeshes);
		for (USkeletalMeshComponent* WeaponMesh : WeaponMeshes)
		{
			if (WeaponMesh->GetName().Contains(TEXT("WeaponMesh")))
			{
				WeaponMesh->DestroyComponent();
			}
		}

		USkeletalMeshComponent* WeaponMeshComponent = NewObject<USkeletalMeshComponent>(this, TEXT("WeaponMesh"));
		WeaponMeshComponent->RegisterComponent();
		WeaponMeshComponent->SetSkeletalMesh(CurrentWeapon->WeaponMesh.Get());
		WeaponMeshComponent->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("WeaponSocket"));

		UE_LOG(LogTemp, Log, TEXT("OnRep_CurrentWeapon: Weapon %s replicated."), *CurrentWeapon->WeaponName.ToString());
	}
	else if (!CurrentWeapon && CharacterAnimInstance && AbilitySystemComponent)
	{
		CharacterAnimInstance->UpdateWeaponAnimations(nullptr);
		CharacterAnimInstance->UpdateStateTags(AbilitySystemComponent->GetOwnedGameplayTags());

		TArray<USkeletalMeshComponent*> WeaponMeshes;
		GetComponents<USkeletalMeshComponent>(WeaponMeshes);
		for (USkeletalMeshComponent* WeaponMesh : WeaponMeshes)
		{
			if (WeaponMesh->GetName().Contains(TEXT("WeaponMesh")))
			{
				WeaponMesh->DestroyComponent();
			}
		}

		UE_LOG(LogTemp, Log, TEXT("OnRep_CurrentWeapon: Weapon unequipped."));
	}
}
