// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "GameplayTagContainer.h"
#include "TronRpgEnhancedInputComponent.generated.h"

class UTronRpgAbilitySystemComponent;
class UInputAction;

/**
 * Структура для привязки InputAction к тегу способности
 */
USTRUCT(BlueprintType)
struct FAbilityInputBinding
{
    GENERATED_BODY()

    /** Действие ввода (Enhanced Input) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* InputAction = nullptr;

    /** Тег, который идентифицирует способность */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    FGameplayTag AbilityTag;

    /** Отменять ли способность при отпускании кнопки */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    bool bCancelOnRelease = false;
    
    /** Состояние кнопки (нажата/отпущена) */
    bool bIsPressed = false;
};

/**
 * Расширенный компонент ввода для прямой связи EnhancedInput с системой способностей
 * Объединяет функциональность ввода и активации способностей
 */
UCLASS()
class TRONRPG_API UTronRpgEnhancedInputComponent : public UEnhancedInputComponent
{
    GENERATED_BODY()

public:
    UTronRpgEnhancedInputComponent();

    virtual void BeginPlay() override;

    /**
     * Инициализация компонента системой способностей
     * @param InASC Компонент системы способностей
     */
    UFUNCTION(BlueprintCallable, Category = "Abilities")
    void InitializeAbilitySystem(UTronRpgAbilitySystemComponent* InASC);

    /**
     * Добавить привязку ввода для способности
     * @param InputAction Действие ввода Enhanced Input
     * @param AbilityTag Тег, идентифицирующий способность
     * @param bCancelOnRelease Отменять ли способность при отпускании кнопки
     */
    UFUNCTION(BlueprintCallable, Category = "Input")
    void AddAbilityInputBinding(UInputAction* InputAction, FGameplayTag AbilityTag, bool bCancelOnRelease = false);

    /**
     * Настройка привязок ввода
     * Вызывается после добавления всех привязок
     */
    UFUNCTION(BlueprintCallable, Category = "Input")
    void SetupInputBindings();

protected:
    /** Компонент системы способностей */
    UPROPERTY(Transient)
    UTronRpgAbilitySystemComponent* AbilitySystemComponent = nullptr;

    /** Массив привязок действий ввода к тегам способностей */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    TArray<FAbilityInputBinding> AbilityInputBindings;

    /**
     * Обработчик нажатия кнопки для активации способности
     * @param InputValue Значение ввода
     * @param BindingIndex Индекс привязки в массиве
     */
    void OnAbilityInputPressed(const FInputActionValue& InputValue, int32 BindingIndex);

    /**
     * Обработчик отпускания кнопки для отмены способности
     * @param InputValue Значение ввода
     * @param BindingIndex Индекс привязки в массиве
     */
    void OnAbilityInputReleased(const FInputActionValue& InputValue, int32 BindingIndex);

    /**
     * Активация способности по тегу
     * @param AbilityTag Тег способности для активации
     * @return true, если активация прошла успешно
     */
    bool ActivateAbilityByTag(const FGameplayTag& AbilityTag);

    /**
     * Отмена способности по тегу
     * @param AbilityTag Тег способности для отмены
     */
    void CancelAbilityByTag(const FGameplayTag& AbilityTag);
};