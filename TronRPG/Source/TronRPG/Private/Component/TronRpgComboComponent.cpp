// Fill out your copyright notice in the Description page of Project Settings.

#include "Component/TronRpgComboComponent.h"
#include "Net/UnrealNetwork.h"

UTronRpgComboComponent::UTronRpgComboComponent()
{
	// Настройки компонента
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickInterval = 0.05f; // Оптимизация - тик каждые 50 мс

	SetIsReplicatedByDefault(true);

	// Инициализация переменных
	ComboCount = 0;
	MaxComboCount = 5;
	ComboTimeout = 3.0f;
	ComboTimeRemaining = 0.0f;
	bComboTimerActive = false;
	bComboTimerPaused = false;
}

void UTronRpgComboComponent::BeginPlay()
{
	Super::BeginPlay();

	// Начальная инициализация при старте игры
	ResetCombo(false);
}

void UTronRpgComboComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Обновление таймера комбо, если он активен
	if (bComboTimerActive && !bComboTimerPaused)
	{
		UpdateComboTimer(DeltaTime);
	}
}

void UTronRpgComboComponent::UpdateComboTimer(float DeltaTime)
{
	if (ComboCount > 0)
	{
		// Уменьшаем оставшееся время
		ComboTimeRemaining -= DeltaTime;

		// Если время истекло, сбрасываем комбо
		if (ComboTimeRemaining <= 0.0f)
		{
			OnComboTimerExpired();
		}
	}
}

void UTronRpgComboComponent::OnComboTimerExpired()
{
	// Сбрасываем комбо при истечении таймера
	ResetCombo(true);

	// Деактивируем таймер
	bComboTimerActive = false;
	ComboTimeRemaining = 0.0f;
}

void UTronRpgComboComponent::IncrementCombo(bool bResetTimer)
{
	// Увеличиваем счетчик комбо, но не превышаем максимальное значение
	ComboCount = FMath::Min(ComboCount + 1, MaxComboCount);

	// Если нужно, сбрасываем таймер
	if (bResetTimer)
	{
		ComboTimeRemaining = ComboTimeout;
		bComboTimerActive = true;
	}

	// Уведомляем подписчиков об изменении счетчика комбо
	OnComboCountChanged.Broadcast(ComboCount);
}

void UTronRpgComboComponent::ResetCombo(bool bFireEvent)
{
	// Запоминаем предыдущее значение для проверки необходимости вызова события
	int32 PreviousComboCount = ComboCount;

	// Сбрасываем счетчик и таймер
	ComboCount = 0;
	ComboTimeRemaining = 0.0f;
	bComboTimerActive = false;

	// Если нужно и было активно комбо, вызываем событие завершения комбо
	if (bFireEvent && PreviousComboCount > 0)
	{
		OnComboEnded.Broadcast();
	}

	// Уведомляем об изменении счетчика комбо
	if (PreviousComboCount != ComboCount)
	{
		OnComboCountChanged.Broadcast(ComboCount);
	}
}

void UTronRpgComboComponent::SetMaxComboCount(int32 NewMaxComboCount)
{
	// Устанавливаем новое максимальное значение (минимум 1)
	MaxComboCount = FMath::Max(1, NewMaxComboCount);

	// Если текущее значение превышает новый максимум, ограничиваем его
	if (ComboCount > MaxComboCount)
	{
		ComboCount = MaxComboCount;
		OnComboCountChanged.Broadcast(ComboCount);
	}
}

float UTronRpgComboComponent::GetNormalizedComboCount() const
{
	// Защита от деления на ноль
	if (MaxComboCount <= 1)
	{
		return ComboCount > 0 ? 1.0f : 0.0f;
	}

	// Возвращаем нормализованное значение (0-1)
	return static_cast<float>(ComboCount) / static_cast<float>(MaxComboCount);
}

float UTronRpgComboComponent::GetComboTimeRemainingPercent() const
{
	// Если таймер не активен или комбо не активно, возвращаем 0
	if (!bComboTimerActive || ComboCount <= 0)
	{
		return 0.0f;
	}

	// Защита от деления на ноль
	if (ComboTimeout <= 0.0f)
	{
		return 0.0f;
	}

	// Возвращаем процент оставшегося времени (0-1)
	return FMath::Clamp(ComboTimeRemaining / ComboTimeout, 0.0f, 1.0f);
}

float UTronRpgComboComponent::GetComboTimeRemaining() const
{
	// Возвращаем оставшееся время в секундах
	return FMath::Max(0.0f, ComboTimeRemaining);
}

void UTronRpgComboComponent::SetComboTimeout(float NewComboTimeout)
{
	// Устанавливаем новое время таймера (минимум 0.1 секунды)
	ComboTimeout = FMath::Max(0.1f, NewComboTimeout);

	// Обновляем оставшееся время, если таймер активен
	if (bComboTimerActive)
	{
		// Сохраняем процент оставшегося времени
		float RemainingPercent = GetComboTimeRemainingPercent();

		// Применяем его к новому времени таймера
		ComboTimeRemaining = RemainingPercent * ComboTimeout;
	}
}

void UTronRpgComboComponent::PauseComboTimer(bool bPause)
{
	// Устанавливаем флаг приостановки таймера
	bComboTimerPaused = bPause;
}

void UTronRpgComboComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Репликация счетчика комбо
	DOREPLIFETIME(UTronRpgComboComponent, ComboCount);
}
