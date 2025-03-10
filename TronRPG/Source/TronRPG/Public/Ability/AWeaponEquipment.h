// Tron

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AWeaponEquipment.generated.h"

class UWeaponDataAsset;
/**
 * 
 */
UCLASS()
class TRONRPG_API UAWeaponEquipment : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	FGameplayTag WeaponTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	UWeaponDataAsset* WeaponAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation", meta = (ClampMin = "0.0"))
	float BlendSpaceTransitionDuration;
};
