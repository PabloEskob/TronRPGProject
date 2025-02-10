// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AuroraDevs_UGC/Public/Camera/Modifiers/UGC_PlayCameraAnimCallbackProxy.h"
#include "EngineCameras/Public/Animations/CameraAnimationCameraModifier.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUGC_PlayCameraAnimCallbackProxy() {}

// Begin Cross Module References
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_CameraAnimationModifier_NoRegister();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_NoRegister();
AURORADEVS_UGC_API UEnum* Z_Construct_UEnum_AuroraDevs_UGC_ECameraAnimationResetType();
AURORADEVS_UGC_API UFunction* Z_Construct_UDelegateFunction_AuroraDevs_UGC_OnCameraAnimationPlayDelegate__DelegateSignature();
AURORADEVS_UGC_API UScriptStruct* Z_Construct_UScriptStruct_FUGCCameraAnimationParams();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ENGINE_API UClass* Z_Construct_UClass_APlayerCameraManager_NoRegister();
ENGINECAMERAS_API UEnum* Z_Construct_UEnum_EngineCameras_ECameraAnimationEasingType();
ENGINECAMERAS_API UScriptStruct* Z_Construct_UScriptStruct_FCameraAnimationHandle();
TEMPLATESEQUENCE_API UClass* Z_Construct_UClass_UCameraAnimationSequence_NoRegister();
UPackage* Z_Construct_UPackage__Script_AuroraDevs_UGC();
// End Cross Module References

// Begin Delegate FOnCameraAnimationPlayDelegate
struct Z_Construct_UDelegateFunction_AuroraDevs_UGC_OnCameraAnimationPlayDelegate__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_PlayCameraAnimCallbackProxy.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_AuroraDevs_UGC_OnCameraAnimationPlayDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_AuroraDevs_UGC, nullptr, "OnCameraAnimationPlayDelegate__DelegateSignature", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AuroraDevs_UGC_OnCameraAnimationPlayDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_AuroraDevs_UGC_OnCameraAnimationPlayDelegate__DelegateSignature_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UDelegateFunction_AuroraDevs_UGC_OnCameraAnimationPlayDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_AuroraDevs_UGC_OnCameraAnimationPlayDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnCameraAnimationPlayDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnCameraAnimationPlayDelegate)
{
	OnCameraAnimationPlayDelegate.ProcessMulticastDelegate<UObject>(NULL);
}
// End Delegate FOnCameraAnimationPlayDelegate

