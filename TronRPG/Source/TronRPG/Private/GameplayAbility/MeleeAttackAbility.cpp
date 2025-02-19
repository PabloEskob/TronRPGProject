// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/MeleeAttackAbility.h"

#include "Character/TronRpgBaseCharacter.h"
#include "Component/TronRpgComboComponent.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "GameplayCueManager.h"
#include "AbilitySystemGlobals.h"
#include "Object/GameplayTagsLibrary.h"

UMeleeAttackAbility::UMeleeAttackAbility()
{
	// Настраиваем политику инстанцирования (на случай, если способность используется разными акторами)
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UMeleeAttackAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	// Проверяем валидность ActorInfo
	if (!ActorInfo || !ActorInfo->AvatarActor.IsValid())
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		return;
	}

	// Приводим нашего актёра к базовому классу
	ATronRpgBaseCharacter* BaseCharacter = Cast<ATronRpgBaseCharacter>(ActorInfo->AvatarActor.Get());
	if (!BaseCharacter)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		return;
	}

	// Получаем компонент комбо
	UTronRpgComboComponent* ComboComp = BaseCharacter->FindComponentByClass<UTronRpgComboComponent>();
	int32 CurrentCombo = (ComboComp) ? ComboComp->ComboCount : 0;

	// Выбираем нужную секцию Montage
	FName MontageSection = GetMontageSectionName(CurrentCombo);

	// Запускаем анимацию атаки
	if (MeleeAttackMontage)
	{
		float PlayRate = 1.0f;
		BaseCharacter->PlayAnimMontage(MeleeAttackMontage, PlayRate, MontageSection);
	}

	// Вызываем Gameplay Cue для визуальных эффектов атаки
	{
		FGameplayCueParameters CueParams;
		CueParams.Location = BaseCharacter->GetActorLocation();
		// Предположим, что в UGameplayTagsLibrary определён статический тег Attack_Melee
		UAbilitySystemGlobals::Get().GetGameplayCueManager()->HandleGameplayCue(
			BaseCharacter,
			GameplayTags::Attack::Melee,
			EGameplayCueEvent::Executed,
			CueParams);
	}

	// Инкрементируем комбо и устанавливаем таймер сброса (логика должна быть внутри ComboComponent)
	if (ComboComp)
	{
		ComboComp->IncrementCombo();
	}

	// Если Ability должна быть завершена сразу или позже по завершению анимации – завершите её здесь или в callback'е
	EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
}

FName UMeleeAttackAbility::GetMontageSectionName(int32 ComboCount) const
{
	// Пример: если ComboCount равен 0 – первый удар, 1 – второй, и т.д.
	FString SectionName = FString::Printf(TEXT("Attack_%d"), ComboCount + 1);
	return FName(*SectionName);
}

void UMeleeAttackAbility::OnApplyDamageNotify()
{
}
