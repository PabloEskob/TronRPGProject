#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "TronRpgAbilitySystemComponent.generated.h"

// Делегат для уведомления об изменении тегов
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGameplayTagChanged, FGameplayTag, Tag, int32, NewCount);

// Делегат для уведомления об активации способности
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAbilityActivated, UGameplayAbility*, Ability, FGameplayAbilitySpecHandle, SpecHandle, FGameplayTag,
                                               AbilityTag);

// Делегат для уведомления о готовности способности
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityCooldownChanged, FGameplayTag, AbilityTag);

/**
 * Расширенный компонент системы способностей с поддержкой событий
 */
UCLASS()
class TRONRPG_API UTronRpgAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UTronRpgAbilitySystemComponent();

	// Переопределение методов для добавления уведомлений

	/**
	 * Добавить тег с отправкой события
	 * @param Tag Тег для добавления
	 * @param Count Количество добавляемых тегов
	 */
	UFUNCTION(BlueprintCallable, Category = "Abilities|Tags")
	virtual void AddLooseGameplayTag(const FGameplayTag& Tag, int32 Count = 1);

	/**
	 * Удалить тег с отправкой события
	 * @param Tag Тег для удаления
	 * @param Count Количество удаляемых тегов
	 */
	UFUNCTION(BlueprintCallable, Category = "Abilities|Tags")
	virtual void RemoveLooseGameplayTag(const FGameplayTag& Tag, int32 Count = 1);

	/**
	 * Выдать способность с тегом для привязки ввода
	 * @param AbilityClass Класс способности
	 * @param Level Уровень способности
	 * @param InputTag Тег для привязки к вводу
	 * @return Хэндл спецификации способности
	 */
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	FGameplayAbilitySpecHandle GiveAbilityWithInputTag(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level, FGameplayTag InputTag);

	/**
	 * Активировать способность по тегу ввода
	 * @param InputTag Тег ввода
	 * @return True если способность успешно активирована
	 */
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	bool TryActivateAbilityByInputTag(const FGameplayTag& InputTag);

	/**
	 * Проверить, есть ли у компонента тег
	 * @param Tag Тег для проверки
	 * @param ExactMatch Требуется ли точное совпадение
	 * @return True если тег присутствует
	 */
	UFUNCTION(BlueprintCallable, Category = "Abilities|Tags")
	bool HasMatchingGameplayTagWithExactOption(const FGameplayTag& Tag, bool ExactMatch = false) const;

	virtual bool HasMatchingGameplayTag(FGameplayTag Tag) const override;

	/**
	 * Получить все активные способности с указанным тегом
	 * @param AbilityTag Тег способности
	 * @return Массив активных способностей
	 */
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	TArray<UGameplayAbility*> GetActiveAbilitiesWithTag(const FGameplayTag& AbilityTag) const;

	/**
	 * Отменить способность по тегу
	 * @param WithTag Тег способности для отмены
	 * @return True если отмена успешна
	 */
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	bool CancelAbilityWithTag(const FGameplayTag& WithTag);

	// События

	/** Событие изменения тега */
	UPROPERTY(BlueprintAssignable, Category = "Abilities|Tags")
	FOnGameplayTagChanged OnGameplayTagChanged;

	/** Событие активации способности */
	UPROPERTY(BlueprintAssignable, Category = "Abilities")
	FOnAbilityActivated OnAbilityActivated;

	/** Событие изменения состояния кулдауна способности */
	UPROPERTY(BlueprintAssignable, Category = "Abilities")
	FOnAbilityCooldownChanged OnAbilityCooldownChanged;

protected:
	// Переопределения методов UAbilitySystemComponent

	/** Уведомление об активации способности */
	virtual void NotifyAbilityActivated(const FGameplayAbilitySpecHandle Handle, UGameplayAbility* Ability) override;

	/** Уведомление о завершении способности */
	virtual void NotifyAbilityEnded(const FGameplayAbilitySpecHandle Handle, UGameplayAbility* Ability, bool bWasCancelled) override;

	/**
	 * Обработка изменения эффекта заморозки (кулдауна)
	 * @param Effect Измененный эффект
	 */
	UFUNCTION()
	void OnActiveGameplayEffectAdded(UAbilitySystemComponent* AbilitySystemComponent,
	                                 const FGameplayEffectSpec& EffectSpec,
	                                 FActiveGameplayEffectHandle ActiveHandle);

	UFUNCTION()
	void OnActiveGameplayEffectRemoved(const FActiveGameplayEffect& RemovedEffect);

	// Вспомогательные методы

	/**
	 * Получить тег способности из спецификации
	 * @param AbilitySpec Спецификация способности
	 * @return Тег способности
	 */
	FGameplayTag GetAbilityTagFromSpec(const FGameplayAbilitySpec& AbilitySpec) const;

	/**
	 * Получить тег ввода из спецификации
	 * @param AbilitySpec Спецификация способности
	 * @return Тег ввода
	 */
	FGameplayTag GetInputTagFromSpec(const FGameplayAbilitySpec& AbilitySpec) const;

	/**
	 * Найти все спецификации способностей с указанным тегом ввода
	 * @param InputTag Тег ввода
	 * @return Массив спецификаций способностей
	 */
	TArray<FGameplayAbilitySpec*> FindAbilitySpecsFromInputTag(const FGameplayTag& InputTag);
};
