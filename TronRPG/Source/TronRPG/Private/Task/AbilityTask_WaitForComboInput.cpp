// TronRPG/Private/AbilityTasks/AbilityTask_WaitForComboInput.cpp

#include "Task/AbilityTask_WaitForComboInput.h"

#include "AbilitySystemComponent.h"

UAbilityTask_WaitForComboInput* UAbilityTask_WaitForComboInput::WaitForComboInput(
	UGameplayAbility* OwningAbility,
	float WindowDuration,
	int32 CurrentComboCount)
{
	UAbilityTask_WaitForComboInput* MyObj = NewAbilityTask<UAbilityTask_WaitForComboInput>(OwningAbility);

	if (MyObj)
	{
		MyObj->ComboCount = CurrentComboCount;
		MyObj->ComboWindowDuration = FMath::Max(WindowDuration, 0.1f);
		MyObj->bComboWindowOpen = false;
	}

	return MyObj;
}

void UAbilityTask_WaitForComboInput::Activate()
{
	// Открываем окно комбо и устанавливаем таймер
	bComboWindowOpen = true;

	// Добавляем тег состояния "ComboWindowOpen"
	if (AbilitySystemComponent.Get())
	{
		AbilitySystemComponent->AddLooseGameplayTag(FGameplayTag::RequestGameplayTag("State.ComboWindowOpen"));
	}

	// Устанавливаем таймер для автоматического закрытия окна
	UWorld* World = GetWorld();
	if (World)
	{
		World->GetTimerManager().SetTimer(
			ComboWindowTimerHandle,
			this,
			&UAbilityTask_WaitForComboInput::OnComboWindowTimerExpired,
			ComboWindowDuration,
			false);
	}

	UE_LOG(LogTemp, Log, TEXT("AbilityTask: Combo window opened. Current combo: %d"), ComboCount);
}

void UAbilityTask_WaitForComboInput::OnDestroy(bool bInOwnerFinished)
{
	// Очищаем таймер при уничтожении задачи
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(ComboWindowTimerHandle);
	}

	// Удаляем тег состояния
	if (AbilitySystemComponent.Get())
	{
		AbilitySystemComponent->RemoveLooseGameplayTag(FGameplayTag::RequestGameplayTag("State.ComboWindowOpen"));
	}

	bComboWindowOpen = false;

	Super::OnDestroy(bInOwnerFinished);
}

void UAbilityTask_WaitForComboInput::ProcessComboInput()
{
	if (!bComboWindowOpen)
	{
		return;
	}

	// Закрываем окно и вызываем делегат с увеличенным счётчиком
	UE_LOG(LogTemp, Log, TEXT("AbilityTask: Combo input received. Current combo: %d"), ComboCount);

	bComboWindowOpen = false;

	// Очищаем таймер
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(ComboWindowTimerHandle);
	}

	// Вызываем делегат с увеличенным счётчиком комбо
	OnComboInputReceived.Broadcast(ComboCount + 1);

	// Завершаем задачу
	EndTask();
}

void UAbilityTask_WaitForComboInput::CloseComboWindow()
{
	if (bComboWindowOpen)
	{
		UE_LOG(LogTemp, Log, TEXT("AbilityTask: Combo window closed manually."));

		bComboWindowOpen = false;

		// Очищаем таймер
		if (UWorld* World = GetWorld())
		{
			World->GetTimerManager().ClearTimer(ComboWindowTimerHandle);
		}

		// Вызываем делегат с текущим счётчиком (без увеличения)
		OnComboWindowExpired.Broadcast(ComboCount);

		// Завершаем задачу
		EndTask();
	}
}

void UAbilityTask_WaitForComboInput::OnComboWindowTimerExpired()
{
	UE_LOG(LogTemp, Log, TEXT("AbilityTask: Combo window timer expired. Combo not continued."));

	bComboWindowOpen = false;

	// Вызываем делегат с текущим счётчиком (без увеличения)
	OnComboWindowExpired.Broadcast(ComboCount);

	// Завершаем задачу
	EndTask();
}
