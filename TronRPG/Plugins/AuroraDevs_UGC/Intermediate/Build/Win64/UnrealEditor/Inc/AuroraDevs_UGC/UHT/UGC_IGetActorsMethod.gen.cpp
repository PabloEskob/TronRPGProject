// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AuroraDevs_UGC/Public/Camera/Methods/UGC_IGetActorsMethod.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUGC_IGetActorsMethod() {}

// Begin Cross Module References
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_IGetActorsMethod();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_IGetActorsMethod_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_AuroraDevs_UGC();
// End Cross Module References

// Begin Class UUGC_IGetActorsMethod Function GetActors
struct UGC_IGetActorsMethod_eventGetActors_Parms
{
	AActor* InOwner;
	FVector OwnerLocation;
	FVector ViewPointLocation;
	FRotator ViewPointRotation;
	TArray<AActor*> OutActors;
};
static const FName NAME_UUGC_IGetActorsMethod_GetActors = FName(TEXT("GetActors"));
void UUGC_IGetActorsMethod::GetActors(AActor* InOwner, FVector OwnerLocation, FVector ViewPointLocation, FRotator ViewPointRotation, TArray<AActor*>& OutActors)
{
	UFunction* Func = FindFunctionChecked(NAME_UUGC_IGetActorsMethod_GetActors);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		UGC_IGetActorsMethod_eventGetActors_Parms Parms;
		Parms.InOwner=InOwner;
		Parms.OwnerLocation=OwnerLocation;
		Parms.ViewPointLocation=ViewPointLocation;
		Parms.ViewPointRotation=ViewPointRotation;
		Parms.OutActors=OutActors;
	ProcessEvent(Func,&Parms);
		OutActors=Parms.OutActors;
	}
	else
	{
		GetActors_Implementation(InOwner, OwnerLocation, ViewPointLocation, ViewPointRotation, OutActors);
	}
}
struct Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Methods" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n     * Get the all actors relevant for this method.\n     * @param   Owner               The owner of the camera.\n     * @param   OwnerLocation       The world location of the owner of camera.\n     * @param   ViewPointLocation   Camera's location.\n     * @param   ViewPointRotation   Camera's rotation.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Methods/UGC_IGetActorsMethod.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Get the all actors relevant for this method.\n* @param   Owner               The owner of the camera.\n* @param   OwnerLocation       The world location of the owner of camera.\n* @param   ViewPointLocation   Camera's location.\n* @param   ViewPointRotation   Camera's rotation." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InOwner;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OwnerLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ViewPointLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ViewPointRotation;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OutActors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutActors;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::NewProp_InOwner = { "InOwner", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_IGetActorsMethod_eventGetActors_Parms, InOwner), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::NewProp_OwnerLocation = { "OwnerLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_IGetActorsMethod_eventGetActors_Parms, OwnerLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::NewProp_ViewPointLocation = { "ViewPointLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_IGetActorsMethod_eventGetActors_Parms, ViewPointLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::NewProp_ViewPointRotation = { "ViewPointRotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_IGetActorsMethod_eventGetActors_Parms, ViewPointRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::NewProp_OutActors_Inner = { "OutActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::NewProp_OutActors = { "OutActors", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_IGetActorsMethod_eventGetActors_Parms, OutActors), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::NewProp_InOwner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::NewProp_OwnerLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::NewProp_ViewPointLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::NewProp_ViewPointRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::NewProp_OutActors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::NewProp_OutActors,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_IGetActorsMethod, nullptr, "GetActors", nullptr, nullptr, Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::PropPointers), sizeof(UGC_IGetActorsMethod_eventGetActors_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0CC20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::Function_MetaDataParams) };
static_assert(sizeof(UGC_IGetActorsMethod_eventGetActors_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_IGetActorsMethod::execGetActors)
{
	P_GET_OBJECT(AActor,Z_Param_InOwner);
	P_GET_STRUCT(FVector,Z_Param_OwnerLocation);
	P_GET_STRUCT(FVector,Z_Param_ViewPointLocation);
	P_GET_STRUCT(FRotator,Z_Param_ViewPointRotation);
	P_GET_TARRAY_REF(AActor*,Z_Param_Out_OutActors);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GetActors_Implementation(Z_Param_InOwner,Z_Param_OwnerLocation,Z_Param_ViewPointLocation,Z_Param_ViewPointRotation,Z_Param_Out_OutActors);
	P_NATIVE_END;
}
// End Class UUGC_IGetActorsMethod Function GetActors

// Begin Class UUGC_IGetActorsMethod
void UUGC_IGetActorsMethod::StaticRegisterNativesUUGC_IGetActorsMethod()
{
	UClass* Class = UUGC_IGetActorsMethod::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetActors", &UUGC_IGetActorsMethod::execGetActors },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUGC_IGetActorsMethod);
UClass* Z_Construct_UClass_UUGC_IGetActorsMethod_NoRegister()
{
	return UUGC_IGetActorsMethod::StaticClass();
}
struct Z_Construct_UClass_UUGC_IGetActorsMethod_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "UGC|Methods" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Function which retrieves a vector of actors. (Uses the Strategy Design Pattern)\n */" },
#endif
		{ "IncludePath", "Camera/Methods/UGC_IGetActorsMethod.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Camera/Methods/UGC_IGetActorsMethod.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Function which retrieves a vector of actors. (Uses the Strategy Design Pattern)" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UUGC_IGetActorsMethod_GetActors, "GetActors" }, // 2308838148
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUGC_IGetActorsMethod>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UUGC_IGetActorsMethod_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_AuroraDevs_UGC,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_IGetActorsMethod_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UUGC_IGetActorsMethod_Statics::ClassParams = {
	&UUGC_IGetActorsMethod::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_IGetActorsMethod_Statics::Class_MetaDataParams), Z_Construct_UClass_UUGC_IGetActorsMethod_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UUGC_IGetActorsMethod()
{
	if (!Z_Registration_Info_UClass_UUGC_IGetActorsMethod.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUGC_IGetActorsMethod.OuterSingleton, Z_Construct_UClass_UUGC_IGetActorsMethod_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UUGC_IGetActorsMethod.OuterSingleton;
}
template<> AURORADEVS_UGC_API UClass* StaticClass<UUGC_IGetActorsMethod>()
{
	return UUGC_IGetActorsMethod::StaticClass();
}
UUGC_IGetActorsMethod::UUGC_IGetActorsMethod(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UUGC_IGetActorsMethod);
UUGC_IGetActorsMethod::~UUGC_IGetActorsMethod() {}
// End Class UUGC_IGetActorsMethod

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Methods_UGC_IGetActorsMethod_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UUGC_IGetActorsMethod, UUGC_IGetActorsMethod::StaticClass, TEXT("UUGC_IGetActorsMethod"), &Z_Registration_Info_UClass_UUGC_IGetActorsMethod, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUGC_IGetActorsMethod), 1479902758U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Methods_UGC_IGetActorsMethod_h_3966420318(TEXT("/Script/AuroraDevs_UGC"),
	Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Methods_UGC_IGetActorsMethod_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Methods_UGC_IGetActorsMethod_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
