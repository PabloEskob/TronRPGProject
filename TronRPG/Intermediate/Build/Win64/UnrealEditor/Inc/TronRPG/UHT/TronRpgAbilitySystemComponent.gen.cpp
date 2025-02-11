// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TronRPG/Public/GAS/TronRpgAbilitySystemComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTronRpgAbilitySystemComponent() {}

// Begin Cross Module References
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent();
TRONRPG_API UClass* Z_Construct_UClass_UTronRpgAbilitySystemComponent();
TRONRPG_API UClass* Z_Construct_UClass_UTronRpgAbilitySystemComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_TronRPG();
// End Cross Module References

// Begin Class UTronRpgAbilitySystemComponent
void UTronRpgAbilitySystemComponent::StaticRegisterNativesUTronRpgAbilitySystemComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTronRpgAbilitySystemComponent);
UClass* Z_Construct_UClass_UTronRpgAbilitySystemComponent_NoRegister()
{
	return UTronRpgAbilitySystemComponent::StaticClass();
}
struct Z_Construct_UClass_UTronRpgAbilitySystemComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Object LOD Lighting Transform Sockets TextureStreaming Object LOD Lighting Transform Sockets TextureStreaming" },
		{ "IncludePath", "GAS/TronRpgAbilitySystemComponent.h" },
		{ "ModuleRelativePath", "Public/GAS/TronRpgAbilitySystemComponent.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTronRpgAbilitySystemComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UTronRpgAbilitySystemComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAbilitySystemComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_TronRPG,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTronRpgAbilitySystemComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UTronRpgAbilitySystemComponent_Statics::ClassParams = {
	&UTronRpgAbilitySystemComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTronRpgAbilitySystemComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UTronRpgAbilitySystemComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UTronRpgAbilitySystemComponent()
{
	if (!Z_Registration_Info_UClass_UTronRpgAbilitySystemComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTronRpgAbilitySystemComponent.OuterSingleton, Z_Construct_UClass_UTronRpgAbilitySystemComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UTronRpgAbilitySystemComponent.OuterSingleton;
}
template<> TRONRPG_API UClass* StaticClass<UTronRpgAbilitySystemComponent>()
{
	return UTronRpgAbilitySystemComponent::StaticClass();
}
UTronRpgAbilitySystemComponent::UTronRpgAbilitySystemComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UTronRpgAbilitySystemComponent);
UTronRpgAbilitySystemComponent::~UTronRpgAbilitySystemComponent() {}
// End Class UTronRpgAbilitySystemComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GAS_TronRpgAbilitySystemComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UTronRpgAbilitySystemComponent, UTronRpgAbilitySystemComponent::StaticClass, TEXT("UTronRpgAbilitySystemComponent"), &Z_Registration_Info_UClass_UTronRpgAbilitySystemComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTronRpgAbilitySystemComponent), 3296737682U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GAS_TronRpgAbilitySystemComponent_h_791436286(TEXT("/Script/TronRPG"),
	Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GAS_TronRpgAbilitySystemComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GAS_TronRpgAbilitySystemComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
