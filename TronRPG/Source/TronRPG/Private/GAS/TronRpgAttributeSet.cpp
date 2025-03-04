#include "GAS/TronRpgAttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

UTronRpgAttributeSet::UTronRpgAttributeSet()
{
    // Инициализация атрибутов значениями по умолчанию
    
    // Базовые значения для персонажа среднего уровня
    InitHealth(100.0f);
    InitMaxHealth(100.0f);
    InitStamina(100.0f);
    InitMaxStamina(100.0f);
    InitAttackPower(10.0f);
    InitDefense(5.0f);
    InitAttackSpeed(1.0f);
    
    // Мета-атрибуты инициализируются нулями
    InitDamage(0.0f);
    InitHealingReceived(0.0f);
    InitStaminaCost(0.0f);
}

void UTronRpgAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    // Репликация основных атрибутов
    DOREPLIFETIME_CONDITION_NOTIFY(UTronRpgAttributeSet, Health, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UTronRpgAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UTronRpgAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UTronRpgAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UTronRpgAttributeSet, AttackPower, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UTronRpgAttributeSet, Defense, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UTronRpgAttributeSet, AttackSpeed, COND_None, REPNOTIFY_Always);
    
    // Мета-атрибуты не реплицируются, так как они используются только для расчётов
}

void UTronRpgAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    Super::PreAttributeChange(Attribute, NewValue);

    // Ограничиваем значения атрибутов перед изменением
    
    // Здоровье не может превышать максимальное здоровье
    if (Attribute == GetHealthAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
    }
    // Выносливость не может превышать максимальную выносливость
    else if (Attribute == GetStaminaAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxStamina());
    }
    // Скорость атаки не может быть ниже определенного минимума
    else if (Attribute == GetAttackSpeedAttribute())
    {
        NewValue = FMath::Max(NewValue, 0.1f); // Минимальная скорость атаки 10% от нормальной
    }
}

void UTronRpgAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);
    
    // Получаем ссылки на важные объекты
    FGameplayEffectContextHandle EffectContext = Data.EffectSpec.GetContext();
    UAbilitySystemComponent* SourceASC = EffectContext.GetOriginalInstigatorAbilitySystemComponent();
    AActor* SourceActor = SourceASC ? SourceASC->GetAvatarActor() : nullptr;
    AActor* TargetActor = GetOwningActor();
    
    // Создаем теги для проверки типа эффекта
    const FGameplayTagContainer& SourceTags = *Data.EffectSpec.CapturedSourceTags.GetAggregatedTags();
    
    // Получаем измененный атрибут
    FGameplayAttribute Attribute = Data.EvaluatedData.Attribute;

    // Получаем модификатор (дельту)
    float ModificationMagnitude = Data.EvaluatedData.Magnitude;
    
    // Обработка урона
    if (Attribute == GetDamageAttribute())
    {
        // Получаем величину урона
        float DamageAmount = GetDamage();
        if (DamageAmount > 0.0f)
        {
            // Применяем защиту
            float DefenseValue = GetDefense();
            float ActualDamage = FMath::Max(DamageAmount - DefenseValue * 0.5f, 0.0f);
            
            // Уменьшаем здоровье
            float NewHealth = GetHealth() - ActualDamage;
            SetHealth(FMath::Clamp(NewHealth, 0.0f, GetMaxHealth()));
            
            // Логируем нанесенный урон
            UE_LOG(LogTemp, Log, TEXT("%s received %.2f damage (mitigated from %.2f) from %s"),
                *TargetActor->GetName(), ActualDamage, DamageAmount,
                SourceActor ? *SourceActor->GetName() : TEXT("unknown source"));
            
            // Проверяем смерть персонажа
            if (GetHealth() <= 0.0f)
            {
                // Персонаж погиб - можно вызвать соответствующие события
                UE_LOG(LogTemp, Log, TEXT("%s was defeated"), *TargetActor->GetName());
                
                // Здесь можно добавить вызов события смерти персонажа
            }
            
            // Сбрасываем мета-атрибут урона
            SetDamage(0.0f);
        }
    }
    // Обработка исцеления
    else if (Attribute == GetHealingReceivedAttribute())
    {
        float HealingAmount = GetHealingReceived();
        if (HealingAmount > 0.0f)
        {
            // Увеличиваем здоровье
            float NewHealth = GetHealth() + HealingAmount;
            SetHealth(FMath::Clamp(NewHealth, 0.0f, GetMaxHealth()));
            
            // Логируем полученное исцеление
            UE_LOG(LogTemp, Log, TEXT("%s was healed for %.2f by %s"),
                *TargetActor->GetName(), HealingAmount,
                SourceActor ? *SourceActor->GetName() : TEXT("unknown source"));
            
            // Сбрасываем мета-атрибут исцеления
            SetHealingReceived(0.0f);
        }
    }
    // Обработка затрат выносливости
    else if (Attribute == GetStaminaCostAttribute())
    {
        float Cost = GetStaminaCost();
        if (Cost > 0.0f)
        {
            // Уменьшаем выносливость
            float NewStamina = GetStamina() - Cost;
            SetStamina(FMath::Clamp(NewStamina, 0.0f, GetMaxStamina()));
            
            // Логируем затраты выносливости
            UE_LOG(LogTemp, Log, TEXT("%s spent %.2f stamina"),
                *TargetActor->GetName(), Cost);
            
            // Сбрасываем мета-атрибут затрат выносливости
            SetStaminaCost(0.0f);
        }
    }
    // Ограничиваем здоровье после любого прямого изменения
    else if (Attribute == GetHealthAttribute())
    {
        SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
    }
    // Ограничиваем выносливость после любого прямого изменения
    else if (Attribute == GetStaminaAttribute())
    {
        SetStamina(FMath::Clamp(GetStamina(), 0.0f, GetMaxStamina()));
    }
    // Корректируем здоровье при изменении максимального здоровья
    else if (Attribute == GetMaxHealthAttribute())
    {
        AdjustAttributeForMaxChange(Health, MaxHealth, GetMaxHealth(), GetHealthAttribute());
    }
    // Корректируем выносливость при изменении максимальной выносливости
    else if (Attribute == GetMaxStaminaAttribute())
    {
        AdjustAttributeForMaxChange(Stamina, MaxStamina, GetMaxStamina(), GetStaminaAttribute());
    }
}

void UTronRpgAttributeSet::AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty)
{
    // Сохраняем старый процент от максимума
    float CurrentValue = AffectedAttribute.GetCurrentValue();
    float CurrentMax = MaxAttribute.GetCurrentValue();
    float Ratio = CurrentMax > 0.f ? CurrentValue / CurrentMax : 0.f;
    
    // Устанавливаем новое значение, сохраняя тот же процент от максимума
    float NewValue = NewMaxValue * Ratio;
    UAbilitySystemComponent* ASC = GetOwningAbilitySystemComponent();
    if (ASC)
    {
        ASC->SetNumericAttributeBase(AffectedAttributeProperty, NewValue);
    }
}

void UTronRpgAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTronRpgAttributeSet, Health, OldValue);
}

void UTronRpgAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTronRpgAttributeSet, MaxHealth, OldValue);
}

void UTronRpgAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTronRpgAttributeSet, Stamina, OldValue);
}

void UTronRpgAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTronRpgAttributeSet, MaxStamina, OldValue);
}

void UTronRpgAttributeSet::OnRep_AttackPower(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTronRpgAttributeSet, AttackPower, OldValue);
}

void UTronRpgAttributeSet::OnRep_Defense(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTronRpgAttributeSet, Defense, OldValue);
}

void UTronRpgAttributeSet::OnRep_AttackSpeed(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTronRpgAttributeSet, AttackSpeed, OldValue);
}