// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Object/GameManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TRONRPG_GameManager_generated_h
#error "GameManager.generated.h already included, missing '#pragma once' in GameManager.h"
#endif
#define TRONRPG_GameManager_generated_h

#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Object_GameManager_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGameManager(); \
	friend struct Z_Construct_UClass_UGameManager_Statics; \
public: \
	DECLARE_CLASS(UGameManager, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TronRPG"), NO_API) \
	DECLARE_SERIALIZER(UGameManager)


#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Object_GameManager_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UGameManager(UGameManager&&); \
	UGameManager(const UGameManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameManager); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameManager) \
	NO_API virtual ~UGameManager();


#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Object_GameManager_h_12_PROLOG
#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Object_GameManager_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Object_GameManager_h_15_INCLASS_NO_PURE_DECLS \
	FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Object_GameManager_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TRONRPG_API UClass* StaticClass<class UGameManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Object_GameManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
