// Tron


#include "Notify/RpgTronWeaponAppearNotify.h"

#include "Character/TronRpgBaseCharacter.h"
#include "Component/Weapon/WeaponComponent.h"
#include "TronRPG/TronRPG.h"

void URpgTronWeaponAppearNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (MeshComp->GetOwner()->Implements<UCharacterComponentProvider>())
	{
		UWeaponComponent* WeaponComp = ICharacterComponentProvider::Execute_GetWeaponComponent(MeshComp->GetOwner());
		WeaponComp->UpdateWeaponVisuals(bShouldShowWeapon);
	}
}
