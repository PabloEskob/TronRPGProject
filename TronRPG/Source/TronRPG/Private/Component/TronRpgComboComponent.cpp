#include "Component/TronRpgComboComponent.h"
#include "GameFramework/Character.h"
#include "Animation/Character/CharacterAnimInstance.h"

UTronRpgComboComponent::UTronRpgComboComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicatedByDefault(true);

	// Инициализация параметров комбо по умолчанию
	CurrentComboCount = 0;
	MaxComboCount = 3;
	ComboTimeWindow = 1.5f;
	bComboWindowOpen = false;
	ComboWindowStartTime = 0.0f;
}

void UTronRpgComboComponent::BeginPlay()
{
	Super::BeginPlay();

	// Получаем AnimInstance для подписки на события анимации
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (OwnerCharacter && OwnerCharacter->GetMesh())
	{
		UCharacterAnimInstance* AnimInstance = Cast<UCharacterAnimInstance>(OwnerCharacter->GetMesh()->GetAnimInstance());
		if (AnimInstance)
		{
			AnimInstance->OnAnimNotifyBegin.AddDynamic(this, &UTronRpgComboComponent::OnAnimNotifyReceived);
		}
	}
}

void UTronRpgComboComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// Отписываемся от событий
	if (OwnerCharacter && OwnerCharacter->GetMesh())
	{
		UCharacterAnimInstance* AnimInstance = Cast<UCharacterAnimInstance>(OwnerCharacter->GetMesh()->GetAnimInstance());
		if (AnimInstance)
		{
			AnimInstance->OnAnimNotifyBegin.RemoveDynamic(this, &UTronRpgComboComponent::OnAnimNotifyReceived);
		}
	}

	// Очищаем таймер
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(ComboWindowTimerHandle);
	}

	Super::EndPlay(EndPlayReason);
}

void UTronRpgComboComponent::InitializeDependencies()
{
	// Инициализация зависимостей через DI
}

void UTronRpgComboComponent::OnAnimNotifyReceived(FName NotifyName)
{
	// Обрабатываем уведомление о комбо из анимации
	if (NotifyName == FName("ComboWindow"))
	{
		OpenComboWindow();
	}
}

void UTronRpgComboComponent::OpenComboWindow()
{
	// Открываем окно комбо
	bComboWindowOpen = true;
	ComboWindowStartTime = GetWorld()->GetTimeSeconds();

	// Оповещаем интерфейс о том, что окно комбо открыто
	OnComboWindowOpened.Broadcast();

	// Устанавливаем таймер для закрытия окна
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(ComboWindowTimerHandle);
		GetWorld()->GetTimerManager().SetTimer(
			ComboWindowTimerHandle,
			this,
			&UTronRpgComboComponent::CloseComboWindow,
			ComboTimeWindow,
			false);
	}

	UE_LOG(LogTemp, Log, TEXT("Combo window opened. Current combo: %d"), CurrentComboCount);
}

void UTronRpgComboComponent::CloseComboWindow()
{
	if (bComboWindowOpen)
	{
		bComboWindowOpen = false;
		OnComboWindowClosed.Broadcast();

		// Если окно закрылось по таймеру (а не из-за продолжения комбо),
		// то сбрасываем комбо, так как игрок не успел продолжить
		if (CurrentComboCount > 0)
		{
			UE_LOG(LogTemp, Log, TEXT("Combo window closed without input. Resetting combo."));
			ResetCombo();
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Combo window closed. No combo was active."));
		}
	}
}

bool UTronRpgComboComponent::IncrementCombo()
{
	if (CurrentComboCount < MaxComboCount - 1)
	{
		CurrentComboCount++;
		OnComboCountChanged.Broadcast(CurrentComboCount);
		UE_LOG(LogTemp, Log, TEXT("Combo incremented to: %d"), CurrentComboCount);
		return true;
	}
	else
	{
		// Достигнут максимум комбо
		UE_LOG(LogTemp, Warning, TEXT("Maximum combo count reached: %d"), MaxComboCount);
		OnMaxComboReached.Broadcast();
		return false;
	}
}

