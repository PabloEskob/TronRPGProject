#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Engine/DataTable.h"
#include "MeleeAttackAbility.generated.h"

class ATronRpgBaseCharacter;
class UAnimMontage;
class UCurveFloat;

/**
 * Способность ближнего боя для нанесения урона, проигрывания анимаций и управления комбо-атаками.
 * Использует GAS для интеграции с системой способностей и тегов.
 */
UCLASS()
class TRONRPG_API UMeleeAttackAbility : public UGameplayAbility
{
    GENERATED_BODY()
};