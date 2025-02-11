// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Character/Player/TronRpgPlayerCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TRONRPG_TronRpgPlayerCharacter_generated_h
#error "TronRpgPlayerCharacter.generated.h already included, missing '#pragma once' in TronRpgPlayerCharacter.h"
#endif
#define TRONRPG_TronRpgPlayerCharacter_generated_h

#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_Player_TronRpgPlayerCharacter_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATronRpgPlayerCharacter(); \
	friend struct Z_Construct_UClass_ATronRpgPlayerCharacter_Statics; \
public: \
	DECLARE_CLASS(ATronRpgPlayerCharacter, ATronRpgBaseCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TronRPG"), NO_API) \
	DECLARE_SERIALIZER(ATronRpgPlayerCharacter)


#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_Player_TronRpgPlayerCharacter_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATronRpgPlayerCharacter(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ATronRpgPlayerCharacter(ATronRpgPlayerCharacter&&); \
	ATronRpgPlayerCharacter(const ATronRpgPlayerCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATronRpgPlayerCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATronRpgPlayerCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATronRpgPlayerCharacter) \
	NO_API virtual ~ATronRpgPlayerCharacter();


#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_Player_TronRpgPlayerCharacter_h_12_PROLOG
#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_Player_TronRpgPlayerCharacter_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_Player_TronRpgPlayerCharacter_h_15_INCLASS_NO_PURE_DECLS \
	FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_Player_TronRpgPlayerCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TRONRPG_API UClass* StaticClass<class ATronRpgPlayerCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_Player_TronRpgPlayerCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
