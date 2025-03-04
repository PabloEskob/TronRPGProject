#include "GAS/TronRpgAbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"

UTronRpgAbilitySystemComponent::UTronRpgAbilitySystemComponent()
{
	// Регистрация обработчика изменений кулдаунов
	OnActiveGameplayEffectAddedDelegateToSelf.AddUObject(this, &UTronRpgAbilitySystemComponent::OnActiveGameplayEffectAdded);
	OnAnyGameplayEffectRemovedDelegate().AddUObject(this, &UTronRpgAbilitySystemComponent::OnActiveGameplayEffectRemoved);
}

void UTronRpgAbilitySystemComponent::AddLooseGameplayTag(const FGameplayTag& Tag, int32 Count)
{
	int32 OldCount = GetTagCount(Tag);
	Super::AddLooseGameplayTag(Tag, Count);
	int32 NewCount = GetTagCount(Tag);

	if (OldCount != NewCount)
	{
		OnGameplayTagChanged.Broadcast(Tag, NewCount);
	}
}

void UTronRpgAbilitySystemComponent::OnActiveGameplayEffectAdded(UAbilitySystemComponent* AbilitySystemComponent, 
															 const FGameplayEffectSpec& EffectSpec, 
															 FActiveGameplayEffectHandle ActiveHandle)
{
	// Проверяем, является ли эффект кулдауном
	static FGameplayTagContainer CooldownTags;
	if (CooldownTags.Num() == 0)
	{
		CooldownTags.AddTag(FGameplayTag::RequestGameplayTag("Cooldown"));
	}
    
	// Проверяем теги эффекта
	const FGameplayTagContainer& EffectTags = EffectSpec.Def->GetGrantedTags();
	if (EffectTags.HasAny(CooldownTags))
	{
		// Получаем теги способности из эффекта
		for (const FGameplayTag& AbilityTag : EffectSpec.DynamicGrantedTags)
		{
			// Отправляем событие об изменении кулдауна
			OnAbilityCooldownChanged.Broadcast(AbilityTag);
		}
	}
}

void UTronRpgAbilitySystemComponent::OnActiveGameplayEffectRemoved(const FActiveGameplayEffect& RemovedEffect)
{
	// Проверяем, является ли эффект кулдауном
	static FGameplayTagContainer CooldownTags;
	if (CooldownTags.Num() == 0)
	{
		CooldownTags.AddTag(FGameplayTag::RequestGameplayTag("Cooldown"));
	}
    
	// Проверяем теги эффекта
	const FGameplayTagContainer& EffectTags = RemovedEffect.Spec.Def->GetGrantedTags();
	if (EffectTags.HasAny(CooldownTags))
	{
		// Получаем теги способности из эффекта
		for (const FGameplayTag& AbilityTag : RemovedEffect.Spec.DynamicGrantedTags)
		{
			// Отправляем событие об изменении кулдауна
			OnAbilityCooldownChanged.Broadcast(AbilityTag);
		}
	}
}

void UTronRpgAbilitySystemComponent::RemoveLooseGameplayTag(const FGameplayTag& Tag, int32 Count)
{
	int32 OldCount = GetTagCount(Tag);
	Super::RemoveLooseGameplayTag(Tag, Count);
	int32 NewCount = GetTagCount(Tag);

	if (OldCount != NewCount)
	{
		OnGameplayTagChanged.Broadcast(Tag, NewCount);
	}
}

FGameplayAbilitySpecHandle UTronRpgAbilitySystemComponent::GiveAbilityWithInputTag(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level,
                                                                                   FGameplayTag InputTag)
{
	if (!AbilityClass || !InputTag.IsValid())
	{
		return FGameplayAbilitySpecHandle();
	}

	// Создаем спецификацию способности
	FGameplayAbilitySpec AbilitySpec(AbilityClass, Level);

	// Добавляем тег ввода в DynamicAbilityTags
	AbilitySpec.DynamicAbilityTags.AddTag(InputTag);

	// Выдаем способность
	return GiveAbility(AbilitySpec);
}

bool UTronRpgAbilitySystemComponent::TryActivateAbilityByInputTag(const FGameplayTag& InputTag)
{
	// Находим все способности с указанным тегом ввода
	TArray<FGameplayAbilitySpec*> AbilitySpecs = FindAbilitySpecsFromInputTag(InputTag);

	if (AbilitySpecs.Num() == 0)
	{
		return false;
	}

	// Пытаемся активировать первую подходящую способность
	for (FGameplayAbilitySpec* AbilitySpec : AbilitySpecs)
	{
		if (AbilitySpec && !AbilitySpec->IsActive())
		{
			return TryActivateAbility(AbilitySpec->Handle);
		}
	}

	// Если все способности уже активны, пробуем отменить и активировать заново первую
	if (AbilitySpecs[0])
	{
		CancelAbilityHandle(AbilitySpecs[0]->Handle);
		return TryActivateAbility(AbilitySpecs[0]->Handle);
	}

	return false;
}

