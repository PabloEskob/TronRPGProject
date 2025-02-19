// Tron

#pragma once

#include "CoreMinimal.h"
#include "Actor/Weapon/WeaponBase.h"
#include "UObject/Interface.h"
#include "WeaponSystemInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable)
class UWeaponSystemInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TRONRPG_API IWeaponSystemInterface
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "WeaponSystem")
	void OnWeaponEquipped(AWeaponBase* Weapon);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "WeaponSystem")
	void OnWeaponUnequipped(AWeaponBase* Weapon);
};
