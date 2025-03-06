// Tron


#include "Config/TronAbilitySet.h"

void UTronAbilitySet::AddOrModifyAbility(const FGameplayTag& AbilityTag, TSubclassOf<UGameplayAbility> AbilityClass, int32 Level, const FString& Name)
{
	// Ищем существующую способность с таким тегом
	for (int32 i = 0; i < Abilities.Num(); ++i)
	{
		if (Abilities[i].AbilityTag == AbilityTag)
		{
			// Нашли существующую запись - обновляем её
			Abilities[i].AbilityClass = AbilityClass;
			Abilities[i].AbilityLevel = Level;

			if (!Name.IsEmpty())
			{
				Abilities[i].TagName = Name;
			}

			return;
		}
	}

	// Не нашли существующую запись - добавляем новую
	FTronAbilityInfo NewAbility;
	NewAbility.AbilityTag = AbilityTag;
	NewAbility.AbilityClass = AbilityClass;
	NewAbility.AbilityLevel = Level;
	NewAbility.TagName = Name.IsEmpty() ? (AbilityClass ? AbilityClass->GetName() : TEXT("Unknown")) : Name;

	Abilities.Add(NewAbility);
}

bool UTronAbilitySet::GetAbilityByTag(const FGameplayTag& AbilityTag, FTronAbilityInfo& OutAbilityInfo) const
{
	for (const FTronAbilityInfo& AbilityInfo : Abilities)
	{
		if (AbilityInfo.AbilityTag == AbilityTag)
		{
			OutAbilityInfo = AbilityInfo;
			return true;
		}
	}

	return false;
}
