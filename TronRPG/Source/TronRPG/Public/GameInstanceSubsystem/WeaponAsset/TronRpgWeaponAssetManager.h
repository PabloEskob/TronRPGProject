// Tron

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TronRpgWeaponAssetManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TRONRPG_API UTronRpgWeaponAssetManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// Получение экземпляра менеджера
	static UTronRpgWeaponAssetManager* Get(const UObject* WorldContextObject);

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// Предзагрузка всех ассетов оружия
	UFUNCTION(BlueprintCallable, Category = "Weapon Manager")
	void PreloadAllWeaponAssets();

	// Получение ассета оружия по имени
	UFUNCTION(BlueprintCallable, Category = "Weapon Manager")
	UWeaponDataAsset* GetWeaponAssetByName(FName WeaponName) const;

	// Получение всех ассетов оружия
	UFUNCTION(BlueprintCallable, Category = "Weapon Manager")
	TArray<UWeaponDataAsset*> GetAllWeaponAssets() const;

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
