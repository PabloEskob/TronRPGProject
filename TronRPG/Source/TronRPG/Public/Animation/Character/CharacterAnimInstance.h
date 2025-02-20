#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

class UWeaponDataAsset;

UCLASS()
class TRONRPG_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	FGameplayTagContainer CurrentStateTags;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float GroundSpeed;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	UBlendSpace* CurrentWalkForwardBlendSpace;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	UBlendSpace* CurrentWalkBackwardBlendSpace;

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void UpdateStateTags(const FGameplayTagContainer& NewTags);

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void UpdateWeaponAnimations(UWeaponDataAsset* WeaponAsset);
};