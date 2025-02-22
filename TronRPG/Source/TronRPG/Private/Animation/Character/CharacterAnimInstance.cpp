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
        if (TransitionTimeRemaining <= 0.f)
        {
            // Завершаем переход: устанавливаем Alpha = 1.0
            BlendSpaceTransitionWeight = 1.0f;
            // Обновляем текущие BlendSpaces
            CurrentWalkForwardBlendSpace = TargetWalkForwardBlendSpace;
            CurrentWalkBackwardBlendSpace = TargetWalkBackwardBlendSpace;
            // Сбрасываем целевые BlendSpaces
            TargetWalkForwardBlendSpace = nullptr;
            TargetWalkBackwardBlendSpace = nullptr;
            // Сбрасываем время и вес
            TransitionTimeRemaining = 0.f;
            BlendSpaceTransitionWeight = 0.f;
        }
        else
        {
            // Обновляем Alpha плавно
            BlendSpaceTransitionWeight = 1.f - (TransitionTimeRemaining / TransitionDuration);
        }
    }
}

void UCharacterAnimInstance::SetMovementBlendSpace(UBlendSpace* WalkForwardBlendSpace, UBlendSpace* WalkBackwardBlendSpace)
{
    CurrentWalkForwardBlendSpace = WalkForwardBlendSpace;
    CurrentWalkBackwardBlendSpace = WalkBackwardBlendSpace;
    TargetWalkForwardBlendSpace = nullptr;
    TargetWalkBackwardBlendSpace = nullptr;
    BlendSpaceTransitionWeight = 0.f;
    TransitionTimeRemaining = 0.f;
}

void UCharacterAnimInstance::TransitionToNewBlendSpace(UBlendSpace* NewWalkForwardBlendSpace, UBlendSpace* NewWalkBackwardBlendSpace, float InTransitionDuration)
{
    if (!NewWalkForwardBlendSpace || !NewWalkBackwardBlendSpace || (NewWalkForwardBlendSpace == CurrentWalkForwardBlendSpace && NewWalkBackwardBlendSpace == CurrentWalkBackwardBlendSpace))
    {
        return;
    }

    TargetWalkForwardBlendSpace = NewWalkForwardBlendSpace;
    TargetWalkBackwardBlendSpace = NewWalkBackwardBlendSpace;
    TransitionDuration = InTransitionDuration;
    TransitionTimeRemaining = InTransitionDuration;
    BlendSpaceTransitionWeight = 0.f;
}
