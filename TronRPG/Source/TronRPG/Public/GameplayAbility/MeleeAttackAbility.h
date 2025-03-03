#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayTagContainer.h"
#include "GameplayEffect.h"
#include "Config/MeleeAttackConfig.h"
#include "Engine/DataTable.h"
#include "MeleeAttackAbility.generated.h"

class ATronRpgBaseCharacter;
class UAnimMontage;
class UCurveFloat;

/**
 * Способность ближнего боя для нанесения урона, проигрывания анимаций и управления комбо-атаками.
 * Использует GAS для интеграции с системой способностей и тегов.
 */
UCLASS()
class TRONRPG_API UMeleeAttackAbility : public UGameplayAbility
{
    GENERATED_BODY()

public:
    UMeleeAttackAbility();

    /** Активирует способность, запуская анимацию и подготавливая урон */
    virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                 const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

    /** Отменяет способность, прерывая анимацию и очищая состояние */
    virtual void CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                               const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility) override;

    /** Проверяет, может ли способность быть активирована */
    virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                    const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags,
                                    OUT FGameplayTagContainer* OptionalRelevantTags) const override;

    /** Завершает способность, очищая состояние */
    virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                            const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

protected:
    /** Анимация атаки ближнего боя */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
    UAnimMontage* MeleeAttackMontage;

    /** Конфигурация параметров атаки */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attack")
    FMeleeAttackConfig AttackConfig;

    /** Конфигурация комбо-системы */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combo")
    FComboConfig ComboConfig;

    /** Таблица конфигураций трассировки для оружия */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    UDataTable* WeaponTraceConfigTable;

    /** Сокеты трассировки по умолчанию */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    TArray<FName> DefaultTraceSocketNames;

    /** Радиус трассировки по умолчанию */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon", meta = (ClampMin = "1.0"))
    float DefaultTraceRadius = 10.0f;

    /** Кривая модификации урона в зависимости от комбо */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attack")
    UCurveFloat* ComboDamageCurve;

    /** Тег события нанесения урона */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gameplay Cues")
    FGameplayTag DamageEventTag;

    /** Эффект урона для применения к целям */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects")
    TSubclassOf<UGameplayEffect> DamageEffect;

    /** Имя профиля трассировки для отладки */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Debug")
    FName TraceProfileName = TEXT("Weapon");

    /** Включение логирования производительности */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Debug")
    bool bEnablePerformanceLogging = false;

    /** Контекст текущей активации способности */
    struct FActivationContext
    {
        FGameplayAbilitySpecHandle SpecHandle;
        const FGameplayAbilityActorInfo* ActorInfo = nullptr;
        FGameplayAbilityActivationInfo ActivationInfo;
        int32 ComboCount = 0;
        TArray<AActor*> HitActors;
    };
    FActivationContext CurrentActivation;

    /** Получает имя секции монтажа для текущего комбо */
    FName GetMontageSectionName(int32 ComboCount) const;

    /** Применяет урон к целям в зоне атаки */
    UFUNCTION()
    void ApplyDamageToTargets(AActor* SourceActor, int32 ComboCount);

    /** Обрабатывает уведомление о нанесении урона из анимации */
    UFUNCTION()
    void OnApplyDamageNotify(FName NotifyName);

    /** Обрабатывает завершение анимации */
    UFUNCTION()
    void OnMontageComplete(UAnimMontage* Montage, bool bInterrupted);

    /** Проверяет, можно ли нанести урон цели */
    bool CanApplyDamageToTarget(AActor* Target) const;

    /** Находит цели в зоне атаки */
    TArray<AActor*> FindTargetsInAttackRange(AActor* SourceActor);

    /** Рассчитывает урон на основе комбо */
    float CalculateDamage(int32 ComboCount, bool& bIsCritical) const;

    /** Создает спецификацию эффекта урона */
    FGameplayEffectSpecHandle CreateDamageEffectSpec(AActor* Target, float DamageAmount, bool bIsCritical);

    /** Получает конфигурацию трассировки для оружия */
    bool GetWeaponTraceConfig(const FGameplayTag& WeaponTypeTag, TArray<FName>& OutSocketNames, float& OutTraceRadius) const;

    /** Получает сокеты трассировки для актора */
    TArray<FName> GetTraceSocketsForActor(AActor* SourceActor) const;

    /** Выполняет оптимизированную трассировку для поиска целей */
    void PerformOptimizedTargetTrace(AActor* SourceActor, TArray<AActor*>& OutHitActors);

    /** Проверяет поддержку интерфейса ближнего боя */
    bool SupportsMeleeInterface(AActor* Actor) const;

    /** Логирует производительность */
    void LogPerformance(const FString& FunctionName, float StartTime) const;
};