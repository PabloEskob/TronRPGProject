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
    
	// Переопределение метода Notify из UAnimNotify
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
    
	// Возвращает имя уведомления
	virtual FString GetNotifyName_Implementation() const override;
    
	// Показывать ли отладочную информацию
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
	bool bShowDebugInfo = true;
};
