// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameplayAbility/MeleeAttackAbility.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TRONRPG_MeleeAttackAbility_generated_h
#error "MeleeAttackAbility.generated.h already included, missing '#pragma once' in MeleeAttackAbility.h"
#endif
#define TRONRPG_MeleeAttackAbility_generated_h

#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GameplayAbility_MeleeAttackAbility_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnApplyDamageNotify);


#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GameplayAbility_MeleeAttackAbility_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMeleeAttackAbility(); \
	friend struct Z_Construct_UClass_UMeleeAttackAbility_Statics; \
public: \
	DECLARE_CLASS(UMeleeAttackAbility, UGameplayAbility, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TronRPG"), NO_API) \
	DECLARE_SERIALIZER(UMeleeAttackAbility)


#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GameplayAbility_MeleeAttackAbility_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMeleeAttackAbility(UMeleeAttackAbility&&); \
	UMeleeAttackAbility(const UMeleeAttackAbility&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMeleeAttackAbility); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMeleeAttackAbility); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMeleeAttackAbility) \
	NO_API virtual ~UMeleeAttackAbility();


#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GameplayAbility_MeleeAttackAbility_h_12_PROLOG
#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GameplayAbility_MeleeAttackAbility_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GameplayAbility_MeleeAttackAbility_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GameplayAbility_MeleeAttackAbility_h_15_INCLASS_NO_PURE_DECLS \
	FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GameplayAbility_MeleeAttackAbility_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TRONRPG_API UClass* StaticClass<class UMeleeAttackAbility>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GameplayAbility_MeleeAttackAbility_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
