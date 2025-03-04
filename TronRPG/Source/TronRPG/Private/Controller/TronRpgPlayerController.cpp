#include "Controller/TronRpgPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "Input/TronRpgEnhancedInputComponent.h"
#include "Character/TronRpgBaseCharacter.h"
#include "Component/Input/AbilityInputComponent.h"
#include "Object/GameplayTagsLibrary.h"

ATronRpgPlayerController::ATronRpgPlayerController()
{
    // Инициализация по умолчанию
    EnhancedInputComp = nullptr;
}

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
    EnhancedInputComp = Cast<UTronRpgEnhancedInputComponent>(InputComponent);
    if (EnhancedInputComp)
    {
        // Привязываем базовые действия движения и камеры
        EnhancedInputComp->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATronRpgPlayerController::Move);
        EnhancedInputComp->BindAction(LookAction, ETriggerEvent::Triggered, this, &ATronRpgPlayerController::Look);
        
        // Привязываем действие комбо-атаки напрямую к EnhancedInputComponent
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

void ATronRpgPlayerController::ProcessComboInput(const FInputActionValue& InputActionValue)
{
    // Проверяем наличие расширенного компонента ввода
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
    
    // Делегируем обработку комбо-ввода расширенному компоненту
    EnhancedInputComp->ProcessComboInput(InputActionValue);
}

void ATronRpgPlayerController::SetupAbilityBindings()
{
    // Получаем базового персонажа
    ATronRpgBaseCharacter* BaseCharacter = Cast<ATronRpgBaseCharacter>(GetPawn());
    if (!BaseCharacter)
    {
        UE_LOG(LogTemp, Warning, TEXT("SetupAbilityBindings: No valid character found"));
        return;
    }

    // Получаем компонент для обработки ввода способностей
    UAbilityInputComponent* AbilityInputComp = BaseCharacter->FindComponentByClass<UAbilityInputComponent>();
    if (!AbilityInputComp)
    {
        UE_LOG(LogTemp, Error, TEXT("AbilityInputComponent not found on character!"));
        return;
    }

    // Привязка для атаки ближнего боя
    if (PrimaryAttackAction)
    {
        AbilityInputComp->AddInputBinding(PrimaryAttackAction, TAG_Ability_Combat_Melee);
        UE_LOG(LogTemp, Log, TEXT("Added primary attack binding"));
    }

    // Привязка для спринта (если есть)
    if (SprintAction)
    {
        AbilityInputComp->AddInputBinding(SprintAction, TAG_State_Sprinting, true);
        UE_LOG(LogTemp, Log, TEXT("Added sprint binding"));
    }

    // Проверяем наличие расширенного компонента ввода
    if (!EnhancedInputComp)
    {
        EnhancedInputComp = Cast<UTronRpgEnhancedInputComponent>(InputComponent);
    }
    
    // Устанавливаем связь между компонентами
    if (EnhancedInputComp)
    {
        EnhancedInputComp->SetAbilityInputComponent(AbilityInputComp);
        UE_LOG(LogTemp, Log, TEXT("Set ability input component reference"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("EnhancedInputComponent not valid in SetupAbilityBindings"));
    }

    // Настраиваем InputComponent для наших привязок
    AbilityInputComp->SetupPlayerInput(InputComponent);

    UE_LOG(LogTemp, Log, TEXT("Ability input bindings setup complete"));
}