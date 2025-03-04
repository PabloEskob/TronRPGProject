// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "Interface/Weapon/MeleeAttackInterface.h"
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
class UWeaponComponent;

/**
 * Делегат для обработки изменения видимости оружия
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponVisibilityChanged, bool, bIsVisible);

/**
 * Базовый класс персонажа в TronRPG
 * Содержит основные компоненты и функциональность для всех персонажей игры
 */
UCLASS(Abstract)
class TRONRPG_API ATronRpgBaseCharacter : public ACharacter, public IAbilitySystemInterface, public IMeleeAttackInterface
{
	GENERATED_BODY()

public:
	ATronRpgBaseCharacter();

	// Реализация IMeleeAttackInterface
	virtual int32 GetComboCount_Implementation() const override;
	virtual void IncrementCombo_Implementation(bool bResetTimer) override;
	virtual void ResetCombo_Implementation(bool bFireEvent) override;
	virtual TArray<FName> GetWeaponTraceSocketNames_Implementation() const override;
	virtual bool HasWeaponWithTag_Implementation(const FGameplayTag& WeaponTag) const override;
	virtual float PlayAttackAnimation_Implementation(UAnimMontage* Montage, float PlayRate, FName SectionName) override;

	// Методы жизненного цикла
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	/**
	 * Обработчик делегата изменения видимости оружия
	 * @param bIsVisible Флаг видимости оружия
	 */
	UFUNCTION()
	void UpdateWeaponVisibility(bool bIsVisible);

	/**
	 * Экипировать указанное оружие
	 * @param WeaponAsset Ассет оружия для экипировки
	 * @param BlendSpaceTransitionDuration Длительность перехода анимации (в секундах)
	 * @return true если экипировка прошла успешно
	 */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool EquipWeapon(UWeaponDataAsset* WeaponAsset, float BlendSpaceTransitionDuration = 1.0f);

	/**
	 * Снять текущее оружие
	 * @return true если оружие было снято успешно
	 */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool UnequipWeapon();

	/**
	 * Экипировать оружие по тегу
	 * @param WeaponTag Геймплей-тег оружия
	 * @return true если оружие было найдено и экипировано
	 */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool EquipWeaponByTag(FGameplayTag WeaponTag);

	/**
	 * Получить компонент AbilitySystem (реализация интерфейса IAbilitySystemInterface)
	 * @return Указатель на компонент AbilitySystem
	 */
	UFUNCTION(BlueprintPure, Category = "Abilities")
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	/**
	 * Инициализация способностей персонажа
	 * Вызывается при получении контроля над персонажем
	 */
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	virtual void InitializeAbilities();

	/**
	 * Получить AttributeSet персонажа
	 * @return Указатель на AttributeSet
	 */
	UFUNCTION(BlueprintPure, Category = "Abilities")
	UTronRpgAttributeSet* GetAttributeSet() const { return AttributeSet; }

	/**
	 * Получить компонент ComboComponent
	 * @return Указатель на ComboComponent
	 */
	UFUNCTION(BlueprintPure, Category = "Combat")
	UTronRpgComboComponent* GetComboComponent() const { return ComboComponent; }

	/**
	 * Получить компонент AnimationComponent
	 * @return Указатель на AnimationComponent
	 */
	UFUNCTION(BlueprintPure, Category = "Animation")
	UAnimationComponent* GetAnimationComponent() const { return AnimationComponent; }

	/**
	 * Получить компонент WeaponComponent
	 * @return Указатель на WeaponComponent
	 */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	UWeaponComponent* GetWeaponComponent() const { return WeaponComponent; }

	/**
	 * Применить базовые эффекты к персонажу
	 * Используется при инициализации персонажа
	 */
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	virtual void ApplyBaseEffects();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	bool GetCurrentWeaponTag();

	// Делегат для обработки изменения видимости оружия
	UPROPERTY(BlueprintAssignable, Category = "Weapon")
	FOnWeaponVisibilityChanged OnWeaponVisibilityChanged;

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
	UAbilityInputComponent* AbilityInputComponent;

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

	/**
	 * Флаг, указывающий, что базовые способности уже были выданы
	 * Помогает избежать дублирования
	 */
	UPROPERTY(Transient)
	bool bAbilitiesInitialized;

	/**
	 * Инициализация компонентов
	 * Вызывается из PostInitializeComponents
	 */
	virtual void SetupComponents();

	/**
	 * Инициализация базового оружия
	 * Вызывается из BeginPlay
	 */
	virtual void InitializeDefaultWeapon();

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Weapon")
	bool bIsPlayingEquipAnimation;

private:
	/**
	 * Сервер-функция для экипировки оружия
	 */
	UFUNCTION(Server, Reliable)
	void Server_EquipWeapon(UWeaponDataAsset* WeaponAsset, float BlendSpaceTransitionDuration);

	/**
	 * Сервер-функция для снятия оружия
	 */
	UFUNCTION(Server, Reliable)
	void Server_UnequipWeapon();
};
