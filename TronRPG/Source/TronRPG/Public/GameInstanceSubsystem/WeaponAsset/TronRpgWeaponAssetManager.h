// Tron

#pragma once

#include "CoreMinimal.h"
#include "Data/Weapon/WeaponDataAsset.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TronRpgWeaponAssetManager.generated.h"

/**
 * 
 */
// Делегат для уведомления о завершении предзагрузки
DECLARE_DYNAMIC_DELEGATE(FOnPreloadComplete);

UCLASS(Blueprintable)
class TRONRPG_API UTronRpgWeaponAssetManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// Получение экземпляра менеджера
	static UTronRpgWeaponAssetManager* Get(const UObject* WorldContextObject);

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

	// Предзагрузка всех ассетов оружия
	UFUNCTION(Category = "Weapon Manager")
	void PreloadAllWeaponAssets(FOnPreloadComplete OnComplete = FOnPreloadComplete());

	// Получение ассета оружия по имени
	UFUNCTION(BlueprintCallable, Category = "Weapon Manager")
	UWeaponDataAsset* GetWeaponAssetByName(FName WeaponName) const;

	// Получение всех ассетов оружия
	UFUNCTION(BlueprintCallable, Category = "Weapon Manager")
	TArray<UWeaponDataAsset*> GetAllWeaponAssets() const;

	UFUNCTION(BlueprintCallable, Category = "Weapon Manager")
	UWeaponDataAsset* GetDefaultWeapon();


protected:
	// Список ассетов оружия, редактируемый в редакторе
	UPROPERTY(EditDefaultsOnly, Category = "Weapon Manager")
	TArray<TSoftObjectPtr<UWeaponDataAsset>> WeaponAssets;

	// Кэш загруженных ассетов
	UPROPERTY()
	TMap<FName, UWeaponDataAsset*> LoadedWeaponAssets;

	// Кэш загруженных анимаций и Blend Spaces
	UPROPERTY()
	TMap<FName, UAnimSequence*> CachedIdleAnimations;

	UPROPERTY()
	TMap<FName, UBlendSpace*> CachedBlendSpaces;

private:
	// Загрузка ассетов для конкретного оружия
	void LoadWeaponAssets(UWeaponDataAsset* WeaponAsset);

	// Проверка, загружен ли ассет
	bool IsAssetLoaded(const TSoftObjectPtr<UObject>& Asset) const;
};
