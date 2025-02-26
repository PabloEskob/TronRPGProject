// Tron

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "RpgTronWeaponAppearNotify.generated.h"

/**
 * 
 */
UCLASS()
class TRONRPG_API URpgTronWeaponAppearNotify : public UAnimNotify
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visibility")
	bool bShouldShowWeapon;
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};
