#include "GAS/TronRpgAbilitySet.h"
#include "AbilitySystemComponent.h"

void FTronRpgAbilitySetGrantedHandles::Reset(UAbilitySystemComponent* ASC)
{
	if (!ASC)
	{
		return;
	}

	// Удаляем все предоставленные способности
	for (const FGameplayAbilitySpecHandle& Handle : AbilityHandles)
	{
		if (Handle.IsValid())
		{
			ASC->ClearAbility(Handle);
		}
	}

	// Удаляем все примененные эффекты
	for (const FActiveGameplayEffectHandle& Handle : EffectHandles)
	{
		if (Handle.IsValid())
		{
			ASC->RemoveActiveGameplayEffect(Handle);
		}
	}

	// Удаляем все предоставленные теги
	if (!GrantedTags.IsEmpty())
	{
		ASC->RemoveLooseGameplayTags(GrantedTags);
	}

	// Очищаем массивы ручек
	AbilityHandles.Empty();
	EffectHandles.Empty();
	GrantedTags.Reset();
}

UTronRpgAbilitySet::UTronRpgAbilitySet()
{
}

void UTronRpgAbilitySet::GiveToAbilitySystem(UAbilitySystemComponent* ASC, OUT FTronRpgAbilitySetGrantedHandles* OutGrantedHandles,
                                             UObject* SourceObject) const
{
	if (!ASC || !OutGrantedHandles)
	{
		return;
	}

	// Добавляем способности
	for (const TSubclassOf<UGameplayAbility>& AbilityClass : GrantedAbilities)
	{
		if (!AbilityClass)
		{
			continue;
		}

		// Создаем спецификацию способности
		FGameplayAbilitySpec AbilitySpec(AbilityClass, 1);

		// Устанавливаем источник
		if (SourceObject)
		{
			AbilitySpec.SourceObject = SourceObject;
		}

		// Выдаем способность
		FGameplayAbilitySpecHandle Handle = ASC->GiveAbility(AbilitySpec);

		// Сохраняем ручку для возможности удаления позже
		if (Handle.IsValid())
		{
			OutGrantedHandles->AbilityHandles.Add(Handle);
		}
	}

	// Применяем эффекты
	for (const TSubclassOf<UGameplayEffect>& EffectClass : GrantedEffects)
	{
		if (!EffectClass)
		{
			continue;
		}

		// Создаем контекст эффекта
		FGameplayEffectContextHandle EffectContext = ASC->MakeEffectContext();

		// Устанавливаем источник
		if (SourceObject)
		{
			EffectContext.AddSourceObject(SourceObject);
		}

		// Создаем спецификацию эффекта
		FGameplayEffectSpecHandle SpecHandle = ASC->MakeOutgoingSpec(EffectClass, 1.0f, EffectContext);

		if (SpecHandle.IsValid())
		{
			// Применяем эффект
			FActiveGameplayEffectHandle ActiveHandle = ASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());

			// Сохраняем ручку для возможности удаления позже
			if (ActiveHandle.IsValid())
			{
				OutGrantedHandles->EffectHandles.Add(ActiveHandle);
			}
		}
	}

	// Добавляем теги
	if (!GrantedTags.IsEmpty())
	{
		ASC->AddLooseGameplayTags(GrantedTags);
		OutGrantedHandles->GrantedTags.AppendTags(GrantedTags);
	}
}

void UTronRpgAbilitySet::RemoveFromAbilitySystem(UAbilitySystemComponent* ASC, const FTronRpgAbilitySetGrantedHandles& Handles) const
{
	if (!ASC)
	{
		return;
	}

	// Вспомогательный объект для удаления всех ручек
	FTronRpgAbilitySetGrantedHandles HandlesCopy = Handles;
	HandlesCopy.Reset(ASC);
}
