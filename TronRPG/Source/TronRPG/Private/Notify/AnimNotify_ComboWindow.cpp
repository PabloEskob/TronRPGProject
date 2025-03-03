// Tron


#include "Notify/AnimNotify_ComboWindow.h"

#include "Animation/Character/CharacterAnimInstance.h"

class UCharacterAnimInstance;

UAnimNotify_ComboWindow::UAnimNotify_ComboWindow()
{
}

void UAnimNotify_ComboWindow::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
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
		CharAnimInstance->HandleNotifyBegin(FName("ComboWindow"));
        
		// Добавим визуальное отображение для отладки
		if (bShowDebugInfo && MeshComp->GetOwner())
		{
			FVector Location = MeshComp->GetOwner()->GetActorLocation() + FVector(0, 0, 100.0f);
			FString DebugMessage = FString::Printf(TEXT("COMBO WINDOW OPEN"));
            
			DrawDebugString(
				MeshComp->GetWorld(),
				Location,
				DebugMessage,
				nullptr,
				FColor::Green,
				1.0f,
				true,
				1.0f
			);
		}
	}
}

FString UAnimNotify_ComboWindow::GetNotifyName_Implementation() const
{
	return FString("ComboWindow");
}
