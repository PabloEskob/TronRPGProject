// Tron

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AnimationComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TRONRPG_API UAnimationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetMovementBlendSpace(UBlendSpace* Forward, UBlendSpace* Backward);

	UFUNCTION(BlueprintCallable)
	void TransitionToNewBlendSpace(UBlendSpace* Forward, UBlendSpace* Backward, float Duration);

	UFUNCTION(BlueprintCallable)
	void PlayMontage(UAnimMontage* Montage);

protected:
	UPROPERTY()
	USkeletalMeshComponent* SkeletalMeshComponent;

	UPROPERTY()
	class UCharacterAnimInstance* AnimInstance;

	void BeginPlay() override;
};
