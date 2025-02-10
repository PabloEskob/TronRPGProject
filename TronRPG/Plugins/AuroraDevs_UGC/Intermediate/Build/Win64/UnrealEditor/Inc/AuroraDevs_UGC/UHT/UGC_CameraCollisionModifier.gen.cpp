// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AuroraDevs_UGC/Public/Camera/Modifiers/UGC_CameraCollisionModifier.h"
#include "AuroraDevs_UGC/Public/Camera/Data/UGC_CameraData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUGC_CameraCollisionModifier() {}

// Begin Cross Module References
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_CameraCollisionModifier();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_CameraCollisionModifier_NoRegister();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_CameraModifier();
AURORADEVS_UGC_API UScriptStruct* Z_Construct_UScriptStruct_FCameraCollisionSettings();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_AuroraDevs_UGC();
// End Cross Module References

// Begin Class UUGC_CameraCollisionModifier
void UUGC_CameraCollisionModifier::StaticRegisterNativesUUGC_CameraCollisionModifier()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUGC_CameraCollisionModifier);
UClass* Z_Construct_UClass_UUGC_CameraCollisionModifier_NoRegister()
{
	return UUGC_CameraCollisionModifier::StaticClass();
}
struct Z_Construct_UClass_UUGC_CameraCollisionModifier_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ClassGroupNames", "UGC Camera Modifiers" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Camera Modifier which does camera avoidance using predictive collision feelers.\n */" },
#endif
		{ "IncludePath", "Camera/Modifiers/UGC_CameraCollisionModifier.h" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraCollisionModifier.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera Modifier which does camera avoidance using predictive collision feelers." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionSettings_MetaData[] = {
		{ "Category", "UGC|Modifiers|Collision" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraCollisionModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimLineToDesiredPosBlockedPct_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// If you don't want the camera to start close to the character and smoothly pan out once your character is spawned, default-initialize this variable to 1.f.\n" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraCollisionModifier.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If you don't want the camera to start close to the character and smoothly pan out once your character is spawned, default-initialize this variable to 1.f." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DebugActorsHitDuringCameraPenetration_MetaData[] = {
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraCollisionModifier.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CollisionSettings;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AimLineToDesiredPosBlockedPct;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DebugActorsHitDuringCameraPenetration_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DebugActorsHitDuringCameraPenetration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUGC_CameraCollisionModifier>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUGC_CameraCollisionModifier_Statics::NewProp_CollisionSettings = { "CollisionSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraCollisionModifier, CollisionSettings), Z_Construct_UScriptStruct_FCameraCollisionSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionSettings_MetaData), NewProp_CollisionSettings_MetaData) }; // 800239519
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UUGC_CameraCollisionModifier_Statics::NewProp_AimLineToDesiredPosBlockedPct = { "AimLineToDesiredPosBlockedPct", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraCollisionModifier, AimLineToDesiredPosBlockedPct), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimLineToDesiredPosBlockedPct_MetaData), NewProp_AimLineToDesiredPosBlockedPct_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUGC_CameraCollisionModifier_Statics::NewProp_DebugActorsHitDuringCameraPenetration_Inner = { "DebugActorsHitDuringCameraPenetration", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UUGC_CameraCollisionModifier_Statics::NewProp_DebugActorsHitDuringCameraPenetration = { "DebugActorsHitDuringCameraPenetration", nullptr, (EPropertyFlags)0x0114000000002000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraCollisionModifier, DebugActorsHitDuringCameraPenetration), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugActorsHitDuringCameraPenetration_MetaData), NewProp_DebugActorsHitDuringCameraPenetration_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUGC_CameraCollisionModifier_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraCollisionModifier_Statics::NewProp_CollisionSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraCollisionModifier_Statics::NewProp_AimLineToDesiredPosBlockedPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraCollisionModifier_Statics::NewProp_DebugActorsHitDuringCameraPenetration_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraCollisionModifier_Statics::NewProp_DebugActorsHitDuringCameraPenetration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraCollisionModifier_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UUGC_CameraCollisionModifier_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUGC_CameraModifier,
	(UObject* (*)())Z_Construct_UPackage__Script_AuroraDevs_UGC,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraCollisionModifier_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UUGC_CameraCollisionModifier_Statics::ClassParams = {
	&UUGC_CameraCollisionModifier::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UUGC_CameraCollisionModifier_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraCollisionModifier_Statics::PropPointers),
	0,
	0x009000A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraCollisionModifier_Statics::Class_MetaDataParams), Z_Construct_UClass_UUGC_CameraCollisionModifier_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UUGC_CameraCollisionModifier()
{
	if (!Z_Registration_Info_UClass_UUGC_CameraCollisionModifier.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUGC_CameraCollisionModifier.OuterSingleton, Z_Construct_UClass_UUGC_CameraCollisionModifier_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UUGC_CameraCollisionModifier.OuterSingleton;
}
template<> AURORADEVS_UGC_API UClass* StaticClass<UUGC_CameraCollisionModifier>()
{
	return UUGC_CameraCollisionModifier::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UUGC_CameraCollisionModifier);
UUGC_CameraCollisionModifier::~UUGC_CameraCollisionModifier() {}
// End Class UUGC_CameraCollisionModifier

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraCollisionModifier_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UUGC_CameraCollisionModifier, UUGC_CameraCollisionModifier::StaticClass, TEXT("UUGC_CameraCollisionModifier"), &Z_Registration_Info_UClass_UUGC_CameraCollisionModifier, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUGC_CameraCollisionModifier), 3913358522U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraCollisionModifier_h_4019267777(TEXT("/Script/AuroraDevs_UGC"),
	Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraCollisionModifier_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraCollisionModifier_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
