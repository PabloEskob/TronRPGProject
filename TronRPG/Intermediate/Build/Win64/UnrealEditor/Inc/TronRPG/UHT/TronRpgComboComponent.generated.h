// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Component/TronRpgComboComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TRONRPG_TronRpgComboComponent_generated_h
#error "TronRpgComboComponent.generated.h already included, missing '#pragma once' in TronRpgComboComponent.h"
#endif
#define TRONRPG_TronRpgComboComponent_generated_h

#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Component_TronRpgComboComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execResetCombo); \
	DECLARE_FUNCTION(execIncrementCombo);


#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Component_TronRpgComboComponent_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUTronRpgComboComponent(); \
	friend struct Z_Construct_UClass_UTronRpgComboComponent_Statics; \
public: \
	DECLARE_CLASS(UTronRpgComboComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TronRPG"), NO_API) \
	DECLARE_SERIALIZER(UTronRpgComboComponent)


#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Component_TronRpgComboComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UTronRpgComboComponent(UTronRpgComboComponent&&); \
	UTronRpgComboComponent(const UTronRpgComboComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTronRpgComboComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTronRpgComboComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UTronRpgComboComponent) \
	NO_API virtual ~UTronRpgComboComponent();


#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Component_TronRpgComboComponent_h_10_PROLOG
#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Component_TronRpgComboComponent_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Component_TronRpgComboComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Component_TronRpgComboComponent_h_13_INCLASS_NO_PURE_DECLS \
	FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Component_TronRpgComboComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TRONRPG_API UClass* StaticClass<class UTronRpgComboComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Component_TronRpgComboComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
