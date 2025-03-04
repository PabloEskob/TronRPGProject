#include "GameplayAbility/MeleeAttackAbility.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Animation/AnimMontage.h"
#include "Interface/Weapon/MeleeAttackInterface.h"
#include "Component/Animation/AnimationComponent.h"
#include "Component/TronRpgComboComponent.h"
#include "Object/GameplayTagsLibrary.h"

UMeleeAttackAbility::UMeleeAttackAbility()
{
	// Настраиваем класс по умолчанию
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;

	// Определяем теги способности с использованием SetAssetTags
	FGameplayTagContainer NewAssetTags;
	NewAssetTags.AddTag(TAG_Ability_Combat_Melee);
	SetAssetTags(NewAssetTags);

	// Определяем теги, добавляемые при активации
	ActivationOwnedTags.AddTag(TAG_State_Attacking);

	// Определяем блокирующие теги
	SourceBlockedTags.AddTag(TAG_State_Dead);
	SourceBlockedTags.AddTag(TAG_State_Disabled);
	SourceBlockedTags.AddTag(TAG_State_Stunned);

	// Настройки стоимости способности
	CostGameplayEffectClass = nullptr; // В данной версии не используем стоимость

	// Настройки внутренних значений
	MaxComboCount = 3;
	CurrentComboCount = 0;
	bCanCombo = false;
	bApplyingDamage = false;
	bAttackInputPressed = false;
	BaseDamage = 20.0f;
	DamageRadius = 150.0f;
	ComboWindowTime = 0.4f;
	AttackState = EMeleeAttackState::Idle;
}

void UMeleeAttackAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	// Сохраняем ссылку на владельца и ActorInfo
	OwningActor = ActorInfo->AvatarActor.Get();
	CachedActorInfo = ActorInfo;

	if (OwningActor)
	{
		// Ищем AnimationComponent и подписываемся на его события
		UAnimationComponent* AnimComp = nullptr;
		IMeleeAttackInterface* MeleeInterface = Cast<IMeleeAttackInterface>(OwningActor);

		if (MeleeInterface)
		{
			// Здесь можно получить AnimationComponent через интерфейс
			// Но для этого нужно добавить соответствующий метод в интерфейс
		}

		// Если нашли компонент, подписываемся на события уведомлений анимации
		if (AnimComp)
		{
			AnimComp->OnMontageNotifyBegin.AddDynamic(this, &UMeleeAttackAbility::OnAnimNotifyBegin);
			UE_LOG(LogTemp, Log, TEXT("Subscribed to animation notify events"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to find AnimationComponent for subscribing to events"));
		}
	}
}

void UMeleeAttackAbility::OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	// Отключаемся от делегатов при удалении способности
	if (OwningActor)
	{
		// Здесь отписываемся от событий
		// Например, от событий AnimationComponent
	}

	Super::OnRemoveAbility(ActorInfo, Spec);
}

bool UMeleeAttackAbility::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                             const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags,
                                             FGameplayTagContainer* OptionalRelevantTags) const
{
	// Проверяем базовые условия активации
	if (!Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags))
	{
		return false;
	}

	// Получаем интерфейс MeleeAttack у владельца
	IMeleeAttackInterface* MeleeInterface = Cast<IMeleeAttackInterface>(ActorInfo->AvatarActor.Get());
	if (!MeleeInterface)
	{
		return false;
	}

	// Проверяем, не находится ли персонаж в процессе экипировки/снятия оружия
	UAbilitySystemComponent* ASC = ActorInfo->AbilitySystemComponent.Get();
	if (!ASC && ASC->HasMatchingGameplayTag(TAG_State_Equipment_Changing))
	{
		return false;
	}

	// Проверяем, есть ли у персонажа оружие
	if (!IMeleeAttackInterface::Execute_HasWeaponWithTag(ActorInfo->AvatarActor.Get(), TAG_WeaponType_Sword) &&
		!IMeleeAttackInterface::Execute_HasWeaponWithTag(ActorInfo->AvatarActor.Get(), TAG_WeaponType_SwordAndShield))
	{
		return false;
	}

	return true;
}

void UMeleeAttackAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                          const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	// Вызываем базовую реализацию активации
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	// Сохраняем текущий контекст
	CurrentSpecHandle = Handle;
	CachedActorInfo = ActorInfo;
	CurrentActivationInfo = ActivationInfo;

	// Получаем интерфейс MeleeAttack у владельца
	IMeleeAttackInterface* MeleeInterface = Cast<IMeleeAttackInterface>(ActorInfo->AvatarActor.Get());
	if (!MeleeInterface)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	// Получаем текущий счетчик комбо
	CurrentComboCount = IMeleeAttackInterface::Execute_GetComboCount(ActorInfo->AvatarActor.Get());

	// Устанавливаем флаг нажатия кнопки
	bAttackInputPressed = true;

	// Устанавливаем состояние атаки
	SetAttackState(EMeleeAttackState::Attacking);

	// Выбираем подходящий монтаж атаки
	AttackMontage = SelectAppropriateAttackMontage();

	// Выполняем атаку
	ExecuteAttack();
}

void UMeleeAttackAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                     const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	// Сбрасываем флаги состояния
	bCanCombo = false;
	bApplyingDamage = false;
	AttackState = EMeleeAttackState::Idle;

	// Останавливаем таймер проверки комбо
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(ComboCheckTimerHandle);
	}

	// Отписываемся от события завершения монтажа
	if (OwningActor)
	{
		// Отписка от событий AnimationComponent если необходимо
	}

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UMeleeAttackAbility::SetAttackState(EMeleeAttackState NewState)
{
	if (AttackState != NewState)
	{
		EMeleeAttackState OldState = AttackState;
		AttackState = NewState;

		// Обработка изменения состояния
		switch (NewState)
		{
		case EMeleeAttackState::Attacking:
			// Начало атаки
			break;

		case EMeleeAttackState::ComboWindow:
			// Открытие окна комбо
			bCanCombo = true;

		// Оповещаем интерфейс для открытия окна комбо
			if (OwningActor)
			{
				IMeleeAttackInterface* MeleeInterface = Cast<IMeleeAttackInterface>(OwningActor);
				if (MeleeInterface)
				{
					// Через интерфейс можно открыть окно комбо
					UTronRpgComboComponent* ComboComp = Cast<UTronRpgComboComponent>(
						IMeleeAttackInterface::Execute_GetComboComponent(OwningActor));

					if (ComboComp)
					{
						ComboComp->OpenComboWindow();
					}
				}
			}
			break;

		case EMeleeAttackState::ApplyingDamage:
			// Применение урона
			ApplyDamage();
			break;

		case EMeleeAttackState::Cancelling:
			// Отмена способности
			if (CurrentSpecHandle.IsValid() && CachedActorInfo)
			{
				EndAbility(CurrentSpecHandle, CachedActorInfo, CurrentActivationInfo, true, true);
			}
			break;

		case EMeleeAttackState::Idle:
			// Возврат в исходное состояние
			if (OldState != EMeleeAttackState::Idle && CurrentSpecHandle.IsValid() && CachedActorInfo)
			{
				EndAbility(CurrentSpecHandle, CachedActorInfo, CurrentActivationInfo, true, false);
			}
			break;
		}
	}
}

bool UMeleeAttackAbility::ContinueComboAttack()
{
	// Проверяем, не достигнут ли максимум комбо
	if (CurrentComboCount >= MaxComboCount - 1)
	{
		UE_LOG(LogTemp, Warning, TEXT("Maximum combo count reached in ability, ending"));

		// Завершаем способность
		if (CachedActorInfo && CurrentSpecHandle.IsValid())
		{
			EndAbility(CurrentSpecHandle, CachedActorInfo, CurrentActivationInfo, true, false);
		}
		return false;
	}

	// Увеличиваем счетчик комбо
	CurrentComboCount++;

	// Закрываем окно комбо
	bCanCombo = false;

	UE_LOG(LogTemp, Log, TEXT("ContinueComboAttack - Current combo: %d"), CurrentComboCount);

	// Формируем имя секции для нового удара
	FString SectionName = FString::Printf(TEXT("Attack_%d"), CurrentComboCount + 1);
	FName NextSection = FName(*SectionName);

	// Проверяем, что секция существует
	if (AttackMontage && AttackMontage->GetSectionIndex(NextSection) == INDEX_NONE)
	{
		UE_LOG(LogTemp, Warning, TEXT("Section %s not found, using default"), *NextSection.ToString());
		NextSection = FName("Attack_1");
	}

	// Переходим к следующей секции монтажа через интерфейс
	if (OwningActor)
	{
		IMeleeAttackInterface* MeleeInterface = Cast<IMeleeAttackInterface>(OwningActor);
		if (MeleeInterface)
		{
			// Сохраняем текущую секцию
			CurrentAttackSection = NextSection;

			// Используем интерфейс для перехода к следующей секции
			float MontageLength = IMeleeAttackInterface::Execute_PlayAttackAnimation(
				OwningActor, AttackMontage, 1.0f, NextSection);

			UE_LOG(LogTemp, Log, TEXT("Jumped to next combo section: %s"), *NextSection.ToString());
			return true;
		}
	}

	return false;
}

