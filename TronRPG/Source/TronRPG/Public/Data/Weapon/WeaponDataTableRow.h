#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"  // Добавляем для FTableRowBase
#include "GameplayTagContainer.h"
#include "WeaponDataTableRow.generated.h"

USTRUCT(BlueprintType)
struct FWeaponDataTableRow: public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	FText WeaponName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	TSoftObjectPtr<USkeletalMesh> WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	TSoftObjectPtr<UAnimMontage> EquipMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float Damage = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float AttackSpeed = 1.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	FGameplayTagContainer StateTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSoftObjectPtr<UTexture2D> WeaponIcon;
};