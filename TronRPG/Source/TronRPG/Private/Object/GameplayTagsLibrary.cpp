﻿#include "Object/GameplayTagsLibrary.h"

#include "GAS/TronRpgAttributeSet.h"
#include "Logging/LogMacros.h"

// Existing tags
UE_DEFINE_GAMEPLAY_TAG(TAG_WeaponType_Sword, "WeaponType.Sword");
UE_DEFINE_GAMEPLAY_TAG(TAG_WeaponType_SwordAndShield, "WeaponType.SwordAndShield");
UE_DEFINE_GAMEPLAY_TAG(TAG_WeaponType_None, "WeaponType.None");

UE_DEFINE_GAMEPLAY_TAG(TAG_Weapon_Equipped, "Weapon.Equipped");
UE_DEFINE_GAMEPLAY_TAG(TAG_Weapon_Broken, "Weapon.Broken");
UE_DEFINE_GAMEPLAY_TAG(TAG_Weapon_Default, "Weapon.Default");

UE_DEFINE_GAMEPLAY_TAG(TAG_Attack_Melee, "GameplayCue.Attack.Melee");
UE_DEFINE_GAMEPLAY_TAG(TAG_Attack_Ranged, "GameplayCue.Attack.Ranged");

UE_DEFINE_GAMEPLAY_TAG(TAG_Equipment_Slot_MainHand, "Equipment.Slot.MainHand");
UE_DEFINE_GAMEPLAY_TAG(TAG_Equipment_Slot_OffHand, "Equipment.Slot.OffHand");

// New tags for abilities and states
UE_DEFINE_GAMEPLAY_TAG(TAG_State_Dead, "State.Dead");
UE_DEFINE_GAMEPLAY_TAG(TAG_State_Disabled, "State.Disabled");
UE_DEFINE_GAMEPLAY_TAG(TAG_State_Stunned, "State.Stunned");
UE_DEFINE_GAMEPLAY_TAG(TAG_State_Attacking, "State.Attacking");
UE_DEFINE_GAMEPLAY_TAG(TAG_State_Sprinting, "State.Sprinting");
UE_DEFINE_GAMEPLAY_TAG(TAG_State_Running, "State.Running");
UE_DEFINE_GAMEPLAY_TAG(TAG_State_Equipment_Equipped, "State.Equipment.Equipped");

// New tags for damage and effects
UE_DEFINE_GAMEPLAY_TAG(TAG_Damage, "GameplayEffect.Damage");
UE_DEFINE_GAMEPLAY_TAG(TAG_Damage_Critical, "Effect.Damage.Critical");

// New tags for status
UE_DEFINE_GAMEPLAY_TAG(TAG_Status_NoWeaponEquipped, "Status.NoWeaponEquipped");

// New tags for abilities
UE_DEFINE_GAMEPLAY_TAG(TAG_Ability_Combat_Melee, "Ability.Combat.Melee");

UE_DEFINE_GAMEPLAY_TAG(TAG_Input_Attack, "Input.Attack");

UE_DEFINE_GAMEPLAY_TAG(TAG_State_Equipment_Changing, "State.Equipment.Changing");

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_State_ComboWindowOpen)
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Ability_Combo_Continue)

// Теги для эффектов и урона
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Effect_Damage_Melee)
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Effect_Damage_Critical)
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Effect_Damage_ComboMultiplier)

// GameplayTagsLibrary.cpp - Добавьте определения новых тегов
UE_DEFINE_GAMEPLAY_TAG(TAG_State_ComboWindowOpen, "State.ComboWindowOpen");
UE_DEFINE_GAMEPLAY_TAG(TAG_Ability_Combo_Continue, "Ability.Combo.Continue");
UE_DEFINE_GAMEPLAY_TAG(TAG_Effect_Damage_Melee, "Effect.Damage.Melee");
UE_DEFINE_GAMEPLAY_TAG(TAG_Effect_Damage_Critical, "Effect.Damage.Critical");
UE_DEFINE_GAMEPLAY_TAG(TAG_Effect_Damage_ComboMultiplier, "Effect.Damage.ComboMultiplier");


