// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AuroraDevs_UGC/Public/Input/UGC_InputAccelerationModifier.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUGC_InputAccelerationModifier() {}

// Begin Cross Module References
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_InputAccelerationModifier();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_InputAccelerationModifier_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputModifier();
UPackage* Z_Construct_UPackage__Script_AuroraDevs_UGC();
// End Cross Module References

// Begin Class UUGC_InputAccelerationModifier
void UUGC_InputAccelerationModifier::StaticRegisterNativesUUGC_InputAccelerationModifier()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUGC_InputAccelerationModifier);
UClass* Z_Construct_UClass_UUGC_InputAccelerationModifier_NoRegister()
{
	return UUGC_InputAccelerationModifier::StaticClass();
}
struct Z_Construct_UClass_UUGC_InputAccelerationModifier_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ClassGroupNames", "UGC Input Modifiers" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Apply an acceleration curve to your input so that it accelerates as time goes by. The given curve should be time-normalized, i.e., between 0 and 1.\n */" },
#endif
		{ "IncludePath", "Input/UGC_InputAccelerationModifier.h" },
		{ "ModuleRelativePath", "Public/Input/UGC_InputAccelerationModifier.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Apply an acceleration curve to your input so that it accelerates as time goes by. The given curve should be time-normalized, i.e., between 0 and 1." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AccelerationTime_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The time it takes to reach full speed.\n" },
#endif
		{ "ModuleRelativePath", "Public/Input/UGC_InputAccelerationModifier.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The time it takes to reach full speed." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AccelerationCurve_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Apply an acceleration curve to your input so that it accelerates as time goes by. The given curve should be time-normalized, i.e., between 0 and 1.\n" },
#endif
		{ "DisplayThumbnail", "false" },
		{ "ModuleRelativePath", "Public/Input/UGC_InputAccelerationModifier.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Apply an acceleration curve to your input so that it accelerates as time goes by. The given curve should be time-normalized, i.e., between 0 and 1." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AccelerationTime;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AccelerationCurve;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUGC_InputAccelerationModifier>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UUGC_InputAccelerationModifier_Statics::NewProp_AccelerationTime = { "AccelerationTime", nullptr, (EPropertyFlags)0x0010000000004805, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_InputAccelerationModifier, AccelerationTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AccelerationTime_MetaData), NewProp_AccelerationTime_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUGC_InputAccelerationModifier_Statics::NewProp_AccelerationCurve = { "AccelerationCurve", nullptr, (EPropertyFlags)0x0114000000000805, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_InputAccelerationModifier, AccelerationCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AccelerationCurve_MetaData), NewProp_AccelerationCurve_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUGC_InputAccelerationModifier_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_InputAccelerationModifier_Statics::NewProp_AccelerationTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_InputAccelerationModifier_Statics::NewProp_AccelerationCurve,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_InputAccelerationModifier_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UUGC_InputAccelerationModifier_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInputModifier,
	(UObject* (*)())Z_Construct_UPackage__Script_AuroraDevs_UGC,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_InputAccelerationModifier_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UUGC_InputAccelerationModifier_Statics::ClassParams = {
	&UUGC_InputAccelerationModifier::StaticClass,
	"Input",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UUGC_InputAccelerationModifier_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_InputAccelerationModifier_Statics::PropPointers),
	0,
	0x401030A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_InputAccelerationModifier_Statics::Class_MetaDataParams), Z_Construct_UClass_UUGC_InputAccelerationModifier_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UUGC_InputAccelerationModifier()
{
	if (!Z_Registration_Info_UClass_UUGC_InputAccelerationModifier.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUGC_InputAccelerationModifier.OuterSingleton, Z_Construct_UClass_UUGC_InputAccelerationModifier_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UUGC_InputAccelerationModifier.OuterSingleton;
}
template<> AURORADEVS_UGC_API UClass* StaticClass<UUGC_InputAccelerationModifier>()
{
	return UUGC_InputAccelerationModifier::StaticClass();
}
UUGC_InputAccelerationModifier::UUGC_InputAccelerationModifier(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UUGC_InputAccelerationModifier);
UUGC_InputAccelerationModifier::~UUGC_InputAccelerationModifier() {}
// End Class UUGC_InputAccelerationModifier

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Input_UGC_InputAccelerationModifier_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UUGC_InputAccelerationModifier, UUGC_InputAccelerationModifier::StaticClass, TEXT("UUGC_InputAccelerationModifier"), &Z_Registration_Info_UClass_UUGC_InputAccelerationModifier, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUGC_InputAccelerationModifier), 1504957839U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Input_UGC_InputAccelerationModifier_h_176815259(TEXT("/Script/AuroraDevs_UGC"),
	Z_CompiledInDeferFile_FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Input_UGC_InputAccelerationModifier_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Input_UGC_InputAccelerationModifier_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
