#include "GameplayAbility/MeleeAttackAbility.h"
#include "Character/TronRpgBaseCharacter.h"
#include "AbilitySystemComponent.h"
#include "Animation/AnimMontage.h"
#include "Component/Animation/AnimationComponent.h"
#include "Component/TronRpgComboComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Component/Weapon/WeaponComponent.h"
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
    
	// Проверяем, не находится ли персонаж в процессе экипировки/снятия оружия
	UAbilitySystemComponent* ASC = ActorInfo->AbilitySystemComponent.Get();
	if (ASC && ASC->HasMatchingGameplayTag(TAG_State_Equipment_Changing))
	{
		return false;
	}
    
	// Проверяем, есть ли у персонажа оружие
	UWeaponComponent* WeaponComp = Character->GetWeaponComponent();
	if (!WeaponComp || !WeaponComp->IsWeaponEquipped())
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

	// Получаем компонент ComboComponent
	OwningCharacter = Cast<ATronRpgBaseCharacter>(ActorInfo->AvatarActor.Get());
	if (!OwningCharacter)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}
	
	UTronRpgComboComponent* ComboComp = OwningCharacter->GetComboComponent();
	
	// Проверяем, находимся ли мы в окне комбо
	bool bInComboWindow = ComboComp && ComboComp->IsComboWindowOpen();
	
	// Если мы в окне комбо, продолжаем комбо, иначе начинаем новое
	if (bInComboWindow)
	{
		// Обрабатываем ввод комбо
		ComboComp->ProcessComboInput();
		
		// Получаем текущий счетчик комбо
		CurrentComboCount = ComboComp->GetCurrentComboCount();
	}
	else
	{
		// Сбрасываем комбо и начинаем новое
		if (ComboComp)
		{
			ComboComp->ResetCombo();
		}
		CurrentComboCount = 0;
	}

	// Устанавливаем флаг нажатия кнопки
	bAttackInputPressed = true;

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

void UMeleeAttackAbility::ContinueComboAttack()
{
    // Увеличиваем счетчик комбо
    CurrentComboCount++;
    
    // Закрываем окно комбо
    bCanCombo = false;
    
    // Закрываем UI-уведомление
    UTronRpgComboComponent* ComboComp = OwningCharacter->GetComboComponent();
    if (ComboComp)
    {
        ComboComp->CloseComboWindow();
    }
    
    // Формируем имя секции для нового удара
    FString SectionName = FString::Printf(TEXT("Attack_%d"), CurrentComboCount + 1);
    FName NextSection = FName(*SectionName);
    
    // Проверяем, что секция существует
    if (AttackMontage->GetSectionIndex(NextSection) == INDEX_NONE)
    {
        UE_LOG(LogTemp, Warning, TEXT("Section %s not found, using default"), *NextSection.ToString());
        NextSection = FName("Attack_1");
    }
    
    // Непосредственно переходим к следующей секции монтажа
    UAnimationComponent* AnimComp = OwningCharacter->GetAnimationComponent();
    if (AnimComp)
    {
        AnimComp->JumpToMontageSection(NextSection);
        CurrentAttackSection = NextSection;
        
        UE_LOG(LogTemp, Log, TEXT("Jumped to next combo section: %s"), *NextSection.ToString());
    }
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
	
	UE_LOG(LogTemp, Log, TEXT("Executing attack: %s, section: %s, combo count: %d"), 
	       *AttackMontage->GetName(), *CurrentAttackSection.ToString(), CurrentComboCount);
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
    // Обрабатываем уведомление об открытии окна комбо
    if (NotifyName == FName("ComboWindow"))
    {
        bCanCombo = true;
        
        // Если есть компонент комбо, открываем в нем окно
        if (OwningCharacter)
        {
            UTronRpgComboComponent* ComboComp = OwningCharacter->GetComboComponent();
            if (ComboComp)
            {
                ComboComp->OpenComboWindow();
            }
        }
        
        UE_LOG(LogTemp, Log, TEXT("ComboWindow opened for combo count: %d"), CurrentComboCount);
    }
    else if (NotifyName == FName("ApplyDamage"))
    {
        // Просто логируем событие, не реализуя логику урона
        UE_LOG(LogTemp, Log, TEXT("ApplyDamage notify received in combo %d"), CurrentComboCount);
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