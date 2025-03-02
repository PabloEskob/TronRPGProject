// Tron

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "WeaponComponent.generated.h"

class UWeaponDataAsset;
class UTronRpgAbilitySystemComponent;
class UWeaponLogicComponent;
class UWeaponVisualComponent;

/**
 * Главный компонент для управления оружием персонажа
 * Выступает в роли фасада для WeaponLogicComponent и WeaponVisualComponent,
 * делегирующий соответствующую функциональность этим компонентам.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TRONRPG_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UWeaponComponent();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	/**
	 * Экипировать указанное оружие
	 * @param WeaponAsset Ассет оружия для экипировки
	 * @return true если экипировка прошла успешно
	 */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool EquipWeapon(UWeaponDataAsset* WeaponAsset);

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
	 * Обновить визуальное представление оружия
	 * @param bIsVisible Флаг видимости оружия
	 */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void UpdateWeaponVisuals(bool bIsVisible);

	/**
	 * Получить теги текущего оружия
	 * @return FGameplayTagContainer с тегами оружия
	 */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	FGameplayTagContainer GetCurrentWeaponTags() const;

	/**
	 * Проверить, экипировано ли оружие
	 * @return true если оружие экипировано
	 */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	bool IsWeaponEquipped() const;

	/**
	 * Проверить, соответствует ли текущее оружие указанному тегу
	 * @param Tag Тег для проверки
	 * @return true если текущее оружие имеет указанный тег
	 */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	bool HasWeaponWithTag(FGameplayTag Tag) const;

	/**
	 * Получить текущее экипированное оружие
	 * @return Текущее оружие или nullptr, если оружие не экипировано
	 */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	UWeaponDataAsset* GetCurrentWeapon() const;

	/**
	 * Получить компонент логики оружия
	 * @return Указатель на компонент логики оружия
	 */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	UWeaponLogicComponent* GetLogicComponent() const { return LogicComponent; }

	/**
	 * Получить компонент визуализации оружия
	 * @return Указатель на компонент визуализации оружия
	 */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	UWeaponVisualComponent* GetVisualComponent() const { return VisualComponent; }

	/**
	 * Обработчик изменения оружия (для обновления визуализации)
	 * @param NewWeapon Новое оружие
	 */
	UFUNCTION()
	void OnWeaponChanged(UWeaponDataAsset* NewWeapon);

protected:
	/**
	 * Компонент логики оружия
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	UWeaponLogicComponent* LogicComponent;

	/**
	 * Компонент визуализации оружия
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	UWeaponVisualComponent* VisualComponent;

	/**
	 * Инициализирует компоненты и их связи
	 */
	void InitializeComponents();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
