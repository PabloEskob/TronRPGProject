#include "GameplayEffectExecutionCalculation/MeleeDamageExecution.h"
#include "GAS/TronRpgAttributeSet.h"
#include "Object/GameplayTagsLibrary.h"
#include "AbilitySystemComponent.h"
#include "TronRPG/TronRPG.h"

UMeleeDamageExecution::UMeleeDamageExecution()
{
	// Инициализация структуры для захвата атрибутов
	RelevantAttributesToCapture.Add(
		FGameplayEffectAttributeCaptureDefinition(
			UTronRpgAttributeSet::GetDamageAttribute(),
			EGameplayEffectAttributeCaptureSource::Source,
			true
		)
	);

	RelevantAttributesToCapture.Add(
		FGameplayEffectAttributeCaptureDefinition(
			UTronRpgAttributeSet::GetAttackPowerAttribute(),
			EGameplayEffectAttributeCaptureSource::Source,
			true
		)
	);

	RelevantAttributesToCapture.Add(
		FGameplayEffectAttributeCaptureDefinition(
			UTronRpgAttributeSet::GetHealthAttribute(),
			EGameplayEffectAttributeCaptureSource::Target,
			true
		)
	);

	// Сохраняем определения для использования в Execute
	DamageAttributeDef = FGameplayEffectAttributeCaptureDefinition(
		UTronRpgAttributeSet::GetDamageAttribute(),
		EGameplayEffectAttributeCaptureSource::Source,
		true
	);

	AttackPowerDef = FGameplayEffectAttributeCaptureDefinition(
		UTronRpgAttributeSet::GetAttackPowerAttribute(),
		EGameplayEffectAttributeCaptureSource::Source,
		true
	);

	HealthDef = FGameplayEffectAttributeCaptureDefinition(
		UTronRpgAttributeSet::GetHealthAttribute(),
		EGameplayEffectAttributeCaptureSource::Target,
		true
	);
}

void UMeleeDamageExecution::Execute_Implementation(
	const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	FGameplayEffectSpec GameplayEffectSpec = ExecutionParams.GetOwningSpec();
	// Создаем контекст для захвата атрибутов
	FGameplayEffectSpec& Spec = GameplayEffectSpec;

	// Получаем теги из эффекта
	FGameplayTagContainer AssetTags;
	Spec.GetAllAssetTags(AssetTags);

	// Захватываем атрибуты источника и цели
	FAggregatorEvaluateParameters EvalParams;
	EvalParams.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvalParams.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	// Захватываем базовый урон
	float BaseDamage = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageAttributeDef, EvalParams, BaseDamage);

	// Если есть SetByCaller для урона, используем его
	float SetByCallerDamage = Spec.GetSetByCallerMagnitude(TAG_Damage, false, 0.0f);
	if (SetByCallerDamage > 0.0f)
	{
		BaseDamage = SetByCallerDamage;
	}

	// Захватываем силу атаки источника
	float AttackPower = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(AttackPowerDef, EvalParams, AttackPower);

	// Расчёт итогового урона
	float FinalDamage = BaseDamage + (AttackPower * 0.1f); // 10% бонус от силы атаки

	// Проверяем, является ли атака критической
	if (AssetTags.HasTag(TAG_Damage_Critical))
	{
		FinalDamage *= 2.0f; // Критический урон
		UE_LOG(LogWeaponSystem, Log, TEXT("Critical Hit! Damage increased to %.1f"), FinalDamage);
	}

	// Защита от отрицательного урона
	FinalDamage = FMath::Max(0.0f, FinalDamage);

	// Выводим отладочную информацию
	UE_LOG(LogWeaponSystem, Log, TEXT("Melee Damage Execution: Base=%.1f, AP=%.1f, Final=%.1f"),
	       BaseDamage, AttackPower, FinalDamage);

	// Применяем изменение здоровья
	if (FinalDamage > 0.0f)
	{
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(
				UTronRpgAttributeSet::GetHealthAttribute(),
				EGameplayModOp::Additive,
				-FinalDamage
			)
		);
	}
}