void UMeleeAttackAbility::ExecuteAttack()
{
	if (!OwningActor)
	{
		EndAbility(CurrentSpecHandle, CachedActorInfo, CurrentActivationInfo, true, true);
		return;
	}

	// Выбираем подходящий монтаж и секцию для текущего удара
	if (!SelectAttackMontageAndSection())
	{
		EndAbility(CurrentSpecHandle, CachedActorInfo, CurrentActivationInfo, true, true);
		return;
	}

	// Воспроизводим анимацию атаки через интерфейс
	IMeleeAttackInterface* MeleeInterface = Cast<IMeleeAttackInterface>(OwningActor);
	if (MeleeInterface)
	{
		float MontageLength = IMeleeAttackInterface::Execute_PlayAttackAnimation(
			OwningActor, AttackMontage, 1.0f, CurrentAttackSection);

		// Подписываемся на завершение монтажа через компонент анимации
		UAnimationComponent* AnimComp = Cast<UAnimationComponent>(
			IMeleeAttackInterface::Execute_GetAnimationComponent(OwningActor));

		if (AnimComp)
		{
			AnimComp->OnMontageEnded.AddDynamic(this, &UMeleeAttackAbility::OnAttackMontageEnded);
		}

		UE_LOG(LogTemp, Log, TEXT("Executing attack: %s, section: %s, combo count: %d"),
		       *AttackMontage->GetName(), *CurrentAttackSection.ToString(), CurrentComboCount);
	}
	else
	{
		EndAbility(CurrentSpecHandle, CachedActorInfo, CurrentActivationInfo, true, true);
	}
}

UAnimMontage* UMeleeAttackAbility::SelectAppropriateAttackMontage()
{
	if (!OwningActor)
	{
		return DefaultAttackMontage;
	}

	// Выбираем монтаж на основе типа оружия через интерфейс
	IMeleeAttackInterface* MeleeInterface = Cast<IMeleeAttackInterface>(OwningActor);
	if (MeleeInterface)
	{
		if (IMeleeAttackInterface::Execute_HasWeaponWithTag(OwningActor, TAG_WeaponType_Sword))
		{
			UAnimMontage* const* FoundMontage = WeaponTypeAttackMontages.Find(TAG_WeaponType_Sword);
			if (FoundMontage && *FoundMontage)
			{
				return *FoundMontage;
			}
		}
		else if (IMeleeAttackInterface::Execute_HasWeaponWithTag(OwningActor, TAG_WeaponType_SwordAndShield))
		{
			UAnimMontage* const* FoundMontage = WeaponTypeAttackMontages.Find(TAG_WeaponType_SwordAndShield);
			if (FoundMontage && *FoundMontage)
			{
				return *FoundMontage;
			}
		}
	}

	return DefaultAttackMontage;
}

bool UMeleeAttackAbility::SelectAttackMontageAndSection()
{
	// Выбираем подходящий монтаж для текущего оружия
	if (!AttackMontage)
	{
		UE_LOG(LogTemp, Error, TEXT("MeleeAttackAbility: No valid attack montage available!"));
		return false;
	}

	// Формируем имя секции на основе текущего счетчика комбо
	FString SectionName = FString::Printf(TEXT("Attack_%d"), CurrentComboCount + 1);
	CurrentAttackSection = FName(*SectionName);

	// Проверяем, что секция существует в монтаже
	if (AttackMontage->GetSectionIndex(CurrentAttackSection) == INDEX_NONE)
	{
		UE_LOG(LogTemp, Warning, TEXT("MeleeAttackAbility: Section %s not found in montage %s. Using default section."),
		       *CurrentAttackSection.ToString(), *AttackMontage->GetName());
		CurrentAttackSection = FName("Attack_1");
	}

	UE_LOG(LogTemp, Log, TEXT("Selected attack section: %s for combo count: %d"),
	       *CurrentAttackSection.ToString(), CurrentComboCount);

	return true;
}

