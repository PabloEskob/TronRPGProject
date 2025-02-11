// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TronRPG/Public/Character/Player/TronRpgPlayerCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTronRpgPlayerCharacter() {}

// Begin Cross Module References
TRONRPG_API UClass* Z_Construct_UClass_ATronRpgBaseCharacter();
TRONRPG_API UClass* Z_Construct_UClass_ATronRpgPlayerCharacter();
TRONRPG_API UClass* Z_Construct_UClass_ATronRpgPlayerCharacter_NoRegister();
UPackage* Z_Construct_UPackage__Script_TronRPG();
// End Cross Module References

// Begin Class ATronRpgPlayerCharacter
void ATronRpgPlayerCharacter::StaticRegisterNativesATronRpgPlayerCharacter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATronRpgPlayerCharacter);
UClass* Z_Construct_UClass_ATronRpgPlayerCharacter_NoRegister()
{
	return ATronRpgPlayerCharacter::StaticClass();
}
struct Z_Construct_UClass_ATronRpgPlayerCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/Player/TronRpgPlayerCharacter.h" },
		{ "ModuleRelativePath", "Public/Character/Player/TronRpgPlayerCharacter.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATronRpgPlayerCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ATronRpgPlayerCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ATronRpgBaseCharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_TronRPG,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATronRpgPlayerCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATronRpgPlayerCharacter_Statics::ClassParams = {
	&ATronRpgPlayerCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATronRpgPlayerCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_ATronRpgPlayerCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATronRpgPlayerCharacter()
{
	if (!Z_Registration_Info_UClass_ATronRpgPlayerCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATronRpgPlayerCharacter.OuterSingleton, Z_Construct_UClass_ATronRpgPlayerCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATronRpgPlayerCharacter.OuterSingleton;
}
template<> TRONRPG_API UClass* StaticClass<ATronRpgPlayerCharacter>()
{
	return ATronRpgPlayerCharacter::StaticClass();
}
ATronRpgPlayerCharacter::ATronRpgPlayerCharacter() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATronRpgPlayerCharacter);
ATronRpgPlayerCharacter::~ATronRpgPlayerCharacter() {}
// End Class ATronRpgPlayerCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_Player_TronRpgPlayerCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATronRpgPlayerCharacter, ATronRpgPlayerCharacter::StaticClass, TEXT("ATronRpgPlayerCharacter"), &Z_Registration_Info_UClass_ATronRpgPlayerCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATronRpgPlayerCharacter), 1600082403U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_Player_TronRpgPlayerCharacter_h_3845599711(TEXT("/Script/TronRPG"),
	Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_Player_TronRpgPlayerCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_Character_Player_TronRpgPlayerCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
