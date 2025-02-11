// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TronRPG/Public/Component/TronRpgComboComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTronRpgComboComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
TRONRPG_API UClass* Z_Construct_UClass_UTronRpgComboComponent();
TRONRPG_API UClass* Z_Construct_UClass_UTronRpgComboComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_TronRPG();
// End Cross Module References

// Begin Class UTronRpgComboComponent Function IncrementCombo
struct Z_Construct_UFunction_UTronRpgComboComponent_IncrementCombo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combo" },
		{ "ModuleRelativePath", "Public/Component/TronRpgComboComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTronRpgComboComponent_IncrementCombo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTronRpgComboComponent, nullptr, "IncrementCombo", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTronRpgComboComponent_IncrementCombo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTronRpgComboComponent_IncrementCombo_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UTronRpgComboComponent_IncrementCombo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTronRpgComboComponent_IncrementCombo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTronRpgComboComponent::execIncrementCombo)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->IncrementCombo();
	P_NATIVE_END;
}
// End Class UTronRpgComboComponent Function IncrementCombo

// Begin Class UTronRpgComboComponent Function ResetCombo
struct Z_Construct_UFunction_UTronRpgComboComponent_ResetCombo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combo" },
		{ "ModuleRelativePath", "Public/Component/TronRpgComboComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTronRpgComboComponent_ResetCombo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTronRpgComboComponent, nullptr, "ResetCombo", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTronRpgComboComponent_ResetCombo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTronRpgComboComponent_ResetCombo_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UTronRpgComboComponent_ResetCombo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTronRpgComboComponent_ResetCombo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTronRpgComboComponent::execResetCombo)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetCombo();
	P_NATIVE_END;
}
// End Class UTronRpgComboComponent Function ResetCombo

// Begin Class UTronRpgComboComponent
void UTronRpgComboComponent::StaticRegisterNativesUTronRpgComboComponent()
{
	UClass* Class = UTronRpgComboComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "IncrementCombo", &UTronRpgComboComponent::execIncrementCombo },
		{ "ResetCombo", &UTronRpgComboComponent::execResetCombo },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTronRpgComboComponent);
UClass* Z_Construct_UClass_UTronRpgComboComponent_NoRegister()
{
	return UTronRpgComboComponent::StaticClass();
}
struct Z_Construct_UClass_UTronRpgComboComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Component/TronRpgComboComponent.h" },
		{ "ModuleRelativePath", "Public/Component/TronRpgComboComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ComboCount_MetaData[] = {
		{ "Category", "Combo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xd0\xa1\xd1\x87\xd1\x91\xd1\x82\xd1\x87\xd0\xb8\xd0\xba \xd0\xba\xd0\xbe\xd0\xbc\xd0\xb1\xd0\xbe\n" },
#endif
		{ "ModuleRelativePath", "Public/Component/TronRpgComboComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xd0\xa1\xd1\x87\xd1\x91\xd1\x82\xd1\x87\xd0\xb8\xd0\xba \xd0\xba\xd0\xbe\xd0\xbc\xd0\xb1\xd0\xbe" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ComboCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UTronRpgComboComponent_IncrementCombo, "IncrementCombo" }, // 2608131128
		{ &Z_Construct_UFunction_UTronRpgComboComponent_ResetCombo, "ResetCombo" }, // 1985649265
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTronRpgComboComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UTronRpgComboComponent_Statics::NewProp_ComboCount = { "ComboCount", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTronRpgComboComponent, ComboCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ComboCount_MetaData), NewProp_ComboCount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTronRpgComboComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTronRpgComboComponent_Statics::NewProp_ComboCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTronRpgComboComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UTronRpgComboComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_TronRPG,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTronRpgComboComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UTronRpgComboComponent_Statics::ClassParams = {
	&UTronRpgComboComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UTronRpgComboComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UTronRpgComboComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTronRpgComboComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UTronRpgComboComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UTronRpgComboComponent()
{
	if (!Z_Registration_Info_UClass_UTronRpgComboComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTronRpgComboComponent.OuterSingleton, Z_Construct_UClass_UTronRpgComboComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UTronRpgComboComponent.OuterSingleton;
}
template<> TRONRPG_API UClass* StaticClass<UTronRpgComboComponent>()
{
	return UTronRpgComboComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UTronRpgComboComponent);
UTronRpgComboComponent::~UTronRpgComboComponent() {}
// End Class UTronRpgComboComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Component_TronRpgComboComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UTronRpgComboComponent, UTronRpgComboComponent::StaticClass, TEXT("UTronRpgComboComponent"), &Z_Registration_Info_UClass_UTronRpgComboComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTronRpgComboComponent), 1178659989U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Component_TronRpgComboComponent_h_1121288027(TEXT("/Script/TronRPG"),
	Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Component_TronRpgComboComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Component_TronRpgComboComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
