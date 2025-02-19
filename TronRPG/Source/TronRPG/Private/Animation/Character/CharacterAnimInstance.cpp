// Tron

#include "Animation/Character/CharacterAnimInstance.h"
#include "AbilitySystemComponent.h"
#include "Character/TronRpgBaseCharacter.h"
#include "Data/Weapon/WeaponDataAsset.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GAS/TronRpgAbilitySystemComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogCharacterAnimInstance, Log, All);

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	ATronRpgBaseCharacter* Character = Cast<ATronRpgBaseCharacter>(GetOwningActor());
	if (!Character)
	{
		UE_LOG(LogCharacterAnimInstance, Warning, TEXT("NativeInitializeAnimation: Owning actor is not ATronRpgBaseCharacter."));
		return;
	}

	UTronRpgAbilitySystemComponent* ASC = Character->FindComponentByClass<UTronRpgAbilitySystemComponent>();
	if (!ASC)
	{
		UE_LOG(LogCharacterAnimInstance, Warning, TEXT("NativeInitializeAnimation: UTronRpgAbilitySystemComponent not found."));
		return;
	}

	CurrentStateTags = ASC->GetOwnedGameplayTags();
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	ATronRpgBaseCharacter* Character = Cast<ATronRpgBaseCharacter>(GetOwningActor());
	if (!Character)
	{
		return;
	}

	if (UCharacterMovementComponent* MovementComponent = Character->GetCharacterMovement())
	{
		GroundSpeed = MovementComponent->Velocity.Size2D();
	}

	UTronRpgAbilitySystemComponent* ASC = Character->FindComponentByClass<UTronRpgAbilitySystemComponent>();
	if (!ASC)
	{
		return;
	}

	FGameplayTagContainer NewTags = ASC->GetOwnedGameplayTags();
	if (NewTags != CurrentStateTags)
	{
		CurrentStateTags = NewTags;
	}
}

void UCharacterAnimInstance::UpdateStateTags(const FGameplayTagContainer& NewTags)
{
	CurrentStateTags = NewTags;
	UE_LOG(LogCharacterAnimInstance, Log, TEXT("UpdateStateTags: State tags updated."));
}

void UCharacterAnimInstance::UpdateWeaponAnimations(UWeaponDataAsset* WeaponAsset)
{
	if (!WeaponAsset)
	{
		CurrentIdleAnimation = nullptr;
		CurrentWalkForwardBlendSpace = nullptr;
		CurrentRunForwardBlendSpace = nullptr;
		CurrentWalkBackwardBlendSpace = nullptr;
		CurrentRunBackwardBlendSpace = nullptr;
		return;
	}

	CurrentIdleAnimation = WeaponAsset->IdleAnimation.Get();
	CurrentWalkForwardBlendSpace = WeaponAsset->WalkForwardBlendSpace.Get();
	CurrentRunForwardBlendSpace = WeaponAsset->RunForwardBlendSpace.Get();
	CurrentWalkBackwardBlendSpace = WeaponAsset->WalkBackwardBlendSpace.Get();
	CurrentRunBackwardBlendSpace = WeaponAsset->RunBackwardBlendSpace.Get();
}
