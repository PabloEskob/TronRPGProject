// Tron


#include "Component/Weapon/WeaponStateComponent.h"
#include "Actor/Weapon/WeaponBase.h"
#include "Net/UnrealNetwork.h"

UWeaponStateComponent::UWeaponStateComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    MaxDurability = 100;
    CurrentDurability = MaxDurability;
    SetIsReplicatedByDefault(true);
}

void UWeaponStateComponent::SetWeaponState(FGameplayTag StateTag, bool bEnable)
{
    if (bEnable)
    {
        WeaponStateTags.AddTag(StateTag);
    }
    else
    {
        WeaponStateTags.RemoveTag(StateTag);
    }
}

bool UWeaponStateComponent::HasWeaponState(FGameplayTag StateTag) const
{
    return WeaponStateTags.HasTag(StateTag);
}

void UWeaponStateComponent::SetDurability(int32 NewDurability)
{
    const int32 PreviousDurability = CurrentDurability;
    CurrentDurability = FMath::Clamp(NewDurability, 0, MaxDurability);

    if (GetOwner()->HasAuthority() && PreviousDurability != CurrentDurability)
    {
        if (CurrentDurability <= 0 && !HasWeaponState(FGameplayTag::RequestGameplayTag("Weapon.Broken")))
        {
            SetWeaponState(FGameplayTag::RequestGameplayTag("Weapon.Broken"), true);
        }
        else if (CurrentDurability > 0 && HasWeaponState(FGameplayTag::RequestGameplayTag("Weapon.Broken")))
        {
            SetWeaponState(FGameplayTag::RequestGameplayTag("Weapon.Broken"), false);
        }

        // Уведомляем о изменении прочности
        OnDurabilityChanged.Broadcast(Cast<AWeaponBase>(GetOwner()), CurrentDurability);
    }
}

void UWeaponStateComponent::InitializeDurability(int32 NewMaxDurability)
{
    MaxDurability = FMath::Max(1, NewMaxDurability);
    CurrentDurability = MaxDurability;

    // Уведомляем о начальной прочности
    if (GetOwner()->HasAuthority())
    {
        OnDurabilityChanged.Broadcast(Cast<AWeaponBase>(GetOwner()), CurrentDurability);
    }
}

void UWeaponStateComponent::OnRep_IsEquipped()
{
  
}

void UWeaponStateComponent::OnRep_Durability()
{
   
    OnDurabilityChanged.Broadcast(Cast<AWeaponBase>(GetOwner()), CurrentDurability);
}

void UWeaponStateComponent::OnRep_StateTags()
{
  
}

void UWeaponStateComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    // Репликация только для владельца (оптимизация сетевого трафика)
    DOREPLIFETIME_CONDITION(UWeaponStateComponent, bIsEquipped, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UWeaponStateComponent, CurrentDurability, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UWeaponStateComponent, WeaponStateTags, COND_OwnerOnly);
}
