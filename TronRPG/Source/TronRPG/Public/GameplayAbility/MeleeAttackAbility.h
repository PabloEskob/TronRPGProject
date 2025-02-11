// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "MeleeAttackAbility.generated.h"

/**
 * 
 */
UCLASS()
class TRONRPG_API UMeleeAttackAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UMeleeAttackAbility();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	                             const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

protected:
	
	// Ссылка на Animation Montage, которую можно задать в настройках (по умолчанию через Blueprint)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* MeleeAttackMontage;

	// Вспомогательная функция для выбора секции Montage на основе текущего комбо
	FName GetMontageSectionName(int32 ComboCount) const;

	// Callback, который можно вызывать через Animation Notify для применения урона
	UFUNCTION()
	void OnApplyDamageNotify();
};
