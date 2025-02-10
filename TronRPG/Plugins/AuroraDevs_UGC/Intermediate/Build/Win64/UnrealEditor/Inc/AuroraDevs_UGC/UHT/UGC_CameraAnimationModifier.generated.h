// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Camera/Modifiers/UGC_CameraAnimationModifier.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UCameraAnimationSequence;
#ifdef AURORADEVS_UGC_UGC_CameraAnimationModifier_generated_h
#error "UGC_CameraAnimationModifier.generated.h already included, missing '#pragma once' in UGC_CameraAnimationModifier.h"
#endif
#define AURORADEVS_UGC_UGC_CameraAnimationModifier_generated_h

#define FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraAnimationModifier_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execIsAnyCameraAnimationSequence); \
	DECLARE_FUNCTION(execIsCameraAnimationSequenceActive); \
	DECLARE_FUNCTION(execGetCurrentCameraAnimation); \
	DECLARE_FUNCTION(execStopCameraAnimationSequence);


#define FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraAnimationModifier_h_38_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUUGC_CameraAnimationModifier(); \
	friend struct Z_Construct_UClass_UUGC_CameraAnimationModifier_Statics; \
public: \
	DECLARE_CLASS(UUGC_CameraAnimationModifier, UCameraAnimationCameraModifier, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/AuroraDevs_UGC"), NO_API) \
	DECLARE_SERIALIZER(UUGC_CameraAnimationModifier)


#define FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraAnimationModifier_h_38_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UUGC_CameraAnimationModifier(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UUGC_CameraAnimationModifier(UUGC_CameraAnimationModifier&&); \
	UUGC_CameraAnimationModifier(const UUGC_CameraAnimationModifier&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUGC_CameraAnimationModifier); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUGC_CameraAnimationModifier); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUGC_CameraAnimationModifier) \
	NO_API virtual ~UUGC_CameraAnimationModifier();


#define FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraAnimationModifier_h_35_PROLOG
#define FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraAnimationModifier_h_38_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraAnimationModifier_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraAnimationModifier_h_38_INCLASS_NO_PURE_DECLS \
	FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraAnimationModifier_h_38_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> AURORADEVS_UGC_API UClass* StaticClass<class UUGC_CameraAnimationModifier>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraAnimationModifier_h


#define FOREACH_ENUM_ECAMERAANIMATIONRESETTYPE(op) \
	op(ECameraAnimationResetType::BackToStart) \
	op(ECameraAnimationResetType::ResetToZero) \
	op(ECameraAnimationResetType::ContinueFromEnd) 

enum class ECameraAnimationResetType : uint8;
template<> struct TIsUEnumClass<ECameraAnimationResetType> { enum { Value = true }; };
template<> AURORADEVS_UGC_API UEnum* StaticEnum<ECameraAnimationResetType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
