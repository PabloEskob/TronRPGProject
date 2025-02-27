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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponVisibilityChanged, bool, bIsVisible);

UCLASS(Abstract)
class TRONRPG_API ATronRpgBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ATronRpgBaseCharacter();

	virtual void BeginPlay() override;
	
	UFUNCTION()
	void UpdateWeaponVisibility(bool bIsVisible);
	
	UFUNCTION(BlueprintCallable)
	void EquipWeapon(UWeaponDataAsset* WeaponAsset, float BlendSpaceTransitionDuration = 1.0f);

	UFUNCTION(BlueprintCallable)
	void UnequipWeapon();

	UFUNCTION(BlueprintCallable)
	void EquipWeaponByTag(FGameplayTag WeaponTag);

	UFUNCTION(BlueprintPure)
	UAbilitySystemComponent* GetAbilitySystemComponent() const;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(BlueprintAssignable)
	FOnWeaponVisibilityChanged OnWeaponVisibilityChanged;

protected:
	UPROPERTY(VisibleAnywhere, Replicated, BlueprintReadOnly)
	class UTronRpgAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UTronRpgAttributeSet* AttributeSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UTronRpgComboComponent* ComboComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UAnimationComponent* AnimationComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UDependencyInjectorComponent* DependencyInjector;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UAbilityInputComponent* AbilityInputComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UWeaponComponent* WeaponComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UWeaponDataAsset* DefaultWeaponAsset;
};