// Begin ScriptStruct FUGCCameraAnimationParams
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_UGCCameraAnimationParams;
class UScriptStruct* FUGCCameraAnimationParams::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_UGCCameraAnimationParams.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_UGCCameraAnimationParams.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FUGCCameraAnimationParams, (UObject*)Z_Construct_UPackage__Script_AuroraDevs_UGC(), TEXT("UGCCameraAnimationParams"));
	}
	return Z_Registration_Info_UScriptStruct_UGCCameraAnimationParams.OuterSingleton;
}
template<> AURORADEVS_UGC_API UScriptStruct* StaticStruct<FUGCCameraAnimationParams>()
{
	return FUGCCameraAnimationParams::StaticStruct();
}
struct Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Parameter struct for adding new camera animations to UGCCameraAnimationCameraModifier */" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_PlayCameraAnimCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Parameter struct for adding new camera animations to UGCCameraAnimationCameraModifier" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayRate_MetaData[] = {
		{ "Category", "Camera Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Time scale for playing the new camera animation */" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_PlayCameraAnimCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Time scale for playing the new camera animation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EaseInType_MetaData[] = {
		{ "Category", "Camera Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ease-in function type */" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_PlayCameraAnimCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ease-in function type" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EaseInDuration_MetaData[] = {
		{ "Category", "Camera Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ease-in duration in seconds */" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_PlayCameraAnimCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ease-in duration in seconds" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EaseOutType_MetaData[] = {
		{ "Category", "Camera Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ease-out function type */" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_PlayCameraAnimCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ease-out function type" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EaseOutDuration_MetaData[] = {
		{ "Category", "Camera Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ease-out duration in seconds */" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_PlayCameraAnimCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ease-out duration in seconds" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResetType_MetaData[] = {
		{ "Category", "Camera Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How should the camera behave after the animation is over. */" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_PlayCameraAnimCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How should the camera behave after the animation is over." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
	static const UECodeGen_Private::FBytePropertyParams NewProp_EaseInType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_EaseInType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EaseInDuration;
	static const UECodeGen_Private::FBytePropertyParams NewProp_EaseOutType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_EaseOutType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EaseOutDuration;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ResetType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ResetType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FUGCCameraAnimationParams>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FUGCCameraAnimationParams, PlayRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayRate_MetaData), NewProp_PlayRate_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::NewProp_EaseInType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::NewProp_EaseInType = { "EaseInType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FUGCCameraAnimationParams, EaseInType), Z_Construct_UEnum_EngineCameras_ECameraAnimationEasingType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EaseInType_MetaData), NewProp_EaseInType_MetaData) }; // 7658545
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::NewProp_EaseInDuration = { "EaseInDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FUGCCameraAnimationParams, EaseInDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EaseInDuration_MetaData), NewProp_EaseInDuration_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::NewProp_EaseOutType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::NewProp_EaseOutType = { "EaseOutType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FUGCCameraAnimationParams, EaseOutType), Z_Construct_UEnum_EngineCameras_ECameraAnimationEasingType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EaseOutType_MetaData), NewProp_EaseOutType_MetaData) }; // 7658545
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::NewProp_EaseOutDuration = { "EaseOutDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FUGCCameraAnimationParams, EaseOutDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EaseOutDuration_MetaData), NewProp_EaseOutDuration_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::NewProp_ResetType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::NewProp_ResetType = { "ResetType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FUGCCameraAnimationParams, ResetType), Z_Construct_UEnum_AuroraDevs_UGC_ECameraAnimationResetType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResetType_MetaData), NewProp_ResetType_MetaData) }; // 1293159519
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::NewProp_PlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::NewProp_EaseInType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::NewProp_EaseInType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::NewProp_EaseInDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::NewProp_EaseOutType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::NewProp_EaseOutType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::NewProp_EaseOutDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::NewProp_ResetType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::NewProp_ResetType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_AuroraDevs_UGC,
	nullptr,
	&NewStructOps,
	"UGCCameraAnimationParams",
	Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::PropPointers),
	sizeof(FUGCCameraAnimationParams),
	alignof(FUGCCameraAnimationParams),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FUGCCameraAnimationParams()
{
	if (!Z_Registration_Info_UScriptStruct_UGCCameraAnimationParams.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_UGCCameraAnimationParams.InnerSingleton, Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_UGCCameraAnimationParams.InnerSingleton;
}
// End ScriptStruct FUGCCameraAnimationParams

// Begin Class UUGC_PlayCameraAnimCallbackProxy Function CreateProxyObjectForPlayCameraAnim
struct Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics
{
	struct UGC_PlayCameraAnimCallbackProxy_eventCreateProxyObjectForPlayCameraAnim_Parms
	{
		APlayerCameraManager* InPlayerCameraManager;
		TSubclassOf<UUGC_CameraAnimationModifier> ModifierClass;
		UCameraAnimationSequence* CameraSequence;
		FUGCCameraAnimationParams Params;
		FCameraAnimationHandle Handle;
		UUGC_PlayCameraAnimCallbackProxy* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Called to perform the query internally\n" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_PlayCameraAnimCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called to perform the query internally" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InPlayerCameraManager;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ModifierClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraSequence;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Params;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Handle;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::NewProp_InPlayerCameraManager = { "InPlayerCameraManager", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_PlayCameraAnimCallbackProxy_eventCreateProxyObjectForPlayCameraAnim_Parms, InPlayerCameraManager), Z_Construct_UClass_APlayerCameraManager_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::NewProp_ModifierClass = { "ModifierClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_PlayCameraAnimCallbackProxy_eventCreateProxyObjectForPlayCameraAnim_Parms, ModifierClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUGC_CameraAnimationModifier_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::NewProp_CameraSequence = { "CameraSequence", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_PlayCameraAnimCallbackProxy_eventCreateProxyObjectForPlayCameraAnim_Parms, CameraSequence), Z_Construct_UClass_UCameraAnimationSequence_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::NewProp_Params = { "Params", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_PlayCameraAnimCallbackProxy_eventCreateProxyObjectForPlayCameraAnim_Parms, Params), Z_Construct_UScriptStruct_FUGCCameraAnimationParams, METADATA_PARAMS(0, nullptr) }; // 3703111386
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::NewProp_Handle = { "Handle", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_PlayCameraAnimCallbackProxy_eventCreateProxyObjectForPlayCameraAnim_Parms, Handle), Z_Construct_UScriptStruct_FCameraAnimationHandle, METADATA_PARAMS(0, nullptr) }; // 459046527
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_PlayCameraAnimCallbackProxy_eventCreateProxyObjectForPlayCameraAnim_Parms, ReturnValue), Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::NewProp_InPlayerCameraManager,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::NewProp_ModifierClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::NewProp_CameraSequence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::NewProp_Params,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::NewProp_Handle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy, nullptr, "CreateProxyObjectForPlayCameraAnim", nullptr, nullptr, Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::UGC_PlayCameraAnimCallbackProxy_eventCreateProxyObjectForPlayCameraAnim_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::UGC_PlayCameraAnimCallbackProxy_eventCreateProxyObjectForPlayCameraAnim_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_PlayCameraAnimCallbackProxy::execCreateProxyObjectForPlayCameraAnim)
{
	P_GET_OBJECT(APlayerCameraManager,Z_Param_InPlayerCameraManager);
	P_GET_OBJECT(UClass,Z_Param_ModifierClass);
	P_GET_OBJECT(UCameraAnimationSequence,Z_Param_CameraSequence);
	P_GET_STRUCT(FUGCCameraAnimationParams,Z_Param_Params);
	P_GET_STRUCT_REF(FCameraAnimationHandle,Z_Param_Out_Handle);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UUGC_PlayCameraAnimCallbackProxy**)Z_Param__Result=UUGC_PlayCameraAnimCallbackProxy::CreateProxyObjectForPlayCameraAnim(Z_Param_InPlayerCameraManager,Z_Param_ModifierClass,Z_Param_CameraSequence,Z_Param_Params,Z_Param_Out_Handle);
	P_NATIVE_END;
}
// End Class UUGC_PlayCameraAnimCallbackProxy Function CreateProxyObjectForPlayCameraAnim

// Begin Class UUGC_PlayCameraAnimCallbackProxy Function CreateProxyObjectForPlayCameraAnimForModifier
struct Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics
{
	struct UGC_PlayCameraAnimCallbackProxy_eventCreateProxyObjectForPlayCameraAnimForModifier_Parms
	{
		UUGC_CameraAnimationModifier* CameraAnimationModifier;
		UCameraAnimationSequence* CameraSequence;
		FUGCCameraAnimationParams Params;
		FCameraAnimationHandle Handle;
		UUGC_PlayCameraAnimCallbackProxy* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_PlayCameraAnimCallbackProxy.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraAnimationModifier;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraSequence;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Params;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Handle;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::NewProp_CameraAnimationModifier = { "CameraAnimationModifier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_PlayCameraAnimCallbackProxy_eventCreateProxyObjectForPlayCameraAnimForModifier_Parms, CameraAnimationModifier), Z_Construct_UClass_UUGC_CameraAnimationModifier_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::NewProp_CameraSequence = { "CameraSequence", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_PlayCameraAnimCallbackProxy_eventCreateProxyObjectForPlayCameraAnimForModifier_Parms, CameraSequence), Z_Construct_UClass_UCameraAnimationSequence_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::NewProp_Params = { "Params", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_PlayCameraAnimCallbackProxy_eventCreateProxyObjectForPlayCameraAnimForModifier_Parms, Params), Z_Construct_UScriptStruct_FUGCCameraAnimationParams, METADATA_PARAMS(0, nullptr) }; // 3703111386
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::NewProp_Handle = { "Handle", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_PlayCameraAnimCallbackProxy_eventCreateProxyObjectForPlayCameraAnimForModifier_Parms, Handle), Z_Construct_UScriptStruct_FCameraAnimationHandle, METADATA_PARAMS(0, nullptr) }; // 459046527
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_PlayCameraAnimCallbackProxy_eventCreateProxyObjectForPlayCameraAnimForModifier_Parms, ReturnValue), Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::NewProp_CameraAnimationModifier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::NewProp_CameraSequence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::NewProp_Params,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::NewProp_Handle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy, nullptr, "CreateProxyObjectForPlayCameraAnimForModifier", nullptr, nullptr, Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::UGC_PlayCameraAnimCallbackProxy_eventCreateProxyObjectForPlayCameraAnimForModifier_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::UGC_PlayCameraAnimCallbackProxy_eventCreateProxyObjectForPlayCameraAnimForModifier_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_PlayCameraAnimCallbackProxy::execCreateProxyObjectForPlayCameraAnimForModifier)
{
	P_GET_OBJECT(UUGC_CameraAnimationModifier,Z_Param_CameraAnimationModifier);
	P_GET_OBJECT(UCameraAnimationSequence,Z_Param_CameraSequence);
	P_GET_STRUCT(FUGCCameraAnimationParams,Z_Param_Params);
	P_GET_STRUCT_REF(FCameraAnimationHandle,Z_Param_Out_Handle);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UUGC_PlayCameraAnimCallbackProxy**)Z_Param__Result=UUGC_PlayCameraAnimCallbackProxy::CreateProxyObjectForPlayCameraAnimForModifier(Z_Param_CameraAnimationModifier,Z_Param_CameraSequence,Z_Param_Params,Z_Param_Out_Handle);
	P_NATIVE_END;
}
// End Class UUGC_PlayCameraAnimCallbackProxy Function CreateProxyObjectForPlayCameraAnimForModifier

