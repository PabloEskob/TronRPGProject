#include "Component/Input/AbilityInputComponent.h"

#include "GAS/TronRpgAbilitySystemComponent.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "GameplayAbilitySpec.h"
#include "Config/AbilityInputConfig.h"
#include "Struct/Input/AbilityInputBinding.h"
#include "Logging/LogMacros.h"

// Определяем логирование для компонента
DEFINE_LOG_CATEGORY_STATIC(LogTronAbilityInput, Log, All);

UAbilityInputComponent::UAbilityInputComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicatedByDefault(true);
}

void UAbilityInputComponent::BeginPlay()
{
	Super::BeginPlay();

	// Инициализация AbilitySystemComponent
	InitializeAbilitySystem();

	// Загружаем привязки из конфига, если он указан
	if (InputConfig)
	{
		LoadInputBindingsFromConfig(InputConfig, false);
	}

	// Загружаем способности из набора, если он указан
	if (AbilitySet && AbilitySystemComponent)
	{
		InitializeFromAbilitySet(AbilitySet);
	}
}

void UAbilityInputComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// Очистка привязок при завершении работы компонента
	if (BoundInputComponent)
	{
		UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(BoundInputComponent);
		if (EnhancedInputComponent)
		{
			EnhancedInputComponent->ClearBindingsForObject(this);
		}
		BoundInputComponent = nullptr;
	}

	// Отписываемся от событий ASC
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityEnded.RemoveAll(this);
	}

	Super::EndPlay(EndPlayReason);
}

void UAbilityInputComponent::InitializeAbilitySystem()
{
	// Получаем AbilitySystemComponent из владельца
	if (!AbilitySystemComponent)
	{
		AbilitySystemComponent = Cast<UTronRpgAbilitySystemComponent>(
			GetOwner()->GetComponentByClass(UTronRpgAbilitySystemComponent::StaticClass())
		);

		if (!AbilitySystemComponent)
		{
			UE_LOG(LogTronAbilityInput, Error, TEXT("[%s] AbilityInputComponent: Failed to find AbilitySystemComponent"), *GetOwner()->GetName());
		}
		else
		{
			UE_LOG(LogTronAbilityInput, Log, TEXT("[%s] AbilityInputComponent: Successfully initialized AbilitySystemComponent"),
			       *GetOwner()->GetName());

			// Подписываемся на события ASC
			BindToAbilitySystemEvents();

			// Проверяем отложенные активации
			CheckPendingActivations();
		}
	}
}

void UAbilityInputComponent::BindToAbilitySystemEvents()
{
	if (!AbilitySystemComponent)
	{
		return;
	}
	AbilitySystemComponent->OnAbilityEnded.AddUObject(this, &UAbilityInputComponent::OnAbilityEnded);
}

void UAbilityInputComponent::OnAbilityEnded(const FAbilityEndedData& AbilityEndedData)
{
	if (!AbilityEndedData.AbilityThatEnded)
	{
		return;
	}

	// Получаем теги способности
	FGameplayTagContainer AbilityTags = AbilityEndedData.AbilityThatEnded->GetAssetTags();

	// Находим все совпадающие теги в наших привязках
	for (const FAbilityInputBinding& Binding : InputConfig->AbilityBindings)
	{
		if (AbilityTags.HasTag(Binding.AbilityTag))
		{
			// Вызываем делегат завершения способности
			OnAbilityActivationEnded.Broadcast(Binding.AbilityTag, AbilityEndedData.bWasCancelled);
			break;
		}
	}
}

void UAbilityInputComponent::CheckPendingActivations()
{
	if (!AbilitySystemComponent || PendingActivationTags.Num() == 0)
	{
		return;
	}

	// Активируем отложенные способности
	for (const FGameplayTag& AbilityTag : PendingActivationTags)
	{
		TryActivateAbilityByTag(AbilityTag, true);
	}

	// Очищаем список
	PendingActivationTags.Empty();
}

