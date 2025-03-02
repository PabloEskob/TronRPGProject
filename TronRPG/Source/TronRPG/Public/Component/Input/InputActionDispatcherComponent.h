#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "InputActionValue.h"
#include "InputActionDispatcherComponent.generated.h"

class UInputComponent;
class UInputAction;
class UEnhancedInputComponent;

/**
 * Делегат для события триггера действия ввода
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInputActionTriggered, const FInputActionValue&, InputValue, const FName&, ActionName);

/**
 * Компонент для обработки и диспетчеризации событий ввода
 * Разделяет логику обработки ввода от логики активации способностей
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TRONRPG_API UInputActionDispatcherComponent : public UActorComponent
{
    GENERATED_BODY()
    
public:
    UInputActionDispatcherComponent();
    
    /**
     * Настройка привязок ввода
     * @param PlayerInputComponent Компонент ввода, к которому привязываем действия
     */
    UFUNCTION(BlueprintCallable, Category = "Input")
    void SetupPlayerInput(UInputComponent* PlayerInputComponent);
    
    /**
     * Добавить привязку действия ввода
     * @param InputAction Действие ввода Enhanced Input
     * @param ActionName Уникальное имя действия для идентификации
     * @param TriggerEvent Событие триггера (начало, завершение и т.д.)
     */
    UFUNCTION(BlueprintCallable, Category = "Input")
    void AddInputBinding(UInputAction* InputAction, FName ActionName, ETriggerEvent TriggerEvent = ETriggerEvent::Triggered);
    
    /**
     * Событие, вызываемое при триггере действия ввода
     */
    UPROPERTY(BlueprintAssignable, Category = "Input|Events")
    FOnInputActionTriggered OnInputActionTriggered;
    
    /**
     * Карта имен действий ввода на теги способностей
     * Используется компонентом AbilityActivator для активации способностей
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    TMap<FName, FGameplayTag> ActionNameToAbilityTagMap;
    
protected:
    /**
     * Структура для хранения привязки действия ввода
     */
    struct FInputActionBinding
    {
        UInputAction* InputAction;
        FName ActionName;
        ETriggerEvent TriggerEvent;
    };
    
    /**
     * Массив привязок действий ввода
     */
    TArray<FInputActionBinding> InputBindings;
    
    /**
     * Кэшированный компонент Enhanced Input
     */
    UPROPERTY()
    UEnhancedInputComponent* CachedEnhancedInputComponent;
    
    /**
     * Обработчик событий ввода
     * @param InputValue Значение ввода
     * @param ActionName Имя действия
     */
    void OnInputActionEvent(const FInputActionValue& InputValue, FName ActionName);
};