// Begin Class UUGC_PlayCameraAnimCallbackProxy Function OnCameraAnimationEasingOut
struct Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEasingOut_Statics
{
	struct UGC_PlayCameraAnimCallbackProxy_eventOnCameraAnimationEasingOut_Parms
	{
		UCameraAnimationSequence* CameraAnimation;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_PlayCameraAnimCallbackProxy.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraAnimation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEasingOut_Statics::NewProp_CameraAnimation = { "CameraAnimation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_PlayCameraAnimCallbackProxy_eventOnCameraAnimationEasingOut_Parms, CameraAnimation), Z_Construct_UClass_UCameraAnimationSequence_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEasingOut_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEasingOut_Statics::NewProp_CameraAnimation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEasingOut_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEasingOut_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy, nullptr, "OnCameraAnimationEasingOut", nullptr, nullptr, Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEasingOut_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEasingOut_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEasingOut_Statics::UGC_PlayCameraAnimCallbackProxy_eventOnCameraAnimationEasingOut_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEasingOut_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEasingOut_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEasingOut_Statics::UGC_PlayCameraAnimCallbackProxy_eventOnCameraAnimationEasingOut_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEasingOut()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEasingOut_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_PlayCameraAnimCallbackProxy::execOnCameraAnimationEasingOut)
{
	P_GET_OBJECT(UCameraAnimationSequence,Z_Param_CameraAnimation);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnCameraAnimationEasingOut(Z_Param_CameraAnimation);
	P_NATIVE_END;
}
// End Class UUGC_PlayCameraAnimCallbackProxy Function OnCameraAnimationEasingOut

// Begin Class UUGC_PlayCameraAnimCallbackProxy Function OnCameraAnimationEnded
struct Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEnded_Statics
{
	struct UGC_PlayCameraAnimCallbackProxy_eventOnCameraAnimationEnded_Parms
	{
		UCameraAnimationSequence* CameraAnimation;
		bool bInterrupted;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_PlayCameraAnimCallbackProxy.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraAnimation;
	static void NewProp_bInterrupted_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInterrupted;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEnded_Statics::NewProp_CameraAnimation = { "CameraAnimation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_PlayCameraAnimCallbackProxy_eventOnCameraAnimationEnded_Parms, CameraAnimation), Z_Construct_UClass_UCameraAnimationSequence_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEnded_Statics::NewProp_bInterrupted_SetBit(void* Obj)
{
	((UGC_PlayCameraAnimCallbackProxy_eventOnCameraAnimationEnded_Parms*)Obj)->bInterrupted = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEnded_Statics::NewProp_bInterrupted = { "bInterrupted", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGC_PlayCameraAnimCallbackProxy_eventOnCameraAnimationEnded_Parms), &Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEnded_Statics::NewProp_bInterrupted_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEnded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEnded_Statics::NewProp_CameraAnimation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEnded_Statics::NewProp_bInterrupted,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEnded_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEnded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy, nullptr, "OnCameraAnimationEnded", nullptr, nullptr, Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEnded_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEnded_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEnded_Statics::UGC_PlayCameraAnimCallbackProxy_eventOnCameraAnimationEnded_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEnded_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEnded_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEnded_Statics::UGC_PlayCameraAnimCallbackProxy_eventOnCameraAnimationEnded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEnded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEnded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_PlayCameraAnimCallbackProxy::execOnCameraAnimationEnded)
{
	P_GET_OBJECT(UCameraAnimationSequence,Z_Param_CameraAnimation);
	P_GET_UBOOL(Z_Param_bInterrupted);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnCameraAnimationEnded(Z_Param_CameraAnimation,Z_Param_bInterrupted);
	P_NATIVE_END;
}
// End Class UUGC_PlayCameraAnimCallbackProxy Function OnCameraAnimationEnded

// Begin Class UUGC_PlayCameraAnimCallbackProxy
void UUGC_PlayCameraAnimCallbackProxy::StaticRegisterNativesUUGC_PlayCameraAnimCallbackProxy()
{
	UClass* Class = UUGC_PlayCameraAnimCallbackProxy::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CreateProxyObjectForPlayCameraAnim", &UUGC_PlayCameraAnimCallbackProxy::execCreateProxyObjectForPlayCameraAnim },
		{ "CreateProxyObjectForPlayCameraAnimForModifier", &UUGC_PlayCameraAnimCallbackProxy::execCreateProxyObjectForPlayCameraAnimForModifier },
		{ "OnCameraAnimationEasingOut", &UUGC_PlayCameraAnimCallbackProxy::execOnCameraAnimationEasingOut },
		{ "OnCameraAnimationEnded", &UUGC_PlayCameraAnimCallbackProxy::execOnCameraAnimationEnded },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUGC_PlayCameraAnimCallbackProxy);
UClass* Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_NoRegister()
{
	return UUGC_PlayCameraAnimCallbackProxy::StaticClass();
}
struct Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Camera/Modifiers/UGC_PlayCameraAnimCallbackProxy.h" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_PlayCameraAnimCallbackProxy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCompleted_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Called when Camera Animation finished playing and wasn't interrupted\n" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_PlayCameraAnimCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when Camera Animation finished playing and wasn't interrupted" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnEaseOut_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Called when Camera Animation starts blending out and is not interrupted\n" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_PlayCameraAnimCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when Camera Animation starts blending out and is not interrupted" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnInterrupted_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Called when Camera Animation has been interrupted (or failed to play)\n" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_PlayCameraAnimCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when Camera Animation has been interrupted (or failed to play)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCompleted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnEaseOut;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInterrupted;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnim, "CreateProxyObjectForPlayCameraAnim" }, // 3412994975
		{ &Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_CreateProxyObjectForPlayCameraAnimForModifier, "CreateProxyObjectForPlayCameraAnimForModifier" }, // 3009903518
		{ &Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEasingOut, "OnCameraAnimationEasingOut" }, // 3896378685
		{ &Z_Construct_UFunction_UUGC_PlayCameraAnimCallbackProxy_OnCameraAnimationEnded, "OnCameraAnimationEnded" }, // 976499374
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUGC_PlayCameraAnimCallbackProxy>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_Statics::NewProp_OnCompleted = { "OnCompleted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_PlayCameraAnimCallbackProxy, OnCompleted), Z_Construct_UDelegateFunction_AuroraDevs_UGC_OnCameraAnimationPlayDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCompleted_MetaData), NewProp_OnCompleted_MetaData) }; // 2586968896
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_Statics::NewProp_OnEaseOut = { "OnEaseOut", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_PlayCameraAnimCallbackProxy, OnEaseOut), Z_Construct_UDelegateFunction_AuroraDevs_UGC_OnCameraAnimationPlayDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnEaseOut_MetaData), NewProp_OnEaseOut_MetaData) }; // 2586968896
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_Statics::NewProp_OnInterrupted = { "OnInterrupted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_PlayCameraAnimCallbackProxy, OnInterrupted), Z_Construct_UDelegateFunction_AuroraDevs_UGC_OnCameraAnimationPlayDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnInterrupted_MetaData), NewProp_OnInterrupted_MetaData) }; // 2586968896
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_Statics::NewProp_OnCompleted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_Statics::NewProp_OnEaseOut,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_Statics::NewProp_OnInterrupted,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_AuroraDevs_UGC,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_Statics::ClassParams = {
	&UUGC_PlayCameraAnimCallbackProxy::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_Statics::Class_MetaDataParams), Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy()
{
	if (!Z_Registration_Info_UClass_UUGC_PlayCameraAnimCallbackProxy.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUGC_PlayCameraAnimCallbackProxy.OuterSingleton, Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UUGC_PlayCameraAnimCallbackProxy.OuterSingleton;
}
template<> AURORADEVS_UGC_API UClass* StaticClass<UUGC_PlayCameraAnimCallbackProxy>()
{
	return UUGC_PlayCameraAnimCallbackProxy::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UUGC_PlayCameraAnimCallbackProxy);
UUGC_PlayCameraAnimCallbackProxy::~UUGC_PlayCameraAnimCallbackProxy() {}
// End Class UUGC_PlayCameraAnimCallbackProxy

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_PlayCameraAnimCallbackProxy_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FUGCCameraAnimationParams::StaticStruct, Z_Construct_UScriptStruct_FUGCCameraAnimationParams_Statics::NewStructOps, TEXT("UGCCameraAnimationParams"), &Z_Registration_Info_UScriptStruct_UGCCameraAnimationParams, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FUGCCameraAnimationParams), 3703111386U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UUGC_PlayCameraAnimCallbackProxy, UUGC_PlayCameraAnimCallbackProxy::StaticClass, TEXT("UUGC_PlayCameraAnimCallbackProxy"), &Z_Registration_Info_UClass_UUGC_PlayCameraAnimCallbackProxy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUGC_PlayCameraAnimCallbackProxy), 2661257402U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_PlayCameraAnimCallbackProxy_h_4278919198(TEXT("/Script/AuroraDevs_UGC"),
	Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_PlayCameraAnimCallbackProxy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_PlayCameraAnimCallbackProxy_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_PlayCameraAnimCallbackProxy_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_PlayCameraAnimCallbackProxy_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
