// Tron

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "TronRpgCombatController.generated.h"


class ATronRpgBaseCharacter;
/**
 * 
 */
UCLASS()
class TRONRPG_API UTronRpgCombatController : public UObject
{
	GENERATED_BODY()

public:
	UTronRpgCombatController();

	// Инициализация с персонажем
	void Initialize(ATronRpgBaseCharacter* InCharacter);

	// Функции боя
	bool ExecuteAttack(const FGameplayTag& AttackTag);
	bool ApplyDamage(AActor* Target, float DamageAmount, bool bIsCritical);

private:
	UPROPERTY()
	TWeakObjectPtr<ATronRpgBaseCharacter> OwnerCharacter;
};
