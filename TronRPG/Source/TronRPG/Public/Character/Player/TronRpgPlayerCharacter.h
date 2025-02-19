// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/TronRpgBaseCharacter.h"
#include "TronRpgPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TRONRPG_API ATronRpgPlayerCharacter : public ATronRpgBaseCharacter
{
	GENERATED_BODY()

public:
	ATronRpgPlayerCharacter();

	virtual void BeginPlay() override;
};
