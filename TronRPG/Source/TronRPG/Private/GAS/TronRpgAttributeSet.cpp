// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/TronRpgAttributeSet.h"

#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"
#include "Character/TronRpgBaseCharacter.h"
#include "GAS/AttributeDefinition.h"
#include "Object/GameplayTagsLibrary.h"

UTronRpgAttributeSet::UTronRpgAttributeSet()
{
	// Инициализация атрибутов значениями по умолчанию
	MaxHealth = 100.0f;
	Health = MaxHealth.GetBaseValue();

	MaxStamina = 100.0f;
	Stamina = MaxStamina.GetBaseValue();

	AttackPower = 20.0f;
	MoveSpeed = 600.0f;

	// Мета-атрибуты должны быть 0
	Damage = 0.0f;
}

void UTronRpgAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Регистрация атрибутов для репликации
	DOREPLIFETIME_CONDITION_NOTIFY(UTronRpgAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UTronRpgAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UTronRpgAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UTronRpgAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UTronRpgAttributeSet, AttackPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UTronRpgAttributeSet, MoveSpeed, COND_None, REPNOTIFY_Always);
}

void UTronRpgAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	// Ограничение атрибутов перед их изменением
	if (Attribute == GetMaxHealthAttribute())
	{
		// Убедимся, что максимальное здоровье не меньше 1
		NewValue = FMath::Max(NewValue, 1.0f);
	}
	else if (Attribute == GetHealthAttribute())
	{
		// Убедимся, что здоровье не превышает максимальное значение
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
	}
	else if (Attribute == GetMaxStaminaAttribute())
	{
		// Убедимся, что максимальная выносливость не меньше 0
		NewValue = FMath::Max(NewValue, 0.0f);
	}
	else if (Attribute == GetStaminaAttribute())
	{
		// Убедимся, что выносливость не превышает максимальное значение
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxStamina());
	}
}

void UTronRpgAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	// Получаем источник и цель эффекта
	AActor* SourceActor = nullptr;
	AActor* TargetActor = nullptr;

	FGameplayEffectContextHandle EffectContext = Data.EffectSpec.GetContext();
	if (EffectContext.IsValid())
	{
		SourceActor = EffectContext.GetOriginalInstigator();
		TargetActor = EffectContext.GetEffectCauser();
	}

	// Получаем теги из эффекта
	FGameplayTagContainer SpecAssetTags;
	Data.EffectSpec.GetAllAssetTags(SpecAssetTags);

	// Обработка изменения атрибутов
	if (Data.EvaluatedData.Attribute == GetDamageAttribute())
	{
		// Получаем значение урона
		const float DamageAmount = GetDamage();
		SetDamage(0.f); // Сбрасываем мета-атрибут урона

		if (DamageAmount > 0.f)
		{
			// Применяем урон к здоровью
			const float NewHealth = GetHealth() - DamageAmount;
			SetHealth(FMath::Max(NewHealth, 0.f));

			// Проверяем, стал ли персонаж мертвым
			if (NewHealth <= 0.f)
			{
				// Получаем персонажа
				ATronRpgBaseCharacter* TargetCharacter = Cast<ATronRpgBaseCharacter>(GetOwningActor());
				if (TargetCharacter)
				{
					// Добавляем тег смерти
					if (UAbilitySystemComponent* ASC = TargetCharacter->GetAbilitySystemComponent())
					{
						ASC->AddLooseGameplayTag(TAG_State_Dead);
					}

					UE_LOG(LogTemp, Log, TEXT("Character %s died from %.1f damage"),
					       *TargetCharacter->GetName(), DamageAmount);
				}
			}
			else
			{
				UE_LOG(LogTemp, Log, TEXT("Character took %.1f damage, Health: %.1f"),
				       DamageAmount, NewHealth);
			}
		}
	}
	else if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		// Ограничиваем здоровье максимальным значением
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
	}
	else if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		// Ограничиваем выносливость максимальным значением
		SetStamina(FMath::Clamp(GetStamina(), 0.0f, GetMaxStamina()));
	}
	else if (Data.EvaluatedData.Attribute == GetMaxHealthAttribute())
	{
		// При изменении максимального здоровья также корректируем текущее здоровье
		float CurrentMaxHealth = GetMaxHealth();
		AdjustAttributeForMaxChange(Health, MaxHealth, CurrentMaxHealth, GetHealthAttribute());
	}
	else if (Data.EvaluatedData.Attribute == GetMaxStaminaAttribute())
	{
		// При изменении максимальной выносливости также корректируем текущую выносливость
		float CurrentMaxStamina = GetMaxStamina();
		AdjustAttributeForMaxChange(Stamina, MaxStamina, CurrentMaxStamina, GetStaminaAttribute());
	}
}

void UTronRpgAttributeSet::AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute,
                                                       float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty)
{
	// Вычисляем отношение текущего значения к максимальному
	float CurrentValue = AffectedAttribute.GetCurrentValue();
	float CurrentMax = MaxAttribute.GetCurrentValue();
	float Ratio = (CurrentMax > 0.f) ? (CurrentValue / CurrentMax) : 0.f;

	// Устанавливаем новое значение атрибута, сохраняя то же отношение к максимуму
	float NewValue = NewMaxValue * Ratio;

	// Устанавливаем новое значение через систему GAS для правильной обработки
	UAbilitySystemComponent* ASC = GetOwningAbilitySystemComponent();
	if (ASC)
	{
		ASC->SetNumericAttributeBase(AffectedAttributeProperty, NewValue);
	}
}

void UTronRpgAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTronRpgAttributeSet, Health, OldHealth);
}

void UTronRpgAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTronRpgAttributeSet, MaxHealth, OldMaxHealth);
}

void UTronRpgAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTronRpgAttributeSet, Stamina, OldStamina);
}

void UTronRpgAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTronRpgAttributeSet, MaxStamina, OldMaxStamina);
}

void UTronRpgAttributeSet::OnRep_AttackPower(const FGameplayAttributeData& OldAttackPower)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTronRpgAttributeSet, AttackPower, OldAttackPower);
}

void UTronRpgAttributeSet::OnRep_MoveSpeed(const FGameplayAttributeData& OldMoveSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTronRpgAttributeSet, MoveSpeed, OldMoveSpeed);
}

void UTronRpgAttributeSet::InitializeFromDefinitions(const TArray<UAttributeDefinition*>& Definitions)
{
    // Очищаем существующие определения
    AttributeDefinitions.Empty();
    
    UAbilitySystemComponent* ASC = GetOwningAbilitySystemComponent();
    if (!ASC)
    {
        UE_LOG(LogTemp, Error, TEXT("InitializeFromDefinitions: No owning ASC found"));
        return;
    }
    
    // Создаем отображение имен атрибутов для удобства
    TMap<FName, FGameplayAttribute> AttributeMap;
    AttributeMap.Add(FName("Health"), GetHealthAttribute());
    AttributeMap.Add(FName("MaxHealth"), GetMaxHealthAttribute());
    AttributeMap.Add(FName("Stamina"), GetStaminaAttribute());
    AttributeMap.Add(FName("MaxStamina"), GetMaxStaminaAttribute());
    AttributeMap.Add(FName("AttackPower"), GetAttackPowerAttribute());
    AttributeMap.Add(FName("MoveSpeed"), GetMoveSpeedAttribute());
    
    // Проходим по всем определениям
    for (UAttributeDefinition* Definition : Definitions)
    {
        if (!Definition || Definition->AttributeId.IsNone())
        {
            continue;
        }
        
        // Сохраняем определение
        AttributeDefinitions.Add(Definition->AttributeId, Definition);
        
        // Получаем атрибут по имени из карты
        FGameplayAttribute* Attribute = AttributeMap.Find(Definition->AttributeId);
        
        if (Attribute && Attribute->IsValid())
        {
            // Инициализируем атрибут базовым значением
            float CurrentBaseValue = ASC->GetNumericAttributeBase(*Attribute);
            
            // Если текущее значение не соответствует определению, устанавливаем новое
            if (!FMath::IsNearlyEqual(CurrentBaseValue, Definition->BaseValue))
            {
                ASC->SetNumericAttributeBase(*Attribute, Definition->BaseValue);
                
                UE_LOG(LogTemp, Log, TEXT("Initialized attribute %s with base value %.2f"),
                       *Definition->AttributeId.ToString(), Definition->BaseValue);
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Attribute not found for ID: %s"),
                   *Definition->AttributeId.ToString());
        }
    }
}

FGameplayAttribute UTronRpgAttributeSet::GetAttributeByID(FName AttributeId) const
{
	if (AttributeId == FName("Health")) return GetHealthAttribute();
	if (AttributeId == FName("MaxHealth")) return GetMaxHealthAttribute();
	if (AttributeId == FName("Stamina")) return GetStaminaAttribute();
	if (AttributeId == FName("MaxStamina")) return GetMaxStaminaAttribute();
	if (AttributeId == FName("AttackPower")) return GetAttackPowerAttribute();
	if (AttributeId == FName("MoveSpeed")) return GetMoveSpeedAttribute();
    
	// Атрибут не найден
	return FGameplayAttribute();
}

float UTronRpgAttributeSet::GetAttributeValueByID(FName AttributeId) const
{
	FGameplayAttribute Attribute = GetAttributeByID(AttributeId);
    
	if (Attribute.IsValid())
	{
		return Attribute.GetNumericValue(this);
	}
    
	return 0.0f;
}

bool UTronRpgAttributeSet::SetAttributeValueByID(FName AttributeId, float Value)
{
	FGameplayAttribute Attribute = GetAttributeByID(AttributeId);
    
	if (!Attribute.IsValid())
	{
		return false;
	}
    
	// Получаем определение атрибута для проверки ограничений
	UAttributeDefinition* Definition = AttributeDefinitions.FindRef(AttributeId);
    
	if (Definition && Definition->bClampValue)
	{
		// Ограничиваем значение, если нужно
		Value = FMath::Clamp(Value, Definition->MinValue, Definition->MaxValue);
	}
    
	// Устанавливаем значение через ASC для корректной обработки
	UAbilitySystemComponent* ASC = GetOwningAbilitySystemComponent();
	if (ASC)
	{
		ASC->SetNumericAttributeBase(Attribute, Value);
		return true;
	}
    
	return false;
}
