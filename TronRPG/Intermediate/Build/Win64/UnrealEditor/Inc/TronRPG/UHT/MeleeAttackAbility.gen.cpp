// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TronRPG/Public/GameplayAbility/MeleeAttackAbility.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMeleeAttackAbility() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility();
TRONRPG_API UClass* Z_Construct_UClass_UMeleeAttackAbility();
TRONRPG_API UClass* Z_Construct_UClass_UMeleeAttackAbility_NoRegister();
UPackage* Z_Construct_UPackage__Script_TronRPG();
// End Cross Module References

// Begin Class UMeleeAttackAbility Function OnApplyDamageNotify
struct Z_Construct_UFunction_UMeleeAttackAbility_OnApplyDamageNotify_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Callback, \xd0\xba\xd0\xbe\xd1\x82\xd0\xbe\xd1\x80\xd1\x8b\xd0\xb9 \xd0\xbc\xd0\xbe\xd0\xb6\xd0\xbd\xd0\xbe \xd0\xb2\xd1\x8b\xd0\xb7\xd1\x8b\xd0\xb2\xd0\xb0\xd1\x82\xd1\x8c \xd1\x87\xd0\xb5\xd1\x80\xd0\xb5\xd0\xb7 Animation Notify \xd0\xb4\xd0\xbb\xd1\x8f \xd0\xbf\xd1\x80\xd0\xb8\xd0\xbc\xd0\xb5\xd0\xbd\xd0\xb5\xd0\xbd\xd0\xb8\xd1\x8f \xd1\x83\xd1\x80\xd0\xbe\xd0\xbd\xd0\xb0\n" },
#endif
		{ "ModuleRelativePath", "Public/GameplayAbility/MeleeAttackAbility.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Callback, \xd0\xba\xd0\xbe\xd1\x82\xd0\xbe\xd1\x80\xd1\x8b\xd0\xb9 \xd0\xbc\xd0\xbe\xd0\xb6\xd0\xbd\xd0\xbe \xd0\xb2\xd1\x8b\xd0\xb7\xd1\x8b\xd0\xb2\xd0\xb0\xd1\x82\xd1\x8c \xd1\x87\xd0\xb5\xd1\x80\xd0\xb5\xd0\xb7 Animation Notify \xd0\xb4\xd0\xbb\xd1\x8f \xd0\xbf\xd1\x80\xd0\xb8\xd0\xbc\xd0\xb5\xd0\xbd\xd0\xb5\xd0\xbd\xd0\xb8\xd1\x8f \xd1\x83\xd1\x80\xd0\xbe\xd0\xbd\xd0\xb0" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeleeAttackAbility_OnApplyDamageNotify_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeleeAttackAbility, nullptr, "OnApplyDamageNotify", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMeleeAttackAbility_OnApplyDamageNotify_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMeleeAttackAbility_OnApplyDamageNotify_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UMeleeAttackAbility_OnApplyDamageNotify()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMeleeAttackAbility_OnApplyDamageNotify_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMeleeAttackAbility::execOnApplyDamageNotify)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnApplyDamageNotify();
	P_NATIVE_END;
}
// End Class UMeleeAttackAbility Function OnApplyDamageNotify

