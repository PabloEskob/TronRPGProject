#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

UCLASS()
class TRONRPG_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void SetMovementBlendSpace(UBlendSpace* WalkForwardBlendSpace, UBlendSpace* WalkBackwardBlendSpace);

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void TransitionToNewBlendSpace(UBlendSpace* NewWalkForwardBlendSpace, UBlendSpace* NewWalkBackwardBlendSpace, float TransitionDuration);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float GroundSpeed = 0.f;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	FGameplayTagContainer CurrentStateTags;

	// Текущие активные BlendSpaces
	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	UBlendSpace* OptionAWalkForwardBlendSpace = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	UBlendSpace* OptionAWalkBackwardBlendSpace = nullptr;

	// Целевые BlendSpaces для перехода
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Animation")
	UBlendSpace* OptionBWalkForwardBlendSpace = nullptr;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Animation")
	UBlendSpace* OptionBWalkBackwardBlendSpace = nullptr;

	// Вес интерполяции для плавного перехода (0 - текущий, 1 - целевой)
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Animation")
	float BlendSpaceTransitionWeight = 0.f;

	UPROPERTY(Transient)
	float TransitionTimeRemaining = 0.f;

	UPROPERTY(Transient)
	float TransitionDuration = 0.5f;

	UPROPERTY(Transient)
	bool bCan;
};
