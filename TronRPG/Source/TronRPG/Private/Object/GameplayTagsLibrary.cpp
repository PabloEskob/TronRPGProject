#include "Object/GameplayTagsLibrary.h"
#include "GameplayTagContainer.h"
#include "Logging/LogMacros.h"

namespace GameplayTags
{
	namespace WeaponType
	{
		const FGameplayTag Sword = FGameplayTag::RequestGameplayTag(FName("WeaponType.Sword"));
		const FGameplayTag None = FGameplayTag::RequestGameplayTag(FName("WeaponType.None"));
		const FGameplayTag SwordAndShield = FGameplayTag::RequestGameplayTag(FName("WeaponType.SwordAndShield"));
	}

	namespace Weapon
	{
		const FGameplayTag Equipped = FGameplayTag::RequestGameplayTag(FName("Weapon.Equipped"));
		const FGameplayTag Broken = FGameplayTag::RequestGameplayTag(FName("Weapon.Broken"));
		const FGameplayTag Default = FGameplayTag::RequestGameplayTag(FName("Weapon.Default"));
	}

	namespace Attack
	{
		const FGameplayTag Melee = FGameplayTag::RequestGameplayTag(FName("GameplayCue.Attack.Melee"));
		const FGameplayTag Ranged = FGameplayTag::RequestGameplayTag(FName("GameplayCue.Attack.Ranged"));
	}

	namespace State
	{
	}

	static bool bTagsInitialized = false;

	bool IsValidTag(const FGameplayTag& Tag, const FString& TagName)
	{
		if (!Tag.IsValid())
		{
			UE_LOG(LogGameplayTags, Error,
			       TEXT("Gameplay Tag '%s' not found. Make sure it is defined in DefaultGameplayTags.ini or Gameplay Tags editor."), *TagName);
			return false;
		}
		return true;
	}

	void InitializeTags()
	{
		if (bTagsInitialized)
		{
			UE_LOG(LogGameplayTags, Warning, TEXT("Gameplay Tags are already initialized."));
			return;
		}

		IsValidTag(Weapon::Equipped, TEXT("Weapon.Equipped"));
		IsValidTag(Weapon::Broken, TEXT("Weapon.Broken"));
		IsValidTag(Weapon::Default, TEXT("Weapon.Default"));
		IsValidTag(Attack::Melee, TEXT("GameplayCue.Attack.Melee"));
		IsValidTag(Attack::Ranged, TEXT("GameplayCue.Attack.Ranged")); 
		IsValidTag(Weapon::Default, TEXT("WeaponType.Sword"));
		IsValidTag(Attack::Melee, TEXT("WeaponType.None"));
		IsValidTag(Attack::Ranged, TEXT("WeaponType.SwordAndShield")); 

		bTagsInitialized = true;
		UE_LOG(LogGameplayTags, Log, TEXT("Gameplay Tags initialized successfully."));
	}

	bool AreTagsInitialized()
	{
		return bTagsInitialized;
	}
}
