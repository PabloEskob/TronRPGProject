#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "TronRpgAbilitySystemComponent.generated.h"

/**
 * Расширенный компонент системы способностей для игры TronRPG
 * Добавляет функции для управления тегами, активации способностей и эффектов
 */
UCLASS()
class TRONRPG_API UTronRpgAbilitySystemComponent : public UAbilitySystemComponent
{
    GENERATED_BODY()
    
public:
    UTronRpgAbilitySystemComponent();
    
    // Инициализация системы способностей на целевом акторе
    void InitializeAbilitySystem(AActor* InOwnerActor, AActor* InAvatarActor);
    
    // Предоставление способности по классу
    UFUNCTION(BlueprintCallable, Category = "Abilities")
    FGameplayAbilitySpecHandle GrantAbilityOfClass(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level = 1, bool bRemoveAfterActivation = false);
    
    // Отмена способностей с определенными тегами
    UFUNCTION(BlueprintCallable, Category = "Abilities")
    void CancelAbilitiesWithTags(const FGameplayTagContainer& Tags);
    
    // Активация способности по тегу
    UFUNCTION(BlueprintCallable, Category = "Abilities")
    bool TryActivateAbilityByTag(const FGameplayTag& AbilityTag);
    
    // Проверка наличия активной способности с указанным тегом
    UFUNCTION(BlueprintCallable, Category = "Abilities")
    bool HasActiveAbilityWithTag(const FGameplayTag& AbilityTag) const;
    
    // Получение ручки спецификации способности по тегу
    UFUNCTION(BlueprintCallable, Category = "Abilities")
    FGameplayAbilitySpecHandle FindAbilitySpecHandleByTag(const FGameplayTag& AbilityTag) const;
    
    // Кэширование тегов состояний для быстрого доступа
    virtual void GetAbilityTagsToGameplayEffectSpec(FGameplayEffectSpec& Spec, FGameplayAbilitySpec* AbilitySpec) override;
    
    // Добавление постоянного эффекта
    UFUNCTION(BlueprintCallable, Category = "Effects")
    FActiveGameplayEffectHandle ApplyPersistentEffect(TSubclassOf<UGameplayEffect> EffectClass, float Level = 1.0f);
    
protected:
    virtual void OnTagUpdated(const FGameplayTag& Tag, bool TagExists) override;
};