void UTronRpgComboComponent::ResetCombo()
{
	if (CurrentComboCount > 0)
	{
		int32 FinalComboCount = CurrentComboCount;
		CurrentComboCount = 0;

		OnComboReset.Broadcast();
		OnComboEnded.Broadcast();

		UE_LOG(LogTemp, Log, TEXT("Combo reset from %d to 0"), FinalComboCount);
	}

	bComboWindowOpen = false;
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(ComboWindowTimerHandle);
	}
}

bool UTronRpgComboComponent::ProcessComboInput()
{
	if (bComboWindowOpen)
	{
		// Закрываем текущее окно комбо
		bComboWindowOpen = false;
		GetWorld()->GetTimerManager().ClearTimer(ComboWindowTimerHandle);

		// Пытаемся увеличить счетчик комбо
		bool bComboIncremented = IncrementCombo();

		if (bComboIncremented)
		{
			// Отправляем событие для продолжения комбо
			OnComboContinue.Broadcast(CurrentComboCount);
			UE_LOG(LogTemp, Log, TEXT("Combo input processed, combo count: %d"), CurrentComboCount);
			return true;
		}
		else
		{
			// Достигнут максимум - завершаем комбо
			UE_LOG(LogTemp, Log, TEXT("Maximum combo reached, ending combo"));
			ResetCombo();
			return false;
		}
	}
	else
	{
		UE_LOG(LogTemp, Verbose, TEXT("ProcessComboInput called but window is not open"));
		return false;
	}
}

bool UTronRpgComboComponent::IsComboWindowOpen() const
{
	return bComboWindowOpen;
}

int32 UTronRpgComboComponent::GetCurrentComboCount() const
{
	return CurrentComboCount;
}

int32 UTronRpgComboComponent::GetMaxComboCount() const
{
	return MaxComboCount;
}

void UTronRpgComboComponent::SetComboCount(int32 NewCount)
{
	if (NewCount >= 0 && NewCount < MaxComboCount)
	{
		int32 OldCount = CurrentComboCount;
		CurrentComboCount = NewCount;

		if (OldCount != CurrentComboCount)
		{
			OnComboCountChanged.Broadcast(CurrentComboCount);
		}
	}
}

void UTronRpgComboComponent::SetMaxComboCount(int32 NewMaxCount)
{
	if (NewMaxCount > 0)
	{
		MaxComboCount = NewMaxCount;

		// Убеждаемся, что текущий счетчик не превышает новый максимум
		if (CurrentComboCount >= MaxComboCount)
		{
			SetComboCount(MaxComboCount - 1);
		}
	}
}

void UTronRpgComboComponent::SetComboWindowDuration(float NewDuration)
{
	if (NewDuration > 0.0f)
	{
		ComboTimeWindow = NewDuration;

		// Обновляем существующий таймер, если окно открыто
		if (bComboWindowOpen && GetWorld())
		{
			float ElapsedTime = GetWorld()->GetTimeSeconds() - ComboWindowStartTime;
			float RemainingTime = FMath::Max(0.0f, NewDuration - ElapsedTime);

			GetWorld()->GetTimerManager().ClearTimer(ComboWindowTimerHandle);
			GetWorld()->GetTimerManager().SetTimer(
				ComboWindowTimerHandle,
				this,
				&UTronRpgComboComponent::CloseComboWindow,
				RemainingTime,
				false);
		}
	}
}

float UTronRpgComboComponent::GetComboWindowTimeRemaining() const
{
	if (bComboWindowOpen && GetWorld())
	{
		float ElapsedTime = GetWorld()->GetTimeSeconds() - ComboWindowStartTime;
		return FMath::Max(0.0f, ComboTimeWindow - ElapsedTime);
	}

	return 0.0f;
}
