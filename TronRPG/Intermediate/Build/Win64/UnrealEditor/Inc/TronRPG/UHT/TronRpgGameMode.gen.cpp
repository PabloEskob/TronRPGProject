// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TronRPG/Public/GameMode/TronRpgGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTronRpgGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
TRONRPG_API UClass* Z_Construct_UClass_ATronRpgGameMode();
TRONRPG_API UClass* Z_Construct_UClass_ATronRpgGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_TronRPG();
// End Cross Module References

// Begin Class ATronRpgGameMode
void ATronRpgGameMode::StaticRegisterNativesATronRpgGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATronRpgGameMode);
UClass* Z_Construct_UClass_ATronRpgGameMode_NoRegister()
{
	return ATronRpgGameMode::StaticClass();
}
struct Z_Construct_UClass_ATronRpgGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GameMode/TronRpgGameMode.h" },
		{ "ModuleRelativePath", "Public/GameMode/TronRpgGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATronRpgGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ATronRpgGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_TronRPG,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATronRpgGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATronRpgGameMode_Statics::ClassParams = {
	&ATronRpgGameMode::StaticClass,
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
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATronRpgGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ATronRpgGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATronRpgGameMode()
{
	if (!Z_Registration_Info_UClass_ATronRpgGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATronRpgGameMode.OuterSingleton, Z_Construct_UClass_ATronRpgGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATronRpgGameMode.OuterSingleton;
}
template<> TRONRPG_API UClass* StaticClass<ATronRpgGameMode>()
{
	return ATronRpgGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATronRpgGameMode);
ATronRpgGameMode::~ATronRpgGameMode() {}
// End Class ATronRpgGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GameMode_TronRpgGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATronRpgGameMode, ATronRpgGameMode::StaticClass, TEXT("ATronRpgGameMode"), &Z_Registration_Info_UClass_ATronRpgGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATronRpgGameMode), 3892276675U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GameMode_TronRpgGameMode_h_2581349255(TEXT("/Script/TronRPG"),
	Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GameMode_TronRpgGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Source_TronRPG_Public_GameMode_TronRpgGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
