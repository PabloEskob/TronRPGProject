#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayTagContainer.h"
#include "Component/TronRpgComboComponent.h"
#include "Task/AbilityTask_WaitForComboInput.h"
#include "MeleeAttackAbility.generated.h"

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
	bool IsCharacterChangingEquipment(const FGameplayAbilityActorInfo* ActorInfo) const;
	bool IsWeaponEquipped(const ATronRpgBaseCharacter* Character) const;
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	                             const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	bool CommitAbilityResources(FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	                            FGameplayAbilityActivationInfo ActivationInfo);
	void SaveCurrentActivationContext(FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	                                  FGameplayAbilityActivationInfo ActivationInfo);
	void InitializeOwningCharacter(const FGameplayAbilityActorInfo* ActorInfo);
	bool ProcessComboState();
	void ResetComboState(UTronRpgComboComponent* ComboComp);
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	                        const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	/**
	 * Продолжить комбо-атаку, переходя к следующей секции
	 */
	void ContinueComboAttack();

	UPROPERTY()
	UAbilityTask_WaitForComboInput* ComboInputTask;

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

	/** Указатель на персонажа-владельца */
	UPROPERTY()
	ATronRpgBaseCharacter* OwningCharacter;

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
	const FGameplayAbilityActorInfo* CurrentActorInfo;

	/** Информация об активации способности */
	FGameplayAbilityActivationInfo CurrentActivationInfo;

	/** Хэндл таймера для проверки комбо */
	FTimerHandle ComboCheckTimerHandle;

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
	 * Проверка ввода для комбо
	 */
	void CheckComboInput();

	/**
	 * Закрыть окно возможности комбо
	 */
	void CloseComboWindow();

	/**
	 * Обработчик завершения анимации атаки
	 * @param Montage Завершившийся монтаж
	 * @param bInterrupted Флаг прерывания
	 */
	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	/**
	 * Применяет урон целям в области атаки
	 */
	void ApplyDamage();

	/**
	 * Запускает ожидание ввода комбо через Ability Task
	 * Вызывается из нотифая анимации или по таймингу
	 */
	UFUNCTION()
	void WaitForComboInput();

	/**
	 * Обработчик получения ввода комбо
	 * @param NewComboCount Новый счётчик комбо
	 */
	UFUNCTION()
	void OnComboInputReceived(int32 NewComboCount);

	/**
	 * Обработчик истечения окна комбо
	 * @param ComboCount Текущий счётчик комбо
	 */
	UFUNCTION()
	void OnComboWindowExpired(int32 ComboCount);
};
