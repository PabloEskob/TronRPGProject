// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "Interface/Combat/CombatInterface.h"
#include "TronRpgBaseCharacter.generated.h"

class UTronRpgEnhancedInputComponent;
// Форвард-декларации
class UTronRpgAbilitySystemComponent;
class UTronRpgAttributeSet;
class UTronRpgComboComponent;
class UAnimationComponent;
class UDependencyInjectorComponent;
class UEnhancedAbilityInputComponent; // Обновлено с UAbilityInputComponent
class UWeaponComponent;
class UWeaponDataAsset;
class UGameplayAbility;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponVisibilityChanged, bool, bIsVisible);

UCLASS(Abstract)
class TRONRPG_API ATronRpgBaseCharacter : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	ATronRpgBaseCharacter();

	// Методы жизненного цикла
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	// Реализация IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	// Реализация ICombatInterface
	virtual bool EquipWeapon_Implementation(UWeaponDataAsset* WeaponAsset, float BlendSpaceTransitionDuration = 1.0f) override;
	virtual bool UnequipWeapon_Implementation() override;
	virtual bool ExecuteAttack_Implementation(const FGameplayTag& AttackTag) override;
	virtual float ApplyDamageToTarget_Implementation(AActor* Target, float DamageAmount, bool bIsCritical) override;
	virtual bool HasWeaponEquipped_Implementation() const override;

	// Дополнительные методы для работы с Ability System
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void InitializeAbilities();

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void ApplyBaseEffects();

	// Методы для работы с конкретными способностями
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	bool ActivateAbilityByTag(const FGameplayTag& AbilityTag);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	bool IsAbilityActive(const FGameplayTag& AbilityTag) const;

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	UGameplayAbility* GetAbilityByTag(const FGameplayTag& AbilityTag) const;

	// Методы для получения компонентов
	UFUNCTION(BlueprintPure, Category = "Abilities")
	UTronRpgAttributeSet* GetAttributeSet() const { return AttributeSet; }

	UFUNCTION(BlueprintPure, Category = "Combat")
	UTronRpgComboComponent* GetComboComponent() const { return ComboComponent; }

	UFUNCTION(BlueprintPure, Category = "Animation")
	UAnimationComponent* GetAnimationComponent() const { return AnimationComponent; }

	UFUNCTION(BlueprintPure, Category = "Weapon")
	UWeaponComponent* GetWeaponComponent() const { return WeaponComponent; }

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Делегат для обработки изменения видимости оружия
	UPROPERTY(BlueprintAssignable, Category = "Weapon")
	FOnWeaponVisibilityChanged OnWeaponVisibilityChanged;

	// Обработчик делегата изменения видимости оружия
	UFUNCTION()
	void UpdateWeaponVisibility(bool bIsVisible);

protected:
	/** Компонент системы способностей (GAS) */
	UPROPERTY(VisibleAnywhere, Replicated, BlueprintReadOnly, Category = "Abilities")
	UTronRpgAbilitySystemComponent* AbilitySystemComponent;

	/** Набор атрибутов персонажа */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	UTronRpgAttributeSet* AttributeSet;

	/** Компонент для комбо-атак */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	UTronRpgComboComponent* ComboComponent;

	/** Компонент для управления анимациями */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Animation")
	UAnimationComponent* AnimationComponent;

	/** Компонент для внедрения зависимостей */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dependencies")
	UDependencyInjectorComponent* DependencyInjector;

	/** Компонент для обработки ввода способностей */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input")
	UTronRpgEnhancedInputComponent* AbilityInputComponent; // Обновлено с UAbilityInputComponent

	/** Компонент для управления оружием */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	UWeaponComponent* WeaponComponent;

	/** Оружие по умолчанию */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	UWeaponDataAsset* DefaultWeaponAsset;

	/** Базовые способности персонажа */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	TArray<TSubclassOf<class UGameplayAbility>> BaseAbilities;

	/** Постоянные эффекты, применяемые к персонажу */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	TArray<TSubclassOf<class UGameplayEffect>> PersistentEffects;

	/** Флаг, указывающий, что базовые способности уже были выданы */
	UPROPERTY(Transient)
	bool bAbilitiesInitialized;

	/** Инициализация компонентов */
	virtual void SetupComponents();

	/** Инициализация базового оружия */
	virtual void InitializeDefaultWeapon();

private:
	/** Серверная функция для экипировки оружия */
	UFUNCTION(Server, Reliable)
	void Server_EquipWeapon(UWeaponDataAsset* WeaponAsset, float BlendSpaceTransitionDuration);

	/** Серверная функция для снятия оружия */
	UFUNCTION(Server, Reliable)
	void Server_UnequipWeapon();
};
