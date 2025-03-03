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
	if (bComboWindowOpen)
	{
		bComboWindowOpen = false;
		OnComboWindowClosed.Broadcast();
		UE_LOG(LogTemp, Log, TEXT("Combo window closed. Combo not continued."));
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
    if (bComboWindowOpen)
    {
        // Закрываем текущее окно комбо
        bComboWindowOpen = false;
        GetWorld()->GetTimerManager().ClearTimer(ComboWindowTimerHandle);
        
        // Увеличиваем счетчик комбо
        IncrementCombo();
        
        // Отправляем событие для продолжения комбо
        OnComboContinue.Broadcast(CurrentComboCount);
        
        UE_LOG(LogTemp, Log, TEXT("Combo input processed, combo count: %d"), CurrentComboCount);
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