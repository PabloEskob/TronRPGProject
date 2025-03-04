// TronRpgBaseCharacter.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "Interface/Weapon/MeleeAttackInterface.h"
#include "Interface/Animation/AnimatableCharacter.h"
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
class TRONRPG_API ATronRpgBaseCharacter : public ACharacter,
                                          public IAbilitySystemInterface,
                                          public IMeleeAttackInterface,
                                          public IAnimatableCharacter
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
	virtual UTronRpgComboComponent* GetComboComponent_Implementation() const override { return ComboComponent; }
	virtual UAnimationComponent* GetAnimationComponent_Implementation() const override { return AnimationComponent; }

	// Реализация IAnimatableCharacter
	virtual UCharacterMovementComponent* GetCharacterMovement_Implementation() const override { return ACharacter::GetCharacterMovement(); }
	virtual UAbilitySystemComponent* GetAbilitySystemComponent_Implementation() const override { return AbilitySystemComponent; }
	virtual FGameplayTagContainer GetCurrentGameplayTags_Implementation() const override;

	// Реализация IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	// Методы жизненного цикла
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	/**
	 * Обработчик делегата изменения видимости оружия
	 */
	UFUNCTION()
	void UpdateWeaponVisibility(bool bIsVisible);

	/**
	 * Экипировать указанное оружие
	 */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool EquipWeapon(UWeaponDataAsset* WeaponAsset, float BlendSpaceTransitionDuration = 1.0f);

	/**
	 * Снять текущее оружие
	 */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool UnequipWeapon();

	/**
	 * Экипировать оружие по тегу
	 */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool EquipWeaponByTag(FGameplayTag WeaponTag);

	/**
	 * Инициализация способностей персонажа
	 */
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	virtual void InitializeAbilities();

	/**
	 * Получить AttributeSet персонажа
	 */
	UFUNCTION(BlueprintPure, Category = "Abilities")
	UTronRpgAttributeSet* GetAttributeSet() const { return AttributeSet; }

	
	/**
	 * Получить компонент WeaponComponent
	 */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	UWeaponComponent* GetWeaponComponent() const { return WeaponComponent; }

	/**
	 * Применить базовые эффекты к персонажу
	 */
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	virtual void ApplyBaseEffects();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/**
	 * Получить текущий тег оружия
	 */
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
	 */
	UPROPERTY(Transient)
	bool bAbilitiesInitialized;

	/**
	 * Инициализация компонентов
	 */
	void InitializeComponents();

	/**
	 * Инициализация системы GAS
	 */
	void InitializeGAS();

	/**
	 * Инициализация анимаций
	 */
	void InitializeAnimations();

	/**
	 * Регистрация компонентов в DI
	 */
	virtual void RegisterComponentsInDI();

	/**
	 * Инициализация базового оружия
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
