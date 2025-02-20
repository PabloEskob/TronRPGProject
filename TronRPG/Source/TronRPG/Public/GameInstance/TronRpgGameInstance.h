// Tron

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TronRpgGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TRONRPG_API UTronRpgGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
};
