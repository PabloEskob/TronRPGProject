#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"


namespace GameplayTags
{
	namespace Weapon
	{
		extern const FGameplayTag Equipped;
		extern const FGameplayTag Broken;
		extern const FGameplayTag Default;  // Новый тег для дефолтного оружия
	}

	namespace Attack
	{
		extern const FGameplayTag Melee;
		extern const FGameplayTag Ranged;  // Новый тег для дальних атак
	}

	namespace State
	{
		// Можно добавить теги сюда, если нужно
	}
    
	void InitializeTags();
	bool IsValidTag(const FGameplayTag& Tag, const FString& TagName);
	bool AreTagsInitialized();
}
