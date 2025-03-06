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
 * Делегаты для событий активации способностей
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAbilityInputActivated, FGameplayTag, AbilityTag, bool, bSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityActivationFailed, FGameplayTag, AbilityTag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAbilityActivationEnded, FGameplayTag, AbilityTag, bool, bWasCancelled);

/**
 * Компонент для связывания EnhancedInput с Gameplay Abilities
 * Обеспечивает конфигурируемую систему активации способностей через ввод
 * Следует принципам SOLID и лучшим практикам GAS
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
    UFUNCTION(BlueprintCallable, Category = "Ability|Input")
    void SetupPlayerInput(UInputComponent* PlayerInputComponent);

    /**
     * Инициализация способностей из набора способностей
     * @param InAbilitySet Набор способностей для инициализации
     */
    UFUNCTION(BlueprintCallable, Category = "Ability|Input")
    void InitializeFromAbilitySet(UTronAbilitySet* InAbilitySet);

    /**
     * Добавить новую привязку ввода для способности
     * @param InputAction Действие ввода Enhanced Input
     * @param AbilityTag Тег, идентифицирующий способность
     * @param bCancelOnRelease Отменять ли способность при отпускании кнопки
     * @param Priority Приоритет привязки, более высокий приоритет перезаписывает более низкий
     */
    UFUNCTION(BlueprintCallable, Category = "Ability|Input")
    void AddInputBinding(UInputAction* InputAction, FGameplayTag AbilityTag, bool bCancelOnRelease = false, int32 Priority = 0);

    /**
     * Удалить привязку ввода по тегу способности
     * @param AbilityTag Тег способности, привязку которой нужно удалить
     */
    UFUNCTION(BlueprintCallable, Category = "Ability|Input")
    void RemoveInputBindingByTag(FGameplayTag AbilityTag);

    /**
     * Удалить привязку ввода по действию
     * @param InputAction Действие ввода, привязку которого нужно удалить
     */
    UFUNCTION(BlueprintCallable, Category = "Ability|Input")
    void RemoveInputBindingByAction(UInputAction* InputAction);

    /**
     * Загрузить привязки из конфигурационного ассета
     * @param InputConfig Конфигурация привязок ввода
     * @param bClearExisting Очистить ли существующие привязки перед загрузкой
     */
    UFUNCTION(BlueprintCallable, Category = "Ability|Input")
    void LoadInputBindingsFromConfig(UAbilityInputConfig* InputConfig, bool bClearExisting = true);

    /**
     * Установить конфигурацию ввода и применить её привязки
     * @param InputConfig Конфигурация привязок ввода
     * @param bClearExisting Очистить ли существующие привязки
     */
    UFUNCTION(BlueprintCallable, Category = "Ability|Input")
    void SetInputConfig(UAbilityInputConfig* InputConfig, bool bClearExisting = true);

    /**
     * Получить текущую конфигурацию ввода
     * @return Текущая конфигурация ввода
     */
    UFUNCTION(BlueprintPure, Category = "Ability|Input")
    UAbilityInputConfig* GetInputConfig() const { return InputConfig; }

    /**
     * Очистить все привязки ввода
     */
    UFUNCTION(BlueprintCallable, Category = "Ability|Input")
    void ClearAllInputBindings();

    /**
     * Симулировать нажатие для активации способности
     * @param AbilityTag Тег способности, которую нужно активировать
     * @return true, если активация прошла успешно
     */
    UFUNCTION(BlueprintCallable, Category = "Ability|Input")
    bool SimulateAbilityInputPressed(FGameplayTag AbilityTag);

    /**
     * Вручную активировать способность по тегу
     * @param AbilityTag Тег способности, которую нужно активировать
     * @return true, если активация прошла успешно
     */
    UFUNCTION(BlueprintCallable, Category = "Ability|Activation")
    bool ActivateAbilityByTag(FGameplayTag AbilityTag);

    /**
     * Активировать способность по тегу с поддержкой сетевой игры
     * @param AbilityTag Тег способности для активации
     * @param bAllowRemoteActivation Разрешить активацию на удаленных клиентах
     * @return true, если активация прошла успешно
     */
    UFUNCTION(BlueprintCallable, Category = "Ability|Activation")
    bool TryActivateAbilityByTag(FGameplayTag AbilityTag, bool bAllowRemoteActivation = true);

    /**
     * Активировать способность по тегу с дополнительным контекстом событий
     * @param AbilityTag Тег способности для активации
     * @param EventData Контекстные данные события для передачи в способность
     * @return true, если активация прошла успешно
     */
    UFUNCTION(BlueprintCallable, Category = "Ability|Activation")
    bool TryActivateAbilityByTagWithContext(FGameplayTag AbilityTag, const FGameplayEventData& EventData);

    /**
     * Отменить способность по тегу
     * @param AbilityTag Тег способности, которую нужно отменить
     * @return true, если отмена прошла успешно
     */
    UFUNCTION(BlueprintCallable, Category = "Ability|Activation")
    bool CancelAbilityByTag(FGameplayTag AbilityTag);

    /**
     * Проверить активна ли способность с указанным тегом
     * @param AbilityTag Тег способности для проверки
     * @return true, если способность активна
     */
    UFUNCTION(BlueprintPure, Category = "Ability|Activation")
    bool IsAbilityActive(FGameplayTag AbilityTag) const;

    /**
     * Получить текущий уровень способности по тегу
     * @param AbilityTag Тег способности для проверки
     * @return Уровень способности или 0, если способность не найдена
     */
    UFUNCTION(BlueprintPure, Category = "Ability|Info")
    int32 GetAbilityLevel(FGameplayTag AbilityTag) const;

    /**
     * События, вызываемые при активации/деактивации способностей
     */
    UPROPERTY(BlueprintAssignable, Category = "Ability|Events")
    FOnAbilityInputActivated OnAbilityInputActivated;

    UPROPERTY(BlueprintAssignable, Category = "Ability|Events")
    FOnAbilityActivationFailed OnAbilityActivationFailed;

    UPROPERTY(BlueprintAssignable, Category = "Ability|Events")
    FOnAbilityActivationEnded OnAbilityActivationEnded;

protected:
    /** Компонент системы способностей */
    UPROPERTY(Transient)
    UTronRpgAbilitySystemComponent* AbilitySystemComponent = nullptr;

    /** Конфигурация привязок ввода */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability|Config")
    TObjectPtr<UAbilityInputConfig> InputConfig;

    /** Набор способностей */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability|Config")
    TObjectPtr<UTronAbilitySet> AbilitySet;

    /** Компонент ввода, с которым установлены привязки */
    UPROPERTY(Transient)
    TObjectPtr<UInputComponent> BoundInputComponent;

    /** Отложенные теги способностей, ожидающие активации при инициализации AbilitySystemComponent */
    UPROPERTY(Transient)
    TArray<FGameplayTag> PendingActivationTags;

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

    /**
     * Обработчик окончания активации способности
     */
    void OnAbilityEnded(const FAbilityEndedData& AbilityEndedData);

    /**
     * Подписаться на события AbilitySystemComponent
     */
    void BindToAbilitySystemEvents();

    /**
     * Проверить наличие отложенных активаций
     */
    void CheckPendingActivations();
};