void UAbilityInputComponent::SetupPlayerInput(UInputComponent* PlayerInputComponent)
{
	InitializeAbilitySystem();

	if (!PlayerInputComponent || !AbilitySystemComponent)
	{
		UE_LOG(LogTronAbilityInput, Error, TEXT("[%s] AbilityInputComponent: SetupPlayerInput failed - invalid components"), *GetOwner()->GetName());
		return;
	}

	// Приводим к EnhancedInputComponent
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!EnhancedInputComponent)
	{
		UE_LOG(LogTronAbilityInput, Error, TEXT("[%s] AbilityInputComponent: PlayerInputComponent is not UEnhancedInputComponent"),
		       *GetOwner()->GetName());
		return;
	}

	// Сохраняем ссылку на компонент ввода
	BoundInputComponent = PlayerInputComponent;

	// Связываем действия ввода с соответствующими действиями способностей
	for (const FAbilityInputBinding& Binding : InputConfig->AbilityBindings)
	{
		if (Binding.InputAction)
		{
			// Привязываем EnhancedInput к нашим функциям-обработчикам
			EnhancedInputComponent->BindAction(Binding.InputAction, ETriggerEvent::Started,
			                                   this, &UAbilityInputComponent::OnAbilityInputPressed, Binding);

			EnhancedInputComponent->BindAction(Binding.InputAction, ETriggerEvent::Completed,
			                                   this, &UAbilityInputComponent::OnAbilityInputReleased, Binding);

			UE_LOG(LogTronAbilityInput, Log, TEXT("[%s] AbilityInputComponent: Bound input action %s to tag %s"),
			       *GetOwner()->GetName(), *Binding.InputAction->GetName(), *Binding.AbilityTag.ToString());
		}
	}
}

void UAbilityInputComponent::InitializeFromAbilitySet(UTronAbilitySet* InAbilitySet)
{
	if (!InAbilitySet)
	{
		UE_LOG(LogTronAbilityInput, Warning, TEXT("[%s] AbilityInputComponent: InitializeFromAbilitySet failed - invalid ability set"),
		       *GetOwner()->GetName());
		return;
	}

	// Сохраняем ссылку на набор способностей
	AbilitySet = InAbilitySet;

	// Если ASC не инициализирован, выходим (будет проверено снова в BeginPlay)
	if (!AbilitySystemComponent)
	{
		UE_LOG(LogTronAbilityInput, Warning,
		       TEXT("[%s] AbilityInputComponent: AbilitySystemComponent not initialized, deferring ability initialization"),
		       *GetOwner()->GetName());
		return;
	}

	// Получаем все способности из набора
	TArray<FTronAbilityInfo> Abilities;
	AbilitySet->GetAllAbilities(Abilities);

	// Выдаем способности через ASC
	for (const FTronAbilityInfo& AbilityInfo : Abilities)
	{
		if (AbilityInfo.AbilityClass)
		{
			// Создаем спецификацию способности с правильными параметрами
			FGameplayAbilitySpec AbilitySpec(
				AbilityInfo.AbilityClass,
				AbilityInfo.AbilityLevel,
				INDEX_NONE // InputID (не тег!)
			);

			// Добавляем тег как динамический тег источника
			AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilityInfo.AbilityTag);

			// Выдаем способность
			FGameplayAbilitySpecHandle Handle = AbilitySystemComponent->GiveAbility(AbilitySpec);

			if (Handle.IsValid())
			{
				UE_LOG(LogTronAbilityInput, Log, TEXT("[%s] AbilityInputComponent: Successfully granted ability %s with tag %s"),
				       *GetOwner()->GetName(), *AbilityInfo.AbilityClass->GetName(), *AbilityInfo.AbilityTag.ToString());
			}
			else
			{
				UE_LOG(LogTronAbilityInput, Warning, TEXT("[%s] AbilityInputComponent: Failed to grant ability %s with tag %s"),
				       *GetOwner()->GetName(), *AbilityInfo.AbilityClass->GetName(), *AbilityInfo.AbilityTag.ToString());
			}
		}
	}

	UE_LOG(LogTronAbilityInput, Log, TEXT("[%s] AbilityInputComponent: Initialized %d abilities from ability set"),
	       *GetOwner()->GetName(), Abilities.Num());
}

