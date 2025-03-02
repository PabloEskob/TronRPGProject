#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "CombatInterface.generated.h"

class UWeaponDataAsset;

UINTERFACE(MinimalAPI, BlueprintType)
class UCombatInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Интерфейс боевой системы
 * Определяет методы для управления боевыми действиями персонажа
 */
class TRONRPG_API ICombatInterface
{
	GENERATED_BODY()

public:
	// Экипировка оружия
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Combat|Weapon")
	bool EquipWeapon(UWeaponDataAsset* WeaponAsset, float BlendSpaceTransitionDuration);

	// Снятие оружия
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Combat|Weapon")
	bool UnequipWeapon();

	// Выполнение атаки с указанным тегом
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Combat|Attack")
	bool ExecuteAttack(const FGameplayTag& AttackTag);

	// Применение урона к цели
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Combat|Damage")
	float ApplyDamageToTarget(AActor* Target, float DamageAmount, bool bIsCritical);

	// Проверка наличия экипированного оружия
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Combat|Weapon")
	bool HasWeaponEquipped() const;
};
