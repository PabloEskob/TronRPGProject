// Tron


#include "GameInstance/TronRpgGameInstance.h"

#include "GameInstanceSubsystem/WeaponAsset/TronRpgWeaponAssetManager.h"

class UTronRpgWeaponAssetManager;

void UTronRpgGameInstance::Init()
{
	Super::Init();

	// Получаем экземпляр подсистемы UTronRpgWeaponAssetManager
	UTronRpgWeaponAssetManager* WeaponManager = GetSubsystem<UTronRpgWeaponAssetManager>();
	if (WeaponManager)
	{
		// Запускаем асинхронную загрузку всех ассетов оружий
		WeaponManager->PreloadAllWeaponAssets();
	}
}
