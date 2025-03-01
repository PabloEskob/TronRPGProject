// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayTagContainer.h"
#include "MeleeAttackAbility.generated.h"

class ATronRpgBaseCharacter;
class UAnimMontage;
class UCurveFloat;

/**
 * Настройки для атаки ближнего боя
 */
USTRUCT(BlueprintType)
struct FMeleeAttackConfig
{
    GENERATED_BODY()

    /** Базовый урон атаки */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
    float BaseDamage = 20.0f;

    /** Радиус атаки */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage", meta = (ClampMin = "10.0"))
    float AttackRadius = 150.0f;

    /** Угол атаки (в градусах) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage", meta = (ClampMin = "0.0", ClampMax = "180.0"))
    float AttackAngle = 60.0f;

    /** Множитель критического урона */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage", meta = (ClampMin = "1.0"))
    float CriticalMultiplier = 2.0f;

    /** Шанс критического удара (0.0 - 1.0) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage", meta = (ClampMin = "0.0", ClampMax = "1.0"))
    float CriticalChance = 0.1f;

    /** Теги, которые должны быть у цели для получения урона */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targeting")
    FGameplayTagContainer TargetRequiredTags;

    /** Теги, которые блокируют нанесение урона цели */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targeting")
    FGameplayTagContainer TargetBlockedTags;
};

/**
 * Способность атаки ближнего боя
 * Обрабатывает логику нанесения урона, проигрывания анимаций и комбо-атак
 */
UCLASS()
class TRONRPG_API UMeleeAttackAbility : public UGameplayAbility
{
    GENERATED_BODY()

public:
    UMeleeAttackAbility();

    /**
     * Активация способности
     */
    virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                               const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

    /**
     * Отмена способности
     */
    virtual void CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                              const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility) override;

    /**
     * Проверка возможности активации способности
     */
    virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                  const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags,
                                  OUT FGameplayTagContainer* OptionalRelevantTags) const override;

protected:
    /** Анимационный монтаж атаки */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
    UAnimMontage* MeleeAttackMontage;

    /** Настройки атаки ближнего боя */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attack")
    FMeleeAttackConfig AttackConfig;

    /** Массив возможных атакуемых костей (имена сокетов) */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attack")
    TArray<FName> WeaponTraceSocketNames;

    /** Кривая изменения урона в зависимости от комбо */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attack")
    UCurveFloat* ComboDamageCurve;

    /** Максимальное количество комбо-ударов */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combo", meta = (ClampMin = "1"))
    int32 MaxComboCount = 3;

    /** Префикс секции в монтаже для комбо (например, Attack_1, Attack_2, ...) */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combo")
    FString ComboSectionPrefix = "Attack_";

    /** Событие для нанесения урона (вызывается из AnimNotify) */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gameplay Cues")
    FGameplayTag DamageEventTag;

    /** Эффект, применяемый при нанесении урона */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects")
    TSubclassOf<UGameplayEffect> DamageEffect;

    /**
     * Получение имени секции монтажа на основе текущего комбо
     * @param ComboCount Текущий счетчик комбо
     * @return Имя секции для воспроизведения
     */
    FName GetMontageSectionName(int32 ComboCount) const;

    /**
     * Применение урона к целям в радиусе атаки
     * @param SourceCharacter Персонаж, выполняющий атаку
     * @param ComboCount Текущий счетчик комбо для расчета урона
     */
    UFUNCTION()
    void ApplyDamageToTargets(ATronRpgBaseCharacter* SourceCharacter, int32 ComboCount);

    /**
     * Callback для обработки события нанесения урона
     * Вызывается из Animation Notify
     */
    UFUNCTION()
    void OnApplyDamageNotify(FName NotifyName);

    /**
     * Обработчик завершения монтажа
     * @param Montage Завершившийся монтаж
     * @param bInterrupted Флаг прерывания монтажа
     */
    UFUNCTION()
    void OnMontageComplete(UAnimMontage* Montage, bool bInterrupted);

    /**
     * Проверка возможности нанесения урона цели
     * @param Target Целевой актор
     * @return true если цель может получить урон
     */
    bool CanApplyDamageToTarget(AActor* Target) const;

    /**
     * Поиск потенциальных целей для атаки
     * @param SourceCharacter Атакующий персонаж
     * @return Массив целей в радиусе атаки
     */
    TArray<AActor*> FindTargetsInAttackRange(ATronRpgBaseCharacter* SourceCharacter) const;

    /**
     * Расчет фактического урона атаки
     * @param ComboCount Текущий счетчик комбо
     * @param bIsCritical Флаг критического удара
     * @return Значение урона
     */
    float CalculateDamage(int32 ComboCount, bool& bIsCritical) const;

    /**
     * Создание контекста нанесения урона
     * @param Target Целевой актор
     * @param DamageAmount Величина урона
     * @param bIsCritical Флаг критического удара
     * @return Спецификация эффекта для нанесения урона
     */
    FGameplayEffectSpecHandle CreateDamageEffectSpec(AActor* Target, float DamageAmount, bool bIsCritical);
};