// Tron


#include "GameInstanceSubsystem/WeaponAsset/TronRpgWeaponAssetManager.h"

#include "Data/Weapon/WeaponDataAsset.h"
#include "Engine/AssetManager.h"

bool UTronRpgWeaponAssetManager::ShouldCreateSubsystem(UObject* Outer) const
{
	if (this->GetClass()->IsInBlueprint() && Super::ShouldCreateSubsystem(Outer))
	{
		UE_LOG(LogTemp, Log, TEXT("CreateSubsystem"));
		return true;
	}
	return false;
}

void UTronRpgWeaponAssetManager::PreloadAllWeaponAssets()
{
	// Array to store assets that need loading
	TArray<FSoftObjectPath> WeaponAssetsToLoad;

	// Check each weapon asset in the WeaponAssets array
	for (const TSoftObjectPtr<UWeaponDataAsset>& WeaponAssetPtr : WeaponAssets)
	{
		if (!WeaponAssetPtr.IsValid()) // Not loaded yet
		{
			WeaponAssetsToLoad.AddUnique(WeaponAssetPtr.ToSoftObjectPath());
		}
		else // Already loaded
		{
			UWeaponDataAsset* WeaponAsset = WeaponAssetPtr.Get();
			LoadedWeaponAssets.Add(FName(*WeaponAsset->WeaponName.ToString()), WeaponAsset);
		}
	}

	// Asynchronously load any unloaded WeaponAssets
	if (WeaponAssetsToLoad.Num() > 0)
	{
		UAssetManager::GetStreamableManager().RequestAsyncLoad(
			WeaponAssetsToLoad,
			[this]() // Callback after loading completes
			{
				LoadInternalAssets(); // Proceed to load internal assets
			},
			FStreamableManager::AsyncLoadHighPriority
		);
	}
	else
	{
		// All assets are already loaded, proceed directly
		LoadInternalAssets();
	}
}

void UTronRpgWeaponAssetManager::LoadInternalAssets()
{
	TArray<FSoftObjectPath> AssetsToLoad;

	// Gather internal assets from all loaded WeaponAssets
	for (const TSoftObjectPtr<UWeaponDataAsset>& WeaponAssetPtr : WeaponAssets)
	{
		if (WeaponAssetPtr.IsValid())
		{
			UWeaponDataAsset* WeaponAsset = WeaponAssetPtr.Get();
			// Add internal asset paths (e.g., mesh, animations)
			AssetsToLoad.AddUnique(WeaponAsset->WeaponMesh.ToSoftObjectPath());
			AssetsToLoad.AddUnique(WeaponAsset->AdditionalWeaponMesh.ToSoftObjectPath());
			AssetsToLoad.AddUnique(WeaponAsset->EquipMontage.ToSoftObjectPath());
			AssetsToLoad.AddUnique(WeaponAsset->UnequipMontage.ToSoftObjectPath());
			AssetsToLoad.AddUnique(WeaponAsset->WalkForwardBlendSpace.ToSoftObjectPath());
			AssetsToLoad.AddUnique(WeaponAsset->WalkBackwardBlendSpace.ToSoftObjectPath());
			// Add to loaded assets map
			LoadedWeaponAssets.Add(FName(*WeaponAsset->WeaponName.ToString()), WeaponAsset);
		}
	}

	// Load all internal assets asynchronously
	if (AssetsToLoad.Num() > 0)
	{
		UAssetManager::GetStreamableManager().RequestAsyncLoad(
			AssetsToLoad,
			[this]() // Callback after loading completes
			{
				UE_LOG(LogTemp, Log, TEXT("All weapon assets preloaded. LoadedWeaponAssets count: %d"), LoadedWeaponAssets.Num());
			},
			FStreamableManager::AsyncLoadHighPriority
		);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("No internal assets to load."));
	}
}

UTronRpgWeaponAssetManager* UTronRpgWeaponAssetManager::Get(const UObject* WorldContextObject)
{
	if (WorldContextObject)
	{
		if (UGameInstance* GameInstance = WorldContextObject->GetWorld()->GetGameInstance())
		{
			return GameInstance->GetSubsystem<UTronRpgWeaponAssetManager>();
		}
	}
	return nullptr;
}

TArray<UWeaponDataAsset*> UTronRpgWeaponAssetManager::GetWeaponsByTag(FGameplayTag Tag) const
{
	TArray<UWeaponDataAsset*> MatchingWeapons;
	for (const auto& Pair : LoadedWeaponAssets)
	{
		UWeaponDataAsset* Weapon = Pair.Value;
		if (Weapon && Weapon->WeaponTags.HasTag(Tag))
		{
			MatchingWeapons.Add(Weapon);
		}
	}
	return MatchingWeapons;
}
