// Tron

#include "Component/Weapon/WeaponVisualComponent.h"
#include "Data/Weapon/WeaponDataAsset.h"
#include "Object/GameplayTagsLibrary.h"

UWeaponVisualComponent::UWeaponVisualComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    SetIsReplicatedByDefault(true);
}

void UWeaponVisualComponent::BeginPlay()
{
    Super::BeginPlay();
    
    // Проверяем, что компоненты оружия правильно настроены
    if (MainHandMeshComponent)
    {
        MainHandMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        MainHandMeshComponent->SetVisibility(false);
    }
    
    if (OffHandMeshComponent)
    {
        OffHandMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        OffHandMeshComponent->SetVisibility(false);
    }
}

void UWeaponVisualComponent::UpdateWeaponVisuals(UWeaponDataAsset* WeaponAsset, bool bIsVisible)
{
    // Обновляем визуализацию оружия
    if (WeaponAsset)
    {
        // Устанавливаем меш для основной руки
        if (MainHandMeshComponent)
        {
            bool bHasMainHandWeapon = WeaponAsset->WeaponSlot.HasTag(TAG_Equipment_Slot_MainHand);
            MainHandMeshComponent->SetStaticMesh(bHasMainHandWeapon ? WeaponAsset->WeaponMesh.Get() : nullptr);
            MainHandMeshComponent->SetVisibility(bIsVisible && bHasMainHandWeapon);
        }
        
        // Устанавливаем меш для дополнительной руки
        if (OffHandMeshComponent)
        {
            bool bHasOffHandWeapon = WeaponAsset->WeaponSlot.HasTag(TAG_Equipment_Slot_OffHand);
            OffHandMeshComponent->SetStaticMesh(bHasOffHandWeapon ? WeaponAsset->AdditionalWeaponMesh.Get() : nullptr);
            OffHandMeshComponent->SetVisibility(bIsVisible && bHasOffHandWeapon);
        }
    }
    else
    {
        // Если нет текущего оружия, скрываем оба меша
        if (MainHandMeshComponent)
        {
            MainHandMeshComponent->SetVisibility(false);
        }
        
        if (OffHandMeshComponent)
        {
            OffHandMeshComponent->SetVisibility(false);
        }
    }
}