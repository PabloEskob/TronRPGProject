// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Object/UIManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TRONRPG_UIManager_generated_h
#error "UIManager.generated.h already included, missing '#pragma once' in UIManager.h"
#endif
#define TRONRPG_UIManager_generated_h

#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Object_UIManager_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUUIManager(); \
	friend struct Z_Construct_UClass_UUIManager_Statics; \
public: \
	DECLARE_CLASS(UUIManager, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TronRPG"), NO_API) \
	DECLARE_SERIALIZER(UUIManager)


#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Object_UIManager_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UUIManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UUIManager(UUIManager&&); \
	UUIManager(const UUIManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUIManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUIManager); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUIManager) \
	NO_API virtual ~UUIManager();


#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Object_UIManager_h_12_PROLOG
#define FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Object_UIManager_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Object_UIManager_h_15_INCLASS_NO_PURE_DECLS \
	FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Object_UIManager_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TRONRPG_API UClass* StaticClass<class UUIManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Object_UIManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
