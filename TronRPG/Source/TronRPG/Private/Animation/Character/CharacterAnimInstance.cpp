// Tron

#include "Animation/Character/CharacterAnimInstance.h"
#include "AbilitySystemComponent.h"
#include "Character/TronRpgBaseCharacter.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GAS/TronRpgAbilitySystemComponent.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	ATronRpgBaseCharacter* Character = Cast<ATronRpgBaseCharacter>(GetOwningActor());
	if (!Character) return;

	// Обновляем скорость движения
	if (UCharacterMovementComponent* MovementComponent = Character->GetCharacterMovement())
	{
		GroundSpeed = MovementComponent->Velocity.Size2D();
	}

	// Обновляем теги состояния
	if (UTronRpgAbilitySystemComponent* ASC = Character->FindComponentByClass<UTronRpgAbilitySystemComponent>())
	{
		CurrentStateTags = ASC->GetOwnedGameplayTags();
	}

	if (TransitionTimeRemaining > 0.f)
	{
		TransitionTimeRemaining -= DeltaSeconds;
		if (bCan)
		{
			if (TransitionTimeRemaining <= 0.f)
			{
				BlendSpaceTransitionWeight = 0.0f;
				OptionAWalkForwardBlendSpace = OptionBWalkForwardBlendSpace;
				OptionAWalkBackwardBlendSpace = OptionBWalkBackwardBlendSpace;
				TransitionTimeRemaining = 0.f;
			}
			else
			{
				float Alpha = 1.f - (TransitionTimeRemaining / TransitionDuration);
				BlendSpaceTransitionWeight = FMath::InterpEaseInOut(1.f, 0.f, Alpha, 2.f);
			}
		}
		else
		{
			if (TransitionTimeRemaining <= 0.f)
			{
				BlendSpaceTransitionWeight = 1.0f; // Устанавливаем вес на 1.0
				OptionBWalkForwardBlendSpace = OptionAWalkForwardBlendSpace;
				OptionBWalkBackwardBlendSpace = OptionAWalkBackwardBlendSpace;
				TransitionTimeRemaining = 0.f; // Сбрасываем время, но вес остается 1.0
			}
			else
			{
				float Alpha = 1.f - (TransitionTimeRemaining / TransitionDuration);
				BlendSpaceTransitionWeight = FMath::InterpEaseInOut(0.f, 1.f, Alpha, 2.f);
			}
		}
	}
}

void UCharacterAnimInstance::SetMovementBlendSpace(UBlendSpace* WalkForwardBlendSpace, UBlendSpace* WalkBackwardBlendSpace)
{
	BlendSpaceTransitionWeight = 0.f;
	TransitionTimeRemaining = 0.f;
}

void UCharacterAnimInstance::TransitionToNewBlendSpace(UBlendSpace* NewWalkForwardBlendSpace, UBlendSpace* NewWalkBackwardBlendSpace,
                                                       float InTransitionDuration)
{
	if (bCan)
	{
		OptionAWalkForwardBlendSpace = NewWalkForwardBlendSpace;
		OptionAWalkBackwardBlendSpace = NewWalkBackwardBlendSpace;
		TransitionDuration = InTransitionDuration;
		TransitionTimeRemaining = InTransitionDuration;
		BlendSpaceTransitionWeight = 0.f;

		bCan = false;
	}
	else
	{
		OptionBWalkForwardBlendSpace = NewWalkForwardBlendSpace;
		OptionBWalkBackwardBlendSpace = NewWalkBackwardBlendSpace;
		TransitionDuration = InTransitionDuration;
		TransitionTimeRemaining = InTransitionDuration;
		BlendSpaceTransitionWeight = 1.f;

		bCan = true;
	}
}