void UAbilityInputComponent::AddInputBinding(UInputAction* InputAction, FGameplayTag AbilityTag, bool bCancelOnRelease, int32 Priority)
{
	// Проверка валидности входных параметров
	if (!InputAction || !AbilityTag.IsValid())
	{
		UE_LOG(LogTronAbilityInput, Warning, TEXT("[%s] AbilityInputComponent: AddInputBinding failed - invalid parameters"), *GetOwner()->GetName());
		return;
	}

	// Проверяем, не существует ли уже такая привязка
	// Если существует с таким же тегом или InputAction, заменяем
	int32 ExistingIndex = INDEX_NONE;
	for (int32 i = 0; i < InputConfig->AbilityBindings.Num(); ++i)
	{
		if (InputConfig->AbilityBindings[i].InputAction == InputAction || InputConfig->AbilityBindings[i].AbilityTag == AbilityTag)
		{
			// Если существующая привязка имеет более высокий приоритет, сохраняем её
			if (InputConfig->AbilityBindings[i].Priority > Priority)
			{
				UE_LOG(LogTronAbilityInput, Warning, TEXT("[%s] AbilityInputComponent: Binding with higher priority already exists for tag %s"),
				       *GetOwner()->GetName(), *AbilityTag.ToString());
				return;
			}

			ExistingIndex = i;
			break;
		}
	}

	// Добавляем или обновляем привязку
	FAbilityInputBinding NewBinding;
	NewBinding.BindingName = InputAction->GetName();
	NewBinding.InputAction = InputAction;
	NewBinding.AbilityTag = AbilityTag;
	NewBinding.bCancelOnRelease = bCancelOnRelease;
	NewBinding.Priority = Priority;

	if (ExistingIndex != INDEX_NONE)
	{
		InputConfig->AbilityBindings[ExistingIndex] = NewBinding;
	}
	else
	{
		InputConfig->AbilityBindings.Add(NewBinding);
	}

	UE_LOG(LogTronAbilityInput, Log, TEXT("[%s] AbilityInputComponent: Added/Updated input binding for action %s with tag %s (Priority: %d)"),
	       *GetOwner()->GetName(), *InputAction->GetName(), *AbilityTag.ToString(), Priority);

	// Если ввод уже настроен, перепривязываем
	if (BoundInputComponent)
	{
		RebindAbilitiesToInput();
	}
}

void UAbilityInputComponent::RemoveInputBindingByTag(FGameplayTag AbilityTag)
{
	if (!AbilityTag.IsValid())
	{
		return;
	}

	int32 RemovedCount = 0;
	for (int32 i = InputConfig->AbilityBindings.Num() - 1; i >= 0; --i)
	{
		if (InputConfig->AbilityBindings[i].AbilityTag == AbilityTag)
		{
			InputConfig->AbilityBindings.RemoveAt(i);
			RemovedCount++;
		}
	}

	if (RemovedCount > 0)
	{
		UE_LOG(LogTronAbilityInput, Log, TEXT("[%s] AbilityInputComponent: Removed %d input bindings for tag %s"),
		       *GetOwner()->GetName(), RemovedCount, *AbilityTag.ToString());

		// Если ввод уже настроен, перепривязываем
		if (BoundInputComponent)
		{
			RebindAbilitiesToInput();
		}
	}
}

void UAbilityInputComponent::RemoveInputBindingByAction(UInputAction* InputAction)
{
	if (!InputAction)
	{
		return;
	}

	int32 RemovedCount = 0;
	for (int32 i = InputConfig->AbilityBindings.Num() - 1; i >= 0; --i)
	{
		if (InputConfig->AbilityBindings[i].InputAction == InputAction)
		{
			InputConfig->AbilityBindings.RemoveAt(i);
			RemovedCount++;
		}
	}

	if (RemovedCount > 0)
	{
		UE_LOG(LogTronAbilityInput, Log, TEXT("[%s] AbilityInputComponent: Removed %d input bindings for action %s"),
		       *GetOwner()->GetName(), RemovedCount, *InputAction->GetName());

		// Если ввод уже настроен, перепривязываем
		if (BoundInputComponent)
		{
			RebindAbilitiesToInput();
		}
	}
}

