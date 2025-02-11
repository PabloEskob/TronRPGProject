// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TronRpgComboComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TRONRPG_API UTronRpgComboComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UTronRpgComboComponent();

	// Счётчик комбо
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combo")
	int32 ComboCount = 0;

	UFUNCTION(BlueprintCallable, Category = "Combo")
	void IncrementCombo();

	UFUNCTION(BlueprintCallable, Category = "Combo")
	void ResetCombo();
};
