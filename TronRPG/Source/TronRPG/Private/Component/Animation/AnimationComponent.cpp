#include "Component/Animation/AnimationComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"

UAnimationComponent::UAnimationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAnimationComponent::BeginPlay()
{
	Super::BeginPlay();

	// Получаем ссылку на SkeletalMeshComponent владельца
	OwnerMesh = GetOwner()->FindComponentByClass<USkeletalMeshComponent>();
	if (OwnerMesh)
	{
		AnimInstance = OwnerMesh->GetAnimInstance();
	}
}

void UAnimationComponent::SetAnimInstanceClass(TSubclassOf<UAnimInstance> NewAnimClass)
{
	if (OwnerMesh && NewAnimClass)
	{
		OwnerMesh->SetAnimInstanceClass(NewAnimClass);
		AnimInstance = OwnerMesh->GetAnimInstance();
	}
}

void UAnimationComponent::PlayMontage(UAnimMontage* Montage, float PlayRate)
{
	if (AnimInstance && Montage)
	{
		AnimInstance->Montage_Play(Montage, PlayRate);
	}
}

void UAnimationComponent::StopMontage(UAnimMontage* Montage, float BlendOutTime)
{
	if (AnimInstance && Montage)
	{
		AnimInstance->Montage_Stop(BlendOutTime, Montage);
	}
}