void UAbilityInputComponent::LoadInputBindingsFromConfig(UAbilityInputConfig* InInputConfig, bool bClearExisting)
{
	if (!InInputConfig)
	{
		UE_LOG(LogTronAbilityInput, Warning, TEXT("[%s] AbilityInputComponent: LoadInputBindingsFromConfig failed - invalid config"),
		       *GetOwner()->GetName());
		return;
	}

	// Очищаем существующие привязки, если требуется
	if (bClearExisting)
	{
		InputConfig->AbilityBindings.Empty();
	}

	// Добавляем привязки из конфига
	const TArray<FAbilityInputBinding>& ConfigBindings = InInputConfig->GetAllBindings();

	// Просто добавляем все привязки из конфига (они имеют тот же тип)
	for (const FAbilityInputBinding& Binding : ConfigBindings)
	{
		if (Binding.InputAction && Binding.AbilityTag.IsValid())
		{
			// Проверяем на наличие дубликатов по тегу или действию
			bool bExists = false;
			for (const FAbilityInputBinding& ExistingBinding : InputConfig->AbilityBindings)
			{
				if (ExistingBinding.InputAction == Binding.InputAction ||
					ExistingBinding.AbilityTag == Binding.AbilityTag)
				{
					bExists = true;
					break;
				}
			}

			if (!bExists)
			{
				InputConfig->AbilityBindings.Add(Binding);

				UE_LOG(LogTronAbilityInput, Log, TEXT("[%s] AbilityInputComponent: Added binding from config: %s (Action: %s, Tag: %s)"),
				       *GetOwner()->GetName(),
				       *Binding.BindingName,
				       *Binding.InputAction->GetName(),
				       *Binding.AbilityTag.ToString());
			}
		}
	}

	UE_LOG(LogTronAbilityInput, Log, TEXT("[%s] AbilityInputComponent: Loaded %d bindings from config"),
	       *GetOwner()->GetName(), ConfigBindings.Num());
}

void UAbilityInputComponent::SetInputConfig(UAbilityInputConfig* InInputConfig, bool bClearExisting)
{
	if (!InInputConfig)
	{
		UE_LOG(LogTronAbilityInput, Warning, TEXT("[%s] AbilityInputComponent: SetInputConfig failed - invalid config"),
		       *GetOwner()->GetName());
		return;
	}

	InputConfig = InInputConfig;

	if (InputConfig)
	{
		LoadInputBindingsFromConfig(InputConfig, bClearExisting);
	}
}

void UAbilityInputComponent::ClearAllInputBindings()
{
	if (!InputConfig)
	{
		return;
	}

	InputConfig->AbilityBindings.Empty();

	// Если ввод уже настроен, очищаем привязки
	if (BoundInputComponent)
	{
		UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(BoundInputComponent);
		if (EnhancedInputComponent)
		{
			EnhancedInputComponent->ClearBindingsForObject(this);
		}
	}

	UE_LOG(LogTronAbilityInput, Log, TEXT("[%s] AbilityInputComponent: Cleared all input bindings"), *GetOwner()->GetName());
}

bool UAbilityInputComponent::SimulateAbilityInputPressed(FGameplayTag AbilityTag)
{
	if (!AbilityTag.IsValid())
	{
		return false;
	}

	// Ищем привязку с нужным тегом
	for (const FAbilityInputBinding& Binding : InputConfig->AbilityBindings)
	{
		if (Binding.AbilityTag == AbilityTag)
		{
			// Вызываем обработчик нажатия с пустым значением
			OnAbilityInputPressed(FInputActionValue(), Binding);
			return true;
		}
	}

	// Если привязки нет, пробуем активировать напрямую
	return ActivateAbilityByTag(AbilityTag);
}

