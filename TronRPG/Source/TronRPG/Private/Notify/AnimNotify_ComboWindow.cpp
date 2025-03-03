// Tron


#include "Notify/AnimNotify_ComboWindow.h"

UAnimNotify_ComboWindow::UAnimNotify_ComboWindow()
{
}

void UAnimNotify_ComboWindow::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
}

FString UAnimNotify_ComboWindow::GetNotifyName_Implementation() const
{
	return FString("ComboWindow");
}
