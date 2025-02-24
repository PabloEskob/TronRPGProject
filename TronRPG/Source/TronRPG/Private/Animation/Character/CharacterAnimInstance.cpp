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

	// Кэшируем основные компоненты
	CachedCharacter = Cast<ATronRpgBaseCharacter>(GetOwningActor());
	if (CachedCharacter)
	{
		CachedMovementComponent = CachedCharacter->GetCharacterMovement();
		CachedASC = CachedCharacter->FindComponentByClass<UTronRpgAbilitySystemComponent>();
	}
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	// Если по какой-то причине кэш не установлен, пытаемся обновить его
	if (!CachedCharacter)
	{
		CachedCharacter = Cast<ATronRpgBaseCharacter>(GetOwningActor());
		if (!CachedCharacter)
		{
			return;
		}
	}

	// Обновляем скорость движения
	if (CachedMovementComponent)
	{
		GroundSpeed = CachedMovementComponent->Velocity.Size2D();
	}
	else if (UCharacterMovementComponent* MovementComponent = CachedCharacter->GetCharacterMovement())
	{
		GroundSpeed = MovementComponent->Velocity.Size2D();
		CachedMovementComponent = MovementComponent;
	}

	// Обновляем теги состояния
	if (CachedASC)
	{
		CurrentStateTags = CachedASC->GetOwnedGameplayTags();
	}
	else if (UTronRpgAbilitySystemComponent* ASC = CachedCharacter->FindComponentByClass<UTronRpgAbilitySystemComponent>())
	{
		CurrentStateTags = ASC->GetOwnedGameplayTags();
		CachedASC = ASC;
	}

	// Обработка перехода между blend space
	if (TransitionTimeRemaining > 0.f)
	{
		TransitionTimeRemaining -= DeltaSeconds;
		if (bTransitionToPrimary)
		{
			// Переход от Target -> Primary: интерполируем с 1 до 0
			if (TransitionTimeRemaining <= 0.f)
			{
				BlendSpaceTransitionWeight = 0.f;
				// Завершение перехода: обновляем первичные blend space
				PrimaryWalkForwardBlendSpace = TargetWalkForwardBlendSpace;
				PrimaryWalkBackwardBlendSpace = TargetWalkBackwardBlendSpace;
				TransitionTimeRemaining = 0.f;
			}
			else
			{
				BlendSpaceTransitionWeight = CalculateTransitionWeight(1.f, 0.f);
			}
		}
		else
		{
			// Переход от Primary -> Target: интерполируем с 0 до 1
			if (TransitionTimeRemaining <= 0.f)
			{
				BlendSpaceTransitionWeight = 1.f;
				// Завершение перехода: обновляем целевые blend space
				TargetWalkForwardBlendSpace = PrimaryWalkForwardBlendSpace;
				TargetWalkBackwardBlendSpace = PrimaryWalkBackwardBlendSpace;
				TransitionTimeRemaining = 0.f;
			}
			else
			{
				BlendSpaceTransitionWeight = CalculateTransitionWeight(0.f, 1.f);
			}
		}
	}
}

float UCharacterAnimInstance::CalculateTransitionWeight(float StartWeight, float EndWeight) const
{
	// Защита от деления на ноль
	if (TotalTransitionDuration <= 0.f)
	{
		return EndWeight;
	}
	float Alpha = 1.f - (TransitionTimeRemaining / TotalTransitionDuration);
	return FMath::InterpEaseInOut(StartWeight, EndWeight, Alpha, 2.f);
}

void UCharacterAnimInstance::SetMovementBlendSpace(UBlendSpace* WalkForwardBlendSpace, UBlendSpace* WalkBackwardBlendSpace)
{
	// Немедленное переключение blend space без перехода
	BlendSpaceTransitionWeight = 0.f;
	TransitionTimeRemaining = 0.f;
	TargetWalkForwardBlendSpace = WalkForwardBlendSpace;
	TargetWalkBackwardBlendSpace = WalkBackwardBlendSpace;
	bTransitionToPrimary = true;
}

void UCharacterAnimInstance::TransitionToNewBlendSpace(UBlendSpace* NewWalkForwardBlendSpace, UBlendSpace* NewWalkBackwardBlendSpace, float InTransitionDuration)
{
	TotalTransitionDuration = InTransitionDuration;
	TransitionTimeRemaining = InTransitionDuration;

	if (bTransitionToPrimary)
	{
		// Выполняем переход, обновляя первичные blend space
		PrimaryWalkForwardBlendSpace = NewWalkForwardBlendSpace;
		PrimaryWalkBackwardBlendSpace = NewWalkBackwardBlendSpace;
		BlendSpaceTransitionWeight = 0.f;
		bTransitionToPrimary = false;
	}
	else
	{
		// Переход обновляет целевые blend space
		TargetWalkForwardBlendSpace = NewWalkForwardBlendSpace;
		TargetWalkBackwardBlendSpace = NewWalkBackwardBlendSpace;
		BlendSpaceTransitionWeight = 1.f;
		bTransitionToPrimary = true;
	}
}
