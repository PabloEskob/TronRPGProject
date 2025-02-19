// Tron


#include "GameInstanceSubsystem/WeaponAsset/TronRpgWeaponAssetManager.h"

#include "Data/Weapon/WeaponDataAsset.h"
#include "Engine/AssetManager.h"

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

void UTronRpgWeaponAssetManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("WeaponAssetManager initialized."));
}

void UTronRpgWeaponAssetManager::Deinitialize()
{
	LoadedWeaponAssets.Empty();
	CachedIdleAnimations.Empty();
	CachedBlendSpaces.Empty();
	Super::Deinitialize();
	UE_LOG(LogTemp, Log, TEXT("WeaponAssetManager deinitialized."));
}

void UTronRpgWeaponAssetManager::PreloadAllWeaponAssets()
{
	TArray<FSoftObjectPath> AssetsToLoad;
	for (const TSoftObjectPtr<UWeaponDataAsset>& WeaponAssetPtr : WeaponAssets)
	{
		if (WeaponAssetPtr.IsValid())
		{
			UWeaponDataAsset* WeaponAsset = WeaponAssetPtr.Get();
			LoadWeaponAssets(WeaponAsset);
			AssetsToLoad.Add(WeaponAsset->EquipMontage.ToSoftObjectPath());
			AssetsToLoad.Add(WeaponAsset->AttackMontage.ToSoftObjectPath());
			AssetsToLoad.Add(WeaponAsset->WeaponMesh.ToSoftObjectPath());
			AssetsToLoad.Add(WeaponAsset->IdleAnimation.ToSoftObjectPath());
			AssetsToLoad.Add(WeaponAsset->WalkForwardBlendSpace.ToSoftObjectPath());
			AssetsToLoad.Add(WeaponAsset->RunForwardBlendSpace.ToSoftObjectPath());
			AssetsToLoad.Add(WeaponAsset->WalkBackwardBlendSpace.ToSoftObjectPath());
			AssetsToLoad.Add(WeaponAsset->RunBackwardBlendSpace.ToSoftObjectPath());
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
			for (const TSoftObjectPtr<UWeaponDataAsset>& WeaponAssetPtr : WeaponAssets)
			{
				if (WeaponAssetPtr.IsValid() && !LoadedWeaponAssets.Contains(FName(*WeaponAssetPtr->WeaponName.ToString())))
				{
					UWeaponDataAsset* WeaponAsset = WeaponAssetPtr.Get();
					LoadWeaponAssets(WeaponAsset);
					LoadedWeaponAssets.Add(FName(*WeaponAsset->WeaponName.ToString()), WeaponAsset);
				}
			}
			UE_LOG(LogTemp, Log, TEXT("All weapon assets preloaded."));
		},
		FStreamableManager::AsyncLoadHighPriority
	);
}

UWeaponDataAsset* UTronRpgWeaponAssetManager::GetWeaponAssetByName(FName WeaponName) const
{
	if (UWeaponDataAsset* const* WeaponAsset = LoadedWeaponAssets.Find(WeaponName))
	{
		return *WeaponAsset;
	}
	return nullptr;
}

TArray<UWeaponDataAsset*> UTronRpgWeaponAssetManager::GetAllWeaponAssets() const
{
	TArray<UWeaponDataAsset*> AllWeapons;
	LoadedWeaponAssets.GenerateValueArray(AllWeapons);
	return AllWeapons;
}

void UTronRpgWeaponAssetManager::LoadWeaponAssets(UWeaponDataAsset* WeaponAsset)
{
	if (!WeaponAsset)
	{
		return;
	}

	FName WeaponName = FName(*WeaponAsset->WeaponName.ToString());

	// Кэшируем анимации
	if (WeaponAsset->IdleAnimation.IsValid())
	{
		CachedIdleAnimations.Add(WeaponName, WeaponAsset->IdleAnimation.Get());
	}

	// Используем FString для конкатенации строк
	FString WeaponNameStr = WeaponName.ToString();
	if (WeaponAsset->WalkForwardBlendSpace.IsValid())
	{
		FName Key = FName(*(WeaponNameStr + TEXT("_WalkForward")));
		CachedBlendSpaces.Add(Key, WeaponAsset->WalkForwardBlendSpace.Get());
	}
	if (WeaponAsset->RunForwardBlendSpace.IsValid())
	{
		FName Key = FName(*(WeaponNameStr + TEXT("_RunForward")));
		CachedBlendSpaces.Add(Key, WeaponAsset->RunForwardBlendSpace.Get());
	}
	if (WeaponAsset->WalkBackwardBlendSpace.IsValid())
	{
		FName Key = FName(*(WeaponNameStr + TEXT("_WalkBackward")));
		CachedBlendSpaces.Add(Key, WeaponAsset->WalkBackwardBlendSpace.Get());
	}
	if (WeaponAsset->RunBackwardBlendSpace.IsValid())
	{
		FName Key = FName(*(WeaponNameStr + TEXT("_RunBackward")));
		CachedBlendSpaces.Add(Key, WeaponAsset->RunBackwardBlendSpace.Get());
	}
}

bool UTronRpgWeaponAssetManager::IsAssetLoaded(const TSoftObjectPtr<UObject>& Asset) const
{
	return Asset.IsValid();
}
