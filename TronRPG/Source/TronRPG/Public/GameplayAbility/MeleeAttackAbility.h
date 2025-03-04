#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayTagContainer.h"
#include "MeleeAttackAbility.generated.h"

// Перечисление состояний комбо-атаки
UENUM(BlueprintType)
enum class EMeleeAttackState : uint8
{
	Idle,
	Attacking,
	ComboWindow,
	ApplyingDamage,
	Cancelling
};

class ATronRpgBaseCharacter;
class UAnimMontage;

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

	// Переопределения методов UGameplayAbility
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	                                const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags,
	                                FGameplayTagContainer* OptionalRelevantTags) const override;
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	                             const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	                        const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	/**
	 * Продолжить комбо-атаку, переходя к следующей секции
	 * @return true если комбо успешно продолжено
	 */
	bool ContinueComboAttack();

protected:
	/** Монтаж атаки по умолчанию */
	UPROPERTY(EditDefaultsOnly, Category = "Attack|Animation")
	UAnimMontage* DefaultAttackMontage;

	/** Монтажи атак для разных типов оружия */
	UPROPERTY(EditDefaultsOnly, Category = "Attack|Animation")
	TMap<FGameplayTag, UAnimMontage*> WeaponTypeAttackMontages;

	/** Максимальное количество ударов в комбо */
	UPROPERTY(EditDefaultsOnly, Category = "Attack|Combo", meta = (ClampMin = "1", ClampMax = "6"))
	int32 MaxComboCount;

	/** Базовый урон атаки */
	UPROPERTY(EditDefaultsOnly, Category = "Attack|Damage", meta = (ClampMin = "0.0"))
	float BaseDamage;

	/** Радиус атаки для определения попаданий */
	UPROPERTY(EditDefaultsOnly, Category = "Attack|Damage", meta = (ClampMin = "10.0"))
	float DamageRadius;

	/** Шанс критического удара (0.0 - 1.0) */
	UPROPERTY(EditDefaultsOnly, Category = "Attack|Damage", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float CriticalChance = 0.1f;

	/** Множитель урона при критическом ударе */
	UPROPERTY(EditDefaultsOnly, Category = "Attack|Damage", meta = (ClampMin = "1.0"))
	float CriticalMultiplier = 2.0f;

	/** Длительность окна возможности комбо в секундах */
	UPROPERTY(EditDefaultsOnly, Category = "Attack|Combo", meta = (ClampMin = "0.1"))
	float ComboWindowTime;

	/** Класс эффекта для нанесения урона */
	UPROPERTY(EditDefaultsOnly, Category = "Attack|Damage")
	TSubclassOf<UGameplayEffect> DamageEffectClass;

	/**
	 * Текущее состояние атаки
	 */
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Attack|State")
	EMeleeAttackState AttackState = EMeleeAttackState::Idle;

	/** Указатель на персонажа-владельца */
	UPROPERTY()
	AActor* OwningActor;

	/** Текущий счетчик комбо */
	int32 CurrentComboCount;

	/** Текущий монтаж атаки */
	UPROPERTY()
	UAnimMontage* AttackMontage;

	/** Текущая секция атаки */
	FName CurrentAttackSection;

	/** Флаг, указывающий, открыто ли окно комбо */
	bool bCanCombo;

	/** Флаг, указывающий, что урон в данный момент применяется */
	bool bApplyingDamage;

	/** Флаг, отслеживающий нажатие ввода атаки */
	bool bAttackInputPressed;

	/** Хэндл текущей спецификации способности */
	FGameplayAbilitySpecHandle CurrentSpecHandle;

	/** Информация об акторе для текущей активации */
	const FGameplayAbilityActorInfo* CachedActorInfo;

	/** Информация об активации способности */
	FGameplayAbilityActivationInfo CurrentActivationInfo;

	/** Хэндл таймера для проверки комбо */
	FTimerHandle ComboCheckTimerHandle;

	/**
	 * Установить состояние атаки
	 */
	void SetAttackState(EMeleeAttackState NewState);

	/**
	 * Обработать события на основе состояния
	 */
	void ProcessAttackState(float DeltaTime);

	/**
	 * Выполнить атаку
	 */
	void ExecuteAttack();

	/**
	 * Выбрать соответствующий монтаж и секцию для текущей атаки
	 * @return true если выбор успешен
	 */
	bool SelectAttackMontageAndSection();

	/**
	 * Выбирает монтаж на основе текущего оружия персонажа
	 * @return Подходящий монтаж для текущего оружия
	 */
	UAnimMontage* SelectAppropriateAttackMontage();

	/**
	 * Обработчик уведомлений анимации
	 * @param NotifyName Имя уведомления
	 */
	UFUNCTION()
	void OnAnimNotifyBegin(FName NotifyName);

	/**
	 * Применяет урон целям в области атаки через GameplayEffect
	 */
	void ApplyDamage();

	/**
	 * Проверяет ввод для комбо
	 */
	void CheckComboInput();

	/**
	 * Закрывает окно возможности комбо
	 */
	void CloseComboWindow();

	/**
	 * Обработчик завершения анимации атаки
	 * @param Montage Завершившийся монтаж
	 * @param bInterrupted Флаг прерывания
	 */
	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);
};
