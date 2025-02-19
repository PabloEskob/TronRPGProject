#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"


namespace GameplayTags
{
	namespace Weapon
	{
		extern const FGameplayTag Equipped;
		extern const FGameplayTag Broken;
	}


	namespace Attack
	{
		extern const FGameplayTag Melee;
	}


	namespace State
	{
	}
	
	void InitializeTags();
	bool IsValidTag(const FGameplayTag& Tag, const FString& TagName);
	bool AreTagsInitialized();
}