// Begin Class UMeleeAttackAbility
void UMeleeAttackAbility::StaticRegisterNativesUMeleeAttackAbility()
{
	UClass* Class = UMeleeAttackAbility::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnApplyDamageNotify", &UMeleeAttackAbility::execOnApplyDamageNotify },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMeleeAttackAbility);
UClass* Z_Construct_UClass_UMeleeAttackAbility_NoRegister()
{
	return UMeleeAttackAbility::StaticClass();
}
struct Z_Construct_UClass_UMeleeAttackAbility_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "GameplayAbility/MeleeAttackAbility.h" },
		{ "ModuleRelativePath", "Public/GameplayAbility/MeleeAttackAbility.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeleeAttackMontage_MetaData[] = {
		{ "Category", "Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xd0\xa1\xd1\x81\xd1\x8b\xd0\xbb\xd0\xba\xd0\xb0 \xd0\xbd\xd0\xb0 Animation Montage, \xd0\xba\xd0\xbe\xd1\x82\xd0\xbe\xd1\x80\xd1\x83\xd1\x8e \xd0\xbc\xd0\xbe\xd0\xb6\xd0\xbd\xd0\xbe \xd0\xb7\xd0\xb0\xd0\xb4\xd0\xb0\xd1\x82\xd1\x8c \xd0\xb2 \xd0\xbd\xd0\xb0\xd1\x81\xd1\x82\xd1\x80\xd0\xbe\xd0\xb9\xd0\xba\xd0\xb0\xd1\x85 (\xd0\xbf\xd0\xbe \xd1\x83\xd0\xbc\xd0\xbe\xd0\xbb\xd1\x87\xd0\xb0\xd0\xbd\xd0\xb8\xd1\x8e \xd1\x87\xd0\xb5\xd1\x80\xd0\xb5\xd0\xb7 Blueprint)\n" },
#endif
		{ "ModuleRelativePath", "Public/GameplayAbility/MeleeAttackAbility.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xd0\xa1\xd1\x81\xd1\x8b\xd0\xbb\xd0\xba\xd0\xb0 \xd0\xbd\xd0\xb0 Animation Montage, \xd0\xba\xd0\xbe\xd1\x82\xd0\xbe\xd1\x80\xd1\x83\xd1\x8e \xd0\xbc\xd0\xbe\xd0\xb6\xd0\xbd\xd0\xbe \xd0\xb7\xd0\xb0\xd0\xb4\xd0\xb0\xd1\x82\xd1\x8c \xd0\xb2 \xd0\xbd\xd0\xb0\xd1\x81\xd1\x82\xd1\x80\xd0\xbe\xd0\xb9\xd0\xba\xd0\xb0\xd1\x85 (\xd0\xbf\xd0\xbe \xd1\x83\xd0\xbc\xd0\xbe\xd0\xbb\xd1\x87\xd0\xb0\xd0\xbd\xd0\xb8\xd1\x8e \xd1\x87\xd0\xb5\xd1\x80\xd0\xb5\xd0\xb7 Blueprint)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MeleeAttackMontage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMeleeAttackAbility_OnApplyDamageNotify, "OnApplyDamageNotify" }, // 294173994
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMeleeAttackAbility>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMeleeAttackAbility_Statics::NewProp_MeleeAttackMontage = { "MeleeAttackMontage", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMeleeAttackAbility, MeleeAttackMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeleeAttackMontage_MetaData), NewProp_MeleeAttackMontage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMeleeAttackAbility_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMeleeAttackAbility_Statics::NewProp_MeleeAttackMontage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMeleeAttackAbility_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMeleeAttackAbility_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameplayAbility,
	(UObject* (*)())Z_Construct_UPackage__Script_TronRPG,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMeleeAttackAbility_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMeleeAttackAbility_Statics::ClassParams = {
	&UMeleeAttackAbility::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UMeleeAttackAbility_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UMeleeAttackAbility_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMeleeAttackAbility_Statics::Class_MetaDataParams), Z_Construct_UClass_UMeleeAttackAbility_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMeleeAttackAbility()
{
	if (!Z_Registration_Info_UClass_UMeleeAttackAbility.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMeleeAttackAbility.OuterSingleton, Z_Construct_UClass_UMeleeAttackAbility_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMeleeAttackAbility.OuterSingleton;
}
template<> TRONRPG_API UClass* StaticClass<UMeleeAttackAbility>()
{
	return UMeleeAttackAbility::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMeleeAttackAbility);
UMeleeAttackAbility::~UMeleeAttackAbility() {}
// End Class UMeleeAttackAbility

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GameplayAbility_MeleeAttackAbility_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMeleeAttackAbility, UMeleeAttackAbility::StaticClass, TEXT("UMeleeAttackAbility"), &Z_Registration_Info_UClass_UMeleeAttackAbility, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMeleeAttackAbility), 829877176U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GameplayAbility_MeleeAttackAbility_h_3875432873(TEXT("/Script/TronRPG"),
	Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GameplayAbility_MeleeAttackAbility_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GameplayAbility_MeleeAttackAbility_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
