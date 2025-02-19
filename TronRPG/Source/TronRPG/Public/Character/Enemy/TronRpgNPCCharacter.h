// Tron

#pragma once

#include "CoreMinimal.h"
#include "Character/TronRpgBaseCharacter.h"
#include "TronRpgNPCCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TRONRPG_API ATronRpgNPCCharacter : public ATronRpgBaseCharacter
{
	GENERATED_BODY()
	
public:
	ATronRpgNPCCharacter();

	virtual void BeginPlay() override;
};
