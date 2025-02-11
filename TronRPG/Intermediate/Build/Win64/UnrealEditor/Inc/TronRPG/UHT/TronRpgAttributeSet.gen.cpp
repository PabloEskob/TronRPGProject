// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TronRPG/Public/GAS/TronRpgAttributeSet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTronRpgAttributeSet() {}

// Begin Cross Module References
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAttributeSet();
TRONRPG_API UClass* Z_Construct_UClass_UTronRpgAttributeSet();
TRONRPG_API UClass* Z_Construct_UClass_UTronRpgAttributeSet_NoRegister();
UPackage* Z_Construct_UPackage__Script_TronRPG();
// End Cross Module References

// Begin Class UTronRpgAttributeSet
void UTronRpgAttributeSet::StaticRegisterNativesUTronRpgAttributeSet()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTronRpgAttributeSet);
UClass* Z_Construct_UClass_UTronRpgAttributeSet_NoRegister()
{
	return UTronRpgAttributeSet::StaticClass();
}
struct Z_Construct_UClass_UTronRpgAttributeSet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "GAS/TronRpgAttributeSet.h" },
		{ "ModuleRelativePath", "Public/GAS/TronRpgAttributeSet.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTronRpgAttributeSet>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UTronRpgAttributeSet_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAttributeSet,
	(UObject* (*)())Z_Construct_UPackage__Script_TronRPG,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTronRpgAttributeSet_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UTronRpgAttributeSet_Statics::ClassParams = {
	&UTronRpgAttributeSet::StaticClass,
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
	0x003000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTronRpgAttributeSet_Statics::Class_MetaDataParams), Z_Construct_UClass_UTronRpgAttributeSet_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UTronRpgAttributeSet()
{
	if (!Z_Registration_Info_UClass_UTronRpgAttributeSet.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTronRpgAttributeSet.OuterSingleton, Z_Construct_UClass_UTronRpgAttributeSet_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UTronRpgAttributeSet.OuterSingleton;
}
template<> TRONRPG_API UClass* StaticClass<UTronRpgAttributeSet>()
{
	return UTronRpgAttributeSet::StaticClass();
}
UTronRpgAttributeSet::UTronRpgAttributeSet(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UTronRpgAttributeSet);
UTronRpgAttributeSet::~UTronRpgAttributeSet() {}
// End Class UTronRpgAttributeSet

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GAS_TronRpgAttributeSet_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UTronRpgAttributeSet, UTronRpgAttributeSet::StaticClass, TEXT("UTronRpgAttributeSet"), &Z_Registration_Info_UClass_UTronRpgAttributeSet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTronRpgAttributeSet), 978903874U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GAS_TronRpgAttributeSet_h_2544029546(TEXT("/Script/TronRPG"),
	Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GAS_TronRpgAttributeSet_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GAS_TronRpgAttributeSet_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
