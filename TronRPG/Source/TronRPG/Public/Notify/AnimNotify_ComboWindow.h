// Tron

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_ComboWindow.generated.h"

/**
 * 
 */
UCLASS()
class TRONRPG_API UAnimNotify_ComboWindow : public UAnimNotify
{
	GENERATED_BODY()
    
public:
	UAnimNotify_ComboWindow();
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
    
	virtual FString GetNotifyName_Implementation() const override;
};
