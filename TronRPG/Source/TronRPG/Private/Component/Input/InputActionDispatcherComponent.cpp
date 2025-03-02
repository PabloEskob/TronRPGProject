#include "Component/Input/InputActionDispatcherComponent.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"

UInputActionDispatcherComponent::UInputActionDispatcherComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    SetIsReplicatedByDefault(false); // Обработка ввода только на клиенте
    
    CachedEnhancedInputComponent = nullptr;
}

void UInputActionDispatcherComponent::SetupPlayerInput(UInputComponent* PlayerInputComponent)
{
    if (!PlayerInputComponent)
    {
        UE_LOG(LogTemp, Error, TEXT("InputActionDispatcherComponent: Invalid PlayerInputComponent"));
        return;
    }
    
    // Приводим к EnhancedInputComponent
    CachedEnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    if (!CachedEnhancedInputComponent)
    {
        UE_LOG(LogTemp, Error, TEXT("InputActionDispatcherComponent: PlayerInputComponent is not UEnhancedInputComponent"));
        return;
    }
    
    // Связываем все предварительно добавленные действия
    for (const FInputActionBinding& Binding : InputBindings)
    {
        if (Binding.InputAction)
        {
            // Создаем захват переменных для лямбды
            UInputAction* InputAction = Binding.InputAction;
            FName ActionName = Binding.ActionName;
            
            // Привязываем действие ввода к обработчику
            CachedEnhancedInputComponent->BindAction(InputAction, Binding.TriggerEvent,
                this, &UInputActionDispatcherComponent::OnInputActionEvent, ActionName);
            
            UE_LOG(LogTemp, Log, TEXT("InputActionDispatcherComponent: Bound input action %s with name %s"),
                   *InputAction->GetName(), *ActionName.ToString());
        }
    }
}

void UInputActionDispatcherComponent::AddInputBinding(UInputAction* InputAction, FName ActionName, ETriggerEvent TriggerEvent)
{
    // Проверка валидности входных параметров
    if (!InputAction || ActionName.IsNone())
    {
        UE_LOG(LogTemp, Warning, TEXT("InputActionDispatcherComponent: Invalid input binding parameters"));
        return;
    }
    
    // Проверяем, не существует ли уже такая привязка
    for (const FInputActionBinding& Binding : InputBindings)
    {
        if (Binding.InputAction == InputAction && Binding.ActionName == ActionName && Binding.TriggerEvent == TriggerEvent)
        {
            UE_LOG(LogTemp, Warning, TEXT("InputActionDispatcherComponent: Binding already exists for action %s with name %s"),
                   *InputAction->GetName(), *ActionName.ToString());
            return;
        }
    }
    
    // Создаем новую привязку
    FInputActionBinding NewBinding;
    NewBinding.InputAction = InputAction;
    NewBinding.ActionName = ActionName;
    NewBinding.TriggerEvent = TriggerEvent;
    
    // Добавляем в массив привязок
    InputBindings.Add(NewBinding);
    
    // Если компонент ввода уже инициализирован, сразу привязываем
    if (CachedEnhancedInputComponent)
    {
        CachedEnhancedInputComponent->BindAction(InputAction, TriggerEvent,
            this, &UInputActionDispatcherComponent::OnInputActionEvent, ActionName);
        
        UE_LOG(LogTemp, Log, TEXT("InputActionDispatcherComponent: Bound input action %s with name %s (late binding)"),
               *InputAction->GetName(), *ActionName.ToString());
    }
}

void UInputActionDispatcherComponent::OnInputActionEvent(const FInputActionValue& InputValue, FName ActionName)
{
    // Вызываем делегат для обработки действия ввода
    OnInputActionTriggered.Broadcast(InputValue, ActionName);
    
    UE_LOG(LogTemp, Verbose, TEXT("InputActionDispatcherComponent: Input action triggered %s"),
           *ActionName.ToString());
}