// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
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

	// Экипировка и снятие оружия
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void EquipWeapon(UWeaponDataAsset* WeaponAsset);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void UnequipWeapon();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void EquipWeaponByTag(FGameplayTag WeaponTag);

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	UWeaponDataAsset* DefaultWeaponAsset;

	// Текущее оружие
	UPROPERTY(VisibleAnywhere,Replicated, BlueprintReadOnly, Category = "Weapon")
	UWeaponDataAsset* CurrentWeapon;

	// Тег экипировки
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay Tags")
	FGameplayTag EquippedTag;

	UPROPERTY()
	UCharacterAnimInstance* CharacterAnimInstance;
};
