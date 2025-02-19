// Tron

#pragma once

#include "CoreMinimal.h"
#include "Actor/Weapon/WeaponBase.h"
#include "WeaponFactory.generated.h"

/**
 * 
 */
UCLASS()
class TRONRPG_API UWeaponFactory : public UObject
{
	GENERATED_BODY()

public:
	static AWeaponBase* CreateWeapon(UWeaponDataAsset* WeaponDataAsset, UWorld* World, ACharacter* Owner);

	static void CreateWeaponFromDataTable(UDataTable* WeaponTable, FName RowName, UWorld* World, ACharacter* Owner);

private:
	static void LoadWeaponResourcesAsync(UWeaponDataAsset* WeaponDataAsset, TFunction<void(bool bSuccess)> OnLoadedCallback);
};