bool UTronRpgAbilitySystemComponent::HasMatchingGameplayTagWithExactOption(const FGameplayTag& Tag, bool ExactMatch) const
{
	if (ExactMatch)
	{
		return GetOwnedGameplayTags().HasTagExact(Tag);
	}
	else
	{
		return GetOwnedGameplayTags().HasTag(Tag);
	}
}

// Переопределение базового метода:
bool UTronRpgAbilitySystemComponent::HasMatchingGameplayTag(FGameplayTag Tag) const
{
	return Super::HasMatchingGameplayTag(Tag);
}

TArray<UGameplayAbility*> UTronRpgAbilitySystemComponent::GetActiveAbilitiesWithTag(const FGameplayTag& AbilityTag) const
{
	TArray<UGameplayAbility*> ActiveAbilities;

	// Получаем все активации с указанным тегом
	TArray<FGameplayAbilitySpec*> AbilitySpecs;
	GetActivatableGameplayAbilitySpecsByAllMatchingTags(FGameplayTagContainer(AbilityTag), AbilitySpecs);

	// Проверяем, какие из них активны
	for (FGameplayAbilitySpec* AbilitySpec : AbilitySpecs)
	{
		if (AbilitySpec && AbilitySpec->IsActive())
		{
			TArray<UGameplayAbility*> AbilityInstances = AbilitySpec->GetAbilityInstances();
			ActiveAbilities.Append(AbilityInstances);
		}
	}

	return ActiveAbilities;
}

bool UTronRpgAbilitySystemComponent::CancelAbilityWithTag(const FGameplayTag& WithTag)
{
	// Отменяем все способности с указанным тегом
	if (WithTag.IsValid())
	{
		FGameplayTagContainer Container;
		Container.AddTag(WithTag);
		CancelAbilities(&Container);
		return true;
	}
	return false;
}

void UTronRpgAbilitySystemComponent::NotifyAbilityActivated(const FGameplayAbilitySpecHandle Handle, UGameplayAbility* Ability)
{
	Super::NotifyAbilityActivated(Handle, Ability);

	if (Ability)
	{
		FGameplayAbilitySpec* AbilitySpecFromHandle = FindAbilitySpecFromHandle(Handle);
		FGameplayTag AbilityTag = GetAbilityTagFromSpec(*AbilitySpecFromHandle);


		// Вызываем событие активации способности
		OnAbilityActivated.Broadcast(Ability, Handle, AbilityTag);
	}
}

void UTronRpgAbilitySystemComponent::NotifyAbilityEnded(const FGameplayAbilitySpecHandle Handle, UGameplayAbility* Ability, bool bWasCancelled)
{
	Super::NotifyAbilityEnded(Handle, Ability, bWasCancelled);

	// Дополнительная логика для окончания способности может быть добавлена здесь
}

FGameplayTag UTronRpgAbilitySystemComponent::GetAbilityTagFromSpec(const FGameplayAbilitySpec& AbilitySpec) const
{
	if (AbilitySpec.Ability)
	{
		// Берем первый тег из контейнера AbilityTags
		const FGameplayTagContainer& AbilityTags = AbilitySpec.Ability->AbilityTags;
		if (AbilityTags.Num() > 0)
		{
			return AbilityTags.GetByIndex(0);
		}
	}

	return FGameplayTag();
}

FGameplayTag UTronRpgAbilitySystemComponent::GetInputTagFromSpec(const FGameplayAbilitySpec& AbilitySpec) const
{
	// Проверяем динамические теги на наличие тега ввода
	for (const FGameplayTag& Tag : AbilitySpec.DynamicAbilityTags)
	{
		if (Tag.MatchesTag(FGameplayTag::RequestGameplayTag("Input")))
		{
			return Tag;
		}
	}

	return FGameplayTag();
}

TArray<FGameplayAbilitySpec*> UTronRpgAbilitySystemComponent::FindAbilitySpecsFromInputTag(const FGameplayTag& InputTag)
{
	TArray<FGameplayAbilitySpec*> Results;

	// Проходим по всем доступным способностям
	for (FGameplayAbilitySpec& Spec : ActivatableAbilities.Items)
	{
		// Проверяем динамические теги
		for (const FGameplayTag& Tag : Spec.DynamicAbilityTags)
		{
			if (Tag == InputTag)
			{
				Results.Add(&Spec);
				break;
			}
		}
	}

	return Results;
}
