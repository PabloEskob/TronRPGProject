#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "GameplayTagContainer.h"
#include "InputActionValue.h"
#include "TronRpgEnhancedInputComponent.generated.h"

class ATronRpgBaseCharacter;
class UTronRpgComboComponent;
class UGameplayAbility;
class UTronRpgAbilitySystemComponent;

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
 * Делегат для событий ввода
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInputActionTriggered, const UInputAction*, InputAction, const FInputActionValue&, Value);

/**
 * Улучшенный компонент ввода для TronRPG
 * Объединяет функциональность обработки ввода для системы способностей и комбо-атак
 */
UCLASS()
class TRONRPG_API UTronRpgEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	UTronRpgEnhancedInputComponent();

	virtual void BeginPlay() override;

	/**
	 * Настройка привязок ввода для способностей
	 * @param PlayerInputComponent Компонент ввода, к которому привязываем действия
	 */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetupPlayerInput(UInputComponent* PlayerInputComponent);

	/**
	 * Настройка привязок способностей
	 */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetupAbilityBindings();

	/**
	 * Добавить новую привязку для способности
	 * @param InputAction Действие ввода Enhanced Input
	 * @param AbilityTag Тег, идентифицирующий способность
	 * @param bCancelOnRelease Отменять ли способность при отпускании кнопки
	 */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void AddAbilityBinding(UInputAction* InputAction, FGameplayTag AbilityTag, bool bCancelOnRelease = false);

	/**
	 * Попытка активировать способность по тегу
	 * @param AbilityTag Тег способности
	 * @return true если активация успешна
	 */
	UFUNCTION(BlueprintCallable, Category = "Input")
	bool TryActivateAbilityByTag(const FGameplayTag& AbilityTag);

	/**
	 * Обработка ввода для комбо
	 * @param InputValue Значение ввода
	 */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void ProcessComboInput(const FInputActionValue& InputValue);

	/**
	 * Установить AbilitySystemComponent
	 * @param InAbilitySystemComponent Компонент системы способностей
	 */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetAbilitySystemComponent(UTronRpgAbilitySystemComponent* InAbilitySystemComponent);

	/**
	 * Получить персонажа-владельца
	 * @return Указатель на персонажа
	 */
	UFUNCTION(BlueprintPure, Category = "Input")
	ATronRpgBaseCharacter* GetOwningCharacter() const;

	/** Делегаты для обработки событий ввода */
	UPROPERTY(BlueprintAssignable, Category = "Input|Events")
	FOnInputActionTriggered OnActionTriggered;

	UPROPERTY(BlueprintAssignable, Category = "Input|Events")
	FOnInputActionTriggered OnActionCompleted;

	UPROPERTY(Transient)
	bool bProcessingComboInput = false;

protected:
	/** Компонент системы способностей */
	UPROPERTY(Transient)
	UTronRpgAbilitySystemComponent* AbilitySystemComponent;

	/** Кэш персонажа-владельца */
	UPROPERTY(Transient)
	ATronRpgBaseCharacter* OwningCharacter;

	/** Массив привязок ввода способностей */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TArray<FAbilityInputBinding> AbilityBindings;

	/**
	 * Обработчик нажатия кнопки для активации способности
	 * @param InputValue Значение ввода
	 * @param Binding Привязка способности
	 */
	void OnAbilityInputPressed(const FInputActionValue& InputValue, FAbilityInputBinding Binding);

	/**
	 * Обработчик отпускания кнопки для отмены способности
	 * @param InputValue Значение ввода
	 * @param Binding Привязка способности
	 */
	void OnAbilityInputReleased(const FInputActionValue& InputValue, FAbilityInputBinding Binding);

	/**
	 * Обновление кэшированных ссылок
	 */
	void UpdateCachedReferences();

	/**
	 * Инициализация системы способностей
	 */
	void InitializeAbilitySystem();
};
