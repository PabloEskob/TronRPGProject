// Tron

#include "Animation/Character/CharacterAnimInstance.h"
#include "AbilitySystemComponent.h"
#include "Character/TronRpgBaseCharacter.h"
#include "Data/Weapon/WeaponDataAsset.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GAS/TronRpgAbilitySystemComponent.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	ATronRpgBaseCharacter* Character = Cast<ATronRpgBaseCharacter>(GetOwningActor());
	if (!Character)
	{
		UE_LOG(LogTemp, Warning, TEXT("NativeInitializeAnimation: Owning actor is not ATronRpgBaseCharacter."));
		return;
	}

	UTronRpgAbilitySystemComponent* ASC = Character->FindComponentByClass<UTronRpgAbilitySystemComponent>();
	if (!ASC)
	{
		UE_LOG(LogTemp, Warning, TEXT("NativeInitializeAnimation: UTronRpgAbilitySystemComponent not found."));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("NativeInitializeAnimation: Owning actor is  ATronRpgBaseCharacter."));
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
	if (ASC)
	{
		FGameplayTagContainer NewTags = ASC->GetOwnedGameplayTags();
		if (NewTags != CurrentStateTags)
		{
			CurrentStateTags = NewTags;
		}
	}
}

void UCharacterAnimInstance::UpdateStateTags(const FGameplayTagContainer& NewTags)
{
	CurrentStateTags = NewTags;
	UE_LOG(LogTemp, Log, TEXT("UpdateStateTags: State tags updated."));
}

void UCharacterAnimInstance::UpdateWeaponAnimations(UWeaponDataAsset* WeaponAsset)
{
	if (!WeaponAsset)
	{
		CurrentWalkForwardBlendSpace = nullptr;
		CurrentWalkBackwardBlendSpace = nullptr;
		return;
	}

	CurrentWalkForwardBlendSpace = WeaponAsset->WalkForwardBlendSpace.Get();
	CurrentWalkBackwardBlendSpace = WeaponAsset->WalkBackwardBlendSpace.Get();
}
