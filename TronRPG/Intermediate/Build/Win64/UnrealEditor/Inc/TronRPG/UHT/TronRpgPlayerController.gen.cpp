// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TronRPG/Public/Controller/TronRpgPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTronRpgPlayerController() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
TRONRPG_API UClass* Z_Construct_UClass_ATronRpgPlayerController();
TRONRPG_API UClass* Z_Construct_UClass_ATronRpgPlayerController_NoRegister();
UPackage* Z_Construct_UPackage__Script_TronRPG();
// End Cross Module References

// Begin Class ATronRpgPlayerController
void ATronRpgPlayerController::StaticRegisterNativesATronRpgPlayerController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATronRpgPlayerController);
UClass* Z_Construct_UClass_ATronRpgPlayerController_NoRegister()
{
	return ATronRpgPlayerController::StaticClass();
}
struct Z_Construct_UClass_ATronRpgPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Controller/TronRpgPlayerController.h" },
		{ "ModuleRelativePath", "Public/Controller/TronRpgPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RpgContext_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Controller/TronRpgPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Controller/TronRpgPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Controller/TronRpgPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_YawSpeed_MetaData[] = {
		{ "Category", "TronRpgPlayerController" },
		{ "ModuleRelativePath", "Public/Controller/TronRpgPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PitchSpeed_MetaData[] = {
		{ "Category", "TronRpgPlayerController" },
		{ "ModuleRelativePath", "Public/Controller/TronRpgPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RpgContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_YawSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PitchSpeed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATronRpgPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATronRpgPlayerController_Statics::NewProp_RpgContext = { "RpgContext", nullptr, (EPropertyFlags)0x0144000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATronRpgPlayerController, RpgContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RpgContext_MetaData), NewProp_RpgContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATronRpgPlayerController_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0144000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATronRpgPlayerController, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATronRpgPlayerController_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0144000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATronRpgPlayerController, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATronRpgPlayerController_Statics::NewProp_YawSpeed = { "YawSpeed", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATronRpgPlayerController, YawSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_YawSpeed_MetaData), NewProp_YawSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATronRpgPlayerController_Statics::NewProp_PitchSpeed = { "PitchSpeed", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATronRpgPlayerController, PitchSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PitchSpeed_MetaData), NewProp_PitchSpeed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATronRpgPlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATronRpgPlayerController_Statics::NewProp_RpgContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATronRpgPlayerController_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATronRpgPlayerController_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATronRpgPlayerController_Statics::NewProp_YawSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATronRpgPlayerController_Statics::NewProp_PitchSpeed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATronRpgPlayerController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ATronRpgPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_TronRPG,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATronRpgPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATronRpgPlayerController_Statics::ClassParams = {
	&ATronRpgPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ATronRpgPlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ATronRpgPlayerController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATronRpgPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_ATronRpgPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATronRpgPlayerController()
{
	if (!Z_Registration_Info_UClass_ATronRpgPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATronRpgPlayerController.OuterSingleton, Z_Construct_UClass_ATronRpgPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATronRpgPlayerController.OuterSingleton;
}
template<> TRONRPG_API UClass* StaticClass<ATronRpgPlayerController>()
{
	return ATronRpgPlayerController::StaticClass();
}
ATronRpgPlayerController::ATronRpgPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATronRpgPlayerController);
ATronRpgPlayerController::~ATronRpgPlayerController() {}
// End Class ATronRpgPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Controller_TronRpgPlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATronRpgPlayerController, ATronRpgPlayerController::StaticClass, TEXT("ATronRpgPlayerController"), &Z_Registration_Info_UClass_ATronRpgPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATronRpgPlayerController), 1140655503U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Controller_TronRpgPlayerController_h_1872972381(TEXT("/Script/TronRPG"),
	Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Controller_TronRpgPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Controller_TronRpgPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
