// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TronRPG/Public/Character/TronRpgBaseCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTronRpgBaseCharacter() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UAnimInstance_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemInterface_NoRegister();
TRONRPG_API UClass* Z_Construct_UClass_ATronRpgBaseCharacter();
TRONRPG_API UClass* Z_Construct_UClass_ATronRpgBaseCharacter_NoRegister();
TRONRPG_API UClass* Z_Construct_UClass_UGameManager_NoRegister();
TRONRPG_API UClass* Z_Construct_UClass_UTronRpgAbilitySystemComponent_NoRegister();
TRONRPG_API UClass* Z_Construct_UClass_UTronRpgAttributeSet_NoRegister();
TRONRPG_API UClass* Z_Construct_UClass_UTronRpgComboComponent_NoRegister();
TRONRPG_API UClass* Z_Construct_UClass_UUIManager_NoRegister();
UPackage* Z_Construct_UPackage__Script_TronRPG();
// End Cross Module References

// Begin Class ATronRpgBaseCharacter Function InjectDependencies
struct Z_Construct_UFunction_ATronRpgBaseCharacter_InjectDependencies_Statics
{
	struct TronRpgBaseCharacter_eventInjectDependencies_Parms
	{
		UGameManager* InGameManager;
		UUIManager* InUIManager;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DI" },
		{ "ModuleRelativePath", "Public/Character/TronRpgBaseCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InGameManager;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InUIManager;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATronRpgBaseCharacter_InjectDependencies_Statics::NewProp_InGameManager = { "InGameManager", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TronRpgBaseCharacter_eventInjectDependencies_Parms, InGameManager), Z_Construct_UClass_UGameManager_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATronRpgBaseCharacter_InjectDependencies_Statics::NewProp_InUIManager = { "InUIManager", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TronRpgBaseCharacter_eventInjectDependencies_Parms, InUIManager), Z_Construct_UClass_UUIManager_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATronRpgBaseCharacter_InjectDependencies_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATronRpgBaseCharacter_InjectDependencies_Statics::NewProp_InGameManager,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATronRpgBaseCharacter_InjectDependencies_Statics::NewProp_InUIManager,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATronRpgBaseCharacter_InjectDependencies_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATronRpgBaseCharacter_InjectDependencies_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATronRpgBaseCharacter, nullptr, "InjectDependencies", nullptr, nullptr, Z_Construct_UFunction_ATronRpgBaseCharacter_InjectDependencies_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATronRpgBaseCharacter_InjectDependencies_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATronRpgBaseCharacter_InjectDependencies_Statics::TronRpgBaseCharacter_eventInjectDependencies_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATronRpgBaseCharacter_InjectDependencies_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATronRpgBaseCharacter_InjectDependencies_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATronRpgBaseCharacter_InjectDependencies_Statics::TronRpgBaseCharacter_eventInjectDependencies_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATronRpgBaseCharacter_InjectDependencies()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATronRpgBaseCharacter_InjectDependencies_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATronRpgBaseCharacter::execInjectDependencies)
{
	P_GET_OBJECT(UGameManager,Z_Param_InGameManager);
	P_GET_OBJECT(UUIManager,Z_Param_InUIManager);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InjectDependencies(Z_Param_InGameManager,Z_Param_InUIManager);
	P_NATIVE_END;
}
// End Class ATronRpgBaseCharacter Function InjectDependencies

// Begin Class ATronRpgBaseCharacter
void ATronRpgBaseCharacter::StaticRegisterNativesATronRpgBaseCharacter()
{
	UClass* Class = ATronRpgBaseCharacter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "InjectDependencies", &ATronRpgBaseCharacter::execInjectDependencies },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATronRpgBaseCharacter);
UClass* Z_Construct_UClass_ATronRpgBaseCharacter_NoRegister()
{
	return ATronRpgBaseCharacter::StaticClass();
}
struct Z_Construct_UClass_ATronRpgBaseCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/TronRpgBaseCharacter.h" },
		{ "ModuleRelativePath", "Public/Character/TronRpgBaseCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilitySystemComponent_MetaData[] = {
		{ "Category", "Abilities" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Ability System Component \xd0\xb4\xd0\xbb\xd1\x8f \xd1\x80\xd0\xb0\xd0\xb1\xd0\xbe\xd1\x82\xd1\x8b \xd1\x81 GAS\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Character/TronRpgBaseCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ability System Component \xd0\xb4\xd0\xbb\xd1\x8f \xd1\x80\xd0\xb0\xd0\xb1\xd0\xbe\xd1\x82\xd1\x8b \xd1\x81 GAS" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttributeSet_MetaData[] = {
		{ "Category", "Attributes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Attribute Set \xd1\x81 \xd0\xbe\xd1\x81\xd0\xbd\xd0\xbe\xd0\xb2\xd0\xbd\xd1\x8b\xd0\xbc\xd0\xb8 \xd0\xb0\xd1\x82\xd1\x80\xd0\xb8\xd0\xb1\xd1\x83\xd1\x82\xd0\xb0\xd0\xbc\xd0\xb8 (Health, Mana, Strength, Agility, Intelligence)\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Character/TronRpgBaseCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Attribute Set \xd1\x81 \xd0\xbe\xd1\x81\xd0\xbd\xd0\xbe\xd0\xb2\xd0\xbd\xd1\x8b\xd0\xbc\xd0\xb8 \xd0\xb0\xd1\x82\xd1\x80\xd0\xb8\xd0\xb1\xd1\x83\xd1\x82\xd0\xb0\xd0\xbc\xd0\xb8 (Health, Mana, Strength, Agility, Intelligence)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ComboComponent_MetaData[] = {
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xd0\x9a\xd0\xbe\xd0\xbc\xd0\xbf\xd0\xbe\xd0\xbd\xd0\xb5\xd0\xbd\xd1\x82 \xd0\xb4\xd0\xbb\xd1\x8f \xd1\x83\xd0\xbf\xd1\x80\xd0\xb0\xd0\xb2\xd0\xbb\xd0\xb5\xd0\xbd\xd0\xb8\xd1\x8f \xd0\xba\xd0\xbe\xd0\xbc\xd0\xb1\xd0\xbe-\xd0\xb0\xd1\x82\xd0\xb0\xd0\xba\xd0\xb0\xd0\xbc\xd0\xb8\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Character/TronRpgBaseCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xd0\x9a\xd0\xbe\xd0\xbc\xd0\xbf\xd0\xbe\xd0\xbd\xd0\xb5\xd0\xbd\xd1\x82 \xd0\xb4\xd0\xbb\xd1\x8f \xd1\x83\xd0\xbf\xd1\x80\xd0\xb0\xd0\xb2\xd0\xbb\xd0\xb5\xd0\xbd\xd0\xb8\xd1\x8f \xd0\xba\xd0\xbe\xd0\xbc\xd0\xb1\xd0\xbe-\xd0\xb0\xd1\x82\xd0\xb0\xd0\xba\xd0\xb0\xd0\xbc\xd0\xb8" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimInstance_MetaData[] = {
		{ "Category", "Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xd0\xa1\xd1\x81\xd1\x8b\xd0\xbb\xd0\xba\xd0\xb0 \xd0\xbd\xd0\xb0 Animation Instance (\xd0\xb4\xd0\xbb\xd1\x8f \xd0\xb8\xd0\xbd\xd1\x82\xd0\xb5\xd0\xb3\xd1\x80\xd0\xb0\xd1\x86\xd0\xb8\xd0\xb8 \xd1\x81 Motion Matching)\n" },
#endif
		{ "ModuleRelativePath", "Public/Character/TronRpgBaseCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xd0\xa1\xd1\x81\xd1\x8b\xd0\xbb\xd0\xba\xd0\xb0 \xd0\xbd\xd0\xb0 Animation Instance (\xd0\xb4\xd0\xbb\xd1\x8f \xd0\xb8\xd0\xbd\xd1\x82\xd0\xb5\xd0\xb3\xd1\x80\xd0\xb0\xd1\x86\xd0\xb8\xd0\xb8 \xd1\x81 Motion Matching)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameManager_MetaData[] = {
		{ "Category", "Managers" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xd0\x97\xd0\xb0\xd0\xb2\xd0\xb8\xd1\x81\xd0\xb8\xd0\xbc\xd0\xbe\xd1\x81\xd1\x82\xd0\xb8, \xd0\xb2\xd0\xbd\xd0\xb5\xd0\xb4\xd1\x80\xd1\x8f\xd0\xb5\xd0\xbc\xd1\x8b\xd0\xb5 \xd1\x87\xd0\xb5\xd1\x80\xd0\xb5\xd0\xb7 DI (\xd0\xbd\xd0\xb0\xd0\xbf\xd1\x80\xd0\xb8\xd0\xbc\xd0\xb5\xd1\x80, \xd0\xbc\xd0\xb5\xd0\xbd\xd0\xb5\xd0\xb4\xd0\xb6\xd0\xb5\xd1\x80\xd1\x8b)\n" },
#endif
		{ "ModuleRelativePath", "Public/Character/TronRpgBaseCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xd0\x97\xd0\xb0\xd0\xb2\xd0\xb8\xd1\x81\xd0\xb8\xd0\xbc\xd0\xbe\xd1\x81\xd1\x82\xd0\xb8, \xd0\xb2\xd0\xbd\xd0\xb5\xd0\xb4\xd1\x80\xd1\x8f\xd0\xb5\xd0\xbc\xd1\x8b\xd0\xb5 \xd1\x87\xd0\xb5\xd1\x80\xd0\xb5\xd0\xb7 DI (\xd0\xbd\xd0\xb0\xd0\xbf\xd1\x80\xd0\xb8\xd0\xbc\xd0\xb5\xd1\x80, \xd0\xbc\xd0\xb5\xd0\xbd\xd0\xb5\xd0\xb4\xd0\xb6\xd0\xb5\xd1\x80\xd1\x8b)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UIManager_MetaData[] = {
		{ "Category", "Managers" },
		{ "ModuleRelativePath", "Public/Character/TronRpgBaseCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AbilitySystemComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttributeSet;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ComboComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AnimInstance;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GameManager;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UIManager;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ATronRpgBaseCharacter_InjectDependencies, "InjectDependencies" }, // 3846562267
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATronRpgBaseCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATronRpgBaseCharacter_Statics::NewProp_AbilitySystemComponent = { "AbilitySystemComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATronRpgBaseCharacter, AbilitySystemComponent), Z_Construct_UClass_UTronRpgAbilitySystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilitySystemComponent_MetaData), NewProp_AbilitySystemComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATronRpgBaseCharacter_Statics::NewProp_AttributeSet = { "AttributeSet", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATronRpgBaseCharacter, AttributeSet), Z_Construct_UClass_UTronRpgAttributeSet_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttributeSet_MetaData), NewProp_AttributeSet_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATronRpgBaseCharacter_Statics::NewProp_ComboComponent = { "ComboComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATronRpgBaseCharacter, ComboComponent), Z_Construct_UClass_UTronRpgComboComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ComboComponent_MetaData), NewProp_ComboComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATronRpgBaseCharacter_Statics::NewProp_AnimInstance = { "AnimInstance", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATronRpgBaseCharacter, AnimInstance), Z_Construct_UClass_UAnimInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimInstance_MetaData), NewProp_AnimInstance_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATronRpgBaseCharacter_Statics::NewProp_GameManager = { "GameManager", nullptr, (EPropertyFlags)0x0010000000002014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATronRpgBaseCharacter, GameManager), Z_Construct_UClass_UGameManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameManager_MetaData), NewProp_GameManager_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATronRpgBaseCharacter_Statics::NewProp_UIManager = { "UIManager", nullptr, (EPropertyFlags)0x0010000000002014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATronRpgBaseCharacter, UIManager), Z_Construct_UClass_UUIManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UIManager_MetaData), NewProp_UIManager_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATronRpgBaseCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATronRpgBaseCharacter_Statics::NewProp_AbilitySystemComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATronRpgBaseCharacter_Statics::NewProp_AttributeSet,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATronRpgBaseCharacter_Statics::NewProp_ComboComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATronRpgBaseCharacter_Statics::NewProp_AnimInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATronRpgBaseCharacter_Statics::NewProp_GameManager,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATronRpgBaseCharacter_Statics::NewProp_UIManager,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATronRpgBaseCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ATronRpgBaseCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_TronRPG,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATronRpgBaseCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ATronRpgBaseCharacter_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UAbilitySystemInterface_NoRegister, (int32)VTABLE_OFFSET(ATronRpgBaseCharacter, IAbilitySystemInterface), false },  // 2272790346
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATronRpgBaseCharacter_Statics::ClassParams = {
	&ATronRpgBaseCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ATronRpgBaseCharacter_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ATronRpgBaseCharacter_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATronRpgBaseCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_ATronRpgBaseCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATronRpgBaseCharacter()
{
	if (!Z_Registration_Info_UClass_ATronRpgBaseCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATronRpgBaseCharacter.OuterSingleton, Z_Construct_UClass_ATronRpgBaseCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATronRpgBaseCharacter.OuterSingleton;
}
template<> TRONRPG_API UClass* StaticClass<ATronRpgBaseCharacter>()
{
	return ATronRpgBaseCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATronRpgBaseCharacter);
ATronRpgBaseCharacter::~ATronRpgBaseCharacter() {}
// End Class ATronRpgBaseCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_TronRpgBaseCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATronRpgBaseCharacter, ATronRpgBaseCharacter::StaticClass, TEXT("ATronRpgBaseCharacter"), &Z_Registration_Info_UClass_ATronRpgBaseCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATronRpgBaseCharacter), 2598699923U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_TronRpgBaseCharacter_h_2479019866(TEXT("/Script/TronRPG"),
	Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_TronRpgBaseCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_TronRpgBaseCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
