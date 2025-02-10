// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Camera/Methods/UGC_IGetActorsMethod.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef AURORADEVS_UGC_UGC_IGetActorsMethod_generated_h
#error "UGC_IGetActorsMethod.generated.h already included, missing '#pragma once' in UGC_IGetActorsMethod.h"
#endif
#define AURORADEVS_UGC_UGC_IGetActorsMethod_generated_h

#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Methods_UGC_IGetActorsMethod_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void GetActors_Implementation(AActor* InOwner, FVector OwnerLocation, FVector ViewPointLocation, FRotator ViewPointRotation, TArray<AActor*>& OutActors); \
	DECLARE_FUNCTION(execGetActors);


#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Methods_UGC_IGetActorsMethod_h_17_CALLBACK_WRAPPERS
#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Methods_UGC_IGetActorsMethod_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUUGC_IGetActorsMethod(); \
	friend struct Z_Construct_UClass_UUGC_IGetActorsMethod_Statics; \
public: \
	DECLARE_CLASS(UUGC_IGetActorsMethod, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/AuroraDevs_UGC"), NO_API) \
	DECLARE_SERIALIZER(UUGC_IGetActorsMethod)


#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Methods_UGC_IGetActorsMethod_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UUGC_IGetActorsMethod(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UUGC_IGetActorsMethod(UUGC_IGetActorsMethod&&); \
	UUGC_IGetActorsMethod(const UUGC_IGetActorsMethod&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUGC_IGetActorsMethod); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUGC_IGetActorsMethod); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUGC_IGetActorsMethod) \
	NO_API virtual ~UUGC_IGetActorsMethod();


#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Methods_UGC_IGetActorsMethod_h_14_PROLOG
#define FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Methods_UGC_IGetActorsMethod_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Methods_UGC_IGetActorsMethod_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Methods_UGC_IGetActorsMethod_h_17_CALLBACK_WRAPPERS \
	FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Methods_UGC_IGetActorsMethod_h_17_INCLASS_NO_PURE_DECLS \
	FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Methods_UGC_IGetActorsMethod_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> AURORADEVS_UGC_API UClass* StaticClass<class UUGC_IGetActorsMethod>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Methods_UGC_IGetActorsMethod_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
