#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MeleeAttackConfig.generated.h"

USTRUCT(BlueprintType)
struct FWeaponTraceSocketConfig : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    FGameplayTag WeaponTypeTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    TArray<FName> SocketNames;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon", meta = (ClampMin = "1.0"))
    float SocketTraceRadius = 10.0f;
};

USTRUCT(BlueprintType)
struct FMeleeAttackConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
    float BaseDamage = 20.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage", meta = (ClampMin = "10.0"))
    float AttackRadius = 150.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage", meta = (ClampMin = "0.0", ClampMax = "180.0"))
    float AttackAngle = 60.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage", meta = (ClampMin = "1.0"))
    float CriticalMultiplier = 2.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage", meta = (ClampMin = "0.0", ClampMax = "1.0"))
    float CriticalChance = 0.1f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage", meta = (ClampMin = "0.0"))
    float MinimumDamage = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targeting", meta = (ClampMin = "1"))
    int32 MaxTargetsPerAttack = 5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combo", meta = (ClampMin = "0.0"))
    float ComboMultiplierPerHit = 0.2f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targeting")
    FGameplayTagContainer TargetRequiredTags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targeting")
    FGameplayTagContainer TargetBlockedTags;
};

USTRUCT(BlueprintType)
struct FComboConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combo", meta = (ClampMin = "1"))
    int32 MaxComboCount = 3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combo")
    FString SectionPrefix = "Attack_";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combo")
    bool bResetOnCancel = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combo")
    bool bRequireAnimationForDamage = true;
};