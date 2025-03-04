#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TronRpgComboComponent.generated.h"

// Делегат для событий изменения комбо
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnComboCountChanged, int32, NewComboCount);

// Делегат для события завершения комбо
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnComboEnded);

// Делегат для события сброса комбо
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnComboReset);

// Делегат для события продолжения комбо
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnComboContinue, int32, CurrentComboCount);

// Делегаты для открытия/закрытия окна комбо
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnComboWindowOpened);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnComboWindowClosed);

/**
 * Компонент для управления комбо-атаками
 * Отслеживает текущее количество ударов в комбо и обеспечивает таймер сброса комбо
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TRONRPG_API UTronRpgComboComponent : public UActorComponent
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
	void IncrementCombo();

	/** Сбросить счетчик комбо */
	UFUNCTION(BlueprintCallable, Category = "Combat|Combo")
	void ResetCombo();

	/** Обработать ввод комбо от игрока */
	UFUNCTION(BlueprintCallable, Category = "Combat|Combo")
	void ProcessComboInput();

	/** Проверить, открыто ли окно комбо */
	UFUNCTION(BlueprintPure, Category = "Combat|Combo")
	bool IsComboWindowOpen() const;

	/** Получить текущий счетчик комбо */
	UFUNCTION(BlueprintPure, Category = "Combat|Combo")
	int32 GetCurrentComboCount() const;

	/** Получить максимальное количество ударов в комбо */
	UFUNCTION(BlueprintPure, Category = "Combat|Combo")
	int32 GetMaxComboCount() const;

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

	/** Обработчик получения уведомления из анимации */
	UFUNCTION()
	void OnAnimNotifyReceived(FName NotifyName);
};