void UMeleeAttackAbility::OnAnimNotifyBegin(FName NotifyName)
{
	if (NotifyName == FName("ComboWindow"))
	{
		// Переход в состояние окна комбо
		SetAttackState(EMeleeAttackState::ComboWindow);
	}
	else if (NotifyName == FName("ApplyDamage"))
	{
		// Переход в состояние применения урона
		SetAttackState(EMeleeAttackState::ApplyingDamage);
	}
}

void UMeleeAttackAbility::ApplyDamage()
{
	// Реализация применения урона через GameplayEffect
	if (!OwningActor || !DamageEffectClass)
		return;

	UAbilitySystemComponent* ASC = GetAbilitySystemComponentFromActorInfo();
	if (!ASC)
		return;

	// Создаем контекст эффекта
	FGameplayEffectContextHandle EffectContext = ASC->MakeEffectContext();
	EffectContext.AddSourceObject(OwningActor);

	// Создаем спецификацию эффекта
	FGameplayEffectSpecHandle SpecHandle = ASC->MakeOutgoingSpec(
		DamageEffectClass, 1.0f, EffectContext);

	if (SpecHandle.IsValid())
	{
		// Устанавливаем величину урона
		float DamageAmount = BaseDamage * (1.0f + CurrentComboCount * 0.2f);

		// Проверяем на критический удар
		bool bIsCritical = FMath::RandRange(0.0f, 1.0f) < CriticalChance;
		if (bIsCritical)
		{
			DamageAmount *= CriticalMultiplier;
			// Добавляем тег критического урона
			SpecHandle.Data->SetSetByCallerMagnitude(TAG_Damage_Critical, 1.0f);
		}

		// Устанавливаем величину урона
		SpecHandle.Data->SetSetByCallerMagnitude(TAG_Damage, DamageAmount);

		// Поиск целей для применения урона можно реализовать в будущем
	}
}

void UMeleeAttackAbility::CheckComboInput()
{
	if (bCanCombo && bAttackInputPressed)
	{
		bAttackInputPressed = false; // Сбрасываем флаг ввода
		bCanCombo = false; // Закрываем окно комбо

		if (GetWorld())
		{
			GetWorld()->GetTimerManager().ClearTimer(ComboCheckTimerHandle);
		}

		// Завершаем текущую способность и активируем заново для следующего удара
		EndAbility(CurrentSpecHandle, CachedActorInfo, CurrentActivationInfo, false, false);

		// Пытаемся активировать следующий удар, если ASC доступен
		UAbilitySystemComponent* ASC = GetAbilitySystemComponentFromActorInfo();
		if (ASC)
		{
			ASC->TryActivateAbilityByClass(GetClass());
		}
	}
}

void UMeleeAttackAbility::CloseComboWindow()
{
	if (bCanCombo)
	{
		bCanCombo = false;

		if (GetWorld())
		{
			GetWorld()->GetTimerManager().ClearTimer(ComboCheckTimerHandle);
		}

		// Сообщаем компоненту комбо о закрытии окна
		if (OwningActor)
		{
			IMeleeAttackInterface* MeleeInterface = Cast<IMeleeAttackInterface>(OwningActor);
			if (MeleeInterface)
			{
				UTronRpgComboComponent* ComboComp = Cast<UTronRpgComboComponent>(
					IMeleeAttackInterface::Execute_GetComboComponent(OwningActor));

				if (ComboComp)
				{
					ComboComp->CloseComboWindow();
				}
			}
		}
	}
}

void UMeleeAttackAbility::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	UE_LOG(LogTemp, Log, TEXT("Attack montage ended: %s, Interrupted: %s"),
	       *Montage->GetName(), bInterrupted ? TEXT("true") : TEXT("false"));

	// Отключаем обработчик завершения монтажа
	if (OwningActor)
	{
		IMeleeAttackInterface* MeleeInterface = Cast<IMeleeAttackInterface>(OwningActor);
		if (MeleeInterface)
		{
			UAnimationComponent* AnimComp = Cast<UAnimationComponent>(
				IMeleeAttackInterface::Execute_GetAnimationComponent(OwningActor));

			if (AnimComp)
			{
				AnimComp->OnMontageEnded.RemoveDynamic(this, &UMeleeAttackAbility::OnAttackMontageEnded);
			}
		}
	}

	// Завершаем способность, если это наш монтаж
	if (Montage == AttackMontage)
	{
		EndAbility(CurrentSpecHandle, CachedActorInfo, CurrentActivationInfo, true, bInterrupted);
	}
}
