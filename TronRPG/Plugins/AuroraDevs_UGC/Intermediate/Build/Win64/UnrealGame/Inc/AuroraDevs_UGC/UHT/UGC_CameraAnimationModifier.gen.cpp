// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AuroraDevs_UGC/Public/Camera/Modifiers/UGC_CameraAnimationModifier.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUGC_CameraAnimationModifier() {}

// Begin Cross Module References
AURORADEVS_UGC_API UClass* Z_Construct_UClass_AUGC_PlayerCameraManager_NoRegister();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_CameraAnimationModifier();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_CameraAnimationModifier_NoRegister();
AURORADEVS_UGC_API UEnum* Z_Construct_UEnum_AuroraDevs_UGC_ECameraAnimationResetType();
GAMEPLAYCAMERAS_API UClass* Z_Construct_UClass_UCameraAnimationCameraModifier();
TEMPLATESEQUENCE_API UClass* Z_Construct_UClass_UCameraAnimationSequence_NoRegister();
UPackage* Z_Construct_UPackage__Script_AuroraDevs_UGC();
// End Cross Module References

// Begin Enum ECameraAnimationResetType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECameraAnimationResetType;
static UEnum* ECameraAnimationResetType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECameraAnimationResetType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECameraAnimationResetType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_AuroraDevs_UGC_ECameraAnimationResetType, (UObject*)Z_Construct_UPackage__Script_AuroraDevs_UGC(), TEXT("ECameraAnimationResetType"));
	}
	return Z_Registration_Info_UEnum_ECameraAnimationResetType.OuterSingleton;
}
template<> AURORADEVS_UGC_API UEnum* StaticEnum<ECameraAnimationResetType>()
{
	return ECameraAnimationResetType_StaticEnum();
}
struct Z_Construct_UEnum_AuroraDevs_UGC_ECameraAnimationResetType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BackToStart.Name", "ECameraAnimationResetType::BackToStart" },
		{ "BackToStart.ToolTip", "The camera will go back to the position it started from." },
		{ "ContinueFromEnd.Name", "ECameraAnimationResetType::ContinueFromEnd" },
		{ "ContinueFromEnd.ToolTip", "The camera will blend out from the last position of the animation." },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraAnimationModifier.h" },
		{ "ResetToZero.Name", "ECameraAnimationResetType::ResetToZero" },
		{ "ResetToZero.ToolTip", "The camera's orientation will be reset to zero. This is usually the back of the character. If UseControllerRotationYaw is true, this is forcefully used." },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECameraAnimationResetType::BackToStart", (int64)ECameraAnimationResetType::BackToStart },
		{ "ECameraAnimationResetType::ResetToZero", (int64)ECameraAnimationResetType::ResetToZero },
		{ "ECameraAnimationResetType::ContinueFromEnd", (int64)ECameraAnimationResetType::ContinueFromEnd },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_AuroraDevs_UGC_ECameraAnimationResetType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_AuroraDevs_UGC,
	nullptr,
	"ECameraAnimationResetType",
	"ECameraAnimationResetType",
	Z_Construct_UEnum_AuroraDevs_UGC_ECameraAnimationResetType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_AuroraDevs_UGC_ECameraAnimationResetType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_AuroraDevs_UGC_ECameraAnimationResetType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_AuroraDevs_UGC_ECameraAnimationResetType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_AuroraDevs_UGC_ECameraAnimationResetType()
{
	if (!Z_Registration_Info_UEnum_ECameraAnimationResetType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECameraAnimationResetType.InnerSingleton, Z_Construct_UEnum_AuroraDevs_UGC_ECameraAnimationResetType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECameraAnimationResetType.InnerSingleton;
}
// End Enum ECameraAnimationResetType

// Begin Class UUGC_CameraAnimationModifier Function GetCurrentCameraAnimation
struct Z_Construct_UFunction_UUGC_CameraAnimationModifier_GetCurrentCameraAnimation_Statics
{
	struct UGC_CameraAnimationModifier_eventGetCurrentCameraAnimation_Parms
	{
		UCameraAnimationSequence* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Modifiers|Camera Animations" },
		{ "Comment", "/**\n     * Get the current camera animation playing on this modifier.\n     * @return      The current camera animation playing.\n     */" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraAnimationModifier.h" },
		{ "ToolTip", "Get the current camera animation playing on this modifier.\n@return      The current camera animation playing." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUGC_CameraAnimationModifier_GetCurrentCameraAnimation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraAnimationModifier_eventGetCurrentCameraAnimation_Parms, ReturnValue), Z_Construct_UClass_UCameraAnimationSequence_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraAnimationModifier_GetCurrentCameraAnimation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraAnimationModifier_GetCurrentCameraAnimation_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraAnimationModifier_GetCurrentCameraAnimation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraAnimationModifier_GetCurrentCameraAnimation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraAnimationModifier, nullptr, "GetCurrentCameraAnimation", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraAnimationModifier_GetCurrentCameraAnimation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraAnimationModifier_GetCurrentCameraAnimation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGC_CameraAnimationModifier_GetCurrentCameraAnimation_Statics::UGC_CameraAnimationModifier_eventGetCurrentCameraAnimation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraAnimationModifier_GetCurrentCameraAnimation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraAnimationModifier_GetCurrentCameraAnimation_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUGC_CameraAnimationModifier_GetCurrentCameraAnimation_Statics::UGC_CameraAnimationModifier_eventGetCurrentCameraAnimation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraAnimationModifier_GetCurrentCameraAnimation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraAnimationModifier_GetCurrentCameraAnimation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraAnimationModifier::execGetCurrentCameraAnimation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UCameraAnimationSequence**)Z_Param__Result=P_THIS->GetCurrentCameraAnimation();
	P_NATIVE_END;
}
// End Class UUGC_CameraAnimationModifier Function GetCurrentCameraAnimation

// Begin Class UUGC_CameraAnimationModifier Function IsAnyCameraAnimationSequence
struct Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsAnyCameraAnimationSequence_Statics
{
	struct UGC_CameraAnimationModifier_eventIsAnyCameraAnimationSequence_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Modifiers|Camera Animations" },
		{ "Comment", "/**\n     * Returns whether any camera animation is playing on this modifier.\n     * @param Sequence      The Camera Animation Sequence.\n     * @return              Whether any camera animation is playing or not.\n     */" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraAnimationModifier.h" },
		{ "ToolTip", "Returns whether any camera animation is playing on this modifier.\n@param Sequence      The Camera Animation Sequence.\n@return              Whether any camera animation is playing or not." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsAnyCameraAnimationSequence_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((UGC_CameraAnimationModifier_eventIsAnyCameraAnimationSequence_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsAnyCameraAnimationSequence_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGC_CameraAnimationModifier_eventIsAnyCameraAnimationSequence_Parms), &Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsAnyCameraAnimationSequence_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsAnyCameraAnimationSequence_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsAnyCameraAnimationSequence_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsAnyCameraAnimationSequence_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsAnyCameraAnimationSequence_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraAnimationModifier, nullptr, "IsAnyCameraAnimationSequence", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsAnyCameraAnimationSequence_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsAnyCameraAnimationSequence_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsAnyCameraAnimationSequence_Statics::UGC_CameraAnimationModifier_eventIsAnyCameraAnimationSequence_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsAnyCameraAnimationSequence_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsAnyCameraAnimationSequence_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsAnyCameraAnimationSequence_Statics::UGC_CameraAnimationModifier_eventIsAnyCameraAnimationSequence_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsAnyCameraAnimationSequence()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsAnyCameraAnimationSequence_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraAnimationModifier::execIsAnyCameraAnimationSequence)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsAnyCameraAnimationSequence();
	P_NATIVE_END;
}
// End Class UUGC_CameraAnimationModifier Function IsAnyCameraAnimationSequence

// Begin Class UUGC_CameraAnimationModifier Function IsCameraAnimationSequenceActive
struct Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsCameraAnimationSequenceActive_Statics
{
	struct UGC_CameraAnimationModifier_eventIsCameraAnimationSequenceActive_Parms
	{
		UCameraAnimationSequence* Sequence;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Modifiers|Camera Animations" },
		{ "Comment", "/**\n     * Returns whether the given camera animation is playing on this modifier.\n     * @param Sequence      The Camera Animation Sequence.\n     * @return              Whether the corresponding camera animation is playing or not.\n     */" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraAnimationModifier.h" },
		{ "ToolTip", "Returns whether the given camera animation is playing on this modifier.\n@param Sequence      The Camera Animation Sequence.\n@return              Whether the corresponding camera animation is playing or not." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Sequence;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsCameraAnimationSequenceActive_Statics::NewProp_Sequence = { "Sequence", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraAnimationModifier_eventIsCameraAnimationSequenceActive_Parms, Sequence), Z_Construct_UClass_UCameraAnimationSequence_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsCameraAnimationSequenceActive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((UGC_CameraAnimationModifier_eventIsCameraAnimationSequenceActive_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsCameraAnimationSequenceActive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGC_CameraAnimationModifier_eventIsCameraAnimationSequenceActive_Parms), &Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsCameraAnimationSequenceActive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsCameraAnimationSequenceActive_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsCameraAnimationSequenceActive_Statics::NewProp_Sequence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsCameraAnimationSequenceActive_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsCameraAnimationSequenceActive_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsCameraAnimationSequenceActive_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraAnimationModifier, nullptr, "IsCameraAnimationSequenceActive", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsCameraAnimationSequenceActive_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsCameraAnimationSequenceActive_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsCameraAnimationSequenceActive_Statics::UGC_CameraAnimationModifier_eventIsCameraAnimationSequenceActive_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsCameraAnimationSequenceActive_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsCameraAnimationSequenceActive_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsCameraAnimationSequenceActive_Statics::UGC_CameraAnimationModifier_eventIsCameraAnimationSequenceActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsCameraAnimationSequenceActive()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsCameraAnimationSequenceActive_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraAnimationModifier::execIsCameraAnimationSequenceActive)
{
	P_GET_OBJECT(UCameraAnimationSequence,Z_Param_Sequence);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsCameraAnimationSequenceActive(Z_Param_Sequence);
	P_NATIVE_END;
}
// End Class UUGC_CameraAnimationModifier Function IsCameraAnimationSequenceActive

// Begin Class UUGC_CameraAnimationModifier Function StopCameraAnimationSequence
struct Z_Construct_UFunction_UUGC_CameraAnimationModifier_StopCameraAnimationSequence_Statics
{
	struct UGC_CameraAnimationModifier_eventStopCameraAnimationSequence_Parms
	{
		UCameraAnimationSequence* Sequence;
		bool bImmediate;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Modifiers|Camera Animation" },
		{ "Comment", "/**\n     * Stops the given camera animation sequence. If nullptr, will stop whatever is currently active.\n     * @param Sequence        The camera sequence animation.\n     * @param bImmediate\x09True to stop it right now and ignore blend out, false to let it blend out as indicated.\n     */" },
		{ "CPP_Default_bImmediate", "false" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraAnimationModifier.h" },
		{ "ToolTip", "Stops the given camera animation sequence. If nullptr, will stop whatever is currently active.\n@param Sequence        The camera sequence animation.\n@param bImmediate       True to stop it right now and ignore blend out, false to let it blend out as indicated." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Sequence;
	static void NewProp_bImmediate_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bImmediate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUGC_CameraAnimationModifier_StopCameraAnimationSequence_Statics::NewProp_Sequence = { "Sequence", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraAnimationModifier_eventStopCameraAnimationSequence_Parms, Sequence), Z_Construct_UClass_UCameraAnimationSequence_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UUGC_CameraAnimationModifier_StopCameraAnimationSequence_Statics::NewProp_bImmediate_SetBit(void* Obj)
{
	((UGC_CameraAnimationModifier_eventStopCameraAnimationSequence_Parms*)Obj)->bImmediate = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUGC_CameraAnimationModifier_StopCameraAnimationSequence_Statics::NewProp_bImmediate = { "bImmediate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGC_CameraAnimationModifier_eventStopCameraAnimationSequence_Parms), &Z_Construct_UFunction_UUGC_CameraAnimationModifier_StopCameraAnimationSequence_Statics::NewProp_bImmediate_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraAnimationModifier_StopCameraAnimationSequence_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraAnimationModifier_StopCameraAnimationSequence_Statics::NewProp_Sequence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraAnimationModifier_StopCameraAnimationSequence_Statics::NewProp_bImmediate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraAnimationModifier_StopCameraAnimationSequence_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraAnimationModifier_StopCameraAnimationSequence_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraAnimationModifier, nullptr, "StopCameraAnimationSequence", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraAnimationModifier_StopCameraAnimationSequence_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraAnimationModifier_StopCameraAnimationSequence_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGC_CameraAnimationModifier_StopCameraAnimationSequence_Statics::UGC_CameraAnimationModifier_eventStopCameraAnimationSequence_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraAnimationModifier_StopCameraAnimationSequence_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraAnimationModifier_StopCameraAnimationSequence_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUGC_CameraAnimationModifier_StopCameraAnimationSequence_Statics::UGC_CameraAnimationModifier_eventStopCameraAnimationSequence_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraAnimationModifier_StopCameraAnimationSequence()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraAnimationModifier_StopCameraAnimationSequence_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraAnimationModifier::execStopCameraAnimationSequence)
{
	P_GET_OBJECT(UCameraAnimationSequence,Z_Param_Sequence);
	P_GET_UBOOL(Z_Param_bImmediate);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopCameraAnimationSequence(Z_Param_Sequence,Z_Param_bImmediate);
	P_NATIVE_END;
}
// End Class UUGC_CameraAnimationModifier Function StopCameraAnimationSequence

// Begin Class UUGC_CameraAnimationModifier
void UUGC_CameraAnimationModifier::StaticRegisterNativesUUGC_CameraAnimationModifier()
{
	UClass* Class = UUGC_CameraAnimationModifier::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetCurrentCameraAnimation", &UUGC_CameraAnimationModifier::execGetCurrentCameraAnimation },
		{ "IsAnyCameraAnimationSequence", &UUGC_CameraAnimationModifier::execIsAnyCameraAnimationSequence },
		{ "IsCameraAnimationSequenceActive", &UUGC_CameraAnimationModifier::execIsCameraAnimationSequenceActive },
		{ "StopCameraAnimationSequence", &UUGC_CameraAnimationModifier::execStopCameraAnimationSequence },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUGC_CameraAnimationModifier);
UClass* Z_Construct_UClass_UUGC_CameraAnimationModifier_NoRegister()
{
	return UUGC_CameraAnimationModifier::StaticClass();
}
struct Z_Construct_UClass_UUGC_CameraAnimationModifier_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ClassGroupNames", "UGC Camera Modifiers" },
		{ "Comment", "/**\n * Gameplay Camera Animation Modifier which plays in the correct transform space in rgeards to the owning player.\n */" },
		{ "IncludePath", "Camera/Modifiers/UGC_CameraAnimationModifier.h" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraAnimationModifier.h" },
		{ "ToolTip", "Gameplay Camera Animation Modifier which plays in the correct transform space in rgeards to the owning player." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UGCCameraManager_MetaData[] = {
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraAnimationModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentResetType_MetaData[] = {
		{ "Comment", "/** How should the camera behave after the current animation is over. */" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraAnimationModifier.h" },
		{ "ToolTip", "How should the camera behave after the current animation is over." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UGCCameraManager;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentResetType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentResetType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UUGC_CameraAnimationModifier_GetCurrentCameraAnimation, "GetCurrentCameraAnimation" }, // 991614767
		{ &Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsAnyCameraAnimationSequence, "IsAnyCameraAnimationSequence" }, // 2769607818
		{ &Z_Construct_UFunction_UUGC_CameraAnimationModifier_IsCameraAnimationSequenceActive, "IsCameraAnimationSequenceActive" }, // 1271251301
		{ &Z_Construct_UFunction_UUGC_CameraAnimationModifier_StopCameraAnimationSequence, "StopCameraAnimationSequence" }, // 3234903084
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUGC_CameraAnimationModifier>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUGC_CameraAnimationModifier_Statics::NewProp_UGCCameraManager = { "UGCCameraManager", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraAnimationModifier, UGCCameraManager), Z_Construct_UClass_AUGC_PlayerCameraManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UGCCameraManager_MetaData), NewProp_UGCCameraManager_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UUGC_CameraAnimationModifier_Statics::NewProp_CurrentResetType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UUGC_CameraAnimationModifier_Statics::NewProp_CurrentResetType = { "CurrentResetType", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraAnimationModifier, CurrentResetType), Z_Construct_UEnum_AuroraDevs_UGC_ECameraAnimationResetType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentResetType_MetaData), NewProp_CurrentResetType_MetaData) }; // 1293159519
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUGC_CameraAnimationModifier_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraAnimationModifier_Statics::NewProp_UGCCameraManager,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraAnimationModifier_Statics::NewProp_CurrentResetType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraAnimationModifier_Statics::NewProp_CurrentResetType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraAnimationModifier_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UUGC_CameraAnimationModifier_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCameraAnimationCameraModifier,
	(UObject* (*)())Z_Construct_UPackage__Script_AuroraDevs_UGC,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraAnimationModifier_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UUGC_CameraAnimationModifier_Statics::ClassParams = {
	&UUGC_CameraAnimationModifier::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UUGC_CameraAnimationModifier_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraAnimationModifier_Statics::PropPointers),
	0,
	0x001000A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraAnimationModifier_Statics::Class_MetaDataParams), Z_Construct_UClass_UUGC_CameraAnimationModifier_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UUGC_CameraAnimationModifier()
{
	if (!Z_Registration_Info_UClass_UUGC_CameraAnimationModifier.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUGC_CameraAnimationModifier.OuterSingleton, Z_Construct_UClass_UUGC_CameraAnimationModifier_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UUGC_CameraAnimationModifier.OuterSingleton;
}
template<> AURORADEVS_UGC_API UClass* StaticClass<UUGC_CameraAnimationModifier>()
{
	return UUGC_CameraAnimationModifier::StaticClass();
}
UUGC_CameraAnimationModifier::UUGC_CameraAnimationModifier(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UUGC_CameraAnimationModifier);
UUGC_CameraAnimationModifier::~UUGC_CameraAnimationModifier() {}
// End Class UUGC_CameraAnimationModifier

// Begin Registration
struct Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraAnimationModifier_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ECameraAnimationResetType_StaticEnum, TEXT("ECameraAnimationResetType"), &Z_Registration_Info_UEnum_ECameraAnimationResetType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1293159519U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UUGC_CameraAnimationModifier, UUGC_CameraAnimationModifier::StaticClass, TEXT("UUGC_CameraAnimationModifier"), &Z_Registration_Info_UClass_UUGC_CameraAnimationModifier, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUGC_CameraAnimationModifier), 4086228031U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraAnimationModifier_h_3423632398(TEXT("/Script/AuroraDevs_UGC"),
	Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraAnimationModifier_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraAnimationModifier_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraAnimationModifier_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraAnimationModifier_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
