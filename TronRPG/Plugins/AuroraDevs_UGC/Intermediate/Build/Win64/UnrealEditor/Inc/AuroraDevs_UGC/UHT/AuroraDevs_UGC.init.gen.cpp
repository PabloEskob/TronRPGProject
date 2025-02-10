// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAuroraDevs_UGC_init() {}
	AURORADEVS_UGC_API UFunction* Z_Construct_UDelegateFunction_AuroraDevs_UGC_OnCameraAnimationPlayDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_AuroraDevs_UGC;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_AuroraDevs_UGC()
	{
		if (!Z_Registration_Info_UPackage__Script_AuroraDevs_UGC.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_AuroraDevs_UGC_OnCameraAnimationPlayDelegate__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/AuroraDevs_UGC",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x180DA0E1,
				0x60A82B82,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_AuroraDevs_UGC.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_AuroraDevs_UGC.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_AuroraDevs_UGC(Z_Construct_UPackage__Script_AuroraDevs_UGC, TEXT("/Script/AuroraDevs_UGC"), Z_Registration_Info_UPackage__Script_AuroraDevs_UGC, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x180DA0E1, 0x60A82B82));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
