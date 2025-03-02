#include "GAS/TronRpgAbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "GameplayEffect.h"
#include "GameplayAbilitySpec.h"
#include "Object/GameplayTagsLibrary.h"

UTronRpgAbilitySystemComponent::UTronRpgAbilitySystemComponent()
{
    // Настройка режима репликации для сетевой игры
    SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

void UTronRpgAbilitySystemComponent::InitializeAbilitySystem(AActor* InOwnerActor, AActor* InAvatarActor)
{
    // Устанавливаем владельца и аватар для системы способностей
    if (InOwnerActor && InAvatarActor)
    {
        InitAbilityActorInfo(InOwnerActor, InAvatarActor);
        UE_LOG(LogTemp, Log, TEXT("AbilitySystem initialized for %s with avatar %s"), 
               *InOwnerActor->GetName(), *InAvatarActor->GetName());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid owner or avatar actor for AbilitySystem initialization"));
    }
}

FGameplayAbilitySpecHandle UTronRpgAbilitySystemComponent::GrantAbilityOfClass(
    TSubclassOf<UGameplayAbility> AbilityClass, int32 Level, bool bRemoveAfterActivation)
{
    if (!AbilityClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("Attempted to grant null ability class"));
        return FGameplayAbilitySpecHandle();
    }
    
    // Создаем спецификацию способности
    FGameplayAbilitySpec AbilitySpec(AbilityClass, Level);
    AbilitySpec.RemoveAfterActivation = bRemoveAfterActivation;
    
    // Предоставляем способность и возвращаем ручку
    FGameplayAbilitySpecHandle Handle = GiveAbility(AbilitySpec);
    
    if (Handle.IsValid())
    {
        UE_LOG(LogTemp, Log, TEXT("Granted ability %s at level %d"),
               *AbilityClass->GetName(), Level);
    }
    
    return Handle;
}

void UTronRpgAbilitySystemComponent::CancelAbilitiesWithTags(const FGameplayTagContainer& Tags)
{
    // Проверка на валидность тегов
    if (Tags.IsEmpty())
    {
        return;
    }
    
    // Отменяем все способности, у которых есть хотя бы один из указанных тегов
    CancelAbilities(&Tags);
    
    UE_LOG(LogTemp, Log, TEXT("Canceled abilities with tags: %s"), *Tags.ToString());
}

bool UTronRpgAbilitySystemComponent::TryActivateAbilityByTag(const FGameplayTag& AbilityTag)
{
    // Проверка на валидность тега
    if (!AbilityTag.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("Attempted to activate ability with invalid tag"));
        return false;
    }
    
    // Создаем контейнер с одним тегом
    FGameplayTagContainer TagContainer;
    TagContainer.AddTag(AbilityTag);
    
    // Пытаемся активировать способность с этим тегом
    return TryActivateAbilitiesByTag(TagContainer);
}

bool UTronRpgAbilitySystemComponent::HasActiveAbilityWithTag(const FGameplayTag& AbilityTag) const
{
    // Проверка на валидность тега
    if (!AbilityTag.IsValid())
    {
        return false;
    }
    
    // Проверяем все активные способности
    for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
    {
        if (AbilitySpec.IsActive() && AbilitySpec.Ability && AbilitySpec.Ability->AbilityTags.HasTag(AbilityTag))
        {
            return true;
        }
    }
    
    return false;
}

FGameplayAbilitySpecHandle UTronRpgAbilitySystemComponent::FindAbilitySpecHandleByTag(const FGameplayTag& AbilityTag) const
{
    // Проверка на валидность тега
    if (!AbilityTag.IsValid())
    {
        return FGameplayAbilitySpecHandle();
    }
    
    // Ищем способность с указанным тегом
    for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
    {
        if (AbilitySpec.Ability && AbilitySpec.Ability->AbilityTags.HasTag(AbilityTag))
        {
            return AbilitySpec.Handle;
        }
    }
    
    return FGameplayAbilitySpecHandle();
}

void UTronRpgAbilitySystemComponent::ApplyAbilityTagsToGameplayEffectSpec(FGameplayEffectSpec& Spec, FGameplayAbilitySpec* AbilitySpec)
{
    // Вызываем базовую реализацию
    Super::ApplyAbilityTagsToGameplayEffectSpec(Spec, AbilitySpec);
    
    // Добавляем дополнительную логику, если необходимо
    // Например, добавление специальных тегов источника для эффектов
    if (AbilitySpec && AbilitySpec->Ability)
    {
        // Добавляем теги из способности в спецификацию эффекта для лучшего отслеживания
        Spec.CapturedSourceTags.GetSpecTags().AppendTags(AbilitySpec->Ability->AbilityTags);
    }
}

FActiveGameplayEffectHandle UTronRpgAbilitySystemComponent::ApplyPersistentEffect(TSubclassOf<UGameplayEffect> EffectClass, float Level)
{
    // Проверка на валидность класса эффекта
    if (!EffectClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("Attempted to apply null effect class"));
        return FActiveGameplayEffectHandle();
    }
    
    // Создаем контекст эффекта
    FGameplayEffectContextHandle EffectContext = MakeEffectContext();
    
    // Создаем спецификацию эффекта
    FGameplayEffectSpecHandle SpecHandle = MakeOutgoingSpec(EffectClass, Level, EffectContext);
    
    if (SpecHandle.IsValid())
    {
        // Применяем эффект к себе
        FActiveGameplayEffectHandle ActiveHandle = ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
        
        if (ActiveHandle.IsValid())
        {
            UE_LOG(LogTemp, Log, TEXT("Applied persistent effect %s at level %.1f"),
                   *EffectClass->GetName(), Level);
        }
        
        return ActiveHandle;
    }
    
    return FActiveGameplayEffectHandle();
}

void UTronRpgAbilitySystemComponent::OnTagUpdated(const FGameplayTag& Tag, bool TagExists)
{
    // Вызываем базовую реализацию
    Super::OnTagUpdated(Tag, TagExists);
    
    // Дополнительная обработка изменений тегов
    // Например, отправка событий другим системам при изменении важных тегов состояния
    
    // Пример: отслеживание тега оглушения
    if (Tag == TAG_State_Stunned)
    {
        if (TagExists > 0)
        {
            // Персонаж получил оглушение
            UE_LOG(LogTemp, Log, TEXT("Character stunned"));
            
            // Отменяем все активные способности при оглушении
            CancelAbilities();
        }
        else
        {
            // Персонаж вышел из оглушения
            UE_LOG(LogTemp, Log, TEXT("Character recovered from stun"));
        }
    }
}
