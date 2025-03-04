// Tron

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "InputActionValue.h"
#include "AbilityInputComponent.generated.h"

class UInputComponent;
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
};

/**
 * Компонент для связывания EnhancedInput с Gameplay Abilities
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TRONRPG_API UAbilityInputComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UAbilityInputComponent();

    virtual void BeginPlay() override;
    void InitializeAbilitySystem();

    /**
     * Настройка привязок ввода для способностей
     * @param PlayerInputComponent Компонент ввода, к которому привязываем действия
     */
    UFUNCTION(BlueprintCallable, Category = "Input")
    void SetupPlayerInput(UInputComponent* PlayerInputComponent);

    /**
     * Добавить новую привязку ввода для способности
     * @param InputAction Действие ввода Enhanced Input
     * @param AbilityTag Тег, идентифицирующий способность
     * @param bCancelOnRelease Отменять ли способность при отпускании кнопки
     */
    UFUNCTION(BlueprintCallable, Category = "Input")
    void AddInputBinding(UInputAction* InputAction, FGameplayTag AbilityTag, bool bCancelOnRelease = false);

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
     * @param Binding Привязка к способности
     */
    void OnAbilityInputPressed(const FInputActionValue& InputValue, FAbilityInputBinding Binding);

    /**
     * Обработчик отпускания кнопки для отмены способности
     * @param InputValue Значение ввода
     * @param Binding Привязка к способности
     */
    void OnAbilityInputReleased(const FInputActionValue& InputValue, FAbilityInputBinding Binding);
};