// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TronRPG/Public/Input/TronRpgEnhancedInputComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTronRpgEnhancedInputComponent() {}

// Begin Cross Module References
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UEnhancedInputComponent();
TRONRPG_API UClass* Z_Construct_UClass_UTronRpgEnhancedInputComponent();
TRONRPG_API UClass* Z_Construct_UClass_UTronRpgEnhancedInputComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_TronRPG();
// End Cross Module References

// Begin Class UTronRpgEnhancedInputComponent
void UTronRpgEnhancedInputComponent::StaticRegisterNativesUTronRpgEnhancedInputComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTronRpgEnhancedInputComponent);
UClass* Z_Construct_UClass_UTronRpgEnhancedInputComponent_NoRegister()
{
	return UTronRpgEnhancedInputComponent::StaticClass();
}
struct Z_Construct_UClass_UTronRpgEnhancedInputComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Activation Components|Activation Activation Components|Activation" },
		{ "IncludePath", "Input/TronRpgEnhancedInputComponent.h" },
		{ "ModuleRelativePath", "Public/Input/TronRpgEnhancedInputComponent.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTronRpgEnhancedInputComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UTronRpgEnhancedInputComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEnhancedInputComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_TronRPG,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTronRpgEnhancedInputComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UTronRpgEnhancedInputComponent_Statics::ClassParams = {
	&UTronRpgEnhancedInputComponent::StaticClass,
	"Input",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B000ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTronRpgEnhancedInputComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UTronRpgEnhancedInputComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UTronRpgEnhancedInputComponent()
{
	if (!Z_Registration_Info_UClass_UTronRpgEnhancedInputComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTronRpgEnhancedInputComponent.OuterSingleton, Z_Construct_UClass_UTronRpgEnhancedInputComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UTronRpgEnhancedInputComponent.OuterSingleton;
}
template<> TRONRPG_API UClass* StaticClass<UTronRpgEnhancedInputComponent>()
{
	return UTronRpgEnhancedInputComponent::StaticClass();
}
UTronRpgEnhancedInputComponent::UTronRpgEnhancedInputComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UTronRpgEnhancedInputComponent);
UTronRpgEnhancedInputComponent::~UTronRpgEnhancedInputComponent() {}
// End Class UTronRpgEnhancedInputComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Input_TronRpgEnhancedInputComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UTronRpgEnhancedInputComponent, UTronRpgEnhancedInputComponent::StaticClass, TEXT("UTronRpgEnhancedInputComponent"), &Z_Registration_Info_UClass_UTronRpgEnhancedInputComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTronRpgEnhancedInputComponent), 3653355141U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Input_TronRpgEnhancedInputComponent_h_738872631(TEXT("/Script/TronRPG"),
	Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Input_TronRpgEnhancedInputComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Input_TronRpgEnhancedInputComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
