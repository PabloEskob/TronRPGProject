// Tron
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "WeaponDataAsset.generated.h"

class UGameplayEffect;
class UGameplayAbility;

UCLASS(BlueprintType)
class TRONRPG_API UWeaponDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("Weapon", *WeaponName.ToString());
	}

	// Название оружия
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	FText WeaponName;

	// Меш оружия
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	TSoftObjectPtr<UStaticMesh> WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	TSoftObjectPtr<UStaticMesh> AdditionalWeaponMesh;

	// Монтаж экипировки
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TSoftObjectPtr<UAnimMontage> EquipMontage;

	// Монтаж снятия
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TSoftObjectPtr<UAnimMontage> UnequipMontage;

	// Теги оружия (например, "Weapon.Sword", "Weapon.Bow")
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	FGameplayTagContainer WeaponTags;

	// Теги Slot
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	FGameplayTagContainer WeaponSlot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TSoftObjectPtr<UBlendSpace> WalkForwardBlendSpace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TSoftObjectPtr<UBlendSpace> WalkBackwardBlendSpace;
};
