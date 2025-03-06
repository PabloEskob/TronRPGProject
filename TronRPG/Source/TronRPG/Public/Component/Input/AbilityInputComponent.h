// Tron

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpec.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "InputActionValue.h"
#include "Config/TronAbilitySet.h"
#include "Struct/Input/AbilityInputBinding.h"
#include "AbilityInputComponent.generated.h"

class UAbilityInputConfig;
class UInputComponent;
class UTronRpgAbilitySystemComponent;
class UInputAction;

/**
 * Делегат, вызываемый при активации способности через ввод
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAbilityInputActivated, FGameplayTag, AbilityTag, bool, bSuccess);

/**
 * Компонент для связывания EnhancedInput с Gameplay Abilities
 * Обеспечивает конфигурируемую систему активации способностей через ввод
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TRONRPG_API UAbilityInputComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAbilityInputComponent();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	/**
	 * Инициализация компонента AbilitySystem
	 */
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
	 * @param Priority Приоритет привязки, более высокий приоритет перезаписывает более низкий
	 */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void AddInputBinding(UInputAction* InputAction, FGameplayTag AbilityTag, bool bCancelOnRelease = false, int32 Priority = 0);

	/**
	 * Удалить привязку ввода по тегу способности
	 * @param AbilityTag Тег способности, привязку которой нужно удалить
	 */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void RemoveInputBindingByTag(FGameplayTag AbilityTag);

	/**
	 * Удалить привязку ввода по действию
	 * @param InputAction Действие ввода, привязку которого нужно удалить
	 */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void RemoveInputBindingByAction(UInputAction* InputAction);

	/**
	 * Загрузить привязки из конфигурационного ассета
	 * @param InputConfig Конфигурация привязок ввода
	 * @param bClearExisting Очистить ли существующие привязки перед загрузкой
	 */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void LoadInputBindingsFromConfig(UAbilityInputConfig* InputConfig, bool bClearExisting = true);

	/**
	 * Установить конфигурацию ввода и применить её привязки
	 * @param InputConfig Конфигурация привязок ввода
	 * @param bClearExisting Очистить ли существующие привязки
	 */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetInputConfig(UAbilityInputConfig* InputConfig, bool bClearExisting = true);

	/**
	 * Получить текущую конфигурацию ввода
	 * @return Текущая конфигурация ввода
	 */
	UFUNCTION(BlueprintPure, Category = "Input")
	UAbilityInputConfig* GetInputConfig() const { return InputConfig; }

	/**
	 * Очистить все привязки ввода
	 */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void ClearAllInputBindings();

	/**
	 * Симулировать нажатие для активации способности
	 * @param AbilityTag Тег способности, которую нужно активировать
	 * @return true, если активация прошла успешно
	 */
	UFUNCTION(BlueprintCallable, Category = "Input")
	bool SimulateAbilityInputPressed(FGameplayTag AbilityTag);

	/**
	 * Вручную активировать способность по тегу
	 * @param AbilityTag Тег способности, которую нужно активировать
	 * @return true, если активация прошла успешно
	 */
	UFUNCTION(BlueprintCallable, Category = "Input")
	bool ActivateAbilityByTag(FGameplayTag AbilityTag);

	/**
	 * Отменить способность по тегу
	 * @param AbilityTag Тег способности, которую нужно отменить
	 * @return true, если отмена прошла успешно
	 */
	UFUNCTION(BlueprintCallable, Category = "Input")
	bool CancelAbilityByTag(FGameplayTag AbilityTag);

	/**
	 * Событие, вызываемое при активации способности через ввод
	 */
	UPROPERTY(BlueprintAssignable, Category = "Input|Events")
	FOnAbilityInputActivated OnAbilityInputActivated;

protected:
	/** Компонент системы способностей */
	UPROPERTY(Transient)
	UTronRpgAbilitySystemComponent* AbilitySystemComponent = nullptr;

	/** Конфигурация привязок ввода */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UAbilityInputConfig> InputConfig;

	/** Компонент ввода, с которым установлены привязки */
	UPROPERTY(Transient)
	TObjectPtr<UInputComponent> BoundInputComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UTronAbilitySet> AbilitySet;
	
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

	/**
	 * Поиск спецификации способности по тегу
	 * @param AbilityTag Тег способности
	 * @return Указатель на спецификацию или nullptr
	 */
	FGameplayAbilitySpec* FindAbilitySpecByTag(FGameplayTag AbilityTag);

	/**
	 * Внутренний метод активации способности по спецификации
	 * @param AbilitySpec Спецификация способности
	 * @param AbilityTag Тег способности (для логирования и делегатов)
	 * @return true, если активация прошла успешно
	 */
	bool ActivateAbilitySpec(FGameplayAbilitySpec* AbilitySpec, FGameplayTag AbilityTag);

	/**
	 * Обработка привязки после перенастройки компонента ввода
	 */
	void RebindAbilitiesToInput();
};
