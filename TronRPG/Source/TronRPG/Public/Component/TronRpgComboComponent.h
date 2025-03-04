#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Component/DI/DIAwareComponent.h"
#include "TronRpgComboComponent.generated.h"

// Делегат для изменения счетчика комбо
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnComboCountChanged, int32, NewComboCount);

// Делегат для завершения комбо
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnComboEnded);

// Делегат для сброса комбо
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnComboReset);

// Делегат для продолжения комбо
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnComboContinue, int32, CurrentComboCount);

// Делегаты для окна комбо
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnComboWindowOpened);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnComboWindowClosed);

// Делегат для достижения максимального комбо
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMaxComboReached);

/**
 * Компонент для управления комбо-атаками
 * Отслеживает текущее количество ударов в комбо и обеспечивает таймер сброса комбо
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TRONRPG_API UTronRpgComboComponent : public UDIAwareComponent
{
	GENERATED_BODY()

public:
	UTronRpgComboComponent();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	/** Открыть окно возможности комбо */
	UFUNCTION(BlueprintCallable, Category = "Combat|Combo")
	void OpenComboWindow();

	/** Закрыть окно возможности комбо */
	UFUNCTION(BlueprintCallable, Category = "Combat|Combo")
	void CloseComboWindow();

	/** Увеличить счетчик комбо */
	UFUNCTION(BlueprintCallable, Category = "Combat|Combo")
	bool IncrementCombo();

	/** Сбросить счетчик комбо */
	UFUNCTION(BlueprintCallable, Category = "Combat|Combo")
	void ResetCombo();

	/** Обработать ввод комбо от игрока */
	UFUNCTION(BlueprintCallable, Category = "Combat|Combo")
	bool ProcessComboInput();

	/** Проверить, открыто ли окно комбо */
	UFUNCTION(BlueprintPure, Category = "Combat|Combo")
	bool IsComboWindowOpen() const;

	/** Получить текущий счетчик комбо */
	UFUNCTION(BlueprintPure, Category = "Combat|Combo")
	int32 GetCurrentComboCount() const;

	/** Получить максимальное количество ударов в комбо */
	UFUNCTION(BlueprintPure, Category = "Combat|Combo")
	int32 GetMaxComboCount() const;

	/** Установить текущий счетчик комбо */
	UFUNCTION(BlueprintCallable, Category = "Combat|Combo")
	void SetComboCount(int32 NewCount);

	/** Установить максимальное количество ударов в комбо */
	UFUNCTION(BlueprintCallable, Category = "Combat|Combo")
	void SetMaxComboCount(int32 NewMaxCount);

	/** Установить длительность окна комбо */
	UFUNCTION(BlueprintCallable, Category = "Combat|Combo")
	void SetComboWindowDuration(float NewDuration);

	/** Получить оставшееся время в текущем окне комбо */
	UFUNCTION(BlueprintPure, Category = "Combat|Combo")
	float GetComboWindowTimeRemaining() const;

	/** Событие изменения счетчика комбо */
	UPROPERTY(BlueprintAssignable, Category = "Combat|Combo|Events")
	FOnComboCountChanged OnComboCountChanged;

	/** Событие завершения комбо */
	UPROPERTY(BlueprintAssignable, Category = "Combat|Combo|Events")
	FOnComboEnded OnComboEnded;

	/** Событие сброса комбо */
	UPROPERTY(BlueprintAssignable, Category = "Combat|Combo|Events")
	FOnComboReset OnComboReset;

	/** Событие продолжения комбо */
	UPROPERTY(BlueprintAssignable, Category = "Combat|Combo|Events")
	FOnComboContinue OnComboContinue;

	/** Событие открытия окна комбо */
	UPROPERTY(BlueprintAssignable, Category = "Combat|Combo|Events")
	FOnComboWindowOpened OnComboWindowOpened;

	/** Событие закрытия окна комбо */
	UPROPERTY(BlueprintAssignable, Category = "Combat|Combo|Events")
	FOnComboWindowClosed OnComboWindowClosed;

	/** Событие достижения максимального комбо */
	UPROPERTY(BlueprintAssignable, Category = "Combat|Combo|Events")
	FOnMaxComboReached OnMaxComboReached;

protected:
	/** Максимальное количество ударов в комбо */
	UPROPERTY(EditDefaultsOnly, Category = "Combat|Combo", meta = (ClampMin = "1", ClampMax = "10"))
	int32 MaxComboCount;

	/** Текущий счетчик комбо */
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Combat|Combo")
	int32 CurrentComboCount;

	/** Время в секундах, в течение которого окно комбо остается открытым */
	UPROPERTY(EditDefaultsOnly, Category = "Combat|Combo", meta = (ClampMin = "0.1", ClampMax = "5.0"))
	float ComboTimeWindow;

	/** Флаг, указывающий, открыто ли окно комбо */
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Combat|Combo")
	bool bComboWindowOpen;

	/** Ссылка на владельца компонента (персонажа) */
	UPROPERTY(Transient)
	class ACharacter* OwnerCharacter;

	/** Таймер для закрытия окна комбо */
	FTimerHandle ComboWindowTimerHandle;

	/** Время, когда было открыто текущее окно комбо */
	float ComboWindowStartTime;

	/** Инициализация зависимостей через DI */
	virtual void InitializeDependencies() override;

	/** Обработчик получения уведомления из анимации */
	UFUNCTION()
	void OnAnimNotifyReceived(FName NotifyName);
};
