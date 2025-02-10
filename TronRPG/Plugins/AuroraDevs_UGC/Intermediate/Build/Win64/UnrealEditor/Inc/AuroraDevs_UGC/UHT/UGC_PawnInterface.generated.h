// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Pawn/UGC_PawnInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef AURORADEVS_UGC_UGC_PawnInterface_generated_h
#error "UGC_PawnInterface.generated.h already included, missing '#pragma once' in UGC_PawnInterface.h"
#endif
#define AURORADEVS_UGC_UGC_PawnInterface_generated_h

#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_13_CALLBACK_WRAPPERS
#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	AURORADEVS_UGC_API UUGC_PawnInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UUGC_PawnInterface(UUGC_PawnInterface&&); \
	UUGC_PawnInterface(const UUGC_PawnInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(AURORADEVS_UGC_API, UUGC_PawnInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUGC_PawnInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUGC_PawnInterface) \
	AURORADEVS_UGC_API virtual ~UUGC_PawnInterface();


#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUUGC_PawnInterface(); \
	friend struct Z_Construct_UClass_UUGC_PawnInterface_Statics; \
public: \
	DECLARE_CLASS(UUGC_PawnInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/AuroraDevs_UGC"), AURORADEVS_UGC_API) \
	DECLARE_SERIALIZER(UUGC_PawnInterface)


#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_13_GENERATED_UINTERFACE_BODY() \
	FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IUGC_PawnInterface() {} \
public: \
	typedef UUGC_PawnInterface UClassType; \
	typedef IUGC_PawnInterface ThisClass; \
	static FVector Execute_GetMovementInput(const UObject* O); \
	static FRotator Execute_GetRotationInput(const UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_10_PROLOG
#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_13_CALLBACK_WRAPPERS \
	FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> AURORADEVS_UGC_API UClass* StaticClass<class UUGC_PawnInterface>();

#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_37_CALLBACK_WRAPPERS
#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_37_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	AURORADEVS_UGC_API UUGC_PawnMovementInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UUGC_PawnMovementInterface(UUGC_PawnMovementInterface&&); \
	UUGC_PawnMovementInterface(const UUGC_PawnMovementInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(AURORADEVS_UGC_API, UUGC_PawnMovementInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUGC_PawnMovementInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUGC_PawnMovementInterface) \
	AURORADEVS_UGC_API virtual ~UUGC_PawnMovementInterface();


#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_37_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUUGC_PawnMovementInterface(); \
	friend struct Z_Construct_UClass_UUGC_PawnMovementInterface_Statics; \
public: \
	DECLARE_CLASS(UUGC_PawnMovementInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/AuroraDevs_UGC"), AURORADEVS_UGC_API) \
	DECLARE_SERIALIZER(UUGC_PawnMovementInterface)


#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_37_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_37_GENERATED_UINTERFACE_BODY() \
	FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_37_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_37_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IUGC_PawnMovementInterface() {} \
public: \
	typedef UUGC_PawnMovementInterface UClassType; \
	typedef IUGC_PawnMovementInterface ThisClass; \
	static FVector Execute_GetOwnerVelocity(const UObject* O); \
	static bool Execute_IsOwnerFalling(const UObject* O); \
	static bool Execute_IsOwnerMovingOnGround(const UObject* O); \
	static bool Execute_IsOwnerStrafing(const UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_34_PROLOG
#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_46_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_37_CALLBACK_WRAPPERS \
	FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_37_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> AURORADEVS_UGC_API UClass* StaticClass<class UUGC_PawnMovementInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
