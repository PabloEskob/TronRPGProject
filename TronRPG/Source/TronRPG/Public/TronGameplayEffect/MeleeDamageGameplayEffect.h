#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "MeleeDamageGameplayEffect.generated.h"

/**
 * Эффект нанесения урона от атаки ближнего боя
 */
UCLASS()
class TRONRPG_API UMeleeDamageGameplayEffect : public UGameplayEffect
{
	GENERATED_BODY()

public:
	UMeleeDamageGameplayEffect();
};
