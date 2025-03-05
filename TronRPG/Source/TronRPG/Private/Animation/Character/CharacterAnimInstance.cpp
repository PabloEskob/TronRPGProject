// Tron

#include "Animation/Character/CharacterAnimInstance.h"
#include "AbilitySystemComponent.h"
#include "Character/TronRpgBaseCharacter.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "Object/GameplayTagsLibrary.h"

UCharacterAnimInstance::UCharacterAnimInstance()
{
	// Инициализация значений по умолчанию
	MaxWalkSpeed = 600.f;
	BreathingDecayRate = 1.0f;
	BreathingBuildupRate = 2.0f;
}

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	// Инициализация кэшированных компонентов
	UpdateCachedReferences();
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
    
	// Кэширование компонентов только при необходимости
	if (!CachedCharacter || !IsComponentValid())
	{
		UpdateCachedReferences();
		if (!CachedCharacter || !IsComponentValid())
		{
			return;
		}
	}
    
	// Используем тик-группы для распределения нагрузки
	const uint8 FrameCounter = GFrameCounter & 0x03; // Модуль 4
    
	// Обновление каждый кадр
	UpdateMovementParameters(DeltaSeconds);
    
	// Обновление каждый второй кадр
	if (FrameCounter % 2 == 0)
	{
		UpdateBreathingParameters(DeltaSeconds);
	}
    
	// Обновление каждый четвертый кадр
	if (FrameCounter == 0)
	{
		UpdateStateTags();
	}
    
	// Обновление при необходимости
	if (TransitionTimeRemaining > 0.f)
	{
		UpdateBlendSpaceTransition(DeltaSeconds);
	}
}

bool UCharacterAnimInstance::IsComponentValid() const
{
	return CachedMovementComponent != nullptr && CachedASC != nullptr;
}

void UCharacterAnimInstance::UpdateCachedReferences()
{
	// Кэшируем основные компоненты для ускорения доступа
	CachedCharacter = Cast<ATronRpgBaseCharacter>(GetOwningActor());
	if (CachedCharacter)
	{
		CachedMovementComponent = CachedCharacter->GetCharacterMovement();
		CachedASC = Cast<UTronRpgAbilitySystemComponent>(CachedCharacter->GetAbilitySystemComponent());
	}
}

void UCharacterAnimInstance::UpdateMovementParameters(float DeltaSeconds)
{
	if (!EnsureMovementComponentValid())
	{
		return;
	}

	UpdateGroundSpeed();
	UpdateDirectionAngle();
	UpdateMovementState();
}

bool UCharacterAnimInstance::EnsureMovementComponentValid()
{
	if (!CachedMovementComponent && CachedCharacter)
	{
		CachedMovementComponent = CachedCharacter->GetCharacterMovement();
	}
    
	return CachedMovementComponent != nullptr;
}

void UCharacterAnimInstance::UpdateGroundSpeed()
{
	const FVector Velocity = CachedMovementComponent->Velocity;
	GroundSpeed = Velocity.Size2D();
	NormalizedSpeed = FMath::Clamp(GroundSpeed / MaxWalkSpeed, 0.0f, 1.0f);
}

void UCharacterAnimInstance::UpdateDirectionAngle()
{
	static const float MinSpeedThreshold = 10.0f;
	static const float MinInputThreshold = 0.1f;
    
	FVector ForwardVector = CachedCharacter->GetActorForwardVector();
	FVector RightVector = CachedCharacter->GetActorRightVector();
    
	if (GroundSpeed > MinSpeedThreshold)
	{
		// Высокая скорость: используем фактический вектор скорости
		FVector VelocityDirection = CachedMovementComponent->Velocity.GetSafeNormal2D();
		CalculateMovementAngle(ForwardVector, RightVector, VelocityDirection);
	}
	else 
	{
		FVector LastInputVector = CachedMovementComponent->GetLastInputVector();
		float LastInputMagnitude = LastInputVector.Size2D();
        
		if (LastInputMagnitude > MinInputThreshold)
		{
			// Низкая скорость, но есть ввод: используем вектор ввода
			FVector InputDirection = LastInputVector.GetSafeNormal2D();
			CalculateMovementAngle(ForwardVector, RightVector, InputDirection);
		}
		else
		{
			// Нет движения и нет ввода: считаем, что персонаж смотрит вперед
			DirectionAngle = 0.0f;
			MovementDirection = 0.0f;
		}
	}
}

void UCharacterAnimInstance::CalculateMovementAngle(const FVector& ForwardVector, const FVector& RightVector, const FVector& DirectionVector)
{
	float ForwardDot = FVector::DotProduct(ForwardVector, DirectionVector);
	float RightDot = FVector::DotProduct(RightVector, DirectionVector);
    
	DirectionAngle = FMath::Atan2(RightDot, ForwardDot) * 180.0f / PI;
	MovementDirection = ForwardDot;
}

void UCharacterAnimInstance::UpdateMovementState()
{
	if (CachedASC)
	{
		bIsJogging = GroundSpeed > MaxWalkSpeed * 0.5f;
		bIsSprinting = CachedASC->HasMatchingGameplayTag(TAG_State_Sprinting);
	}
}

void UCharacterAnimInstance::UpdateBreathingParameters(float DeltaSeconds)
{
	float targetIntensity = CalculateTargetBreathingIntensity();
	SmoothlyUpdateBreathingIntensity(targetIntensity, DeltaSeconds);
}

