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

void ATronRpgBaseCharacter::EquipWeapon(UWeaponDataAsset* WeaponAsset)
{
	if (!WeaponAsset) return;

	// Снимаем текущее оружие, если оно есть
	if (CurrentWeapon)
	{
		UnequipWeapon();
	}

	CurrentWeapon = WeaponAsset;

	// Добавляем теги оружия и тег экипировки
	AbilitySystemComponent->AddLooseGameplayTags(CurrentWeapon->WeaponTags);
	AbilitySystemComponent->AddLooseGameplayTag(EquippedTag);

	// Обновляем BlendSpace в Animation Instance
	if (UCharacterAnimInstance* AnimInstance = Cast<UCharacterAnimInstance>(GetMesh()->GetAnimInstance()))
	{
		AnimInstance->SetMovementBlendSpace(CurrentWeapon->WalkForwardBlendSpace.Get(), CurrentWeapon->WalkBackwardBlendSpace.Get());
	}

	// Проигрываем монтаж экипировки
	if (CurrentWeapon->EquipMontage.IsValid())
	{
		PlayAnimMontage(CurrentWeapon->EquipMontage.Get());
	}
}

void ATronRpgBaseCharacter::UnequipWeapon()
{
	if (!CurrentWeapon) return;

	// Проигрываем монтаж снятия
	if (CurrentWeapon->UnequipMontage.IsValid())
	{
		PlayAnimMontage(CurrentWeapon->UnequipMontage.Get());
	}

	// Удаляем теги оружия и тег экипировки
	AbilitySystemComponent->RemoveLooseGameplayTags(CurrentWeapon->WeaponTags);
	AbilitySystemComponent->RemoveLooseGameplayTag(EquippedTag);

	// Сбрасываем BlendSpace
	if (UCharacterAnimInstance* AnimInstance = Cast<UCharacterAnimInstance>(GetMesh()->GetAnimInstance()))
	{
		AnimInstance->SetMovementBlendSpace(DefaultWeaponAsset->WalkForwardBlendSpace.Get(), DefaultWeaponAsset->WalkBackwardBlendSpace.Get());
	}

	CurrentWeapon = nullptr;
}

void ATronRpgBaseCharacter::EquipWeaponByTag(FGameplayTag WeaponTag)
{
	// Пример: получение оружия через менеджер ассетов (дополните под вашу систему)
	UTronRpgWeaponAssetManager* WeaponManager = UTronRpgWeaponAssetManager::Get(this);
	if (WeaponManager)
	{
		TArray<UWeaponDataAsset*> Weapons = WeaponManager->GetWeaponsByTag(WeaponTag);
		if (Weapons.Num() > 0)
		{
			EquipWeapon(Weapons[0]); // Экипируем первое найденное оружие с тегом
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Оружие с тегом %s не найдено"), *WeaponTag.ToString());
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("WeaponManager не найден"));
	}
}
