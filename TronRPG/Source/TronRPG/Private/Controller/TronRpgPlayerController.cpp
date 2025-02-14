// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/TronRpgPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "Input/TronRpgEnhancedInputComponent.h"

void ATronRpgPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(RpgContext, 0);
	}
}

void ATronRpgPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UTronRpgEnhancedInputComponent* EnhancedInputComponent = Cast<UTronRpgEnhancedInputComponent>(InputComponent);
	if (EnhancedInputComponent)
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATronRpgPlayerController::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ATronRpgPlayerController::Look);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("EnhancedInputComponent is NOT valid!"));
	}
}

void ATronRpgPlayerController::Move(const FInputActionValue& InputActionValue)
{
	if (!IsLocalController())
	{
		return;
	}

	FVector2D MovementVector = InputActionValue.Get<FVector2D>();
	
	if (MovementVector.SizeSquared() > 1.0f)
	{
		MovementVector.Normalize();
	}

	if (APawn* ControlledPawn = GetPawn())
	{
		if (MovementVector.SizeSquared() > 0.0f)
		{
			const FRotator Rotation = GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

			ControlledPawn->AddMovementInput(ForwardDirection, MovementVector.Y);
			ControlledPawn->AddMovementInput(RightDirection, MovementVector.X);
		}
	}
}

void ATronRpgPlayerController::Look(const FInputActionValue& InputActionValue)
{
	if (const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>(); !LookAxisVector.IsNearlyZero())
	{
		AddYawInput(LookAxisVector.X * YawSpeed);
		AddPitchInput(LookAxisVector.Y * PitchSpeed);
	}
}
