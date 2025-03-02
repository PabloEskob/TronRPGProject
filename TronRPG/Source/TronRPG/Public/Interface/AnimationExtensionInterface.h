// Tron

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AnimationExtensionInterface.generated.h"

UINTERFACE(BlueprintType)
class UAnimationExtensionInterface : public UInterface
{
	GENERATED_BODY()
};

class IAnimationExtensionInterface
{
	GENERATED_BODY()
    
public:
	virtual void OnBeforeMontagePlay(UAnimMontage* Montage, float PlayRate) = 0;
	virtual void OnAfterMontagePlay(UAnimMontage* Montage, float Duration) = 0;
};
