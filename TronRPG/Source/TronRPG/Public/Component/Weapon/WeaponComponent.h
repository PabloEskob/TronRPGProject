// Tron

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"


class UWeaponDataAsset;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TRONRPG_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(ReplicatedUsing=OnRep_CurrentWeapon, BlueprintReadOnly)
	UWeaponDataAsset* CurrentWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* MainHandMeshComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* OffHandMeshComponent;

	UFUNCTION(BlueprintCallable)
	void EquipWeapon(UWeaponDataAsset* WeaponAsset);

	UFUNCTION(BlueprintCallable)
	void UnequipWeapon();

	UFUNCTION(BlueprintCallable)
	void EquipWeaponByTag(FGameplayTag WeaponTag);

	void UpdateWeaponVisuals(bool bIsVisible);

protected:
	UPROPERTY()
	class UTronRpgAbilitySystemComponent* AbilitySystemComponent;

	void BeginPlay() override;

	void UpdateGameplayTags(UWeaponDataAsset* WeaponAsset, bool bAdd);

	UFUNCTION()
	void OnRep_CurrentWeapon();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
