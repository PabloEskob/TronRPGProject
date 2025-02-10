// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AuroraDevs_UGC/Public/Camera/Methods/UGC_IFocusTargetMethod.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUGC_IFocusTargetMethod() {}

// Begin Cross Module References
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_IFocusTargetMethod();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_IFocusTargetMethod_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_AuroraDevs_UGC();
// End Cross Module References

// Begin Class UUGC_IFocusTargetMethod Function GetTargetLocation
struct UGC_IFocusTargetMethod_eventGetTargetLocation_Parms
{
	AActor* InOwner;
	FVector OwnerLocation;
	FVector ViewPointLocation;
	FRotator ViewPointRotation;
	FVector OutTargetLocation;
	AActor* ReturnValue;

	/** Constructor, initializes return property only **/
	UGC_IFocusTargetMethod_eventGetTargetLocation_Parms()
		: ReturnValue(NULL)
	{
	}
};
static FName NAME_UUGC_IFocusTargetMethod_GetTargetLocation = FName(TEXT("GetTargetLocation"));
AActor* UUGC_IFocusTargetMethod::GetTargetLocation(AActor* InOwner, FVector OwnerLocation, FVector ViewPointLocation, FRotator ViewPointRotation, FVector& OutTargetLocation)
{
	UGC_IFocusTargetMethod_eventGetTargetLocation_Parms Parms;
	Parms.InOwner=InOwner;
	Parms.OwnerLocation=OwnerLocation;
	Parms.ViewPointLocation=ViewPointLocation;
	Parms.ViewPointRotation=ViewPointRotation;
	Parms.OutTargetLocation=OutTargetLocation;
	ProcessEvent(FindFunctionChecked(NAME_UUGC_IFocusTargetMethod_GetTargetLocation),&Parms);
	OutTargetLocation=Parms.OutTargetLocation;
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Methods" },
		{ "Comment", "/*\n     * Get the location of the target we want the camera to look at.\n     * @param   Owner               The owner of the camera.\n     * @param   OwnerLocation       The world location of the owner of camera.\n     * @param   ViewPointLocation   Camera's location.\n     * @param   ViewPointRotation   Camera's rotation.\n     */" },
		{ "ModuleRelativePath", "Public/Camera/Methods/UGC_IFocusTargetMethod.h" },
		{ "ToolTip", "* Get the location of the target we want the camera to look at.\n* @param   Owner               The owner of the camera.\n* @param   OwnerLocation       The world location of the owner of camera.\n* @param   ViewPointLocation   Camera's location.\n* @param   ViewPointRotation   Camera's rotation." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InOwner;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OwnerLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ViewPointLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ViewPointRotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutTargetLocation;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::NewProp_InOwner = { "InOwner", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_IFocusTargetMethod_eventGetTargetLocation_Parms, InOwner), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::NewProp_OwnerLocation = { "OwnerLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_IFocusTargetMethod_eventGetTargetLocation_Parms, OwnerLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::NewProp_ViewPointLocation = { "ViewPointLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_IFocusTargetMethod_eventGetTargetLocation_Parms, ViewPointLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::NewProp_ViewPointRotation = { "ViewPointRotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_IFocusTargetMethod_eventGetTargetLocation_Parms, ViewPointRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::NewProp_OutTargetLocation = { "OutTargetLocation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_IFocusTargetMethod_eventGetTargetLocation_Parms, OutTargetLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_IFocusTargetMethod_eventGetTargetLocation_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::NewProp_InOwner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::NewProp_OwnerLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::NewProp_ViewPointLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::NewProp_ViewPointRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::NewProp_OutTargetLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_IFocusTargetMethod, nullptr, "GetTargetLocation", nullptr, nullptr, Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::PropPointers), sizeof(UGC_IFocusTargetMethod_eventGetTargetLocation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0CC20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::Function_MetaDataParams) };
static_assert(sizeof(UGC_IFocusTargetMethod_eventGetTargetLocation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_IFocusTargetMethod::execGetTargetLocation)
{
	P_GET_OBJECT(AActor,Z_Param_InOwner);
	P_GET_STRUCT(FVector,Z_Param_OwnerLocation);
	P_GET_STRUCT(FVector,Z_Param_ViewPointLocation);
	P_GET_STRUCT(FRotator,Z_Param_ViewPointRotation);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_OutTargetLocation);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetTargetLocation_Implementation(Z_Param_InOwner,Z_Param_OwnerLocation,Z_Param_ViewPointLocation,Z_Param_ViewPointRotation,Z_Param_Out_OutTargetLocation);
	P_NATIVE_END;
}
// End Class UUGC_IFocusTargetMethod Function GetTargetLocation

// Begin Class UUGC_IFocusTargetMethod
void UUGC_IFocusTargetMethod::StaticRegisterNativesUUGC_IFocusTargetMethod()
{
	UClass* Class = UUGC_IFocusTargetMethod::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetTargetLocation", &UUGC_IFocusTargetMethod::execGetTargetLocation },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUGC_IFocusTargetMethod);
UClass* Z_Construct_UClass_UUGC_IFocusTargetMethod_NoRegister()
{
	return UUGC_IFocusTargetMethod::StaticClass();
}
struct Z_Construct_UClass_UUGC_IFocusTargetMethod_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "UGC|Methods" },
		{ "Comment", "/**\n * Function which retrieves the target we want the camera to look at. (Uses the Strategy Design Pattern)\n */" },
		{ "IncludePath", "Camera/Methods/UGC_IFocusTargetMethod.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Camera/Methods/UGC_IFocusTargetMethod.h" },
		{ "ToolTip", "Function which retrieves the target we want the camera to look at. (Uses the Strategy Design Pattern)" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UUGC_IFocusTargetMethod_GetTargetLocation, "GetTargetLocation" }, // 2035881639
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUGC_IFocusTargetMethod>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UUGC_IFocusTargetMethod_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_AuroraDevs_UGC,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_IFocusTargetMethod_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UUGC_IFocusTargetMethod_Statics::ClassParams = {
	&UUGC_IFocusTargetMethod::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_IFocusTargetMethod_Statics::Class_MetaDataParams), Z_Construct_UClass_UUGC_IFocusTargetMethod_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UUGC_IFocusTargetMethod()
{
	if (!Z_Registration_Info_UClass_UUGC_IFocusTargetMethod.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUGC_IFocusTargetMethod.OuterSingleton, Z_Construct_UClass_UUGC_IFocusTargetMethod_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UUGC_IFocusTargetMethod.OuterSingleton;
}
template<> AURORADEVS_UGC_API UClass* StaticClass<UUGC_IFocusTargetMethod>()
{
	return UUGC_IFocusTargetMethod::StaticClass();
}
UUGC_IFocusTargetMethod::UUGC_IFocusTargetMethod(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UUGC_IFocusTargetMethod);
UUGC_IFocusTargetMethod::~UUGC_IFocusTargetMethod() {}
// End Class UUGC_IFocusTargetMethod

// Begin Registration
struct Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Methods_UGC_IFocusTargetMethod_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UUGC_IFocusTargetMethod, UUGC_IFocusTargetMethod::StaticClass, TEXT("UUGC_IFocusTargetMethod"), &Z_Registration_Info_UClass_UUGC_IFocusTargetMethod, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUGC_IFocusTargetMethod), 787194859U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Methods_UGC_IFocusTargetMethod_h_1322466571(TEXT("/Script/AuroraDevs_UGC"),
	Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Methods_UGC_IFocusTargetMethod_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Methods_UGC_IFocusTargetMethod_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
