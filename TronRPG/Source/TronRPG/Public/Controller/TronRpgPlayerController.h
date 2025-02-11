// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TronRpgPlayerController.generated.h"

struct FInputActionValue;
class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class TRONRPG_API ATronRpgPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> RpgContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	void Move(const FInputActionValue& InputActionValue);
	void Look(const FInputActionValue& InputActionValue);

	UPROPERTY(EditAnywhere)
	float YawSpeed = 1.f;

	UPROPERTY(EditAnywhere)
	float PitchSpeed = 1.f;
};
