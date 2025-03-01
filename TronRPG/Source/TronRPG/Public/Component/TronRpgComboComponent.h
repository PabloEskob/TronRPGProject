// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TronRpgComboComponent.generated.h"

// Делегат для событий изменения комбо
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnComboCountChanged, int32, NewComboCount);

// Делегат для события завершения комбо
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnComboEnded);

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
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/**
	 * Увеличить счетчик комбо
	 * @param bResetTimer Сбросить ли таймер завершения комбо
	 */
	UFUNCTION(BlueprintCallable, Category = "Combo")
	void IncrementCombo(bool bResetTimer = true);

	/**
	 * Сбросить счетчик комбо
	 * @param bFireEvent Вызвать ли событие завершения комбо
	 */
	UFUNCTION(BlueprintCallable, Category = "Combo")
	void ResetCombo(bool bFireEvent = true);

	/**
	 * Установить максимальное значение комбо
	 * @param NewMaxComboCount Новое максимальное значение
	 */
	UFUNCTION(BlueprintCallable, Category = "Combo")
	void SetMaxComboCount(int32 NewMaxComboCount);

	/**
	 * Получить текущее значение комбо
	 * @return Текущее значение комбо
	 */
	UFUNCTION(BlueprintPure, Category = "Combo")
	int32 GetComboCount() const { return ComboCount; }

	/**
	 * Получить максимальное значение комбо
	 * @return Максимальное значение комбо
	 */
	UFUNCTION(BlueprintPure, Category = "Combo")
	int32 GetMaxComboCount() const { return MaxComboCount; }

	/**
	 * Получить нормализованное значение комбо (0-1)
	 * @return Нормализованное значение комбо
	 */
	UFUNCTION(BlueprintPure, Category = "Combo")
	float GetNormalizedComboCount() const;

	/**
	 * Получить процент оставшегося времени комбо (0-1)
	 * @return Процент оставшегося времени до сброса комбо
	 */
	UFUNCTION(BlueprintPure, Category = "Combo")
	float GetComboTimeRemainingPercent() const;

	/**
	 * Получить оставшееся время до сброса комбо
	 * @return Время в секундах до сброса комбо
	 */
	UFUNCTION(BlueprintPure, Category = "Combo")
	float GetComboTimeRemaining() const;

	/**
	 * Установить время до сброса комбо
	 * @param NewComboTimeout Новое время в секундах
	 */
	UFUNCTION(BlueprintCallable, Category = "Combo")
	void SetComboTimeout(float NewComboTimeout);

	/**
	 * Проверить, активно ли текущее комбо
	 * @return true, если комбо активно (счетчик > 0)
	 */
	UFUNCTION(BlueprintPure, Category = "Combo")
	bool IsComboActive() const { return ComboCount > 0; }

	/**
	 * Приостановить/возобновить таймер сброса комбо
	 * @param bPause Приостановить (true) или возобновить (false) таймер
	 */
	UFUNCTION(BlueprintCallable, Category = "Combo")
	void PauseComboTimer(bool bPause);

	/** Событие изменения счетчика комбо */
	UPROPERTY(BlueprintAssignable, Category = "Combo|Events")
	FOnComboCountChanged OnComboCountChanged;

	/** Событие завершения комбо */
	UPROPERTY(BlueprintAssignable, Category = "Combo|Events")
	FOnComboEnded OnComboEnded;

	/** Счётчик комбо */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, Category = "Combo")
	int32 ComboCount = 0;

protected:
	/** Максимальное количество комбо */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combo", meta = (ClampMin = "1"))
	int32 MaxComboCount = 5;

	/** Время до сброса комбо (в секундах) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combo", meta = (ClampMin = "0.1"))
	float ComboTimeout = 3.0f;

	/** Оставшееся время до сброса комбо */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combo")
	float ComboTimeRemaining = 0.0f;

	/** Флаг активности таймера комбо */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combo")
	bool bComboTimerActive = false;

	/** Флаг приостановки таймера комбо */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combo")
	bool bComboTimerPaused = false;

	/** Обновление таймера комбо */
	void UpdateComboTimer(float DeltaTime);

	/** Обработчик события таймера комбо */
	void OnComboTimerExpired();

	/** Репликация свойств */
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
