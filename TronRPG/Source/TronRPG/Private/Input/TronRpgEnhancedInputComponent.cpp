// Fill out your copyright notice in the Description page of Project Settings.

#include "Input/TronRpgEnhancedInputComponent.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "GameplayAbilitySpec.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"

UTronRpgEnhancedInputComponent::UTronRpgEnhancedInputComponent()
{
    // Компонент не требует тиков для работы
    PrimaryComponentTick.bCanEverTick = false;
    
    // Устанавливаем репликацию для сетевой игры
    SetIsReplicatedByDefault(true);
}

void UTronRpgEnhancedInputComponent::BeginPlay()
{
    Super::BeginPlay();
    
    // Автоматически находим ASC, если он не был предоставлен
    if (!AbilitySystemComponent)
    {
        InitializeAbilitySystem(Cast<UTronRpgAbilitySystemComponent>(
            GetOwner()->GetComponentByClass(UTronRpgAbilitySystemComponent::StaticClass())));
    }
}

void UTronRpgEnhancedInputComponent::InitializeAbilitySystem(UTronRpgAbilitySystemComponent* InASC)
{
    if (!InASC)
    {
        UE_LOG(LogTemp, Error, TEXT("TronRpgEnhancedInputComponent: Invalid ASC provided"));
        return;
    }
    
    // Сохраняем ссылку на компонент способностей
    AbilitySystemComponent = InASC;
    
    UE_LOG(LogTemp, Log, TEXT("TronRpgEnhancedInputComponent: Successfully initialized with ASC"));
    
    // Настраиваем все существующие привязки
    SetupInputBindings();
}

void UTronRpgEnhancedInputComponent::AddAbilityInputBinding(UInputAction* InputAction, 
                                                           FGameplayTag AbilityTag, 
                                                           bool bCancelOnRelease)
{
    // Проверка валидности параметров
    if (!InputAction || !AbilityTag.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("TronRpgEnhancedInputComponent: Invalid input binding parameters"));
        return;
    }
    
    // Проверяем, не существует ли уже такая привязка
    for (int32 i = 0; i < AbilityInputBindings.Num(); ++i)
    {
        const FAbilityInputBinding& Binding = AbilityInputBindings[i];
        if (Binding.InputAction == InputAction && Binding.AbilityTag == AbilityTag)
        {
            UE_LOG(LogTemp, Warning, TEXT("TronRpgEnhancedInputComponent: Binding already exists for action %s with tag %s"),
                   *InputAction->GetName(), *AbilityTag.ToString());
            return;
        }
    }
    
    // Создаем новую привязку
    FAbilityInputBinding NewBinding;
    NewBinding.InputAction = InputAction;
    NewBinding.AbilityTag = AbilityTag;
    NewBinding.bCancelOnRelease = bCancelOnRelease;
    NewBinding.bIsPressed = false;
    
    // Добавляем привязку в массив
    int32 NewBindingIndex = AbilityInputBindings.Add(NewBinding);
    
    // Если компонент уже инициализирован, добавляем привязки
    if (IsRegistered())
    {
        // Привязываем действия для нового индекса
        BindAction(InputAction, ETriggerEvent::Started, 
            this, &UTronRpgEnhancedInputComponent::OnAbilityInputPressed, NewBindingIndex);
        
        BindAction(InputAction, ETriggerEvent::Completed, 
            this, &UTronRpgEnhancedInputComponent::OnAbilityInputReleased, NewBindingIndex);
        
        UE_LOG(LogTemp, Log, TEXT("TronRpgEnhancedInputComponent: Added binding for action %s with tag %s"),
               *InputAction->GetName(), *AbilityTag.ToString());
    }
}

void UTronRpgEnhancedInputComponent::SetupInputBindings()
{
    // Настраиваем все существующие привязки
    for (int32 i = 0; i < AbilityInputBindings.Num(); ++i)
    {
        FAbilityInputBinding& Binding = AbilityInputBindings[i];
        if (Binding.InputAction)
        {
            // Привязываем действия к обработчикам с индексом привязки
            BindAction(Binding.InputAction, ETriggerEvent::Started, 
                this, &UTronRpgEnhancedInputComponent::OnAbilityInputPressed, i);
            
            BindAction(Binding.InputAction, ETriggerEvent::Completed, 
                this, &UTronRpgEnhancedInputComponent::OnAbilityInputReleased, i);
            
            UE_LOG(LogTemp, Log, TEXT("TronRpgEnhancedInputComponent: Setup binding for action %s with tag %s"),
                   *Binding.InputAction->GetName(), *Binding.AbilityTag.ToString());
        }
    }
}

void UTronRpgEnhancedInputComponent::OnAbilityInputPressed(const FInputActionValue& InputValue, int32 BindingIndex)
{
    // Проверка валидности индекса
    if (!AbilitySystemComponent || BindingIndex < 0 || BindingIndex >= AbilityInputBindings.Num())
    {
        return;
    }
    
    // Получаем привязку по индексу
    FAbilityInputBinding& Binding = AbilityInputBindings[BindingIndex];
    if (!Binding.AbilityTag.IsValid())
    {
        return;
    }
    
    // Обновляем состояние кнопки
    Binding.bIsPressed = true;
    
    // Активируем способность
    if (ActivateAbilityByTag(Binding.AbilityTag))
    {
        UE_LOG(LogTemp, Log, TEXT("TronRpgEnhancedInputComponent: Activated ability with tag %s"),
               *Binding.AbilityTag.ToString());
    }
    else
    {
        UE_LOG(LogTemp, Verbose, TEXT("TronRpgEnhancedInputComponent: Failed to activate ability with tag %s"),
               *Binding.AbilityTag.ToString());
    }
}

void UTronRpgEnhancedInputComponent::OnAbilityInputReleased(const FInputActionValue& InputValue, int32 BindingIndex)
{
    // Проверка валидности индекса
    if (!AbilitySystemComponent || BindingIndex < 0 || BindingIndex >= AbilityInputBindings.Num())
    {
        return;
    }
    
    // Получаем привязку по индексу
    FAbilityInputBinding& Binding = AbilityInputBindings[BindingIndex];
    if (!Binding.AbilityTag.IsValid())
    {
        return;
    }
    
    // Обновляем состояние кнопки
    Binding.bIsPressed = false;
    
    // Если нужно отменить способность при отпускании
    if (Binding.bCancelOnRelease)
    {
        CancelAbilityByTag(Binding.AbilityTag);
        
        UE_LOG(LogTemp, Log, TEXT("TronRpgEnhancedInputComponent: Canceled ability with tag %s"),
               *Binding.AbilityTag.ToString());
    }
}

bool UTronRpgEnhancedInputComponent::ActivateAbilityByTag(const FGameplayTag& AbilityTag)
{
    if (!AbilitySystemComponent || !AbilityTag.IsValid())
    {
        return false;
    }
    
    // Создаем контейнер с тегом
    FGameplayTagContainer TagContainer;
    TagContainer.AddTag(AbilityTag);
    
    // Пытаемся активировать способность
    return AbilitySystemComponent->TryActivateAbilitiesByTag(TagContainer);
}

void UTronRpgEnhancedInputComponent::CancelAbilityByTag(const FGameplayTag& AbilityTag)
{
    if (!AbilitySystemComponent || !AbilityTag.IsValid())
    {
        return;
    }
    
    // Создаем контейнер с тегом для отмены
    FGameplayTagContainer TagContainer;
    TagContainer.AddTag(AbilityTag);
    
    // Отменяем способности с этим тегом
    AbilitySystemComponent->CancelAbilities(&TagContainer);
}