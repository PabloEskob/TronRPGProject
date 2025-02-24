#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

class UBlendSpace;
class UCharacterMovementComponent;
class ATronRpgBaseCharacter;
class UTronRpgAbilitySystemComponent;

UCLASS()
class TRONRPG_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	/** Устанавливает blend space без перехода */
	UFUNCTION(BlueprintCallable, Category = "Animation")
	void SetMovementBlendSpace(UBlendSpace* WalkForwardBlendSpace, UBlendSpace* WalkBackwardBlendSpace);

	/** Плавно переходит к новому blend space за заданную длительность */
	UFUNCTION(BlueprintCallable, Category = "Animation")
	void TransitionToNewBlendSpace(UBlendSpace* NewWalkForwardBlendSpace, UBlendSpace* NewWalkBackwardBlendSpace, float InTransitionDuration);

protected:
	// Текущая скорость персонажа
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float GroundSpeed = 0.f;

	// Теги состояния персонажа
	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	FGameplayTagContainer CurrentStateTags;

	// Первичные (текущие) blend space для движения вперед и назад
	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	UBlendSpace* PrimaryWalkForwardBlendSpace = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	UBlendSpace* PrimaryWalkBackwardBlendSpace = nullptr;

	// Целевые (ожидаемые) blend space для перехода
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Animation")
	UBlendSpace* TargetWalkForwardBlendSpace = nullptr;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Animation")
	UBlendSpace* TargetWalkBackwardBlendSpace = nullptr;

	// Вес интерполяции: 0 - полностью первичные, 1 - полностью целевые
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Animation")
	float BlendSpaceTransitionWeight = 0.f;

	// Остаток времени перехода
	UPROPERTY(Transient)
	float TransitionTimeRemaining = 0.f;

	// Общая длительность перехода
	UPROPERTY(Transient)
	float TotalTransitionDuration = 0.5f;

	// Флаг, определяющий направление перехода:
	// true  – выполняется переход от Target -> Primary,
	// false – от Primary -> Target.
	UPROPERTY(Transient)
	bool bTransitionToPrimary = true;

	// Кэшированные указатели на компоненты
	UPROPERTY(Transient)
	ATronRpgBaseCharacter* CachedCharacter = nullptr;

	UPROPERTY(Transient)
	UCharacterMovementComponent* CachedMovementComponent = nullptr;

	UPROPERTY(Transient)
	UTronRpgAbilitySystemComponent* CachedASC = nullptr;

	// Вспомогательная функция для расчёта веса перехода
	float CalculateTransitionWeight(float StartWeight, float EndWeight) const;
};