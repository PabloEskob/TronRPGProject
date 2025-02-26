#include "Character/TronRpgBaseCharacter.h"

#include "Animation/Character/CharacterAnimInstance.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "GAS/TronRpgAttributeSet.h"
#include "Component/TronRpgComboComponent.h"
#include "Component/Animation/AnimationComponent.h"
#include "Component/DI/DependencyInjectorComponent.h"
#include "Component/Input/AbilityInputComponent.h"
#include "Data/Weapon/WeaponDataAsset.h"
#include "GameInstanceSubsystem/WeaponAsset/TronRpgWeaponAssetManager.h"
#include "Net/UnrealNetwork.h"
#include "Object/GameplayTagsLibrary.h"

ATronRpgBaseCharacter::ATronRpgBaseCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UTronRpgAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<UTronRpgAttributeSet>(TEXT("AttributeSet"));
	ComboComponent = CreateDefaultSubobject<UTronRpgComboComponent>(TEXT("ComboComponent"));
	AnimationComponent = CreateDefaultSubobject<UAnimationComponent>(TEXT("AnimationComponent"));
	DependencyInjector = CreateDefaultSubobject<UDependencyInjectorComponent>(TEXT("DependencyInjector"));
	AbilityInputComponent = CreateDefaultSubobject<UAbilityInputComponent>(TEXT("AbilityInputComponent"));

	MainHandMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MainHandMesh"));
	MainHandMeshComponent->SetupAttachment(GetMesh(), TEXT("WeaponSocket_MainHand"));
	MainHandMeshComponent->SetVisibility(false);

	OffHandMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OffHandMesh"));
	OffHandMeshComponent->SetupAttachment(GetMesh(), TEXT("WeaponSocket_OffHand"));
	OffHandMeshComponent->SetVisibility(false);
}

void ATronRpgBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (!CurrentWeapon)
	{
		if (DefaultWeaponAsset)
		{
			// Синхронная загрузка BlendSpace
			if (!DefaultWeaponAsset->WalkForwardBlendSpace.IsValid())
			{
				UBlendSpace* LoadSynchronous = DefaultWeaponAsset->WalkForwardBlendSpace.LoadSynchronous();
			}
			if (!DefaultWeaponAsset->WalkBackwardBlendSpace.IsValid())
			{
				UBlendSpace* LoadSynchronous = DefaultWeaponAsset->WalkBackwardBlendSpace.LoadSynchronous();
			}

			// Устанавливаем дефолтные BlendSpace
			if (UCharacterAnimInstance* AnimInstance = Cast<UCharacterAnimInstance>(GetMesh()->GetAnimInstance()))
			{
				AnimInstance->SetMovementBlendSpace(
					DefaultWeaponAsset->WalkForwardBlendSpace.Get(),
					DefaultWeaponAsset->WalkBackwardBlendSpace.Get()
				);
			}
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

void ATronRpgBaseCharacter::EquipWeapon(UWeaponDataAsset* WeaponAsset, float BlendSpaceTransitionDuration)
{
    if (!WeaponAsset)
    {
        UE_LOG(LogTemp, Warning, TEXT("EquipWeapon: Invalid WeaponAsset provided"));
        return;
    }

    // Если текущее оружие уже установлено и совпадает с новым, ничего не делаем
    if (CurrentWeapon == WeaponAsset)
    {
        return;
    }

    // Сохраняем текущее оружие
    UWeaponDataAsset* PreviousWeapon = CurrentWeapon;

    // Устанавливаем новое оружие
    CurrentWeapon = WeaponAsset;

    // Обновляем теги
    if (PreviousWeapon)
    {
        AbilitySystemComponent->RemoveLooseGameplayTags(PreviousWeapon->WeaponTags);
    }
    AbilitySystemComponent->AddLooseGameplayTags(CurrentWeapon->WeaponTags);
    AbilitySystemComponent->AddLooseGameplayTag(EquippedTag);

    // Загружаем ассеты анимации оружия
    if (!CurrentWeapon->WalkForwardBlendSpace.IsValid())
    {
        CurrentWeapon->WalkForwardBlendSpace.LoadSynchronous();
    }
    if (!CurrentWeapon->WalkBackwardBlendSpace.IsValid())
    {
        CurrentWeapon->WalkBackwardBlendSpace.LoadSynchronous();
    }

    // Проигрываем монтаж экипировки
    if (CurrentWeapon->EquipMontage.IsValid())
    {
        UAnimMontage* EquipMontage = CurrentWeapon->EquipMontage.Get();
        PlayAnimMontage(EquipMontage);
    }

    // Обновляем BlendSpace для анимаций
    if (UCharacterAnimInstance* AnimInstance = Cast<UCharacterAnimInstance>(GetMesh()->GetAnimInstance()))
    {
        AnimInstance->TransitionToNewBlendSpace(
            CurrentWeapon->WalkForwardBlendSpace.Get(),
            CurrentWeapon->WalkBackwardBlendSpace.Get(),
            BlendSpaceTransitionDuration
        );
    }

    // Обновляем визуальные компоненты (меши оружия)
	if (CurrentWeapon->WeaponSlot.HasTag(TAG_Equipment_Slot_MainHand))
	{
		if (CurrentWeapon->WeaponMesh.IsValid())
		{
			MainHandMeshComponent->SetStaticMesh(CurrentWeapon->WeaponMesh.Get());
			MainHandMeshComponent->SetVisibility(true);
		}
	}
	else
	{
		MainHandMeshComponent->SetStaticMesh(nullptr);
		MainHandMeshComponent->SetVisibility(false);
	}

	if (CurrentWeapon->WeaponSlot.HasTag(TAG_Equipment_Slot_MainHand))
	{
		if (CurrentWeapon->AdditionalWeaponMesh.IsValid())
		{
			OffHandMeshComponent->SetStaticMesh(CurrentWeapon->AdditionalWeaponMesh.Get());
			OffHandMeshComponent->SetVisibility(true);
		}
	}
	else
	{
		OffHandMeshComponent->SetStaticMesh(nullptr);
		OffHandMeshComponent->SetVisibility(false);
	}
}

void ATronRpgBaseCharacter::UnequipWeapon()
{
	if (!CurrentWeapon)
	{
		return;
	}

	// Проигрываем монтаж снятия
	if (CurrentWeapon->UnequipMontage.IsValid())
	{
		UAnimMontage* UnequipMontage = CurrentWeapon->UnequipMontage.Get();
		PlayAnimMontage(UnequipMontage);
	}

	// Удаляем теги оружия и тег экипировки
	AbilitySystemComponent->RemoveLooseGameplayTags(CurrentWeapon->WeaponTags);
	AbilitySystemComponent->RemoveLooseGameplayTag(EquippedTag);

	// Возвращаем дефолтные BlendSpace
	if (DefaultWeaponAsset && DefaultWeaponAsset->WalkForwardBlendSpace.IsValid() && DefaultWeaponAsset->WalkBackwardBlendSpace.IsValid())
	{
		if (UCharacterAnimInstance* AnimInstance = Cast<UCharacterAnimInstance>(GetMesh()->GetAnimInstance()))
		{
			AnimInstance->TransitionToNewBlendSpace(
				DefaultWeaponAsset->WalkForwardBlendSpace.Get(),
				DefaultWeaponAsset->WalkBackwardBlendSpace.Get(),
				1.0f // Длительность перехода
			);
		}
	}

	// Скрываем визуальные компоненты
	MainHandMeshComponent->SetStaticMesh(nullptr);
	MainHandMeshComponent->SetVisibility(false);
	OffHandMeshComponent->SetStaticMesh(nullptr);
	OffHandMeshComponent->SetVisibility(false);

	// Очищаем текущее оружие
	CurrentWeapon = nullptr;
}

void ATronRpgBaseCharacter::EquipWeaponByTag(FGameplayTag WeaponTag)
{
	// Проверяем валидность тега
	if (!WeaponTag.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("EquipWeaponByTag: Invalid WeaponTag provided"));
		return;
	}

	// Получаем менеджер оружия через подсистему
	UTronRpgWeaponAssetManager* WeaponManager = GetGameInstance() ? 
		GetGameInstance()->GetSubsystem<UTronRpgWeaponAssetManager>() : nullptr;
	if (!WeaponManager)
	{
		UE_LOG(LogTemp, Error, TEXT("EquipWeaponByTag: WeaponManager subsystem not found"));
		return;
	}

	// Ищем оружие по тегу
	TArray<UWeaponDataAsset*> Weapons = WeaponManager->GetWeaponsByTag(WeaponTag);
	if (Weapons.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("EquipWeaponByTag: No weapons found with tag %s"), *WeaponTag.ToString());
		return;
	}

	// Для простоты берём первое оружие из списка (можно расширить логику выбора)
	UWeaponDataAsset* TargetWeapon = Weapons[0];

	// Проверяем, экипировано ли уже оружие с этим тегом
	if (CurrentWeapon && CurrentWeapon->WeaponTags.HasTagExact(WeaponTag))
	{
		// Снимаем текущее оружие, если оно имеет тот же тег
		UnequipWeapon();
	}
	else
	{
		// Экипируем новое оружие
		EquipWeapon(TargetWeapon, 1.0f); // 1.0f — длительность перехода анимации
	}
}
