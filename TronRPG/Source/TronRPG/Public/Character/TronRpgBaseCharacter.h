// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "TronRpgBaseCharacter.generated.h"

class UWeaponDataAsset;
class UWeaponComponent;
class UAbilityInputComponent;
class UAnimationComponent;
class UTronRpgAttributeSet;
class UTronRpgAbilitySystemComponent;
/**
 * Делегат для обработки изменения видимости оружия
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponVisibilityChanged, bool, bIsVisible);

/**
 * Базовый класс персонажа в TronRPG
 * Содержит основные компоненты и функциональность для всех персонажей игры
 */
UCLASS(Abstract)
class TRONRPG_API ATronRpgBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ATronRpgBaseCharacter();
	void ConfigureAbilityComponents();
	void ConfigureWeaponComponents();
	void ConfigureWeaponMesh(UStaticMeshComponent* MeshComponent, const FName& SocketName);

	// Методы жизненного цикла
	virtual void BeginPlay() override;

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


	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	UWeaponComponent* GetWeaponComponent() const { return WeaponComponent; }

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

	/** Компонент для управления анимациями */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Animation")
	UAnimationComponent* AnimationComponent;

	/** Компонент для обработки ввода способностей */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input")
	UAbilityInputComponent* AbilityInputComponent;

	/** Компонент для управления оружием */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	UWeaponComponent* WeaponComponent;

	/** Оружие по умолчанию */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	UWeaponDataAsset* DefaultWeaponAsset;

	/**
	 * Флаг, указывающий, что базовые способности уже были выданы
	 * Помогает избежать дублирования
	 */
	UPROPERTY(Transient)
	bool bAbilitiesInitialized;

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
