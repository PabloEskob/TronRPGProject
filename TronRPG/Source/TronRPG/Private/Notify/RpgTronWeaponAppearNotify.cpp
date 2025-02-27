// Tron


#include "Notify/RpgTronWeaponAppearNotify.h"

#include "Character/TronRpgBaseCharacter.h"
#include "Data/Weapon/WeaponDataAsset.h"
#include "Object/GameplayTagsLibrary.h"

void URpgTronWeaponAppearNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	// Проверяем, что владелец компонента — это ATronRpgBaseCharacter
	if (ATronRpgBaseCharacter* Character = Cast<ATronRpgBaseCharacter>(MeshComp->GetOwner()))
	{
		// Вызываем делегат, передавая параметр bShouldShowWeapon
		Character->OnWeaponVisibilityChanged.Broadcast(bShouldShowWeapon);
	}
}
