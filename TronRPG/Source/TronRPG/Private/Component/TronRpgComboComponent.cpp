#include "Component/TronRpgComboComponent.h"
#include "GameFramework/Character.h"
#include "Animation/Character/CharacterAnimInstance.h"
#include "GameplayAbility/MeleeAttackAbility.h"
#include "Task/AbilityTask_WaitForComboInput.h"

UTronRpgComboComponent::UTronRpgComboComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicatedByDefault(true);

	// Инициализация параметров комбо по умолчанию
	CurrentComboCount = 0;
	MaxComboCount = 3;
	ComboTimeWindow = 1.5f;
	bComboWindowOpen = false;
}

void UTronRpgComboComponent::BeginPlay()
{
	Super::BeginPlay();

	// Получаем AnimInstance для подписки на события анимации
	if (AActor* Owner = GetOwner())
	{
		OwnerCharacter = Cast<ACharacter>(Owner);
		if (OwnerCharacter && OwnerCharacter->GetMesh())
		{
			UCharacterAnimInstance* AnimInstance = Cast<UCharacterAnimInstance>(OwnerCharacter->GetMesh()->GetAnimInstance());
			if (AnimInstance)
			{
				AnimInstance->OnAnimNotifyBegin.AddDynamic(this, &UTronRpgComboComponent::OnAnimNotifyReceived);
			}
		}
	}
}

void UTronRpgComboComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// Очищаем задачу
	if (ComboInputTask)
	{
		ComboInputTask->EndTask();
		ComboInputTask = nullptr;
	}
	
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
	if (!bComboWindowOpen)
	{
		return;
	}

	bComboWindowOpen = false;

	// Останавливаем таймер
	ClearComboTimer();

	// Уведомляем о закрытии окна комбо
	NotifyComboWindowClosed();

	// Если существует активная задача, закрываем окно в ней
	if (ComboInputTask)
	{
		ComboInputTask->CloseComboWindow();
		ComboInputTask = nullptr;
	}
}

void UTronRpgComboComponent::IncrementCombo()
{
	if (CurrentComboCount < MaxComboCount - 1)
	{
		CurrentComboCount++;
		OnComboCountChanged.Broadcast(CurrentComboCount);
		UE_LOG(LogTemp, Log, TEXT("Combo incremented to: %d"), CurrentComboCount);
	}
}

void UTronRpgComboComponent::ResetCombo()
{
	if (CurrentComboCount > 0)
	{
		CurrentComboCount = 0;
		OnComboReset.Broadcast();
		UE_LOG(LogTemp, Log, TEXT("Combo reset"));
	}

	bComboWindowOpen = false;
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(ComboWindowTimerHandle);
	}
}

void UTronRpgComboComponent::ProcessComboInput()
{
	if (!IsComboWindowOpen() || !ComboInputTask)
	{
		return;
	}

	// Делегируем обработку ввода непосредственно задаче
	ComboInputTask->ProcessComboInput();
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

void UTronRpgComboComponent::IncrementAndNotifyCombo()
{
	IncrementCombo();
	OnComboContinue.Broadcast(CurrentComboCount);

	UE_LOG(LogTemp, Log, TEXT("Combo input processed, combo count: %d"), CurrentComboCount);
}

void UTronRpgComboComponent::ClearComboTimer()
{
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(ComboWindowTimerHandle);
	}
}

void UTronRpgComboComponent::NotifyComboWindowClosed()
{
	OnComboWindowClosed.Broadcast();
	UE_LOG(LogTemp, Log, TEXT("Combo window closed. Combo not continued."));
}

void UTronRpgComboComponent::SetComboCount(int32 NewCount)
{
	if (NewCount >= 0 && NewCount < MaxComboCount)
	{
		CurrentComboCount = NewCount;
		OnComboCountChanged.Broadcast(CurrentComboCount);
		UE_LOG(LogTemp, Log, TEXT("Combo explicitly set to: %d"), CurrentComboCount);
	}
}

void UTronRpgComboComponent::StartWaitingForComboInput(UMeleeAttackAbility* OwningAbility, int32 ComboCount)
{
	// Сохраняем ссылку на текущую способность
	CurrentAttackAbility = OwningAbility;

	// Создаем и настраиваем задачу ожидания ввода
	if (CurrentAttackAbility)
	{
		ComboInputTask = UAbilityTask_WaitForComboInput::WaitForComboInput(
			CurrentAttackAbility, ComboWindowTime, ComboCount);

		if (ComboInputTask)
		{
			// Подписываемся на события task'а
			ComboInputTask->OnComboInputReceived.AddDynamic(this, &UTronRpgComboComponent::OnComboInputTaskReceived);
			ComboInputTask->OnComboWindowExpired.AddDynamic(this, &UTronRpgComboComponent::OnComboInputTaskExpired);

			// Активируем task
			ComboInputTask->ReadyForActivation();

			// Открываем окно комбо
			OpenComboWindow();

			UE_LOG(LogTemp, Log, TEXT("ComboComponent: ComboWindow opened for combo count: %d"), ComboCount);
		}
	}
}

void UTronRpgComboComponent::OnComboInputTaskReceived(int32 ComboCount)
{
	// Увеличиваем счетчик комбо
	IncrementCombo();

	// Закрываем окно комбо
	CloseComboWindow();

	// Сбрасываем задачу
	ComboInputTask = nullptr;

	// Передаем событие в способность через делегат
	OnComboInputReceived.Broadcast(ComboCount);

	UE_LOG(LogTemp, Log, TEXT("ComboComponent: Combo input received, new count: %d"), CurrentComboCount);
}

// Добавьте метод обработки истечения окна от AbilityTask
void UTronRpgComboComponent::OnComboInputTaskExpired(int32 ComboCount)
{
	// Закрываем окно комбо
	CloseComboWindow();

	// Сбрасываем задачу
	ComboInputTask = nullptr;

	// Передаем событие в способность через делегат
	OnComboWindowExpired.Broadcast(ComboCount);

	UE_LOG(LogTemp, Log, TEXT("ComboComponent: Combo window expired without input"));
}

// Добавьте метод проверки валидности запроса комбо
bool UTronRpgComboComponent::IsValidComboRequest(UMeleeAttackAbility* RequestingAbility) const
{
	return RequestingAbility && RequestingAbility == CurrentAttackAbility && bComboWindowOpen;
}
