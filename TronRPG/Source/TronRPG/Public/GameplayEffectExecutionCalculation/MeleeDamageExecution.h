#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "MeleeDamageExecution.generated.h"

/**
 * Расчет выполнения эффекта урона ближнего боя
 * Обрабатывает модификаторы урона и взаимодействие с атрибутами цели
 */
UCLASS()
class TRONRPG_API UMeleeDamageExecution : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
    
public:
	UMeleeDamageExecution();
    
	virtual void Execute_Implementation(
		const FGameplayEffectCustomExecutionParameters& ExecutionParams,
		OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
    
protected:
	// Ключевые атрибуты для расчета урона
	FGameplayEffectAttributeCaptureDefinition DamageAttributeDef;
	FGameplayEffectAttributeCaptureDefinition AttackPowerDef;
	FGameplayEffectAttributeCaptureDefinition HealthDef;
};