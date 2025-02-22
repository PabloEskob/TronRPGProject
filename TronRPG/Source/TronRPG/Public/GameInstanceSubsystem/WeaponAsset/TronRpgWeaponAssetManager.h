// Tron

#pragma once

#include "CoreMinimal.h"
#include "Data/Weapon/WeaponDataAsset.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TronRpgWeaponAssetManager.generated.h"

/**
 * 
 */

UCLASS(Blueprintable)
class TRONRPG_API UTronRpgWeaponAssetManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	// Предварительная загрузка всех ассетов оружий
	void PreloadAllWeaponAssets();
	void LoadInternalAssets();

	static UTronRpgWeaponAssetManager* Get(const UObject* WorldContextObject);

	UFUNCTION()
	TArray<UWeaponDataAsset*> GetWeaponsByTag(FGameplayTag Tag) const;

protected:
	// Кэш загруженных ассетов
	UPROPERTY()
	TMap<FName, UWeaponDataAsset*> LoadedWeaponAssets;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Manager")
	TArray<TSoftObjectPtr<UWeaponDataAsset>> WeaponAssets;
};
