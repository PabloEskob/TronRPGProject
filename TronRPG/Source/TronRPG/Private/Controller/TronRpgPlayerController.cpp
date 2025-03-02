#include "Controller/TronRpgPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "Input/TronRpgEnhancedInputComponent.h"
#include "Character/TronRpgBaseCharacter.h"
#include "Component/Input/AbilityInputComponent.h"
#include "Object/GameplayTagsLibrary.h"

void ATronRpgPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Добавляем контекст ввода в подсистему
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(RpgContext, 0);
	}

	// Настраиваем привязки способностей при старте игры
	SetupAbilityBindings();
}

void ATronRpgPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Приводим InputComponent к нашему типу
	UTronRpgEnhancedInputComponent* EnhancedInputComponent = Cast<UTronRpgEnhancedInputComponent>(InputComponent);
	if (EnhancedInputComponent)
	{
		// Привязываем базовые действия движения и камеры
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

void ATronRpgPlayerController::SetupAbilityBindings()
{
	// Получаем базового персонажа
	ATronRpgBaseCharacter* BaseCharacter = Cast<ATronRpgBaseCharacter>(GetPawn());
	if (!BaseCharacter)
	{
		return;
	}

	// Получаем компонент для обработки ввода способностей
	UAbilityInputComponent* AbilityInputComp = BaseCharacter->FindComponentByClass<UAbilityInputComponent>();
	if (!AbilityInputComp)
	{
		UE_LOG(LogTemp, Error, TEXT("AbilityInputComponent not found on character!"));
		return;
	}

	// Добавляем привязки для наших способностей

	// Привязка для атаки ближнего боя
	if (PrimaryAttackAction)
	{
		AbilityInputComp->AddInputBinding(PrimaryAttackAction, TAG_Ability_Combat_Melee);
	}

	// Привязка для спринта (если есть)
	if (SprintAction)
	{
		AbilityInputComp->AddInputBinding(SprintAction, TAG_State_Sprinting, true);
	}

	// Настраиваем InputComponent для наших привязок
	AbilityInputComp->SetupPlayerInput(InputComponent);

	UE_LOG(LogTemp, Log, TEXT("Ability input bindings setup complete"));
}
