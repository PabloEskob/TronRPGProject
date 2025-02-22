// Tron

#include "Animation/Character/CharacterAnimInstance.h"
#include "AbilitySystemComponent.h"
#include "Character/TronRpgBaseCharacter.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GAS/TronRpgAbilitySystemComponent.h"

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

void UCharacterAnimInstance::SetMovementBlendSpace(UBlendSpace* WalkForwardBlendSpace,UBlendSpace* WalkBackwardBlendSpace)
{
	CurrentWalkForwardBlendSpace = WalkForwardBlendSpace;
	CurrentWalkBackwardBlendSpace = WalkBackwardBlendSpace;
}
