#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Animation/AnimInstance.h"
#include "Interface/Animation/AnimatableCharacter.h"
#include "CharacterAnimInstance.generated.h"

class UBlendSpace;
class UCharacterMovementComponent;
class UAbilitySystemComponent;

/**
 * Делегат для события уведомления в анимации
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAnimNotifyBegin, FName, NotifyName);

/**
 * Класс анимационного экземпляра для персонажей TronRPG
 * Обеспечивает плавные переходы между анимациями и интеграцию с GAS
 */
UCLASS()
class TRONRPG_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UCharacterAnimInstance();

	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	/**
	 * Устанавливает blend space без перехода
	 */
	UFUNCTION(BlueprintCallable, Category = "Animation")
	void SetMovementBlendSpace(UBlendSpace* WalkForwardBlendSpace, UBlendSpace* WalkBackwardBlendSpace);

	/**
	 * Плавно переходит к новому blend space за заданную длительность
	 */
	UFUNCTION(BlueprintCallable, Category = "Animation")
	void TransitionToNewBlendSpace(UBlendSpace* NewWalkForwardBlendSpace, UBlendSpace* NewWalkBackwardBlendSpace, float InTransitionDuration);

	/**
	 * Проверяет наличие тега состояния у персонажа
	 */
	UFUNCTION(BlueprintPure, Category = "Animation|State")
	bool HasStateTag(FGameplayTag StateTag) const;

	/**
	 * Получить текущую скорость персонажа
	 */
	UFUNCTION(BlueprintPure, Category = "Animation|Movement")
	float GetGroundSpeed() const { return GroundSpeed; }

	/**
	 * Событие начала Notify в анимации
	 */
	UPROPERTY(BlueprintAssignable, Category = "Animation|Events")
	FOnAnimNotifyBegin OnAnimNotifyBegin;

	/**
	 * Обработчик события Notify в анимации
	 */
	UFUNCTION(BlueprintCallable, Category = "Animation|Events")
	void HandleNotifyBegin(FName NotifyName);

	/**
	 * Получить текущий угол направления для BlendSpace
	 */
	UFUNCTION(BlueprintPure, Category = "Animation|Movement")
	float GetDirectionAngle() const { return DirectionAngle; }

protected:
	/** Текущая скорость персонажа на земле */
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float GroundSpeed = 0.f;

	/** Нормализованная скорость (0-1) для анимации */
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float NormalizedSpeed = 0.f;

	/** Максимальная скорость ходьбы для нормализации */
	UPROPERTY(EditDefaultsOnly, Category = "Movement", meta = (ClampMin = "1.0"))
	float MaxWalkSpeed = 600.f;

	/** Направление движения (положительное - вперед, отрицательное - назад) */
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float MovementDirection = 0.f;

	/** Флаг бега трусцой */
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	bool bIsJogging = false;

	/** Флаг бега (спринта) */
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	bool bIsSprinting = false;

	/** Тяжесть дыхания (для анимаций дыхания) */
	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	float BreathingIntensity = 0.f;

	/** Теги состояния персонажа */
	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	FGameplayTagContainer CurrentStateTags;

	/** Blend space для движения */
	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	UBlendSpace* PrimaryWalkForwardBlendSpace = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	UBlendSpace* PrimaryWalkBackwardBlendSpace = nullptr;

	/** Целевые (ожидаемые) blend space для перехода */
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Animation")
	UBlendSpace* TargetWalkForwardBlendSpace = nullptr;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Animation")
	UBlendSpace* TargetWalkBackwardBlendSpace = nullptr;

	/** Вес интерполяции: 0 - полностью первичные, 1 - полностью целевые */
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Animation")
	float BlendSpaceTransitionWeight = 0.f;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float DirectionAngle = 0.f;

	/** Остаток времени перехода */
	UPROPERTY(Transient)
	float TransitionTimeRemaining = 0.f;

	/** Общая длительность перехода */
	UPROPERTY(Transient)
	float TotalTransitionDuration = 0.5f;

	/** Флаг направления перехода */
	UPROPERTY(Transient)
	bool bTransitionToPrimary = true;

	/** Кэшированные указатели на компоненты */
	UPROPERTY(Transient)
	TScriptInterface<IAnimatableCharacter> CachedAnimatableCharacter;
	
	UPROPERTY(Transient)
	UCharacterMovementComponent* CachedMovementComponent = nullptr;

	UPROPERTY(Transient)
	UAbilitySystemComponent* CachedASC = nullptr;

	/** Скорость затухания интенсивности дыхания */
	UPROPERTY(EditDefaultsOnly, Category = "Animation", meta = (ClampMin = "0.1"))
	float BreathingDecayRate = 1.0f;

	/** Множитель увеличения интенсивности дыхания при движении */
	UPROPERTY(EditDefaultsOnly, Category = "Animation", meta = (ClampMin = "0.1"))
	float BreathingBuildupRate = 2.0f;

	/** Вспомогательная функция для расчёта веса перехода */
	float CalculateTransitionWeight(float StartWeight, float EndWeight) const;

	// Методы обновления состояний
	void UpdateCachedReferences();
	void UpdateMovementSpeed(float DeltaSeconds);
	void UpdateMovementDirection();
	void UpdateMovementState();
	void UpdateBreathingParameters(float DeltaSeconds);
	void UpdateStateTags();
	void UpdateBlendSpaceTransition(float DeltaSeconds);
};