bool UAbilityInputComponent::ActivateAbilityByTag(FGameplayTag AbilityTag)
{
	if (!AbilitySystemComponent || !AbilityTag.IsValid())
	{
		UE_LOG(LogTronAbilityInput, Warning, TEXT("[%s] AbilityInputComponent: ActivateAbilityByTag failed - invalid parameters"),
		       *GetOwner()->GetName());
		return false;
	}

	// Ищем способность с соответствующим тегом
	FGameplayAbilitySpec* FoundSpec = FindAbilitySpecByTag(AbilityTag);

	// Если нашли способность, активируем её
	if (FoundSpec)
	{
		return ActivateAbilitySpec(FoundSpec, AbilityTag);
	}

	UE_LOG(LogTronAbilityInput, Warning, TEXT("[%s] AbilityInputComponent: No ability found with tag %s"),
	       *GetOwner()->GetName(), *AbilityTag.ToString());

	// Вызываем делегат с отрицательным результатом
	OnAbilityInputActivated.Broadcast(AbilityTag, false);
	OnAbilityActivationFailed.Broadcast(AbilityTag);

	return false;
}

bool UAbilityInputComponent::TryActivateAbilityByTag(FGameplayTag AbilityTag, bool bAllowRemoteActivation)
{
	if (!AbilitySystemComponent || !AbilityTag.IsValid())
	{
		// Если ASC еще не готов, добавляем тег в список ожидания
		if (!AbilitySystemComponent && AbilityTag.IsValid())
		{
			PendingActivationTags.AddUnique(AbilityTag);
			UE_LOG(LogTronAbilityInput, Log, TEXT("[%s] AbilityInputComponent: Added tag %s to pending activations"),
			       *GetOwner()->GetName(), *AbilityTag.ToString());
			return true; // Оптимистично предполагаем, что активация произойдет позже
		}

		return false;
	}

	// Ищем способность с соответствующим тегом
	FGameplayAbilitySpec* FoundSpec = FindAbilitySpecByTag(AbilityTag);

	// Если нашли способность, активируем её
	if (FoundSpec)
	{
		bool bSuccess = AbilitySystemComponent->TryActivateAbility(FoundSpec->Handle, bAllowRemoteActivation);

		// Вызываем делегат с результатом активации
		OnAbilityInputActivated.Broadcast(AbilityTag, bSuccess);

		if (!bSuccess)
		{
			OnAbilityActivationFailed.Broadcast(AbilityTag);
		}

		UE_LOG(LogTronAbilityInput, Log, TEXT("[%s] AbilityInputComponent: TryActivateAbilityByTag %s - %s"),
		       *GetOwner()->GetName(), *AbilityTag.ToString(), bSuccess ? TEXT("SUCCESS") : TEXT("FAILED"));

		return bSuccess;
	}

	UE_LOG(LogTronAbilityInput, Warning, TEXT("[%s] AbilityInputComponent: No ability found with tag %s for TryActivateAbilityByTag"),
	       *GetOwner()->GetName(), *AbilityTag.ToString());

	OnAbilityActivationFailed.Broadcast(AbilityTag);
	return false;
}

bool UAbilityInputComponent::TryActivateAbilityByTagWithContext(FGameplayTag AbilityTag, const FGameplayEventData& EventData)
{
	if (!AbilitySystemComponent || !AbilityTag.IsValid())
	{
		return false;
	}

	// Проверяем наличие способности с указанным тегом
	FGameplayAbilitySpec* FoundSpec = FindAbilitySpecByTag(AbilityTag);
	bool bFoundAbility = (FoundSpec != nullptr);

	if (bFoundAbility)
	{
		// Создаем контейнер тегов для активации
		FGameplayTagContainer TagContainer;
		TagContainer.AddTag(AbilityTag);

		// Версия, которая не вызовет предупреждений компилятора
		// Вместо передачи указателя на EventData, передаем саму структуру
		AbilitySystemComponent->TryActivateAbilitiesByTag(TagContainer);

		// После активации проверяем, стала ли способность активной
		bFoundAbility = FoundSpec->IsActive();
	}

	// Вызываем делегаты в зависимости от результата
	OnAbilityInputActivated.Broadcast(AbilityTag, bFoundAbility);

	if (!bFoundAbility)
	{
		OnAbilityActivationFailed.Broadcast(AbilityTag);
		UE_LOG(LogTronAbilityInput, Warning, TEXT("[%s] AbilityInputComponent: Failed to activate ability with tag %s using context"),
		       *GetOwner()->GetName(), *AbilityTag.ToString());
	}
	else
	{
		UE_LOG(LogTronAbilityInput, Log, TEXT("[%s] AbilityInputComponent: Successfully activated ability with tag %s using context"),
		       *GetOwner()->GetName(), *AbilityTag.ToString());
	}

	return bFoundAbility;
}

