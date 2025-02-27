// Tron


#include "Component/Weapon/WeaponComponent.h"

#include "GameInstanceSubsystem/WeaponAsset/TronRpgWeaponAssetManager.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"
#include "Object/GameplayTagsLibrary.h"


void UWeaponComponent::BeginPlay()
{
    Super::BeginPlay();
    AbilitySystemComponent = GetOwner()->FindComponentByClass<UTronRpgAbilitySystemComponent>();
}

void UWeaponComponent::EquipWeapon(UWeaponDataAsset* WeaponAsset)
{
    if (!WeaponAsset || CurrentWeapon == WeaponAsset) return;

    UWeaponDataAsset* PreviousWeapon = CurrentWeapon;
    CurrentWeapon = WeaponAsset;

    if (PreviousWeapon)
    {
        UpdateGameplayTags(PreviousWeapon, false);
        UpdateWeaponVisuals(false);
    }
    UpdateGameplayTags(CurrentWeapon, true);
}

void UWeaponComponent::UnequipWeapon()
{
    if (!CurrentWeapon) return;

    UpdateGameplayTags(CurrentWeapon, false);
    UpdateWeaponVisuals(false);
    CurrentWeapon = nullptr;
}

void UWeaponComponent::EquipWeaponByTag(FGameplayTag WeaponTag)
{
    if (!WeaponTag.IsValid()) return;

    UTronRpgWeaponAssetManager* WeaponManager = GetOwner()->GetGameInstance() ? 
        GetOwner()->GetGameInstance()->GetSubsystem<UTronRpgWeaponAssetManager>() : nullptr;
    if (!WeaponManager) return;

    TArray<UWeaponDataAsset*> Weapons = WeaponManager->GetWeaponsByTag(WeaponTag);
    if (Weapons.Num() == 0) return;

    UWeaponDataAsset* TargetWeapon = Weapons[0];

    if (CurrentWeapon && CurrentWeapon->WeaponTags.HasTagExact(WeaponTag))
    {
        UnequipWeapon();
    }
    else
    {
        EquipWeapon(TargetWeapon);
    }
}

void UWeaponComponent::UpdateWeaponVisuals(bool bIsVisible)
{
    if (CurrentWeapon)
    {
        MainHandMeshComponent->SetStaticMesh(
            CurrentWeapon->WeaponSlot.HasTag(TAG_Equipment_Slot_MainHand) ? CurrentWeapon->WeaponMesh.Get() : nullptr
        );
        OffHandMeshComponent->SetStaticMesh(
            CurrentWeapon->WeaponSlot.HasTag(TAG_Equipment_Slot_OffHand) ? CurrentWeapon->AdditionalWeaponMesh.Get() : nullptr
        );
    }
    MainHandMeshComponent->SetVisibility(bIsVisible);
    OffHandMeshComponent->SetVisibility(bIsVisible);
}

void UWeaponComponent::UpdateGameplayTags(UWeaponDataAsset* WeaponAsset, bool bAdd)
{
    if (!AbilitySystemComponent || !WeaponAsset) return;
    if (bAdd)
    {
        AbilitySystemComponent->AddLooseGameplayTags(WeaponAsset->WeaponTags);
        AbilitySystemComponent->AddLooseGameplayTag(FGameplayTag::RequestGameplayTag(TEXT("State.Equipment.Equipped")));
    }
    else
    {
        AbilitySystemComponent->RemoveLooseGameplayTags(WeaponAsset->WeaponTags);
        AbilitySystemComponent->RemoveLooseGameplayTag(FGameplayTag::RequestGameplayTag(TEXT("State.Equipment.Equipped")));
    }
}

void UWeaponComponent::OnRep_CurrentWeapon()
{
    UpdateWeaponVisuals(CurrentWeapon != nullptr);
}

void UWeaponComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(UWeaponComponent, CurrentWeapon);
}

