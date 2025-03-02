#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InputActionValue.h"
#include "GameplayTagContainer.h"
#include "AbilityActivatorComponent.generated.h"

class UTronRpgAbilitySystemComponent;
class UInputActionDispatcherComponent;

/**
 * Компонент для активации способностей на основе событий ввода
 * Отделен от ввода для лучшей модульности и переиспользуемости
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TRONRPG_API UAbilityActivatorComponent : public UActorComponent
{
    GENERATED_BODY()
    
public:
    UAbilityActivatorComponent();
    
    virtual void BeginPlay() override;
    
    /**
     * Инициализация компонента с системой способностей и диспетчером ввода
     * @param InASC Компонент системы способностей
     * @param InInputDispatcher Компонент диспетчера ввода
     */
    UFUNCTION(BlueprintCallable, Category = "Abilities")
    void Initialize(UTronRpgAbilitySystemComponent* InASC, UInputActionDispatcherComponent* InInputDispatcher);
    
    /**
     * Обработка события ввода
     * @param InputValue Значение ввода
     * @param ActionName Имя действия
     */
    UFUNCTION()
    void HandleInputAction(const FInputActionValue& InputValue, const FName& ActionName);
    
    /**
     * Регистрация привязки действия ввода к тегу способности
     * @param ActionName Имя действия ввода
     * @param AbilityTag Тег способности для активации
     * @param bCancelOnRelease Отменять ли способность при отпускании
     */
    UFUNCTION(BlueprintCallable, Category = "Abilities")
    void RegisterAbilityInputBinding(FName ActionName, FGameplayTag AbilityTag, bool bCancelOnRelease = false);
    
    /**
     * Активация способности по тегу
     * @param AbilityTag Тег способности для активации
     * @return true, если активация прошла успешно
     */
    UFUNCTION(BlueprintCallable, Category = "Abilities")
    bool ActivateAbilityByTag(const FGameplayTag& AbilityTag);
    
protected:
    /**
     * Компонент системы способностей
     */
    UPROPERTY()
    UTronRpgAbilitySystemComponent* AbilitySystemComponent;
    
    /**
     * Компонент диспетчера ввода
     */
    UPROPERTY()
    UInputActionDispatcherComponent* InputDispatcher;
    
    /**
     * Структура для хранения привязки ввода к способности
     */
    struct FAbilityInputBinding
    {
        FName ActionName;
        FGameplayTag AbilityTag;
        bool bCancelOnRelease;
        bool bIsPressed;
    };
    
    /**
     * Карта имен действий на привязки способностей
     */
    TMap<FName, FAbilityInputBinding> ActionToAbilityBindings;
};