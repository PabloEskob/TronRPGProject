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

ATronRpgBaseCharacter::ATronRpgBaseCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UTronRpgAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<UTronRpgAttributeSet>(TEXT("AttributeSet"));
	ComboComponent = CreateDefaultSubobject<UTronRpgComboComponent>(TEXT("ComboComponent"));
	AnimationComponent = CreateDefaultSubobject<UAnimationComponent>(TEXT("AnimationComponent"));
	DependencyInjector = CreateDefaultSubobject<UDependencyInjectorComponent>(TEXT("DependencyInjector"));
	AbilityInputComponent = CreateDefaultSubobject<UAbilityInputComponent>(TEXT("AbilityInputComponent"));
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
	if (!WeaponAsset) return;

	// Сохраняем текущее оружие
	UWeaponDataAsset* PreviousWeapon = CurrentWeapon;

	// Устанавливаем новое оружие
	CurrentWeapon = WeaponAsset;

	// Обновляем теги: убираем старые, добавляем новые
	if (PreviousWeapon)
	{
		AbilitySystemComponent->RemoveLooseGameplayTags(PreviousWeapon->WeaponTags);
	}
	AbilitySystemComponent->AddLooseGameplayTags(CurrentWeapon->WeaponTags);
	AbilitySystemComponent->AddLooseGameplayTag(EquippedTag);

	// Проверяем, что ассеты нового оружия загружены
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
	if (UCharacterAnimInstance* AnimInstance = Cast<UCharacterAnimInstance>(GetMesh()->GetAnimInstance()))
	{
		AnimInstance->TransitionToNewBlendSpace(
			CurrentWeapon->WalkForwardBlendSpace.Get(),
			CurrentWeapon->WalkBackwardBlendSpace.Get(),
			BlendSpaceTransitionDuration
		);
	}
}

void ATronRpgBaseCharacter::UnequipWeapon()
{
	if (!CurrentWeapon) return;

	// Проигрываем монтаж снятия
	if (CurrentWeapon->UnequipMontage.IsValid())
	{
		UAnimMontage* UnequipMontage = CurrentWeapon->UnequipMontage.Get();
		PlayAnimMontage(UnequipMontage);
	}

	// Удаляем теги оружия и тег экипировки
	AbilitySystemComponent->RemoveLooseGameplayTags(CurrentWeapon->WeaponTags);
	AbilitySystemComponent->RemoveLooseGameplayTag(EquippedTag);

	// Возвращаем дефолтные BlendSpaces
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

	CurrentWeapon = nullptr;
}

void ATronRpgBaseCharacter::EquipWeaponByTag(FGameplayTag WeaponTag)
{
	// Получаем менеджер оружия
	UTronRpgWeaponAssetManager* WeaponManager = UTronRpgWeaponAssetManager::Get(this);
	if (!WeaponManager)
	{
		UE_LOG(LogTemp, Error, TEXT("WeaponManager not found"));
		return;
	}

	// Ищем оружие по тегу
	TArray<UWeaponDataAsset*> Weapons = WeaponManager->GetWeaponsByTag(WeaponTag);
	if (Weapons.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon with tag %s not found"), *WeaponTag.ToString());
		return;
	}

	UWeaponDataAsset* TargetWeapon = Weapons[0];

	// Проверяем, экипировано ли уже оружие с этим тегом
	if (CurrentWeapon && CurrentWeapon->WeaponTags.HasTagExact(WeaponTag))
	{
		// Если оружие уже экипировано, снимаем его
		UnequipWeapon();
	}
	else
	{
		// Если оружие не экипировано, надеваем его
		EquipWeapon(TargetWeapon, 1.0f); // 1.0f — длительность перехода
	}
}
