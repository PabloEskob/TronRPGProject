// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Camera/Modifiers/UGC_CameraDitheringModifier.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef AURORADEVS_UGC_UGC_CameraDitheringModifier_generated_h
#error "UGC_CameraDitheringModifier.generated.h already included, missing '#pragma once' in UGC_CameraDitheringModifier.h"
#endif
#define AURORADEVS_UGC_UGC_CameraDitheringModifier_generated_h

#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraDitheringModifier_h_22_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FDitheredActorState_Statics; \
	AURORADEVS_UGC_API static class UScriptStruct* StaticStruct();


template<> AURORADEVS_UGC_API UScriptStruct* StaticStruct<struct FDitheredActorState>();

#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraDitheringModifier_h_62_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUUGC_CameraDitheringModifier(); \
	friend struct Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics; \
public: \
	DECLARE_CLASS(UUGC_CameraDitheringModifier, UUGC_CameraModifier, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AuroraDevs_UGC"), NO_API) \
	DECLARE_SERIALIZER(UUGC_CameraDitheringModifier)


#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraDitheringModifier_h_62_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UUGC_CameraDitheringModifier(UUGC_CameraDitheringModifier&&); \
	UUGC_CameraDitheringModifier(const UUGC_CameraDitheringModifier&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUGC_CameraDitheringModifier); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUGC_CameraDitheringModifier); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UUGC_CameraDitheringModifier) \
	NO_API virtual ~UUGC_CameraDitheringModifier();


#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraDitheringModifier_h_59_PROLOG
#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraDitheringModifier_h_62_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraDitheringModifier_h_62_INCLASS_NO_PURE_DECLS \
	FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraDitheringModifier_h_62_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> AURORADEVS_UGC_API UClass* StaticClass<class UUGC_CameraDitheringModifier>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraDitheringModifier_h


#define FOREACH_ENUM_EDITHERTYPE(op) \
	op(EDitherType::None) \
	op(EDitherType::BlockingLOS) \
	op(EDitherType::OverlappingCamera) 

enum class EDitherType : uint8;
template<> struct TIsUEnumClass<EDitherType> { enum { Value = true }; };
template<> AURORADEVS_UGC_API UEnum* StaticEnum<EDitherType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