float UCharacterAnimInstance::CalculateTargetBreathingIntensity() const
{
	if (bIsSprinting)
	{
		return 1.0f; // Максимальная интенсивность при спринте
	}
    
	if (bIsJogging)
	{
		return 0.6f; // Средняя интенсивность при беге
	}
    
	static const float MinMovementThreshold = 10.0f;
	if (GroundSpeed > MinMovementThreshold)
	{
		return 0.3f; // Низкая интенсивность при ходьбе
	}
    
	return 0.0f; // В состоянии покоя
}

void UCharacterAnimInstance::SmoothlyUpdateBreathingIntensity(float TargetIntensity, float DeltaSeconds)
{
	if (BreathingIntensity < TargetIntensity)
	{
		// Быстрое увеличение интенсивности при активности
		BreathingIntensity = FMath::Min(BreathingIntensity + DeltaSeconds * BreathingBuildupRate, TargetIntensity);
	}
	else if (BreathingIntensity > TargetIntensity)
	{
		// Медленное снижение интенсивности при отдыхе
		BreathingIntensity = FMath::Max(BreathingIntensity - DeltaSeconds * BreathingDecayRate, TargetIntensity);
	}
}

void UCharacterAnimInstance::UpdateStateTags()
{
	// Обновляем теги состояния
	if (CachedASC)
	{
		CurrentStateTags = CachedASC->GetOwnedGameplayTags();
	}
	else if (CachedCharacter)
	{
		// Если ASC не кэширован, пытаемся получить его
		UTronRpgAbilitySystemComponent* ASC = Cast<UTronRpgAbilitySystemComponent>(CachedCharacter->GetAbilitySystemComponent());
		if (ASC)
		{
			CurrentStateTags = ASC->GetOwnedGameplayTags();
			CachedASC = ASC;
		}
	}
}

void UCharacterAnimInstance::UpdateBlendSpaceTransition(float DeltaSeconds)
{
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
				TargetWalkForwardBlendSpace = PrimaryWalkForwardBlendSpace;
				TargetWalkBackwardBlendSpace = PrimaryWalkBackwardBlendSpace;
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
				PrimaryWalkForwardBlendSpace = TargetWalkForwardBlendSpace;
				PrimaryWalkBackwardBlendSpace = TargetWalkBackwardBlendSpace;
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

	// Вычисление альфы интерполяции
	float Alpha = 1.f - (TransitionTimeRemaining / TotalTransitionDuration);

	// Плавная интерполяция с ускорением и замедлением
	return FMath::InterpEaseInOut(StartWeight, EndWeight, Alpha, 2.f);
}

void UCharacterAnimInstance::SetMovementBlendSpace(UBlendSpace* WalkForwardBlendSpace, UBlendSpace* WalkBackwardBlendSpace)
{
	// Немедленное переключение blend space без перехода
	BlendSpaceTransitionWeight = 0.f;
	TransitionTimeRemaining = 0.f;

	PrimaryWalkForwardBlendSpace = WalkForwardBlendSpace;
	PrimaryWalkBackwardBlendSpace = WalkBackwardBlendSpace;

	TargetWalkForwardBlendSpace = WalkForwardBlendSpace;
	TargetWalkBackwardBlendSpace = WalkBackwardBlendSpace;

	bTransitionToPrimary = true;
}

void UCharacterAnimInstance::TransitionToNewBlendSpace(UBlendSpace* NewWalkForwardBlendSpace, UBlendSpace* NewWalkBackwardBlendSpace,
                                                       float InTransitionDuration)
{
	// Проверка валидности параметров
	if (!NewWalkForwardBlendSpace || !NewWalkBackwardBlendSpace)
	{
		UE_LOG(LogTemp, Warning, TEXT("Attempted to transition to invalid blend space"));
		return;
	}

	// Настройка длительности перехода
	TotalTransitionDuration = FMath::Max(InTransitionDuration, 0.001f); // Минимальная длительность для предотвращения деления на ноль
	TransitionTimeRemaining = TotalTransitionDuration;

	// Определение направления перехода
	if (bTransitionToPrimary)
	{
		// Если ранее был переход к Primary, теперь переходим к Target
		// Установка новых целевых blend space
		TargetWalkForwardBlendSpace = NewWalkForwardBlendSpace;
		TargetWalkBackwardBlendSpace = NewWalkBackwardBlendSpace;

		// Начинаем с весом 0 (полностью Primary) и переходим к 1 (полностью Target)
		BlendSpaceTransitionWeight = 0.f;
		bTransitionToPrimary = false;
	}
	else
	{
		// Если ранее был переход к Target, теперь переходим к Primary
		// Установка новых первичных blend space
		PrimaryWalkForwardBlendSpace = NewWalkForwardBlendSpace;
		PrimaryWalkBackwardBlendSpace = NewWalkBackwardBlendSpace;

		// Начинаем с весом 1 (полностью Target) и переходим к 0 (полностью Primary)
		BlendSpaceTransitionWeight = 1.f;
		bTransitionToPrimary = true;
	}
}

bool UCharacterAnimInstance::HasStateTag(FGameplayTag StateTag) const
{
	return CurrentStateTags.HasTag(StateTag);
}

void UCharacterAnimInstance::HandleNotifyBegin(FName NotifyName)
{
	// Вызываем делегат для обработки уведомления
	OnAnimNotifyBegin.Broadcast(NotifyName);
}
