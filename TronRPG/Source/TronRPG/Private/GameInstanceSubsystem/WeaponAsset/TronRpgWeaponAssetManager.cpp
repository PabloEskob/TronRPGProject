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
	TArray<FSoftObjectPath> AssetsToLoad;
	for (const TSoftObjectPtr<UWeaponDataAsset>& WeaponAssetPtr : WeaponAssets)
	{
		if (WeaponAssetPtr.IsValid())
		{
			UWeaponDataAsset* WeaponAsset = WeaponAssetPtr.Get();
			AssetsToLoad.Add(WeaponAsset->WeaponMesh.ToSoftObjectPath());
			AssetsToLoad.Add(WeaponAsset->EquipMontage.ToSoftObjectPath());
			AssetsToLoad.Add(WeaponAsset->WalkForwardBlendSpace.ToSoftObjectPath());
			AssetsToLoad.Add(WeaponAsset->WalkBackwardBlendSpace.ToSoftObjectPath());
			LoadedWeaponAssets.Add(FName(*WeaponAsset->WeaponName.ToString()), WeaponAsset);
		}
		else
		{
			AssetsToLoad.Add(WeaponAssetPtr.ToSoftObjectPath());
		}
	}

	UAssetManager::GetStreamableManager().RequestAsyncLoad(
		AssetsToLoad,
		[this]()
		{
			UE_LOG(LogTemp, Log, TEXT("All weapon assets preloaded."));
		},
		FStreamableManager::AsyncLoadHighPriority
	);
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
