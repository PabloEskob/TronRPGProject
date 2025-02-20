// Tron
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "WeaponDataAsset.generated.h"

class UGameplayEffect;
class UGameplayAbility;

USTRUCT(BlueprintType)
struct FWeaponUIData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    FText WeaponName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSoftObjectPtr<UTexture2D> WeaponIcon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    float Damage = 1.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    float AttackSpeed = 10.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    FGameplayTagContainer StateTags;
};

UCLASS(BlueprintType)
class TRONRPG_API UWeaponDataAsset : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    virtual FPrimaryAssetId GetPrimaryAssetId() const override
    {
        return FPrimaryAssetId("Weapon", *WeaponName.ToString());
    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    FText WeaponName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    TSoftObjectPtr<USkeletalMesh> WeaponMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    TSoftObjectPtr<UAnimMontage> EquipMontage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    TSoftObjectPtr<UAnimMontage> AttackMontage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    TSubclassOf<UAnimInstance> WeaponAnimInstanceClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    TSubclassOf<UGameplayAbility> AttackAbilityClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    float Damage = 10.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    float AttackSpeed = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    FGameplayTagContainer WeaponStateTags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    FGameplayTag WeaponTypeTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization")
    TArray<TSoftObjectPtr<UMaterialInstance>> AvailableSkins;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization")
    TArray<TSubclassOf<UGameplayEffect>> AvailableUpgrades;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSoftObjectPtr<UTexture2D> WeaponIcon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
    TSoftObjectPtr<UBlendSpace> WalkForwardBlendSpace;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
    TSoftObjectPtr<UBlendSpace> WalkBackwardBlendSpace;
};
