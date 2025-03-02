#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "WeaponLogicComponent.generated.h"

class UWeaponDataAsset;
class UTronRpgAbilitySystemComponent;
class UWeaponVisualComponent;
class UTronRpgAbilitySystemComponent;
class UWeaponVisualComponent;
struct FGameplayTag;
class UWeaponDataAsset;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TRONRPG_API UWeaponLogicComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UWeaponLogicComponent();

	virtual void BeginPlay() override;

	/**
	 * Текущее экипированное оружие
	 */
	UPROPERTY(ReplicatedUsing=OnRep_CurrentWeapon, BlueprintReadOnly, Category = "Weapon")
	UWeaponDataAsset* CurrentWeapon;

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
	bool IsWeaponEquipped() const { return CurrentWeapon != nullptr; }

	/**
	 * Проверить, соответствует ли текущее оружие указанному тегу
	 * @param Tag Тег для проверки
	 * @return true если текущее оружие имеет указанный тег
	 */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	bool HasWeaponWithTag(FGameplayTag Tag) const;

	/**
	 * Установить компонент визуализации оружия
	 * @param InVisualComponent Компонент для обновления визуализации оружия
	 */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void SetVisualComponent(UWeaponVisualComponent* InVisualComponent) { VisualComponent = InVisualComponent; }

	// Делегат для уведомления об изменении оружия
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponChanged, UWeaponDataAsset*, NewWeapon);

	// Делегат вызывается при смене оружия
	UPROPERTY(BlueprintAssignable, Category = "Weapon|Events")
	FOnWeaponChanged OnWeaponChanged;

protected:
	/**
	 * Компонент системы способностей для управления тегами
	 */
	UPROPERTY()
	UTronRpgAbilitySystemComponent* AbilitySystemComponent;

	/**
	 * Компонент визуализации оружия
	 */
	UPROPERTY()
	UWeaponVisualComponent* VisualComponent;

	/**
	 * История последних экипированных оружий
	 * Используется для быстрого переключения между оружием
	 */
	UPROPERTY()
	TArray<UWeaponDataAsset*> WeaponHistory;

	/**
	 * Максимальный размер истории оружия
	 */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	int32 MaxWeaponHistorySize = 5;

	/**
	 * Добавить оружие в историю
	 * @param WeaponAsset Оружие для добавления
	 */
	void AddToWeaponHistory(UWeaponDataAsset* WeaponAsset);

	/**
	 * Обновить теги геймплея, связанные с оружием
	 * @param WeaponAsset Оружие для обновления тегов
	 * @param bAdd Добавить или удалить теги
	 */
	void UpdateGameplayTags(UWeaponDataAsset* WeaponAsset, bool bAdd);

	/**
	 * Обработчик изменения текущего оружия (для репликации)
	 */
	UFUNCTION()
	void OnRep_CurrentWeapon();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/**
	 * Получить Asset Manager для оружия
	 * @return Указатель на Asset Manager
	 */
	class UTronRpgWeaponAssetManager* GetWeaponAssetManager() const;
};