bool UAbilityInputComponent::CancelAbilityByTag(FGameplayTag AbilityTag)
{
	if (!AbilitySystemComponent || !AbilityTag.IsValid())
	{
		return false;
	}

	// Проверяем, есть ли активные способности с этим тегом
	bool bHasActiveAbility = false;
	for (const FGameplayAbilitySpec& Spec : AbilitySystemComponent->GetActivatableAbilities())
	{
		if ((Spec.Ability && Spec.Ability->GetAssetTags().HasTag(AbilityTag) ||
				Spec.GetDynamicSpecSourceTags().HasTag(AbilityTag)) &&
			Spec.IsActive())
		{
			bHasActiveAbility = true;
			break;
		}
	}

	if (bHasActiveAbility)
	{
		// Создаем контейнер тегов для отмены
		FGameplayTagContainer TagContainer;
		TagContainer.AddTag(AbilityTag);

		// Вызываем метод отмены (не возвращает результат)
		AbilitySystemComponent->CancelAbilities(&TagContainer);

		UE_LOG(LogTronAbilityInput, Log, TEXT("[%s] AbilityInputComponent: Canceled abilities with tag %s"),
		       *GetOwner()->GetName(), *AbilityTag.ToString());

		return true; // Предполагаем успех, если были активные способности
	}

	return false; // Не было активных способностей с этим тегом
}

bool UAbilityInputComponent::IsAbilityActive(FGameplayTag AbilityTag) const
{
	if (!AbilitySystemComponent || !AbilityTag.IsValid())
	{
		return false;
	}

	// Проверяем, активна ли способность с данным тегом
	FGameplayAbilitySpec* FoundSpec = const_cast<UAbilityInputComponent*>(this)->FindAbilitySpecByTag(AbilityTag);

	return FoundSpec && FoundSpec->IsActive();
}

int32 UAbilityInputComponent::GetAbilityLevel(FGameplayTag AbilityTag) const
{
	if (!AbilitySystemComponent || !AbilityTag.IsValid())
	{
		return 0;
	}

	// Получаем уровень способности с данным тегом
	FGameplayAbilitySpec* FoundSpec = const_cast<UAbilityInputComponent*>(this)->FindAbilitySpecByTag(AbilityTag);

	return FoundSpec ? FoundSpec->Level : 0;
}

void UAbilityInputComponent::OnAbilityInputPressed(const FInputActionValue& InputValue, FAbilityInputBinding Binding)
{
	if (!AbilitySystemComponent || !Binding.AbilityTag.IsValid())
	{
		return;
	}

	// Логируем нажатие клавиши для отладки
	UE_LOG(LogTronAbilityInput, Log, TEXT("[%s] AbilityInputComponent: Input pressed for tag %s"),
	       *GetOwner()->GetName(), *Binding.AbilityTag.ToString());

	// Пытаемся найти способность с соответствующим тегом
	FGameplayAbilitySpec* FoundSpec = FindAbilitySpecByTag(Binding.AbilityTag);

	// Если нашли способность, активируем её
	if (FoundSpec)
	{
		ActivateAbilitySpec(FoundSpec, Binding.AbilityTag);
	}
	else
	{
		UE_LOG(LogTronAbilityInput, Warning, TEXT("[%s] AbilityInputComponent: No ability found with tag %s"),
		       *GetOwner()->GetName(), *Binding.AbilityTag.ToString());

		// Вызываем делегат с отрицательным результатом
		OnAbilityInputActivated.Broadcast(Binding.AbilityTag, false);
		OnAbilityActivationFailed.Broadcast(Binding.AbilityTag);
	}
}

