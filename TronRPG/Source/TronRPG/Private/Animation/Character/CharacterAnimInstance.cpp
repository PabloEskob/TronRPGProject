#include "Animation/Character/CharacterAnimInstance.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
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

    // Проверка кэшированных компонентов
    if (!CachedAnimatableCharacter.GetInterface())
    {
        UpdateCachedReferences();
        if (!CachedAnimatableCharacter.GetInterface())
        {
            return;
        }
    }

    // Обновление различных аспектов анимации с разделением ответственности
    UpdateMovementSpeed(DeltaSeconds);
    UpdateMovementDirection();
    UpdateMovementState();
    UpdateBreathingParameters(DeltaSeconds);
    UpdateStateTags();
    UpdateBlendSpaceTransition(DeltaSeconds);
}

void UCharacterAnimInstance::UpdateCachedReferences()
{
    // Получаем владельца и пытаемся привести к интерфейсу IAnimatableCharacter
    AActor* Owner = GetOwningActor();
    
    if (Owner && Owner->Implements<UAnimatableCharacter>())
    {
        CachedAnimatableCharacter = Owner;
        
        // Получаем компоненты через интерфейс
        if (CachedAnimatableCharacter.GetInterface())
        {
            CachedMovementComponent = IAnimatableCharacter::Execute_GetCharacterMovement(Owner);
            CachedASC = IAnimatableCharacter::Execute_GetAbilitySystemComponent(Owner);
        }
    }
}

void UCharacterAnimInstance::UpdateMovementSpeed(float DeltaSeconds)
{
    if (!CachedMovementComponent)
        return;

    // Получаем скорость движения
    FVector Velocity = CachedMovementComponent->Velocity;
    GroundSpeed = Velocity.Size2D();

    // Нормализация скорости для blend space
    NormalizedSpeed = FMath::Clamp(GroundSpeed / MaxWalkSpeed, 0.0f, 1.0f);
}

void UCharacterAnimInstance::UpdateMovementDirection()
{
    if (!CachedMovementComponent || !CachedAnimatableCharacter.GetInterface())
        return;

    AActor* Owner = GetOwningActor();
    if (!Owner)
        return;

    // Получаем последний входной вектор движения из компонента движения
    FVector LastInputVector = CachedMovementComponent->GetLastInputVector();
    float LastInputMagnitude = LastInputVector.Size2D();

    // Вычисление угла направления для BlendSpace
    if (GroundSpeed > 10.0f)
    {
        // Высокая скорость: используем фактический вектор скорости
        FVector ForwardVector = Owner->GetActorForwardVector();
        FVector RightVector = Owner->GetActorRightVector();
        FVector VelocityDirection = CachedMovementComponent->Velocity.GetSafeNormal2D();
        
        // Вычисляем угол между направлением персонажа и его скоростью
        float ForwardDot = FVector::DotProduct(ForwardVector, VelocityDirection);
        float RightDot = FVector::DotProduct(RightVector, VelocityDirection);
        
        // Преобразуем в угол от -180 до 180 градусов
        DirectionAngle = FMath::Atan2(RightDot, ForwardDot) * 180.0f / PI;
        
        // Для использования в определении направления вперед/назад
        MovementDirection = ForwardDot;
    }
    else if (LastInputMagnitude > 0.1f)
    {
        // Низкая скорость, но есть ввод: используем вектор ввода
        FVector ForwardVector = Owner->GetActorForwardVector();
        FVector RightVector = Owner->GetActorRightVector();
        FVector InputDirection = LastInputVector.GetSafeNormal2D();
        
        // Аналогично вычисляем угол, но используя вектор ввода
        float ForwardDot = FVector::DotProduct(ForwardVector, InputDirection);
        float RightDot = FVector::DotProduct(RightVector, InputDirection);
        
        DirectionAngle = FMath::Atan2(RightDot, ForwardDot) * 180.0f / PI;
        MovementDirection = ForwardDot;
    }
    else
    {
        // Нет движения и нет ввода: считаем, что персонаж смотрит вперед
        DirectionAngle = 0.0f;
        MovementDirection = 0.0f;
    }
}

void UCharacterAnimInstance::UpdateMovementState()
{
    if (!CachedASC)
        return;

    // Определение типа движения на основе скорости и тегов
    bIsJogging = GroundSpeed > MaxWalkSpeed * 0.5f;
    bIsSprinting = CachedASC->HasMatchingGameplayTag(TAG_State_Sprinting);
}

void UCharacterAnimInstance::UpdateBreathingParameters(float DeltaSeconds)
{
    // Обновляем интенсивность дыхания в зависимости от активности
    float TargetBreathingIntensity = 0.0f;

    if (bIsSprinting)
    {
        // При спринте - максимальная интенсивность
        TargetBreathingIntensity = 1.0f;
    }
    else if (bIsJogging)
    {
        // При беге - средняя интенсивность
        TargetBreathingIntensity = 0.6f;
    }
    else if (GroundSpeed > 10.0f)
    {
        // При ходьбе - низкая интенсивность
        TargetBreathingIntensity = 0.3f;
    }

    // Плавное изменение интенсивности дыхания
    if (BreathingIntensity < TargetBreathingIntensity)
    {
        // Быстрое увеличение интенсивности при активности
        BreathingIntensity = FMath::Min(BreathingIntensity + DeltaSeconds * BreathingBuildupRate, TargetBreathingIntensity);
    }
    else if (BreathingIntensity > TargetBreathingIntensity)
    {
        // Медленное снижение интенсивности при отдыхе
        BreathingIntensity = FMath::Max(BreathingIntensity - DeltaSeconds * BreathingDecayRate, TargetBreathingIntensity);
    }
}

void UCharacterAnimInstance::UpdateStateTags()
{
    if (!CachedAnimatableCharacter.GetInterface())
        return;

    AActor* Owner = GetOwningActor();
    if (Owner)
    {
        CurrentStateTags = IAnimatableCharacter::Execute_GetCurrentGameplayTags(Owner);
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