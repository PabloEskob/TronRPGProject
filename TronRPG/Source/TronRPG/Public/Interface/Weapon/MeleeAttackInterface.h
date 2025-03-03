// Tron

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MeleeAttackInterface.generated.h"

class UAnimMontage;
// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UMeleeAttackInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Интерфейс для сущностей, поддерживающих атаки ближнего боя
 */
class TRONRPG_API IMeleeAttackInterface
{
	GENERATED_BODY()

public:
	/** Получить текущий счетчик комбо */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Melee")
	int32 GetComboCount() const;
	virtual int32 GetComboCount_Implementation() const = 0;

	/** Увеличить счетчик комбо */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Melee")
	void IncrementCombo(bool bResetTimer);
	virtual void IncrementCombo_Implementation(bool bResetTimer) = 0;

	/** Сбросить счетчик комбо */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Melee")
	void ResetCombo(bool bFireEvent);
	virtual void ResetCombo_Implementation(bool bFireEvent) = 0;

	/** Получить сокеты для трассировки атаки */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Melee")
	TArray<FName> GetWeaponTraceSocketNames() const;
	virtual TArray<FName> GetWeaponTraceSocketNames_Implementation() const = 0;

	/** Проверить, есть ли у сущности оружие с указанным тегом */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Melee")
	bool HasWeaponWithTag(const FGameplayTag& WeaponTag) const;
	virtual bool HasWeaponWithTag_Implementation(const FGameplayTag& WeaponTag) const = 0;

	/** Воспроизвести анимацию атаки */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Melee")
	float PlayAttackAnimation(UAnimMontage* Montage, float PlayRate, FName SectionName);
	virtual float PlayAttackAnimation_Implementation(UAnimMontage* Montage, float PlayRate, FName SectionName) = 0;
};
