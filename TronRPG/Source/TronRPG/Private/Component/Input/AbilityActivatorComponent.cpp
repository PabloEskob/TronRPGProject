#include "Component/Input/AbilityActivatorComponent.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "Component/Input/InputActionDispatcherComponent.h"
#include "GameplayTagContainer.h"

UAbilityActivatorComponent::UAbilityActivatorComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    
    AbilitySystemComponent = nullptr;
    InputDispatcher = nullptr;
}

void UAbilityActivatorComponent::BeginPlay()
{
    Super::BeginPlay();
    
    // Автоматически находим и инициализируем компоненты, если они не были установлены извне
    if (!AbilitySystemComponent || !InputDispatcher)
    {
        UTronRpgAbilitySystemComponent* ASC = Cast<UTronRpgAbilitySystemComponent>(
            GetOwner()->GetComponentByClass(UTronRpgAbilitySystemComponent::StaticClass()));
            
        UInputActionDispatcherComponent* Dispatcher = GetOwner()->FindComponentByClass<UInputActionDispatcherComponent>();
        
        if (ASC && Dispatcher)
        {
            Initialize(ASC, Dispatcher);
        }
    }
}

void UAbilityActivatorComponent::Initialize(UTronRpgAbilitySystemComponent* InASC, UInputActionDispatcherComponent* InInputDispatcher)
{
    if (!InASC || !InInputDispatcher)
    {
        UE_LOG(LogTemp, Error, TEXT("AbilityActivatorComponent: Initialize failed - invalid components"));
        return;
    }
    
    AbilitySystemComponent = InASC;
    InputDispatcher = InInputDispatcher;
    
    // Регистрируем обработчик событий ввода
    InputDispatcher->OnInputActionTriggered.AddDynamic(this, &UAbilityActivatorComponent::HandleInputAction);
    
    // Автоматически регистрируем привязки на основе карты в диспетчере
    for (const TPair<FName, FGameplayTag>& Pair : InputDispatcher->ActionNameToAbilityTagMap)
    {
        RegisterAbilityInputBinding(Pair.Key, Pair.Value);
    }
    
    UE_LOG(LogTemp, Log, TEXT("AbilityActivatorComponent: Initialized with ASC and InputDispatcher"));
}

void UAbilityActivatorComponent::HandleInputAction(const FInputActionValue& InputValue, const FName& ActionName)
{
    if (!AbilitySystemComponent || ActionName.IsNone())
    {
        return;
    }
    
    // Проверяем, есть ли привязка для этого действия
    FAbilityInputBinding* Binding = ActionToAbilityBindings.Find(ActionName);
    if (!Binding || !Binding->AbilityTag.IsValid())
    {
        return;
    }
    
    // Определяем, является ли это нажатием или отпусканием
    bool bIsPressed = !InputValue.Get<bool>(); // Предполагаем, что отсутствие значения означает отпускание
    
    if (InputValue.GetValueType() == EInputActionValueType::Boolean)
    {
        bIsPressed = InputValue.Get<bool>();
    }
    else if (InputValue.GetValueType() == EInputActionValueType::Axis1D)
    {
        bIsPressed = FMath::Abs(InputValue.Get<float>()) > 0.1f;
    }
    else if (InputValue.GetValueType() == EInputActionValueType::Axis2D)
    {
        bIsPressed = InputValue.Get<FVector2D>().SizeSquared() > 0.01f;
    }
    else if (InputValue.GetValueType() == EInputActionValueType::Axis3D)
    {
        bIsPressed = InputValue.Get<FVector>().SizeSquared() > 0.01f;
    }
    
    // Обновляем состояние привязки
    Binding->bIsPressed = bIsPressed;
    
    // Активируем или отменяем способность в зависимости от состояния
    if (bIsPressed)
    {
        // Нажатие - активируем способность
        ActivateAbilityByTag(Binding->AbilityTag);
        
        UE_LOG(LogTemp, Log, TEXT("AbilityActivatorComponent: Activated ability with tag %s"),
               *Binding->AbilityTag.ToString());
    }
    else if (Binding->bCancelOnRelease)
    {
        // Отпускание с флагом отмены - отменяем способность
        if (AbilitySystemComponent->HasActiveAbilityWithTag(Binding->AbilityTag))
        {
            FGameplayTagContainer TagContainer;
            TagContainer.AddTag(Binding->AbilityTag);
            
            AbilitySystemComponent->CancelAbilitiesWithTags(TagContainer);
            
            UE_LOG(LogTemp, Log, TEXT("AbilityActivatorComponent: Canceled ability with tag %s"),
                   *Binding->AbilityTag.ToString());
        }
    }
}

void UAbilityActivatorComponent::RegisterAbilityInputBinding(FName ActionName, FGameplayTag AbilityTag, bool bCancelOnRelease)
{
    if (ActionName.IsNone() || !AbilityTag.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("AbilityActivatorComponent: Invalid binding parameters"));
        return;
    }
    
    // Создаем новую привязку
    FAbilityInputBinding NewBinding;
    NewBinding.ActionName = ActionName;
    NewBinding.AbilityTag = AbilityTag;
    NewBinding.bCancelOnRelease = bCancelOnRelease;
    NewBinding.bIsPressed = false;
   
    // Добавляем или обновляем привязку
    ActionToAbilityBindings.Add(ActionName, NewBinding);
   
    UE_LOG(LogTemp, Log, TEXT("AbilityActivatorComponent: Registered binding for action %s to ability tag %s"),
           *ActionName.ToString(), *AbilityTag.ToString());
}

bool UAbilityActivatorComponent::ActivateAbilityByTag(const FGameplayTag& AbilityTag)
{
    if (!AbilitySystemComponent || !AbilityTag.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("AbilityActivatorComponent: Cannot activate ability - invalid parameters"));
        return false;
    }
   
    return AbilitySystemComponent->TryActivateAbilityByTag(AbilityTag);
}