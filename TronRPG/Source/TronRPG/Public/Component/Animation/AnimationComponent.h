#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AnimationComponent.generated.h"

class USkeletalMeshComponent;
class UAnimInstance;
class UAnimMontage;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TRONRPG_API UAnimationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAnimationComponent();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void SetAnimInstanceClass(TSubclassOf<UAnimInstance> NewAnimClass);

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void PlayMontage(UAnimMontage* Montage, float PlayRate = 1.0f);

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void StopMontage(UAnimMontage* Montage, float BlendOutTime = 0.2f);

protected:
	UPROPERTY(Transient)
	USkeletalMeshComponent* OwnerMesh;

	UPROPERTY(Transient)
	UAnimInstance* AnimInstance;
};