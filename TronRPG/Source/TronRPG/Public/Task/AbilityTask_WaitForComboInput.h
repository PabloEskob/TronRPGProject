#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "AbilityTask_WaitForComboInput.generated.h"

// Делегат, вызываемый при получении ввода комбо
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWaitForComboInputDelegate, int32, ComboCount);

/**
 * Задача способности для ожидания ввода комбо от игрока
 * Реализует асинхронное ожидание ввода в рамках GAS
 */
UCLASS()
class TRONRPG_API UAbilityTask_WaitForComboInput : public UAbilityTask
{
    GENERATED_BODY()

public:
    // Делегаты для событий
    UPROPERTY(BlueprintAssignable)
    FWaitForComboInputDelegate OnComboInputReceived;

    UPROPERTY(BlueprintAssignable)
    FWaitForComboInputDelegate OnComboWindowExpired;

    /**
     * Создает экземпляр задачи ожидания ввода комбо
     * @param OwningAbility Способность, создающая задачу
     * @param WindowDuration Длительность окна комбо в секундах
     * @param CurrentComboCount Текущий счётчик комбо
     * @return Созданный экземпляр задачи
     */
    UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", 
              meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
    static UAbilityTask_WaitForComboInput* WaitForComboInput(
        UGameplayAbility* OwningAbility, 
        float WindowDuration, 
        int32 CurrentComboCount
    );

    // Переопределенные методы абстрактного класса
    virtual void Activate() override;
    virtual void OnDestroy(bool bInOwnerFinished) override;

    /**
     * Обрабатывает ввод комбо от игрока
     * Вызывается из контроллера или компонента ввода
     */
    void ProcessComboInput();
    
    /**
     * Принудительно закрывает окно комбо
     * Может использоваться для отмены комбо
     */
    void CloseComboWindow();

protected:
    // Текущий счётчик комбо
    int32 ComboCount;
    
    // Длительность окна комбо
    float ComboWindowDuration;
    
    // Флаг открытого окна комбо
    bool bComboWindowOpen;
    
    // Таймер для закрытия окна
    FTimerHandle ComboWindowTimerHandle;
    
    /**
     * Обработчик истечения таймера окна комбо
     * Вызывается автоматически по истечении времени
     */
    void OnComboWindowTimerExpired();
};