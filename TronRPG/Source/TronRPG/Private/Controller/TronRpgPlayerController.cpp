#include "Controller/TronRpgPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "Character/TronRpgBaseCharacter.h"
#include "Object/GameplayTagsLibrary.h"

ATronRpgPlayerController::ATronRpgPlayerController()
{
	// Default initialization
	EnhancedInputComp = nullptr;
}

void ATronRpgPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Add input mapping context to the input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (RpgContext)
		{
			Subsystem->AddMappingContext(RpgContext, 0);
			UE_LOG(LogTemp, Log, TEXT("Added RPG input mapping context"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("RpgContext is not set in TronRpgPlayerController"));
		}
	}

	// Set up ability bindings at game start
	SetupAbilityBindings();
}

void ATronRpgPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Cast InputComponent to our enhanced type
	EnhancedInputComp = Cast<UTronRpgEnhancedInputComponent>(InputComponent);
	if (EnhancedInputComp)
	{
		// Bind basic movement and camera actions
		if (MoveAction)
		{
			EnhancedInputComp->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATronRpgPlayerController::Move);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("MoveAction is not set in TronRpgPlayerController"));
		}

		if (LookAction)
		{
			EnhancedInputComp->BindAction(LookAction, ETriggerEvent::Triggered, this, &ATronRpgPlayerController::Look);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("LookAction is not set in TronRpgPlayerController"));
		}

		// Bind combo attack action directly to the enhanced input component
		if (ComboAttackAction)
		{
			EnhancedInputComp->BindAction(ComboAttackAction, ETriggerEvent::Started, this, &ATronRpgPlayerController::ProcessComboInput);
			UE_LOG(LogTemp, Log, TEXT("Bound combo attack action"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("ComboAttackAction is not set in TronRpgPlayerController"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error,
		       TEXT(
			       "Failed to cast InputComponent to UTronEnhancedRpgInputComponent. Make sure it's set as the default input component class in project settings."
		       ));
	}
}

void ATronRpgPlayerController::Move(const FInputActionValue& InputActionValue)
{
	// Only process for local controllers
	if (!IsLocalController())
	{
		return;
	}

	// Get movement vector
	FVector2D MovementVector = InputActionValue.Get<FVector2D>();

	// Normalize if needed
	if (MovementVector.SizeSquared() > 1.0f)
	{
		MovementVector.Normalize();
	}

	// Apply movement if we have a valid pawn
	if (APawn* ControlledPawn = GetPawn())
	{
		if (MovementVector.SizeSquared() > 0.0f)
		{
			// Get rotation based on camera direction
			const FRotator Rotation = GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			// Get forward and right directions
			const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

			// Apply movement input
			ControlledPawn->AddMovementInput(ForwardDirection, MovementVector.Y);
			ControlledPawn->AddMovementInput(RightDirection, MovementVector.X);
		}
	}
}

void ATronRpgPlayerController::Look(const FInputActionValue& InputActionValue)
{
	// Get look axis vector
	FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	// Apply camera rotation if not near zero
	if (!LookAxisVector.IsNearlyZero())
	{
		AddYawInput(LookAxisVector.X * YawSpeed);
		AddPitchInput(LookAxisVector.Y * PitchSpeed);
	}
}

void ATronRpgPlayerController::ProcessComboInput(const FInputActionValue& InputActionValue)
{
	// Ensure we have a valid enhanced input component
	if (!EnhancedInputComp)
	{
		EnhancedInputComp = Cast<UTronRpgEnhancedInputComponent>(InputComponent);
		if (!EnhancedInputComp)
		{
			UE_LOG(LogTemp, Error, TEXT("ProcessComboInput: EnhancedInputComponent is not valid!"));
			return;
		}
	}

	UE_LOG(LogTemp, Log, TEXT("TronRpgPlayerController: Processing combo input"));

	// Delegate combo input processing to the enhanced input component
	EnhancedInputComp->ProcessComboInput(InputActionValue);
}

void ATronRpgPlayerController::SetupAbilityBindings()
{
	// Get the player character
	ATronRpgBaseCharacter* BaseCharacter = Cast<ATronRpgBaseCharacter>(GetPawn());
	if (!BaseCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("SetupAbilityBindings: No valid character found"));
		return;
	}

	// Make sure we have a valid input component
	if (!EnhancedInputComp)
	{
		EnhancedInputComp = Cast<UTronRpgEnhancedInputComponent>(InputComponent);
		if (!EnhancedInputComp)
		{
			UE_LOG(LogTemp, Warning, TEXT("SetupAbilityBindings: EnhancedInputComp not valid"));
			return;
		}
	}

	// Add ability bindings
	if (PrimaryAttackAction)
	{
		EnhancedInputComp->AddAbilityBinding(PrimaryAttackAction, TAG_Ability_Combat_Melee);
		UE_LOG(LogTemp, Log, TEXT("Added primary attack binding"));
	}

	if (SprintAction)
	{
		EnhancedInputComp->AddAbilityBinding(SprintAction, TAG_State_Sprinting, true);
		UE_LOG(LogTemp, Log, TEXT("Added sprint binding"));
	}

	// Set up input bindings
	EnhancedInputComp->SetupAbilityBindings();

	UE_LOG(LogTemp, Log, TEXT("Ability input bindings setup complete"));
}
