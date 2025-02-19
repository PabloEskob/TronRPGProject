// Tron

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "WeaponStateComponent.generated.h"

class AWeaponBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDurabilityChanged, AWeaponBase*, Weapon, int32, NewDurability);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TRONRPG_API UWeaponStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UWeaponStateComponent();

	// Установка состояния оружия (например, "Weapon.Broken")
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void SetWeaponState(FGameplayTag StateTag, bool bEnable);

	// Проверка наличия состояния оружия
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool HasWeaponState(FGameplayTag StateTag) const;

	// Установка прочности оружия
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void SetDurability(int32 NewDurability);

	// Инициализация максимальной прочности
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void InitializeDurability(int32 NewMaxDurability);
	
	// Событие изменения прочности оружия (для обновления UI)
	UPROPERTY(BlueprintAssignable, Category = "Weapon")
	FOnDurabilityChanged OnDurabilityChanged;

	// Флаг экипировки оружия
	UPROPERTY(ReplicatedUsing = OnRep_IsEquipped, BlueprintReadOnly, Category = "Weapon")
	bool bIsEquipped = false;

	// Текущая прочность оружия
	UPROPERTY(ReplicatedUsing = OnRep_Durability, BlueprintReadOnly, Category = "Weapon")
	int32 CurrentDurability = 100;

	// Максимальная прочность оружия
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	int32 MaxDurability = 100;

	// Теги состояния оружия (например, "Weapon.Broken")
	UPROPERTY(ReplicatedUsing = OnRep_StateTags, BlueprintReadOnly, Category = "Weapon")
	FGameplayTagContainer WeaponStateTags;

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Репликация флага экипировки
	UFUNCTION()
	void OnRep_IsEquipped();

	// Репликация прочности
	UFUNCTION()
	void OnRep_Durability();

	// Репликация тегов состояния
	UFUNCTION()
	void OnRep_StateTags();
};
