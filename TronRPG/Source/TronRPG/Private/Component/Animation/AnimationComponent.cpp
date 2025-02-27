// Tron


#include "Component/Animation/AnimationComponent.h"

#include "Animation/Character/CharacterAnimInstance.h"


void UAnimationComponent::BeginPlay()
{
	Super::BeginPlay();
	SkeletalMeshComponent = GetOwner()->FindComponentByClass<USkeletalMeshComponent>();
	AnimInstance = SkeletalMeshComponent ? Cast<UCharacterAnimInstance>(SkeletalMeshComponent->GetAnimInstance()) : nullptr;
}

void UAnimationComponent::SetMovementBlendSpace(UBlendSpace* Forward, UBlendSpace* Backward)
{
	if (AnimInstance)
	{
		AnimInstance->SetMovementBlendSpace(Forward, Backward);
	}
}

void UAnimationComponent::TransitionToNewBlendSpace(UBlendSpace* Forward, UBlendSpace* Backward, float Duration)
{
	if (AnimInstance)
	{
		AnimInstance->TransitionToNewBlendSpace(Forward, Backward, Duration);
	}
}

void UAnimationComponent::PlayMontage(UAnimMontage* Montage)
{
	if (SkeletalMeshComponent && Montage)
	{
		SkeletalMeshComponent->GetAnimInstance()->Montage_Play(Montage);
	}
}

