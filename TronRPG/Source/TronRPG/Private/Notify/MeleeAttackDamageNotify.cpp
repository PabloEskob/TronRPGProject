#include "Notify/MeleeAttackDamageNotify.h"
#include "Animation/Character/CharacterAnimInstance.h"
#include "Components/SkeletalMeshComponent.h"

UMeleeAttackDamageNotify::UMeleeAttackDamageNotify()
{
	// По умолчанию используем имя "ApplyDamage"
	NotifyName = FName("ApplyDamage");
}

void UMeleeAttackDamageNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (!MeshComp)
	{
		return;
	}

	// Получаем анимационный экземпляр
	UAnimInstance* AnimInstance = MeshComp->GetAnimInstance();
	UCharacterAnimInstance* CharAnimInstance = Cast<UCharacterAnimInstance>(AnimInstance);

	// Если это наш кастомный анимационный экземпляр, вызываем его метод для обработки уведомления
	if (CharAnimInstance)
	{
		CharAnimInstance->HandleNotifyBegin(NotifyName);
	}
}
