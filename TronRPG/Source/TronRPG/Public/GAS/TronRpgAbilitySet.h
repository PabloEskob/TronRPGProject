#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayAbilitySpec.h"
#include "GameplayEffect.h"
#include "TronRpgAbilitySet.generated.h"

class UGameplayAbility;
class UGameplayEffect;
class UAbilitySystemComponent;

/**
 * Структура для отслеживания предоставленных способностей
 */
USTRUCT()
struct FTronRpgAbilitySetGrantedHandles
{
    GENERATED_BODY()
    
    // Ручки предоставленных способностей
    UPROPERTY()
    TArray<FGameplayAbilitySpecHandle> AbilityHandles;
    
    // Ручки примененных эффектов
    UPROPERTY()
    TArray<FActiveGameplayEffectHandle> EffectHandles;
    
    // Теги, добавленные набором
    UPROPERTY()
    FGameplayTagContainer GrantedTags;
    
    // Очистка всех ручек
    void Reset(UAbilitySystemComponent* ASC);
};

/**
 * Набор способностей и эффектов, который можно применить к персонажу
 * Позволяет модульно группировать связанные способности и эффекты
 */
UCLASS(BlueprintType)
class TRONRPG_API UTronRpgAbilitySet : public UPrimaryDataAsset
{
    GENERATED_BODY()
    
public:
    UTronRpgAbilitySet();
    
    // Применить набор к компоненту системы способностей
    void GiveToAbilitySystem(UAbilitySystemComponent* ASC, OUT FTronRpgAbilitySetGrantedHandles* OutGrantedHandles, UObject* SourceObject = nullptr) const;
    
    // Удалить набор из компонента системы способностей
    void RemoveFromAbilitySystem(UAbilitySystemComponent* ASC, const FTronRpgAbilitySetGrantedHandles& Handles) const;
    
protected:
    // Способности, предоставляемые набором
    UPROPERTY(EditDefaultsOnly, Category = "Abilities", meta = (TitleProperty = "Ability"))
    TArray<TSubclassOf<UGameplayAbility>> GrantedAbilities;
    
    // Эффекты, применяемые набором
    UPROPERTY(EditDefaultsOnly, Category = "Effects", meta = (TitleProperty = "Effect"))
    TArray<TSubclassOf<UGameplayEffect>> GrantedEffects;
    
    // Теги, добавляемые набором
    UPROPERTY(EditDefaultsOnly, Category = "Tags")
    FGameplayTagContainer GrantedTags;
};