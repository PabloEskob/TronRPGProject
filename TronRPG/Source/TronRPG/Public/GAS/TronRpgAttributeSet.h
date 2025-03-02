#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "TronRpgAttributeSet.generated.h"

// Макрос для создания геттеров/сеттеров атрибутов
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

class UAttributeDefinition;
/**
 * Набор атрибутов для персонажей TronRPG
 * Содержит основные характеристики персонажа и обрабатывает их изменения
 */
UCLASS()
class TRONRPG_API UTronRpgAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UTronRpgAttributeSet();

	// Репликация атрибутов
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Методы жизненного цикла атрибутов
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	// Определение основных атрибутов

	// Здоровье
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Vital", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UTronRpgAttributeSet, Health)

	// Максимальное здоровье
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Vital", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UTronRpgAttributeSet, MaxHealth)

	// Выносливость
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Vital", ReplicatedUsing = OnRep_Stamina)
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UTronRpgAttributeSet, Stamina)

	// Максимальная выносливость
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Vital", ReplicatedUsing = OnRep_MaxStamina)
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UTronRpgAttributeSet, MaxStamina)

	// Сила атаки
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Combat", ReplicatedUsing = OnRep_AttackPower)
	FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(UTronRpgAttributeSet, AttackPower)

	// Скорость передвижения
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Movement", ReplicatedUsing = OnRep_MoveSpeed)
	FGameplayAttributeData MoveSpeed;
	ATTRIBUTE_ACCESSORS(UTronRpgAttributeSet, MoveSpeed)

	// Дополнительный атрибут для обработки входящего урона
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Meta")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UTronRpgAttributeSet, Damage)

	// Обработчики репликации атрибутов
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

	UFUNCTION()
	virtual void OnRep_Stamina(const FGameplayAttributeData& OldStamina);

	UFUNCTION()
	virtual void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina);

	UFUNCTION()
	virtual void OnRep_AttackPower(const FGameplayAttributeData& OldAttackPower);

	UFUNCTION()
	virtual void OnRep_MoveSpeed(const FGameplayAttributeData& OldMoveSpeed);

	// Вспомогательные методы
	void AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue,
	                                 const FGameplayAttribute& AffectedAttributeProperty);

	/**
	 * Инициализация атрибутов из определений
	 * @param Definitions Массив определений атрибутов
	 */
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void InitializeFromDefinitions(const TArray<UAttributeDefinition*>& Definitions);

	/**
	 * Получить атрибут по ID с использованием рефлексии
	 * @param AttributeId ID атрибута
	 * @return Объект атрибута или недействительный атрибут, если не найден
	 */
	UFUNCTION(BlueprintPure, Category = "Attributes")
	FGameplayAttribute GetAttributeByID(FName AttributeId) const;

	/**
	 * Получить значение атрибута по ID
	 * @param AttributeId ID атрибута
	 * @return Текущее значение атрибута или 0, если атрибут не найден
	 */
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetAttributeValueByID(FName AttributeId) const;


	/**
	 * Установить значение атрибута по ID
	 * @param AttributeId ID атрибута
	 * @param Value Новое значение атрибута
	 * @return true, если атрибут найден и значение установлено
	 */
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	bool SetAttributeValueByID(FName AttributeId, float Value);

protected:
	/**
	 * Карта ID атрибутов на их настройки
	 */
	UPROPERTY(Transient)
	TMap<FName, UAttributeDefinition*> AttributeDefinitions;

	TMap<FName, TWeakFieldPtr<FProperty>> AttributePropertyMap;

	/**
	 * Карта ID атрибутов на указатели на их данные
	 */
	TMap<FName, FGameplayAttributeData*> AttributeDataMap;
};
