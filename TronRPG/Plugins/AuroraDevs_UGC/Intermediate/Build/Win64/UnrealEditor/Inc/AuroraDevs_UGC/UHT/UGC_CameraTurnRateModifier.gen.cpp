// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AuroraDevs_UGC/Public/Input/UGC_CameraTurnRateModifier.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUGC_CameraTurnRateModifier() {}

// Begin Cross Module References
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_CameraTurnRateModifier();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_CameraTurnRateModifier_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputModifier();
UPackage* Z_Construct_UPackage__Script_AuroraDevs_UGC();
// End Cross Module References

// Begin Class UUGC_CameraTurnRateModifier
void UUGC_CameraTurnRateModifier::StaticRegisterNativesUUGC_CameraTurnRateModifier()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUGC_CameraTurnRateModifier);
UClass* Z_Construct_UClass_UUGC_CameraTurnRateModifier_NoRegister()
{
	return UUGC_CameraTurnRateModifier::StaticClass();
}
struct Z_Construct_UClass_UUGC_CameraTurnRateModifier_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "IncludePath", "Input/UGC_CameraTurnRateModifier.h" },
		{ "ModuleRelativePath", "Public/Input/UGC_CameraTurnRateModifier.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUGC_CameraTurnRateModifier>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UUGC_CameraTurnRateModifier_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInputModifier,
	(UObject* (*)())Z_Construct_UPackage__Script_AuroraDevs_UGC,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraTurnRateModifier_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UUGC_CameraTurnRateModifier_Statics::ClassParams = {
	&UUGC_CameraTurnRateModifier::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x401030A2u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraTurnRateModifier_Statics::Class_MetaDataParams), Z_Construct_UClass_UUGC_CameraTurnRateModifier_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UUGC_CameraTurnRateModifier()
{
	if (!Z_Registration_Info_UClass_UUGC_CameraTurnRateModifier.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUGC_CameraTurnRateModifier.OuterSingleton, Z_Construct_UClass_UUGC_CameraTurnRateModifier_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UUGC_CameraTurnRateModifier.OuterSingleton;
}
template<> AURORADEVS_UGC_API UClass* StaticClass<UUGC_CameraTurnRateModifier>()
{
	return UUGC_CameraTurnRateModifier::StaticClass();
}
UUGC_CameraTurnRateModifier::UUGC_CameraTurnRateModifier(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UUGC_CameraTurnRateModifier);
UUGC_CameraTurnRateModifier::~UUGC_CameraTurnRateModifier() {}
// End Class UUGC_CameraTurnRateModifier

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Input_UGC_CameraTurnRateModifier_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UUGC_CameraTurnRateModifier, UUGC_CameraTurnRateModifier::StaticClass, TEXT("UUGC_CameraTurnRateModifier"), &Z_Registration_Info_UClass_UUGC_CameraTurnRateModifier, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUGC_CameraTurnRateModifier), 2441967286U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Input_UGC_CameraTurnRateModifier_h_659832917(TEXT("/Script/AuroraDevs_UGC"),
	Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Input_UGC_CameraTurnRateModifier_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Input_UGC_CameraTurnRateModifier_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
