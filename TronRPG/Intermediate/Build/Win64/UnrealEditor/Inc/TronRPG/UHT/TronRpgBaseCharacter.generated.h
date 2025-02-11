// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Character/TronRpgBaseCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UGameManager;
class UUIManager;
#ifdef TRONRPG_TronRpgBaseCharacter_generated_h
#error "TronRpgBaseCharacter.generated.h already included, missing '#pragma once' in TronRpgBaseCharacter.h"
#endif
#define TRONRPG_TronRpgBaseCharacter_generated_h

#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_TronRpgBaseCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execInjectDependencies);


#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_TronRpgBaseCharacter_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATronRpgBaseCharacter(); \
	friend struct Z_Construct_UClass_ATronRpgBaseCharacter_Statics; \
public: \
	DECLARE_CLASS(ATronRpgBaseCharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/TronRPG"), NO_API) \
	DECLARE_SERIALIZER(ATronRpgBaseCharacter) \
	virtual UObject* _getUObject() const override { return const_cast<ATronRpgBaseCharacter*>(this); }


#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_TronRpgBaseCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ATronRpgBaseCharacter(ATronRpgBaseCharacter&&); \
	ATronRpgBaseCharacter(const ATronRpgBaseCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATronRpgBaseCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATronRpgBaseCharacter); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(ATronRpgBaseCharacter) \
	NO_API virtual ~ATronRpgBaseCharacter();


#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_TronRpgBaseCharacter_h_17_PROLOG
#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_TronRpgBaseCharacter_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_TronRpgBaseCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_TronRpgBaseCharacter_h_20_INCLASS_NO_PURE_DECLS \
	FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_TronRpgBaseCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TRONRPG_API UClass* StaticClass<class ATronRpgBaseCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_TronRpgBaseCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
