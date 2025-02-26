// Tron


#include "Notify/RpgTronWeaponAppearNotify.h"

#include "Character/TronRpgBaseCharacter.h"
#include "Data/Weapon/WeaponDataAsset.h"
#include "Object/GameplayTagsLibrary.h"

void URpgTronWeaponAppearNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (ATronRpgBaseCharacter* Character = Cast<ATronRpgBaseCharacter>(MeshComp->GetOwner()))
	{
		if (Character->CurrentWeapon)
		{
			if (bShouldShowWeapon)
			{
				if (Character->CurrentWeapon->WeaponSlot.HasTag(TAG_Equipment_Slot_MainHand))
				{
					Character->MainHandMeshComponent->SetVisibility(true);
				}
				if (Character->CurrentWeapon->WeaponSlot.HasTag(TAG_Equipment_Slot_OffHand))
				{
					Character->OffHandMeshComponent->SetVisibility(true);
				}
			}
			else
			{
				Character->MainHandMeshComponent->SetStaticMesh(nullptr);
				Character->MainHandMeshComponent->SetVisibility(false);
				Character->OffHandMeshComponent->SetStaticMesh(nullptr);
				Character->OffHandMeshComponent->SetVisibility(false);
				Character->CurrentWeapon = nullptr;
			}
		}
	}
}
