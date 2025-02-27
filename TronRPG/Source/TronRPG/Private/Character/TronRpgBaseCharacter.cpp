#include "Character/TronRpgBaseCharacter.h"

#include "Animation/Character/CharacterAnimInstance.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "GAS/TronRpgAttributeSet.h"
#include "Component/TronRpgComboComponent.h"
#include "Component/Animation/AnimationComponent.h"
#include "Component/DI/DependencyInjectorComponent.h"
#include "Component/Input/AbilityInputComponent.h"
#include "Component/Weapon/WeaponComponent.h"
#include "Data/Weapon/WeaponDataAsset.h"
#include "Net/UnrealNetwork.h"

ATronRpgBaseCharacter::ATronRpgBaseCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UTronRpgAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<UTronRpgAttributeSet>(TEXT("AttributeSet"));
	ComboComponent = CreateDefaultSubobject<UTronRpgComboComponent>(TEXT("ComboComponent"));
	AnimationComponent = CreateDefaultSubobject<UAnimationComponent>(TEXT("AnimationComponent"));
	DependencyInjector = CreateDefaultSubobject<UDependencyInjectorComponent>(TEXT("DependencyInjector"));
	AbilityInputComponent = CreateDefaultSubobject<UAbilityInputComponent>(TEXT("AbilityInputComponent"));
	WeaponComponent = CreateDefaultSubobject<UWeaponComponent>(TEXT("WeaponComponent"));

	// Привязка делегата к методу (можно сделать в конструкторе или BeginPlay)
	OnWeaponVisibilityChanged.AddDynamic(this, &ATronRpgBaseCharacter::UpdateWeaponVisibility);

	WeaponComponent->MainHandMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MainHandMesh"));
	WeaponComponent->MainHandMeshComponent->SetupAttachment(GetMesh(), TEXT("WeaponSocket_MainHand"));
	WeaponComponent->MainHandMeshComponent->SetVisibility(false);

	WeaponComponent->OffHandMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OffHandMesh"));
	WeaponComponent->OffHandMeshComponent->SetupAttachment(GetMesh(), TEXT("WeaponSocket_OffHand"));
	WeaponComponent->OffHandMeshComponent->SetVisibility(false);
}

void ATronRpgBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (DefaultWeaponAsset)
	{
		AnimationComponent->SetMovementBlendSpace(
			DefaultWeaponAsset->WalkForwardBlendSpace.Get(),
			DefaultWeaponAsset->WalkBackwardBlendSpace.Get()
		);
	}
}

void ATronRpgBaseCharacter::UpdateWeaponVisibility(bool bIsVisible)
{
	WeaponComponent->UpdateWeaponVisuals(bIsVisible);
}

UAbilitySystemComponent* ATronRpgBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ATronRpgBaseCharacter::EquipWeapon(UWeaponDataAsset* WeaponAsset, float BlendSpaceTransitionDuration)
{
	if (!WeaponAsset) return;

	WeaponComponent->EquipWeapon(WeaponAsset);
	AnimationComponent->PlayMontage(WeaponAsset->EquipMontage.Get());
	AnimationComponent->TransitionToNewBlendSpace(
		WeaponAsset->WalkForwardBlendSpace.Get(),
		WeaponAsset->WalkBackwardBlendSpace.Get(),
		BlendSpaceTransitionDuration
	);
}

void ATronRpgBaseCharacter::UnequipWeapon()
{
	if (!WeaponComponent->CurrentWeapon) return;

	AnimationComponent->PlayMontage(WeaponComponent->CurrentWeapon->UnequipMontage.Get());
	AnimationComponent->TransitionToNewBlendSpace(
		DefaultWeaponAsset->WalkForwardBlendSpace.Get(),
		DefaultWeaponAsset->WalkBackwardBlendSpace.Get(),
		1.0f
	);
	WeaponComponent->UnequipWeapon();
}

void ATronRpgBaseCharacter::EquipWeaponByTag(FGameplayTag WeaponTag)
{
	WeaponComponent->EquipWeaponByTag(WeaponTag);
}

void ATronRpgBaseCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ATronRpgBaseCharacter, AbilitySystemComponent);
}
