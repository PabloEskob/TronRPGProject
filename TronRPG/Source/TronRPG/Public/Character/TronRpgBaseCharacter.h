// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "TronRpgBaseCharacter.generated.h"

class UWeaponDataAsset;
class UCharacterAnimInstance;
class UAbilityInputComponent;
class UTronRpgAbilitySystemComponent;
class UTronRpgAttributeSet;
class UWeaponManagerComponent;
class UInventoryComponent;
class UTronRpgComboComponent;
class UAnimationComponent;
class UDependencyInjectorComponent;

UCLASS(Abstract)
class TRONRPG_API ATronRpgBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ATronRpgBaseCharacter();

	virtual void BeginPlay() override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void EquipWeapon(UWeaponDataAsset* WeaponAsset);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void UnequipWeapon();

	UFUNCTION()
	void OnRep_CurrentWeapon();
	

	UFUNCTION()
	void OnWeaponAssetsPreloadComplete();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, Category = "Components")
	UTronRpgAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UTronRpgAttributeSet* AttributeSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UTronRpgComboComponent* ComboComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAnimationComponent* AnimationComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UDependencyInjectorComponent* DependencyInjector;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAbilityInputComponent* AbilityInputComponent;

	UPROPERTY(ReplicatedUsing = OnRep_CurrentWeapon, BlueprintReadOnly, Category = "Weapon")
	UWeaponDataAsset* CurrentWeapon;

	UPROPERTY()
	UCharacterAnimInstance* CharacterAnimInstance;

	UPROPERTY()
	float LastWeaponSwitchTime;

	UPROPERTY()
	bool IsSwitchingWeapon;

	UPROPERTY()
	UWeaponDataAsset* PendingWeapon;

private:
	void ProcessWeaponSwitch();
};
