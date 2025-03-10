// Tron


#include "Notify/RpgTronWeaponAppearNotify.h"

#include "Character/TronRpgBaseCharacter.h"
#include "Component/Weapon/WeaponComponent.h"
#include "TronRPG/TronRPG.h"

void URpgTronWeaponAppearNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	// Проверяем, что владелец компонента — это ATronRpgBaseCharacter
	if (ATronRpgBaseCharacter* Character = Cast<ATronRpgBaseCharacter>(MeshComp->GetOwner()))
	{
		// Получаем компонент оружия
		UWeaponComponent* WeaponComp = Character->GetWeaponComponent();
		if (WeaponComp)
		{
			// Обновляем видимость напрямую через компонент
			WeaponComp->UpdateWeaponVisuals(bShouldShowWeapon);
		}
		else
		{
			// Используем делегат, если компонент недоступен
			Character->OnWeaponVisibilityChanged.Broadcast(bShouldShowWeapon);
		}
	}
}
