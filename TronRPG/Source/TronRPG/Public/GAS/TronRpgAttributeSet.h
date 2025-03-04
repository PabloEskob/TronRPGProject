#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "TronRpgAttributeSet.generated.h"

// Макрос для удобного доступа к атрибутам
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * Набор атрибутов для системы боя и прогресса персонажа
 */
UCLASS()
class TRONRPG_API UTronRpgAttributeSet : public UAttributeSet
{
    GENERATED_BODY()

public:
    UTronRpgAttributeSet();

    // Переопределения базовых методов AttributeSet
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

    // Основные атрибуты

    // Здоровье - текущее значение здоровья персонажа
    UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Health)
    FGameplayAttributeData Health;
    ATTRIBUTE_ACCESSORS(UTronRpgAttributeSet, Health)

    // Максимальное здоровье - определяет верхний предел здоровья
    UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxHealth)
    FGameplayAttributeData MaxHealth;
    ATTRIBUTE_ACCESSORS(UTronRpgAttributeSet, MaxHealth)

    // Выносливость - ресурс для спринта и специальных атак
    UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Stamina)
    FGameplayAttributeData Stamina;
    ATTRIBUTE_ACCESSORS(UTronRpgAttributeSet, Stamina)

    // Максимальная выносливость
    UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxStamina)
    FGameplayAttributeData MaxStamina;
    ATTRIBUTE_ACCESSORS(UTronRpgAttributeSet, MaxStamina)

    // Сила атаки - базовый множитель урона
    UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_AttackPower)
    FGameplayAttributeData AttackPower;
    ATTRIBUTE_ACCESSORS(UTronRpgAttributeSet, AttackPower)

    // Защита - снижение получаемого урона
    UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Defense)
    FGameplayAttributeData Defense;
    ATTRIBUTE_ACCESSORS(UTronRpgAttributeSet, Defense)

    // Скорость атаки - влияет на скорость анимаций и время между атаками
    UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_AttackSpeed)
    FGameplayAttributeData AttackSpeed;
    ATTRIBUTE_ACCESSORS(UTronRpgAttributeSet, AttackSpeed)

    // Мета-атрибуты (временные, для расчётов)

    // Входящий урон (не реплицируется)
    UPROPERTY(BlueprintReadOnly, Category = "Attributes")
    FGameplayAttributeData Damage;
    ATTRIBUTE_ACCESSORS(UTronRpgAttributeSet, Damage)

    // Восстановление здоровья (не реплицируется)
    UPROPERTY(BlueprintReadOnly, Category = "Attributes")
    FGameplayAttributeData HealingReceived;
    ATTRIBUTE_ACCESSORS(UTronRpgAttributeSet, HealingReceived)

    // Стоимость выносливости (не реплицируется)
    UPROPERTY(BlueprintReadOnly, Category = "Attributes")
    FGameplayAttributeData StaminaCost;
    ATTRIBUTE_ACCESSORS(UTronRpgAttributeSet, StaminaCost)

protected:
    // Обработчики репликации
    UFUNCTION()
    virtual void OnRep_Health(const FGameplayAttributeData& OldValue);

    UFUNCTION()
    virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);

    UFUNCTION()
    virtual void OnRep_Stamina(const FGameplayAttributeData& OldValue);

    UFUNCTION()
    virtual void OnRep_MaxStamina(const FGameplayAttributeData& OldValue);

    UFUNCTION()
    virtual void OnRep_AttackPower(const FGameplayAttributeData& OldValue);

    UFUNCTION()
    virtual void OnRep_Defense(const FGameplayAttributeData& OldValue);

    UFUNCTION()
    virtual void OnRep_AttackSpeed(const FGameplayAttributeData& OldValue);

    // Вспомогательные методы
    void AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty);
};