void UAbilityInputComponent::OnAbilityInputReleased(const FInputActionValue& InputValue, FAbilityInputBinding Binding)
{
	if (!AbilitySystemComponent || !Binding.AbilityTag.IsValid())
	{
		return;
	}

	// Обрабатываем отпускание кнопки, если нужно отменить способность
	if (Binding.bCancelOnRelease)
	{
		// Находим активные способности с соответствующим тегом
		FGameplayAbilitySpec* FoundSpec = FindAbilitySpecByTag(Binding.AbilityTag);

		// Если нашли активную способность, отменяем её
		if (FoundSpec && FoundSpec->IsActive())
		{
			AbilitySystemComponent->CancelAbilityHandle(FoundSpec->Handle);
			UE_LOG(LogTronAbilityInput, Log, TEXT("[%s] AbilityInputComponent: Canceled ability with tag %s"),
			       *GetOwner()->GetName(), *Binding.AbilityTag.ToString());
		}
	}
}

FGameplayAbilitySpec* UAbilityInputComponent::FindAbilitySpecByTag(FGameplayTag AbilityTag)
{
	if (!AbilitySystemComponent || !AbilityTag.IsValid())
	{
		return nullptr;
	}

	// Ищем способность с соответствующим тегом в двух местах:
	// 1. В тегах самого класса способности (AbilityTags)
	// 2. В динамических тегах способности (DynamicAbilityTags)
	for (FGameplayAbilitySpec& Spec : AbilitySystemComponent->GetActivatableAbilities())
	{
		if (Spec.Ability)
		{
			// Проверяем теги класса способности
			if (Spec.Ability->GetAssetTags().HasTag(AbilityTag))
			{
				return &Spec;
			}

			// Проверяем динамические теги
			if (Spec.GetDynamicSpecSourceTags().HasTag(AbilityTag))
			{
				return &Spec;
			}
		}
	}

	return nullptr;
}

bool UAbilityInputComponent::ActivateAbilitySpec(FGameplayAbilitySpec* AbilitySpec, FGameplayTag AbilityTag)
{
	if (!AbilitySystemComponent || !AbilitySpec)
	{
		OnAbilityInputActivated.Broadcast(AbilityTag, false);
		OnAbilityActivationFailed.Broadcast(AbilityTag);
		return false;
	}

	bool bSuccess = AbilitySystemComponent->TryActivateAbility(AbilitySpec->Handle);

	// Вызываем делегат с результатом активации
	OnAbilityInputActivated.Broadcast(AbilityTag, bSuccess);

	if (bSuccess)
	{
		UE_LOG(LogTronAbilityInput, Log, TEXT("[%s] AbilityInputComponent: Successfully activated ability with tag %s"),
		       *GetOwner()->GetName(), *AbilityTag.ToString());
	}
	else
	{
		UE_LOG(LogTronAbilityInput, Warning, TEXT("[%s] AbilityInputComponent: Failed to activate ability with tag %s"),
		       *GetOwner()->GetName(), *AbilityTag.ToString());
		OnAbilityActivationFailed.Broadcast(AbilityTag);
	}

	return bSuccess;
}

void UAbilityInputComponent::RebindAbilitiesToInput()
{
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(BoundInputComponent);
	if (!EnhancedInputComponent)
	{
		return;
	}

	// Очищаем существующие привязки для этого объекта
	EnhancedInputComponent->ClearBindingsForObject(this);

	// Заново устанавливаем все привязки
	for (const FAbilityInputBinding& Binding : InputConfig->AbilityBindings)
	{
		if (Binding.InputAction)
		{
			EnhancedInputComponent->BindAction(Binding.InputAction, ETriggerEvent::Started,
			                                   this, &UAbilityInputComponent::OnAbilityInputPressed, Binding);

			EnhancedInputComponent->BindAction(Binding.InputAction, ETriggerEvent::Completed,
			                                   this, &UAbilityInputComponent::OnAbilityInputReleased, Binding);
		}
	}

	UE_LOG(LogTronAbilityInput, Log, TEXT("[%s] AbilityInputComponent: Rebound %d ability inputs"),
	       *GetOwner()->GetName(), InputConfig->AbilityBindings.Num());
}
