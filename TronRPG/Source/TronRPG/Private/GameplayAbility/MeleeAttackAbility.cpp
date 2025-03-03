#include "GameplayAbility/MeleeAttackAbility.h"
#include "Character/TronRpgBaseCharacter.h"
#include "AbilitySystemComponent.h"
#include "Animation/AnimMontage.h"
#include "Component/Animation/AnimationComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
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
}

void UMeleeAttackAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	// Получаем ссылку на владельца
	OwningCharacter = Cast<ATronRpgBaseCharacter>(ActorInfo->AvatarActor.Get());

	if (OwningCharacter)
	{
		// Подключаемся к делегату анимационного уведомления
		UAnimationComponent* AnimComp = OwningCharacter->GetAnimationComponent();
		if (AnimComp)
		{
			AnimComp->OnMontageNotifyBegin.AddDynamic(this, &UMeleeAttackAbility::OnAnimNotifyBegin);
		}
	}
}

void UMeleeAttackAbility::OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	// Отключаемся от делегата при удалении способности
	if (OwningCharacter)
	{
		UAnimationComponent* AnimComp = OwningCharacter->GetAnimationComponent();
		if (AnimComp)
		{
			AnimComp->OnMontageNotifyBegin.RemoveDynamic(this, &UMeleeAttackAbility::OnAnimNotifyBegin);
		}
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

	// Проверяем, что у персонажа есть меч
	const ATronRpgBaseCharacter* Character = Cast<ATronRpgBaseCharacter>(ActorInfo->AvatarActor.Get());
	if (!Character)
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
	CurrentActorInfo = ActorInfo;
	CurrentActivationInfo = ActivationInfo;

	// Сбрасываем флаг ввода
	bAttackInputPressed = false;

	AttackMontage = DefaultAttackMontage;
	// Выполняем атаку
	ExecuteAttack();
}

void UMeleeAttackAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                     const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	// Сбрасываем флаги состояния
	bCanCombo = false;
	bApplyingDamage = false;

	// Останавливаем таймер проверки комбо
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(ComboCheckTimerHandle);
	}

	// Отключаем обработчик завершения монтажа и останавливаем монтаж
	if (OwningCharacter)
	{
		UAnimationComponent* AnimComp = OwningCharacter->GetAnimationComponent();
		if (AnimComp)
		{
			AnimComp->OnMontageEnded.RemoveDynamic(this, &UMeleeAttackAbility::OnAttackMontageEnded);

			if (bWasCancelled && AttackMontage)
			{
				AnimComp->StopMontage(AttackMontage);
			}
		}
	}

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}


void UMeleeAttackAbility::ExecuteAttack()
{
	if (!OwningCharacter)
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
		return;
	}

	// Выбираем подходящий монтаж и секцию для текущего удара
	if (!SelectAttackMontageAndSection())
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
		return;
	}

	// Воспроизводим анимацию атаки
	float MontageLength = OwningCharacter->Execute_PlayAttackAnimation(OwningCharacter, AttackMontage, 1.0f, CurrentAttackSection);
	
	// Настраиваем автоматическое завершение способности по окончании анимации
	UAnimationComponent* AnimComp = OwningCharacter->GetAnimationComponent();
	if (AnimComp)
	{
		// Убедимся, что обработчик ещё не добавлен
		AnimComp->OnMontageEnded.RemoveDynamic(this, &UMeleeAttackAbility::OnAttackMontageEnded);
		AnimComp->OnMontageEnded.AddDynamic(this, &UMeleeAttackAbility::OnAttackMontageEnded);
	}
}

UAnimMontage* UMeleeAttackAbility::SelectAppropriateAttackMontage()
{
	if (!OwningCharacter)
	{
		return DefaultAttackMontage;
	}
	
	return DefaultAttackMontage;
}

bool UMeleeAttackAbility::SelectAttackMontageAndSection()
{
	// Проверяем, доступен ли комбо-удар
	if (bCanCombo && bAttackInputPressed && CurrentComboCount < MaxComboCount - 1)
	{
		// Увеличиваем счетчик комбо
		CurrentComboCount++;
	}
	else
	{
		// Начинаем новую серию ударов
		CurrentComboCount = 0;
		bCanCombo = false;
	}

	// Выбираем подходящий монтаж для текущего оружия

	// Проверяем наличие монтажа
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

	return true;
}

void UMeleeAttackAbility::OnAnimNotifyBegin(FName NotifyName)
{
	// Обрабатываем различные типы уведомлений анимации

	// Уведомление о нанесении урона
	if (NotifyName == FName("ApplyDamage") && !bApplyingDamage)
	{
		bApplyingDamage = true;
		ApplyDamage();
		bApplyingDamage = false;
	}
	// Уведомление об открытии окна комбо
	else if (NotifyName == FName("ComboWindow"))
	{
		bCanCombo = true;
		// Запускаем таймер для проверки ввода
		if (GetWorld())
		{
			GetWorld()->GetTimerManager().ClearTimer(ComboCheckTimerHandle);
			GetWorld()->GetTimerManager().SetTimer(
				ComboCheckTimerHandle,
				this,
				&UMeleeAttackAbility::CheckComboInput,
				0.05f,
				true);
		}
	}
}

void UMeleeAttackAbility::ApplyDamage()
{
	// Заглушка для метода нанесения урона
	// Реализация будет добавлена позже
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
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, false, false);

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
	}
}

void UMeleeAttackAbility::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	// Отключаем обработчик завершения монтажа
	if (OwningCharacter)
	{
		UAnimationComponent* AnimComp = OwningCharacter->GetAnimationComponent();
		if (AnimComp)
		{
			AnimComp->OnMontageEnded.RemoveDynamic(this, &UMeleeAttackAbility::OnAttackMontageEnded);
		}
	}

	// Завершаем способность, если окно комбо закрыто
	if (Montage == AttackMontage && !bCanCombo)
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, bInterrupted);
	}
}
