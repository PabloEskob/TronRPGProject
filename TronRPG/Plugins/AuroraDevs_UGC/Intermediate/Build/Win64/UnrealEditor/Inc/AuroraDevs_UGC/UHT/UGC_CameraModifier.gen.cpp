// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AuroraDevs_UGC/Public/Camera/Modifiers/UGC_CameraModifier.h"
#include "Runtime/Engine/Classes/Camera/CameraTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUGC_CameraModifier() {}

// Begin Cross Module References
AURORADEVS_UGC_API UClass* Z_Construct_UClass_AUGC_PlayerCameraManager_NoRegister();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_CameraAddOnModifier();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_CameraAddOnModifier_NoRegister();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_CameraAddOnModifierSettings_NoRegister();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_CameraModifier();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_CameraModifier_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCameraModifier();
ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FMinimalViewInfo();
UPackage* Z_Construct_UPackage__Script_AuroraDevs_UGC();
// End Cross Module References

// Begin Class UUGC_CameraModifier Function ComputeOwnerFloorDistance
struct Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics
{
	struct UGC_CameraModifier_eventComputeOwnerFloorDistance_Parms
	{
		float SweepDistance;
		float CapsuleRadius;
		bool bOutFloorExists;
		float OutFloorDistance;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier|Movement" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SweepDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CapsuleRadius;
	static void NewProp_bOutFloorExists_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOutFloorExists;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutFloorDistance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::NewProp_SweepDistance = { "SweepDistance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventComputeOwnerFloorDistance_Parms, SweepDistance), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::NewProp_CapsuleRadius = { "CapsuleRadius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventComputeOwnerFloorDistance_Parms, CapsuleRadius), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::NewProp_bOutFloorExists_SetBit(void* Obj)
{
	((UGC_CameraModifier_eventComputeOwnerFloorDistance_Parms*)Obj)->bOutFloorExists = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::NewProp_bOutFloorExists = { "bOutFloorExists", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGC_CameraModifier_eventComputeOwnerFloorDistance_Parms), &Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::NewProp_bOutFloorExists_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::NewProp_OutFloorDistance = { "OutFloorDistance", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventComputeOwnerFloorDistance_Parms, OutFloorDistance), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::NewProp_SweepDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::NewProp_CapsuleRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::NewProp_bOutFloorExists,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::NewProp_OutFloorDistance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "ComputeOwnerFloorDistance", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::UGC_CameraModifier_eventComputeOwnerFloorDistance_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::UGC_CameraModifier_eventComputeOwnerFloorDistance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execComputeOwnerFloorDistance)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_SweepDistance);
	P_GET_PROPERTY(FFloatProperty,Z_Param_CapsuleRadius);
	P_GET_UBOOL_REF(Z_Param_Out_bOutFloorExists);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OutFloorDistance);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ComputeOwnerFloorDistance(Z_Param_SweepDistance,Z_Param_CapsuleRadius,Z_Param_Out_bOutFloorExists,Z_Param_Out_OutFloorDistance);
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function ComputeOwnerFloorDistance

// Begin Class UUGC_CameraModifier Function ComputeOwnerFloorNormal
struct Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics
{
	struct UGC_CameraModifier_eventComputeOwnerFloorNormal_Parms
	{
		float SweepDistance;
		float CapsuleRadius;
		bool bOutFloorExists;
		FVector OutFloorNormal;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier|Movement" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SweepDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CapsuleRadius;
	static void NewProp_bOutFloorExists_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOutFloorExists;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutFloorNormal;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::NewProp_SweepDistance = { "SweepDistance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventComputeOwnerFloorNormal_Parms, SweepDistance), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::NewProp_CapsuleRadius = { "CapsuleRadius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventComputeOwnerFloorNormal_Parms, CapsuleRadius), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::NewProp_bOutFloorExists_SetBit(void* Obj)
{
	((UGC_CameraModifier_eventComputeOwnerFloorNormal_Parms*)Obj)->bOutFloorExists = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::NewProp_bOutFloorExists = { "bOutFloorExists", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGC_CameraModifier_eventComputeOwnerFloorNormal_Parms), &Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::NewProp_bOutFloorExists_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::NewProp_OutFloorNormal = { "OutFloorNormal", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventComputeOwnerFloorNormal_Parms, OutFloorNormal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::NewProp_SweepDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::NewProp_CapsuleRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::NewProp_bOutFloorExists,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::NewProp_OutFloorNormal,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "ComputeOwnerFloorNormal", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::UGC_CameraModifier_eventComputeOwnerFloorNormal_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::UGC_CameraModifier_eventComputeOwnerFloorNormal_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execComputeOwnerFloorNormal)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_SweepDistance);
	P_GET_PROPERTY(FFloatProperty,Z_Param_CapsuleRadius);
	P_GET_UBOOL_REF(Z_Param_Out_bOutFloorExists);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_OutFloorNormal);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ComputeOwnerFloorNormal(Z_Param_SweepDistance,Z_Param_CapsuleRadius,Z_Param_Out_bOutFloorExists,Z_Param_Out_OutFloorNormal);
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function ComputeOwnerFloorNormal

// Begin Class UUGC_CameraModifier Function ComputeOwnerLookAndMovementDot
struct Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerLookAndMovementDot_Statics
{
	struct UGC_CameraModifier_eventComputeOwnerLookAndMovementDot_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier|Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n     * Returns value betwen 1 (the character is looking where they're moving) or -1 (looking in the opposite direction they're moving).\n     * Will return 0 if the character isn't moving.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Returns value betwen 1 (the character is looking where they're moving) or -1 (looking in the opposite direction they're moving).\n* Will return 0 if the character isn't moving." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerLookAndMovementDot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventComputeOwnerLookAndMovementDot_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerLookAndMovementDot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerLookAndMovementDot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerLookAndMovementDot_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerLookAndMovementDot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "ComputeOwnerLookAndMovementDot", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerLookAndMovementDot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerLookAndMovementDot_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerLookAndMovementDot_Statics::UGC_CameraModifier_eventComputeOwnerLookAndMovementDot_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerLookAndMovementDot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerLookAndMovementDot_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerLookAndMovementDot_Statics::UGC_CameraModifier_eventComputeOwnerLookAndMovementDot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerLookAndMovementDot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerLookAndMovementDot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execComputeOwnerLookAndMovementDot)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->ComputeOwnerLookAndMovementDot();
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function ComputeOwnerLookAndMovementDot

// Begin Class UUGC_CameraModifier Function ComputeOwnerSlopeAngle
struct Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerSlopeAngle_Statics
{
	struct UGC_CameraModifier_eventComputeOwnerSlopeAngle_Parms
	{
		float OutSlopePitchDegrees;
		float OutSlopeRollDegrees;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier|Movement" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutSlopePitchDegrees;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutSlopeRollDegrees;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerSlopeAngle_Statics::NewProp_OutSlopePitchDegrees = { "OutSlopePitchDegrees", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventComputeOwnerSlopeAngle_Parms, OutSlopePitchDegrees), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerSlopeAngle_Statics::NewProp_OutSlopeRollDegrees = { "OutSlopeRollDegrees", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventComputeOwnerSlopeAngle_Parms, OutSlopeRollDegrees), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerSlopeAngle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerSlopeAngle_Statics::NewProp_OutSlopePitchDegrees,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerSlopeAngle_Statics::NewProp_OutSlopeRollDegrees,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerSlopeAngle_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerSlopeAngle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "ComputeOwnerSlopeAngle", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerSlopeAngle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerSlopeAngle_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerSlopeAngle_Statics::UGC_CameraModifier_eventComputeOwnerSlopeAngle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerSlopeAngle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerSlopeAngle_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerSlopeAngle_Statics::UGC_CameraModifier_eventComputeOwnerSlopeAngle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerSlopeAngle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerSlopeAngle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execComputeOwnerSlopeAngle)
{
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OutSlopePitchDegrees);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OutSlopeRollDegrees);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ComputeOwnerSlopeAngle(Z_Param_Out_OutSlopePitchDegrees,Z_Param_Out_OutSlopeRollDegrees);
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function ComputeOwnerSlopeAngle

// Begin Class UUGC_CameraModifier Function GetOwnerVelocity
struct Z_Construct_UFunction_UUGC_CameraModifier_GetOwnerVelocity_Statics
{
	struct UGC_CameraModifier_eventGetOwnerVelocity_Parms
	{
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier|Movement" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_GetOwnerVelocity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventGetOwnerVelocity_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraModifier_GetOwnerVelocity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_GetOwnerVelocity_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_GetOwnerVelocity_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_GetOwnerVelocity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "GetOwnerVelocity", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraModifier_GetOwnerVelocity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_GetOwnerVelocity_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGC_CameraModifier_GetOwnerVelocity_Statics::UGC_CameraModifier_eventGetOwnerVelocity_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_GetOwnerVelocity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_GetOwnerVelocity_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUGC_CameraModifier_GetOwnerVelocity_Statics::UGC_CameraModifier_eventGetOwnerVelocity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_GetOwnerVelocity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_GetOwnerVelocity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execGetOwnerVelocity)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->GetOwnerVelocity();
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function GetOwnerVelocity

// Begin Class UUGC_CameraModifier Function IsDebugEnabled
struct Z_Construct_UFunction_UUGC_CameraModifier_IsDebugEnabled_Statics
{
	struct UGC_CameraModifier_eventIsDebugEnabled_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UUGC_CameraModifier_IsDebugEnabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((UGC_CameraModifier_eventIsDebugEnabled_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_IsDebugEnabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGC_CameraModifier_eventIsDebugEnabled_Parms), &Z_Construct_UFunction_UUGC_CameraModifier_IsDebugEnabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraModifier_IsDebugEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_IsDebugEnabled_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_IsDebugEnabled_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_IsDebugEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "IsDebugEnabled", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraModifier_IsDebugEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_IsDebugEnabled_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGC_CameraModifier_IsDebugEnabled_Statics::UGC_CameraModifier_eventIsDebugEnabled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_IsDebugEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_IsDebugEnabled_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUGC_CameraModifier_IsDebugEnabled_Statics::UGC_CameraModifier_eventIsDebugEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_IsDebugEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_IsDebugEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execIsDebugEnabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsDebugEnabled();
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function IsDebugEnabled

// Begin Class UUGC_CameraModifier Function IsOwnerFalling
struct Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerFalling_Statics
{
	struct UGC_CameraModifier_eventIsOwnerFalling_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier|Movement" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerFalling_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((UGC_CameraModifier_eventIsOwnerFalling_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerFalling_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGC_CameraModifier_eventIsOwnerFalling_Parms), &Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerFalling_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerFalling_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerFalling_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerFalling_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerFalling_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "IsOwnerFalling", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerFalling_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerFalling_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerFalling_Statics::UGC_CameraModifier_eventIsOwnerFalling_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerFalling_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerFalling_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerFalling_Statics::UGC_CameraModifier_eventIsOwnerFalling_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerFalling()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerFalling_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execIsOwnerFalling)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsOwnerFalling();
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function IsOwnerFalling

// Begin Class UUGC_CameraModifier Function IsOwnerMovingOnGround
struct Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerMovingOnGround_Statics
{
	struct UGC_CameraModifier_eventIsOwnerMovingOnGround_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier|Movement" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerMovingOnGround_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((UGC_CameraModifier_eventIsOwnerMovingOnGround_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerMovingOnGround_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGC_CameraModifier_eventIsOwnerMovingOnGround_Parms), &Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerMovingOnGround_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerMovingOnGround_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerMovingOnGround_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerMovingOnGround_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerMovingOnGround_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "IsOwnerMovingOnGround", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerMovingOnGround_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerMovingOnGround_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerMovingOnGround_Statics::UGC_CameraModifier_eventIsOwnerMovingOnGround_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerMovingOnGround_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerMovingOnGround_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerMovingOnGround_Statics::UGC_CameraModifier_eventIsOwnerMovingOnGround_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerMovingOnGround()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerMovingOnGround_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execIsOwnerMovingOnGround)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsOwnerMovingOnGround();
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function IsOwnerMovingOnGround

// Begin Class UUGC_CameraModifier Function IsOwnerStrafing
struct Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerStrafing_Statics
{
	struct UGC_CameraModifier_eventIsOwnerStrafing_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier|Movement" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerStrafing_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((UGC_CameraModifier_eventIsOwnerStrafing_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerStrafing_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGC_CameraModifier_eventIsOwnerStrafing_Parms), &Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerStrafing_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerStrafing_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerStrafing_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerStrafing_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerStrafing_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "IsOwnerStrafing", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerStrafing_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerStrafing_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerStrafing_Statics::UGC_CameraModifier_eventIsOwnerStrafing_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerStrafing_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerStrafing_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerStrafing_Statics::UGC_CameraModifier_eventIsOwnerStrafing_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerStrafing()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerStrafing_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execIsOwnerStrafing)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsOwnerStrafing();
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function IsOwnerStrafing

// Begin Class UUGC_CameraModifier Function OnAnyLevelSequenceEnded
static const FName NAME_UUGC_CameraModifier_OnAnyLevelSequenceEnded = FName(TEXT("OnAnyLevelSequenceEnded"));
void UUGC_CameraModifier::OnAnyLevelSequenceEnded()
{
	UFunction* Func = FindFunctionChecked(NAME_UUGC_CameraModifier_OnAnyLevelSequenceEnded);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		OnAnyLevelSequenceEnded_Implementation();
	}
}
struct Z_Construct_UFunction_UUGC_CameraModifier_OnAnyLevelSequenceEnded_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_OnAnyLevelSequenceEnded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "OnAnyLevelSequenceEnded", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_OnAnyLevelSequenceEnded_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_OnAnyLevelSequenceEnded_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_OnAnyLevelSequenceEnded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_OnAnyLevelSequenceEnded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execOnAnyLevelSequenceEnded)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAnyLevelSequenceEnded_Implementation();
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function OnAnyLevelSequenceEnded

// Begin Class UUGC_CameraModifier Function OnAnyLevelSequenceStarted
static const FName NAME_UUGC_CameraModifier_OnAnyLevelSequenceStarted = FName(TEXT("OnAnyLevelSequenceStarted"));
void UUGC_CameraModifier::OnAnyLevelSequenceStarted()
{
	UFunction* Func = FindFunctionChecked(NAME_UUGC_CameraModifier_OnAnyLevelSequenceStarted);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		OnAnyLevelSequenceStarted_Implementation();
	}
}
struct Z_Construct_UFunction_UUGC_CameraModifier_OnAnyLevelSequenceStarted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_OnAnyLevelSequenceStarted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "OnAnyLevelSequenceStarted", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_OnAnyLevelSequenceStarted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_OnAnyLevelSequenceStarted_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_OnAnyLevelSequenceStarted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_OnAnyLevelSequenceStarted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execOnAnyLevelSequenceStarted)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAnyLevelSequenceStarted_Implementation();
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function OnAnyLevelSequenceStarted

// Begin Class UUGC_CameraModifier Function OnModifierDisabled
struct UGC_CameraModifier_eventOnModifierDisabled_Parms
{
	FMinimalViewInfo LastPOV;
	bool bWasImmediate;
};
static const FName NAME_UUGC_CameraModifier_OnModifierDisabled = FName(TEXT("OnModifierDisabled"));
void UUGC_CameraModifier::OnModifierDisabled(FMinimalViewInfo const& LastPOV, bool bWasImmediate)
{
	UFunction* Func = FindFunctionChecked(NAME_UUGC_CameraModifier_OnModifierDisabled);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		UGC_CameraModifier_eventOnModifierDisabled_Parms Parms;
		Parms.LastPOV=LastPOV;
		Parms.bWasImmediate=bWasImmediate ? true : false;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		OnModifierDisabled_Implementation(LastPOV, bWasImmediate);
	}
}
struct Z_Construct_UFunction_UUGC_CameraModifier_OnModifierDisabled_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     *  Function called once this modifier gets disabled.\n     *  @param  bWasImmediate  - true if modifier was disabled without a blend out.\n     *  @param  LastPOV  - the last view POV of the camera.\n    */" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Function called once this modifier gets disabled.\n@param  bWasImmediate  - true if modifier was disabled without a blend out.\n@param  LastPOV  - the last view POV of the camera." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastPOV_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_LastPOV;
	static void NewProp_bWasImmediate_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasImmediate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_OnModifierDisabled_Statics::NewProp_LastPOV = { "LastPOV", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventOnModifierDisabled_Parms, LastPOV), Z_Construct_UScriptStruct_FMinimalViewInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastPOV_MetaData), NewProp_LastPOV_MetaData) }; // 1624714218
void Z_Construct_UFunction_UUGC_CameraModifier_OnModifierDisabled_Statics::NewProp_bWasImmediate_SetBit(void* Obj)
{
	((UGC_CameraModifier_eventOnModifierDisabled_Parms*)Obj)->bWasImmediate = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_OnModifierDisabled_Statics::NewProp_bWasImmediate = { "bWasImmediate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGC_CameraModifier_eventOnModifierDisabled_Parms), &Z_Construct_UFunction_UUGC_CameraModifier_OnModifierDisabled_Statics::NewProp_bWasImmediate_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraModifier_OnModifierDisabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_OnModifierDisabled_Statics::NewProp_LastPOV,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_OnModifierDisabled_Statics::NewProp_bWasImmediate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_OnModifierDisabled_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_OnModifierDisabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "OnModifierDisabled", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraModifier_OnModifierDisabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_OnModifierDisabled_Statics::PropPointers), sizeof(UGC_CameraModifier_eventOnModifierDisabled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_OnModifierDisabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_OnModifierDisabled_Statics::Function_MetaDataParams) };
static_assert(sizeof(UGC_CameraModifier_eventOnModifierDisabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_OnModifierDisabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_OnModifierDisabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execOnModifierDisabled)
{
	P_GET_STRUCT_REF(FMinimalViewInfo,Z_Param_Out_LastPOV);
	P_GET_UBOOL(Z_Param_bWasImmediate);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnModifierDisabled_Implementation(Z_Param_Out_LastPOV,Z_Param_bWasImmediate);
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function OnModifierDisabled

// Begin Class UUGC_CameraModifier Function OnModifierEnabled
struct UGC_CameraModifier_eventOnModifierEnabled_Parms
{
	FMinimalViewInfo LastPOV;
};
static const FName NAME_UUGC_CameraModifier_OnModifierEnabled = FName(TEXT("OnModifierEnabled"));
void UUGC_CameraModifier::OnModifierEnabled(FMinimalViewInfo const& LastPOV)
{
	UFunction* Func = FindFunctionChecked(NAME_UUGC_CameraModifier_OnModifierEnabled);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		UGC_CameraModifier_eventOnModifierEnabled_Parms Parms;
		Parms.LastPOV=LastPOV;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		OnModifierEnabled_Implementation(LastPOV);
	}
}
struct Z_Construct_UFunction_UUGC_CameraModifier_OnModifierEnabled_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     *  Function called once this modifier gets enabled.\n     *  @param  LastPOV  - the last view POV of the camera.\n    */" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Function called once this modifier gets enabled.\n@param  LastPOV  - the last view POV of the camera." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastPOV_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_LastPOV;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_OnModifierEnabled_Statics::NewProp_LastPOV = { "LastPOV", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventOnModifierEnabled_Parms, LastPOV), Z_Construct_UScriptStruct_FMinimalViewInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastPOV_MetaData), NewProp_LastPOV_MetaData) }; // 1624714218
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraModifier_OnModifierEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_OnModifierEnabled_Statics::NewProp_LastPOV,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_OnModifierEnabled_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_OnModifierEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "OnModifierEnabled", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraModifier_OnModifierEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_OnModifierEnabled_Statics::PropPointers), sizeof(UGC_CameraModifier_eventOnModifierEnabled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_OnModifierEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_OnModifierEnabled_Statics::Function_MetaDataParams) };
static_assert(sizeof(UGC_CameraModifier_eventOnModifierEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_OnModifierEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_OnModifierEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execOnModifierEnabled)
{
	P_GET_STRUCT_REF(FMinimalViewInfo,Z_Param_Out_LastPOV);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnModifierEnabled_Implementation(Z_Param_Out_LastPOV);
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function OnModifierEnabled

// Begin Class UUGC_CameraModifier Function OnSetViewTarget
struct UGC_CameraModifier_eventOnSetViewTarget_Parms
{
	bool bImmediate;
	bool bNewTargetIsOwner;
};
static const FName NAME_UUGC_CameraModifier_OnSetViewTarget = FName(TEXT("OnSetViewTarget"));
void UUGC_CameraModifier::OnSetViewTarget(bool bImmediate, bool bNewTargetIsOwner)
{
	UFunction* Func = FindFunctionChecked(NAME_UUGC_CameraModifier_OnSetViewTarget);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		UGC_CameraModifier_eventOnSetViewTarget_Parms Parms;
		Parms.bImmediate=bImmediate ? true : false;
		Parms.bNewTargetIsOwner=bNewTargetIsOwner ? true : false;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		OnSetViewTarget_Implementation(bImmediate, bNewTargetIsOwner);
	}
}
struct Z_Construct_UFunction_UUGC_CameraModifier_OnSetViewTarget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bImmediate_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bImmediate;
	static void NewProp_bNewTargetIsOwner_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewTargetIsOwner;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UUGC_CameraModifier_OnSetViewTarget_Statics::NewProp_bImmediate_SetBit(void* Obj)
{
	((UGC_CameraModifier_eventOnSetViewTarget_Parms*)Obj)->bImmediate = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_OnSetViewTarget_Statics::NewProp_bImmediate = { "bImmediate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGC_CameraModifier_eventOnSetViewTarget_Parms), &Z_Construct_UFunction_UUGC_CameraModifier_OnSetViewTarget_Statics::NewProp_bImmediate_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UUGC_CameraModifier_OnSetViewTarget_Statics::NewProp_bNewTargetIsOwner_SetBit(void* Obj)
{
	((UGC_CameraModifier_eventOnSetViewTarget_Parms*)Obj)->bNewTargetIsOwner = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_OnSetViewTarget_Statics::NewProp_bNewTargetIsOwner = { "bNewTargetIsOwner", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGC_CameraModifier_eventOnSetViewTarget_Parms), &Z_Construct_UFunction_UUGC_CameraModifier_OnSetViewTarget_Statics::NewProp_bNewTargetIsOwner_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraModifier_OnSetViewTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_OnSetViewTarget_Statics::NewProp_bImmediate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_OnSetViewTarget_Statics::NewProp_bNewTargetIsOwner,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_OnSetViewTarget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_OnSetViewTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "OnSetViewTarget", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraModifier_OnSetViewTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_OnSetViewTarget_Statics::PropPointers), sizeof(UGC_CameraModifier_eventOnSetViewTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_OnSetViewTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_OnSetViewTarget_Statics::Function_MetaDataParams) };
static_assert(sizeof(UGC_CameraModifier_eventOnSetViewTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_OnSetViewTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_OnSetViewTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execOnSetViewTarget)
{
	P_GET_UBOOL(Z_Param_bImmediate);
	P_GET_UBOOL(Z_Param_bNewTargetIsOwner);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnSetViewTarget_Implementation(Z_Param_bImmediate,Z_Param_bNewTargetIsOwner);
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function OnSetViewTarget

// Begin Class UUGC_CameraModifier Function ProcessBoomLengthAndFOV
struct UGC_CameraModifier_eventProcessBoomLengthAndFOV_Parms
{
	float DeltaTime;
	float InFOV;
	float InArmLength;
	FVector ViewLocation;
	FRotator ViewRotation;
	float OutFOV;
	float OutArmLength;
};
static const FName NAME_UUGC_CameraModifier_ProcessBoomLengthAndFOV = FName(TEXT("ProcessBoomLengthAndFOV"));
void UUGC_CameraModifier::ProcessBoomLengthAndFOV(float DeltaTime, float InFOV, float InArmLength, FVector ViewLocation, FRotator ViewRotation, float& OutFOV, float& OutArmLength)
{
	UFunction* Func = FindFunctionChecked(NAME_UUGC_CameraModifier_ProcessBoomLengthAndFOV);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		UGC_CameraModifier_eventProcessBoomLengthAndFOV_Parms Parms;
		Parms.DeltaTime=DeltaTime;
		Parms.InFOV=InFOV;
		Parms.InArmLength=InArmLength;
		Parms.ViewLocation=ViewLocation;
		Parms.ViewRotation=ViewRotation;
		Parms.OutFOV=OutFOV;
		Parms.OutArmLength=OutArmLength;
	ProcessEvent(Func,&Parms);
		OutFOV=Parms.OutFOV;
		OutArmLength=Parms.OutArmLength;
	}
	else
	{
		ProcessBoomLengthAndFOV_Implementation(DeltaTime, InFOV, InArmLength, ViewLocation, ViewRotation, OutFOV, OutArmLength);
	}
}
struct Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Called to give modifiers a chance to adjust arm length and FOV before they are applied.\n     *\n     * @param DeltaTime - Frame time in seconds.\n     * @param InFOV - The Current FOV of the camera.\n     * @param InArmLength - The Current Arm Length of the camera.\n     * @param ViewLocation - The view location of the camera.\n     * @param ViewRotation - The view rotation of the camera.\n     * @param OutFOV - The New FOV of the camera.\n     * @param OutArmLength - The New Arm Length of the camera.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called to give modifiers a chance to adjust arm length and FOV before they are applied.\n\n@param DeltaTime - Frame time in seconds.\n@param InFOV - The Current FOV of the camera.\n@param InArmLength - The Current Arm Length of the camera.\n@param ViewLocation - The view location of the camera.\n@param ViewRotation - The view rotation of the camera.\n@param OutFOV - The New FOV of the camera.\n@param OutArmLength - The New Arm Length of the camera." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InFOV;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InArmLength;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ViewLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ViewRotation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutFOV;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutArmLength;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessBoomLengthAndFOV_Parms, DeltaTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::NewProp_InFOV = { "InFOV", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessBoomLengthAndFOV_Parms, InFOV), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::NewProp_InArmLength = { "InArmLength", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessBoomLengthAndFOV_Parms, InArmLength), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::NewProp_ViewLocation = { "ViewLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessBoomLengthAndFOV_Parms, ViewLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::NewProp_ViewRotation = { "ViewRotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessBoomLengthAndFOV_Parms, ViewRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::NewProp_OutFOV = { "OutFOV", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessBoomLengthAndFOV_Parms, OutFOV), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::NewProp_OutArmLength = { "OutArmLength", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessBoomLengthAndFOV_Parms, OutArmLength), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::NewProp_DeltaTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::NewProp_InFOV,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::NewProp_InArmLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::NewProp_ViewLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::NewProp_ViewRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::NewProp_OutFOV,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::NewProp_OutArmLength,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "ProcessBoomLengthAndFOV", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::PropPointers), sizeof(UGC_CameraModifier_eventProcessBoomLengthAndFOV_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0CC20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::Function_MetaDataParams) };
static_assert(sizeof(UGC_CameraModifier_eventProcessBoomLengthAndFOV_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execProcessBoomLengthAndFOV)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InFOV);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InArmLength);
	P_GET_STRUCT(FVector,Z_Param_ViewLocation);
	P_GET_STRUCT(FRotator,Z_Param_ViewRotation);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OutFOV);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OutArmLength);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ProcessBoomLengthAndFOV_Implementation(Z_Param_DeltaTime,Z_Param_InFOV,Z_Param_InArmLength,Z_Param_ViewLocation,Z_Param_ViewRotation,Z_Param_Out_OutFOV,Z_Param_Out_OutArmLength);
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function ProcessBoomLengthAndFOV

// Begin Class UUGC_CameraModifier Function ProcessBoomOffsets
struct UGC_CameraModifier_eventProcessBoomOffsets_Parms
{
	float DeltaTime;
	FVector InSocketOffset;
	FVector InTargetOffset;
	FVector ViewLocation;
	FRotator ViewRotation;
	FVector OutSocketOffset;
	FVector OutTargetOffset;
};
static const FName NAME_UUGC_CameraModifier_ProcessBoomOffsets = FName(TEXT("ProcessBoomOffsets"));
void UUGC_CameraModifier::ProcessBoomOffsets(float DeltaTime, FVector InSocketOffset, FVector InTargetOffset, FVector ViewLocation, FRotator ViewRotation, FVector& OutSocketOffset, FVector& OutTargetOffset)
{
	UFunction* Func = FindFunctionChecked(NAME_UUGC_CameraModifier_ProcessBoomOffsets);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		UGC_CameraModifier_eventProcessBoomOffsets_Parms Parms;
		Parms.DeltaTime=DeltaTime;
		Parms.InSocketOffset=InSocketOffset;
		Parms.InTargetOffset=InTargetOffset;
		Parms.ViewLocation=ViewLocation;
		Parms.ViewRotation=ViewRotation;
		Parms.OutSocketOffset=OutSocketOffset;
		Parms.OutTargetOffset=OutTargetOffset;
	ProcessEvent(Func,&Parms);
		OutSocketOffset=Parms.OutSocketOffset;
		OutTargetOffset=Parms.OutTargetOffset;
	}
	else
	{
		ProcessBoomOffsets_Implementation(DeltaTime, InSocketOffset, InTargetOffset, ViewLocation, ViewRotation, OutSocketOffset, OutTargetOffset);
	}
}
struct Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Called to give modifiers a chance to adjust arm offsets before they are applied.\n     *\n     * @param DeltaTime - Frame time in seconds.\n     * @param InSocketOffset - The Current Socket Offset of the camera.\n     * @param InTargetOffset - The Current Target Offset of the camera.\n     * @param ViewLocation - The view location of the camera.\n     * @param ViewRotation - The view rotation of the camera.\n     * @param OutSocketOffset - New Socket Offset of the camera.\n     * @param OutTargetOffset - New Target Offset of the camera.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called to give modifiers a chance to adjust arm offsets before they are applied.\n\n@param DeltaTime - Frame time in seconds.\n@param InSocketOffset - The Current Socket Offset of the camera.\n@param InTargetOffset - The Current Target Offset of the camera.\n@param ViewLocation - The view location of the camera.\n@param ViewRotation - The view rotation of the camera.\n@param OutSocketOffset - New Socket Offset of the camera.\n@param OutTargetOffset - New Target Offset of the camera." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InSocketOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InTargetOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ViewLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ViewRotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutSocketOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutTargetOffset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessBoomOffsets_Parms, DeltaTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::NewProp_InSocketOffset = { "InSocketOffset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessBoomOffsets_Parms, InSocketOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::NewProp_InTargetOffset = { "InTargetOffset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessBoomOffsets_Parms, InTargetOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::NewProp_ViewLocation = { "ViewLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessBoomOffsets_Parms, ViewLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::NewProp_ViewRotation = { "ViewRotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessBoomOffsets_Parms, ViewRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::NewProp_OutSocketOffset = { "OutSocketOffset", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessBoomOffsets_Parms, OutSocketOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::NewProp_OutTargetOffset = { "OutTargetOffset", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessBoomOffsets_Parms, OutTargetOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::NewProp_DeltaTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::NewProp_InSocketOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::NewProp_InTargetOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::NewProp_ViewLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::NewProp_ViewRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::NewProp_OutSocketOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::NewProp_OutTargetOffset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "ProcessBoomOffsets", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::PropPointers), sizeof(UGC_CameraModifier_eventProcessBoomOffsets_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0CC20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::Function_MetaDataParams) };
static_assert(sizeof(UGC_CameraModifier_eventProcessBoomOffsets_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execProcessBoomOffsets)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
	P_GET_STRUCT(FVector,Z_Param_InSocketOffset);
	P_GET_STRUCT(FVector,Z_Param_InTargetOffset);
	P_GET_STRUCT(FVector,Z_Param_ViewLocation);
	P_GET_STRUCT(FRotator,Z_Param_ViewRotation);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_OutSocketOffset);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_OutTargetOffset);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ProcessBoomOffsets_Implementation(Z_Param_DeltaTime,Z_Param_InSocketOffset,Z_Param_InTargetOffset,Z_Param_ViewLocation,Z_Param_ViewRotation,Z_Param_Out_OutSocketOffset,Z_Param_Out_OutTargetOffset);
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function ProcessBoomOffsets

// Begin Class UUGC_CameraModifier Function ProcessControlRotation
struct UGC_CameraModifier_eventProcessControlRotation_Parms
{
	AActor* ViewTarget;
	float DeltaTime;
	FVector InViewLocation;
	FRotator InViewRotation;
	FRotator InLocalControlRotation;
	FRotator InDeltaRot;
	FRotator OutDeltaRot;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	UGC_CameraModifier_eventProcessControlRotation_Parms()
		: ReturnValue(false)
	{
	}
};
static const FName NAME_UUGC_CameraModifier_ProcessControlRotation = FName(TEXT("ProcessControlRotation"));
bool UUGC_CameraModifier::ProcessControlRotation(AActor* ViewTarget, float DeltaTime, FVector InViewLocation, FRotator InViewRotation, FRotator InLocalControlRotation, FRotator InDeltaRot, FRotator& OutDeltaRot)
{
	UFunction* Func = FindFunctionChecked(NAME_UUGC_CameraModifier_ProcessControlRotation);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		UGC_CameraModifier_eventProcessControlRotation_Parms Parms;
		Parms.ViewTarget=ViewTarget;
		Parms.DeltaTime=DeltaTime;
		Parms.InViewLocation=InViewLocation;
		Parms.InViewRotation=InViewRotation;
		Parms.InLocalControlRotation=InLocalControlRotation;
		Parms.InDeltaRot=InDeltaRot;
		Parms.OutDeltaRot=OutDeltaRot;
	ProcessEvent(Func,&Parms);
		OutDeltaRot=Parms.OutDeltaRot;
		return !!Parms.ReturnValue;
	}
	else
	{
		return ProcessControlRotation_Implementation(ViewTarget, DeltaTime, InViewLocation, InViewRotation, InLocalControlRotation, InDeltaRot, OutDeltaRot);
	}
}
struct Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Called to give modifiers a chance to adjust view rotation updates before they are applied.\n     *\n     * Default just returns ViewRotation unchanged\n     * @param ViewTarget - Current view target.\n     * @param InLocalControlRotation - The difference between the actor rotation and the control rotation.\n     * @param DeltaTime - Frame time in seconds.\n     * @param InViewLocation - In. The view location of the camera.\n     * @param InViewRotation - In. The view rotation of the camera.\n     * @param InDeltaRot - In/out. How much the rotation changed this frame.\n     * @param OutDeltaRot - Out. How much the control rotation should change this frame.\n     * @return Return true to prevent subsequent (lower priority) modifiers to further adjust rotation, false otherwise.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called to give modifiers a chance to adjust view rotation updates before they are applied.\n\nDefault just returns ViewRotation unchanged\n@param ViewTarget - Current view target.\n@param InLocalControlRotation - The difference between the actor rotation and the control rotation.\n@param DeltaTime - Frame time in seconds.\n@param InViewLocation - In. The view location of the camera.\n@param InViewRotation - In. The view rotation of the camera.\n@param InDeltaRot - In/out. How much the rotation changed this frame.\n@param OutDeltaRot - Out. How much the control rotation should change this frame.\n@return Return true to prevent subsequent (lower priority) modifiers to further adjust rotation, false otherwise." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ViewTarget;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InViewLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InViewRotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InLocalControlRotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InDeltaRot;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutDeltaRot;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::NewProp_ViewTarget = { "ViewTarget", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessControlRotation_Parms, ViewTarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessControlRotation_Parms, DeltaTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::NewProp_InViewLocation = { "InViewLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessControlRotation_Parms, InViewLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::NewProp_InViewRotation = { "InViewRotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessControlRotation_Parms, InViewRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::NewProp_InLocalControlRotation = { "InLocalControlRotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessControlRotation_Parms, InLocalControlRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::NewProp_InDeltaRot = { "InDeltaRot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessControlRotation_Parms, InDeltaRot), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::NewProp_OutDeltaRot = { "OutDeltaRot", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessControlRotation_Parms, OutDeltaRot), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((UGC_CameraModifier_eventProcessControlRotation_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGC_CameraModifier_eventProcessControlRotation_Parms), &Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::NewProp_ViewTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::NewProp_DeltaTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::NewProp_InViewLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::NewProp_InViewRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::NewProp_InLocalControlRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::NewProp_InDeltaRot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::NewProp_OutDeltaRot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "ProcessControlRotation", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::PropPointers), sizeof(UGC_CameraModifier_eventProcessControlRotation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08C20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::Function_MetaDataParams) };
static_assert(sizeof(UGC_CameraModifier_eventProcessControlRotation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execProcessControlRotation)
{
	P_GET_OBJECT(AActor,Z_Param_ViewTarget);
	P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
	P_GET_STRUCT(FVector,Z_Param_InViewLocation);
	P_GET_STRUCT(FRotator,Z_Param_InViewRotation);
	P_GET_STRUCT(FRotator,Z_Param_InLocalControlRotation);
	P_GET_STRUCT(FRotator,Z_Param_InDeltaRot);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_OutDeltaRot);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ProcessControlRotation_Implementation(Z_Param_ViewTarget,Z_Param_DeltaTime,Z_Param_InViewLocation,Z_Param_InViewRotation,Z_Param_InLocalControlRotation,Z_Param_InDeltaRot,Z_Param_Out_OutDeltaRot);
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function ProcessControlRotation

// Begin Class UUGC_CameraModifier Function ProcessTurnRate
struct UGC_CameraModifier_eventProcessTurnRate_Parms
{
	float DeltaTime;
	FRotator InLocalControlRotation;
	float InPitchTurnRate;
	float InYawTurnRate;
	float OutPitchTurnRate;
	float OutYawTurnRate;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	UGC_CameraModifier_eventProcessTurnRate_Parms()
		: ReturnValue(false)
	{
	}
};
static const FName NAME_UUGC_CameraModifier_ProcessTurnRate = FName(TEXT("ProcessTurnRate"));
bool UUGC_CameraModifier::ProcessTurnRate(float DeltaTime, FRotator InLocalControlRotation, float InPitchTurnRate, float InYawTurnRate, float& OutPitchTurnRate, float& OutYawTurnRate)
{
	UFunction* Func = FindFunctionChecked(NAME_UUGC_CameraModifier_ProcessTurnRate);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		UGC_CameraModifier_eventProcessTurnRate_Parms Parms;
		Parms.DeltaTime=DeltaTime;
		Parms.InLocalControlRotation=InLocalControlRotation;
		Parms.InPitchTurnRate=InPitchTurnRate;
		Parms.InYawTurnRate=InYawTurnRate;
		Parms.OutPitchTurnRate=OutPitchTurnRate;
		Parms.OutYawTurnRate=OutYawTurnRate;
	ProcessEvent(Func,&Parms);
		OutPitchTurnRate=Parms.OutPitchTurnRate;
		OutYawTurnRate=Parms.OutYawTurnRate;
		return !!Parms.ReturnValue;
	}
	else
	{
		return ProcessTurnRate_Implementation(DeltaTime, InLocalControlRotation, InPitchTurnRate, InYawTurnRate, OutPitchTurnRate, OutYawTurnRate);
	}
}
struct Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Called to give modifiers a chance to adjust both the yaw turn rate and pitch turn rate. However the input for looking needs to have UGC_CameraTurnRateModifier.\n     *\n     * @param DeltaTime - Frame time in seconds.\n     * @param InLocalControlRotation - The difference between the actor rotation and the control rotation.\n     * @param OutPitchTurnRate - Out. New value of the pitch turn rate (between 0 and 1).\n     * @param OutYawTurnRate - Out. New value of the yaw turn rate (between 0 and 1).\n     * @return Return true to prevent subsequent (lower priority) modifiers to further adjust rotation, false otherwise.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called to give modifiers a chance to adjust both the yaw turn rate and pitch turn rate. However the input for looking needs to have UGC_CameraTurnRateModifier.\n\n@param DeltaTime - Frame time in seconds.\n@param InLocalControlRotation - The difference between the actor rotation and the control rotation.\n@param OutPitchTurnRate - Out. New value of the pitch turn rate (between 0 and 1).\n@param OutYawTurnRate - Out. New value of the yaw turn rate (between 0 and 1).\n@return Return true to prevent subsequent (lower priority) modifiers to further adjust rotation, false otherwise." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InLocalControlRotation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InPitchTurnRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InYawTurnRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutPitchTurnRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutYawTurnRate;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessTurnRate_Parms, DeltaTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::NewProp_InLocalControlRotation = { "InLocalControlRotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessTurnRate_Parms, InLocalControlRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::NewProp_InPitchTurnRate = { "InPitchTurnRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessTurnRate_Parms, InPitchTurnRate), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::NewProp_InYawTurnRate = { "InYawTurnRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessTurnRate_Parms, InYawTurnRate), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::NewProp_OutPitchTurnRate = { "OutPitchTurnRate", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessTurnRate_Parms, OutPitchTurnRate), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::NewProp_OutYawTurnRate = { "OutYawTurnRate", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventProcessTurnRate_Parms, OutYawTurnRate), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((UGC_CameraModifier_eventProcessTurnRate_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGC_CameraModifier_eventProcessTurnRate_Parms), &Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::NewProp_DeltaTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::NewProp_InLocalControlRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::NewProp_InPitchTurnRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::NewProp_InYawTurnRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::NewProp_OutPitchTurnRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::NewProp_OutYawTurnRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "ProcessTurnRate", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::PropPointers), sizeof(UGC_CameraModifier_eventProcessTurnRate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08C20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::Function_MetaDataParams) };
static_assert(sizeof(UGC_CameraModifier_eventProcessTurnRate_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execProcessTurnRate)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
	P_GET_STRUCT(FRotator,Z_Param_InLocalControlRotation);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InPitchTurnRate);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InYawTurnRate);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OutPitchTurnRate);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OutYawTurnRate);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ProcessTurnRate_Implementation(Z_Param_DeltaTime,Z_Param_InLocalControlRotation,Z_Param_InPitchTurnRate,Z_Param_InYawTurnRate,Z_Param_Out_OutPitchTurnRate,Z_Param_Out_OutYawTurnRate);
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function ProcessTurnRate

// Begin Class UUGC_CameraModifier Function SetAlpha
struct Z_Construct_UFunction_UUGC_CameraModifier_SetAlpha_Statics
{
	struct UGC_CameraModifier_eventSetAlpha_Parms
	{
		float InAlpha;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InAlpha;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_SetAlpha_Statics::NewProp_InAlpha = { "InAlpha", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraModifier_eventSetAlpha_Parms, InAlpha), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraModifier_SetAlpha_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_SetAlpha_Statics::NewProp_InAlpha,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_SetAlpha_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_SetAlpha_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "SetAlpha", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraModifier_SetAlpha_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_SetAlpha_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGC_CameraModifier_SetAlpha_Statics::UGC_CameraModifier_eventSetAlpha_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_SetAlpha_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_SetAlpha_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUGC_CameraModifier_SetAlpha_Statics::UGC_CameraModifier_eventSetAlpha_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_SetAlpha()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_SetAlpha_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execSetAlpha)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InAlpha);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAlpha(Z_Param_InAlpha);
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function SetAlpha

// Begin Class UUGC_CameraModifier Function ToggleDebug
struct Z_Construct_UFunction_UUGC_CameraModifier_ToggleDebug_Statics
{
	struct UGC_CameraModifier_eventToggleDebug_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Modifier" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UUGC_CameraModifier_ToggleDebug_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((UGC_CameraModifier_eventToggleDebug_Parms*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUGC_CameraModifier_ToggleDebug_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGC_CameraModifier_eventToggleDebug_Parms), &Z_Construct_UFunction_UUGC_CameraModifier_ToggleDebug_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraModifier_ToggleDebug_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraModifier_ToggleDebug_Statics::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ToggleDebug_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraModifier_ToggleDebug_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraModifier, nullptr, "ToggleDebug", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraModifier_ToggleDebug_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ToggleDebug_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGC_CameraModifier_ToggleDebug_Statics::UGC_CameraModifier_eventToggleDebug_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraModifier_ToggleDebug_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraModifier_ToggleDebug_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUGC_CameraModifier_ToggleDebug_Statics::UGC_CameraModifier_eventToggleDebug_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraModifier_ToggleDebug()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraModifier_ToggleDebug_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraModifier::execToggleDebug)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleDebug(Z_Param_bEnabled);
	P_NATIVE_END;
}
// End Class UUGC_CameraModifier Function ToggleDebug

// Begin Class UUGC_CameraModifier
void UUGC_CameraModifier::StaticRegisterNativesUUGC_CameraModifier()
{
	UClass* Class = UUGC_CameraModifier::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ComputeOwnerFloorDistance", &UUGC_CameraModifier::execComputeOwnerFloorDistance },
		{ "ComputeOwnerFloorNormal", &UUGC_CameraModifier::execComputeOwnerFloorNormal },
		{ "ComputeOwnerLookAndMovementDot", &UUGC_CameraModifier::execComputeOwnerLookAndMovementDot },
		{ "ComputeOwnerSlopeAngle", &UUGC_CameraModifier::execComputeOwnerSlopeAngle },
		{ "GetOwnerVelocity", &UUGC_CameraModifier::execGetOwnerVelocity },
		{ "IsDebugEnabled", &UUGC_CameraModifier::execIsDebugEnabled },
		{ "IsOwnerFalling", &UUGC_CameraModifier::execIsOwnerFalling },
		{ "IsOwnerMovingOnGround", &UUGC_CameraModifier::execIsOwnerMovingOnGround },
		{ "IsOwnerStrafing", &UUGC_CameraModifier::execIsOwnerStrafing },
		{ "OnAnyLevelSequenceEnded", &UUGC_CameraModifier::execOnAnyLevelSequenceEnded },
		{ "OnAnyLevelSequenceStarted", &UUGC_CameraModifier::execOnAnyLevelSequenceStarted },
		{ "OnModifierDisabled", &UUGC_CameraModifier::execOnModifierDisabled },
		{ "OnModifierEnabled", &UUGC_CameraModifier::execOnModifierEnabled },
		{ "OnSetViewTarget", &UUGC_CameraModifier::execOnSetViewTarget },
		{ "ProcessBoomLengthAndFOV", &UUGC_CameraModifier::execProcessBoomLengthAndFOV },
		{ "ProcessBoomOffsets", &UUGC_CameraModifier::execProcessBoomOffsets },
		{ "ProcessControlRotation", &UUGC_CameraModifier::execProcessControlRotation },
		{ "ProcessTurnRate", &UUGC_CameraModifier::execProcessTurnRate },
		{ "SetAlpha", &UUGC_CameraModifier::execSetAlpha },
		{ "ToggleDebug", &UUGC_CameraModifier::execToggleDebug },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUGC_CameraModifier);
UClass* Z_Construct_UClass_UUGC_CameraModifier_NoRegister()
{
	return UUGC_CameraModifier::StaticClass();
}
struct Z_Construct_UClass_UUGC_CameraModifier_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ClassGroupNames", "UGC|Camera Modifiers" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Base Camera Modifier Class\n */" },
#endif
		{ "IncludePath", "Camera/Modifiers/UGC_CameraModifier.h" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base Camera Modifier Class" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPlayDuringCameraAnimations_MetaData[] = {
		{ "Category", "Modifier Settings" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UGCCameraManager_MetaData[] = {
		{ "Category", "UGC|Camera Modifier|Internal" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwnerController_MetaData[] = {
		{ "Category", "UGC|Camera Modifier|Internal" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwnerCharacter_MetaData[] = {
		{ "Category", "UGC|Camera Modifier|Internal" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwnerPawn_MetaData[] = {
		{ "Category", "UGC|Camera Modifier|Internal" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[] = {
		{ "Category", "UGC|Camera Modifier|Internal" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovementComponent_MetaData[] = {
		{ "Category", "UGC|Camera Modifier|Internal" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentSocketOffset_MetaData[] = {
		{ "Category", "UGC|Camera Modifier|Internal" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentTargetOffset_MetaData[] = {
		{ "Category", "UGC|Camera Modifier|Internal" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentArmLength_MetaData[] = {
		{ "Category", "UGC|Camera Modifier|Internal" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasMovementInput_MetaData[] = {
		{ "Category", "UGC|Camera Modifier|Internal" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviousMovementInput_MetaData[] = {
		{ "Category", "UGC|Camera Modifier|Internal" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovementInput_MetaData[] = {
		{ "Category", "UGC|Camera Modifier|Internal" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimeSinceMovementInput_MetaData[] = {
		{ "Category", "UGC|Camera Modifier|Internal" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasRotationInput_MetaData[] = {
		{ "Category", "UGC|Camera Modifier|Internal" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotationInput_MetaData[] = {
		{ "Category", "UGC|Camera Modifier|Internal" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimeSinceRotationInput_MetaData[] = {
		{ "Category", "UGC|Camera Modifier|Internal" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bPlayDuringCameraAnimations_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPlayDuringCameraAnimations;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UGCCameraManager;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwnerController;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwnerCharacter;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwnerPawn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MovementComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentSocketOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentTargetOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentArmLength;
	static void NewProp_bHasMovementInput_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasMovementInput;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PreviousMovementInput;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MovementInput;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeSinceMovementInput;
	static void NewProp_bHasRotationInput_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasRotationInput;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RotationInput;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeSinceRotationInput;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorDistance, "ComputeOwnerFloorDistance" }, // 835643721
		{ &Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerFloorNormal, "ComputeOwnerFloorNormal" }, // 1257020570
		{ &Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerLookAndMovementDot, "ComputeOwnerLookAndMovementDot" }, // 4275339106
		{ &Z_Construct_UFunction_UUGC_CameraModifier_ComputeOwnerSlopeAngle, "ComputeOwnerSlopeAngle" }, // 1892260656
		{ &Z_Construct_UFunction_UUGC_CameraModifier_GetOwnerVelocity, "GetOwnerVelocity" }, // 3193180057
		{ &Z_Construct_UFunction_UUGC_CameraModifier_IsDebugEnabled, "IsDebugEnabled" }, // 741803376
		{ &Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerFalling, "IsOwnerFalling" }, // 2009511724
		{ &Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerMovingOnGround, "IsOwnerMovingOnGround" }, // 2980518932
		{ &Z_Construct_UFunction_UUGC_CameraModifier_IsOwnerStrafing, "IsOwnerStrafing" }, // 1084195129
		{ &Z_Construct_UFunction_UUGC_CameraModifier_OnAnyLevelSequenceEnded, "OnAnyLevelSequenceEnded" }, // 3057294618
		{ &Z_Construct_UFunction_UUGC_CameraModifier_OnAnyLevelSequenceStarted, "OnAnyLevelSequenceStarted" }, // 73170702
		{ &Z_Construct_UFunction_UUGC_CameraModifier_OnModifierDisabled, "OnModifierDisabled" }, // 2825715215
		{ &Z_Construct_UFunction_UUGC_CameraModifier_OnModifierEnabled, "OnModifierEnabled" }, // 4017187875
		{ &Z_Construct_UFunction_UUGC_CameraModifier_OnSetViewTarget, "OnSetViewTarget" }, // 3781741122
		{ &Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomLengthAndFOV, "ProcessBoomLengthAndFOV" }, // 579371472
		{ &Z_Construct_UFunction_UUGC_CameraModifier_ProcessBoomOffsets, "ProcessBoomOffsets" }, // 47387835
		{ &Z_Construct_UFunction_UUGC_CameraModifier_ProcessControlRotation, "ProcessControlRotation" }, // 3669413043
		{ &Z_Construct_UFunction_UUGC_CameraModifier_ProcessTurnRate, "ProcessTurnRate" }, // 3120438087
		{ &Z_Construct_UFunction_UUGC_CameraModifier_SetAlpha, "SetAlpha" }, // 3304891574
		{ &Z_Construct_UFunction_UUGC_CameraModifier_ToggleDebug, "ToggleDebug" }, // 340255431
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUGC_CameraModifier>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_bPlayDuringCameraAnimations_SetBit(void* Obj)
{
	((UUGC_CameraModifier*)Obj)->bPlayDuringCameraAnimations = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_bPlayDuringCameraAnimations = { "bPlayDuringCameraAnimations", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UUGC_CameraModifier), &Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_bPlayDuringCameraAnimations_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPlayDuringCameraAnimations_MetaData), NewProp_bPlayDuringCameraAnimations_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_UGCCameraManager = { "UGCCameraManager", nullptr, (EPropertyFlags)0x0124080000020815, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraModifier, UGCCameraManager), Z_Construct_UClass_AUGC_PlayerCameraManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UGCCameraManager_MetaData), NewProp_UGCCameraManager_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_OwnerController = { "OwnerController", nullptr, (EPropertyFlags)0x0124080000020815, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraModifier, OwnerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnerController_MetaData), NewProp_OwnerController_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_OwnerCharacter = { "OwnerCharacter", nullptr, (EPropertyFlags)0x0124080000020815, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraModifier, OwnerCharacter), Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnerCharacter_MetaData), NewProp_OwnerCharacter_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_OwnerPawn = { "OwnerPawn", nullptr, (EPropertyFlags)0x0124080000020815, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraModifier, OwnerPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnerPawn_MetaData), NewProp_OwnerPawn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x01240800000a081d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraModifier, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringArm_MetaData), NewProp_SpringArm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_MovementComponent = { "MovementComponent", nullptr, (EPropertyFlags)0x01240800000a081d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraModifier, MovementComponent), Z_Construct_UClass_UCharacterMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovementComponent_MetaData), NewProp_MovementComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_CurrentSocketOffset = { "CurrentSocketOffset", nullptr, (EPropertyFlags)0x0020080000020815, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraModifier, CurrentSocketOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentSocketOffset_MetaData), NewProp_CurrentSocketOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_CurrentTargetOffset = { "CurrentTargetOffset", nullptr, (EPropertyFlags)0x0020080000020815, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraModifier, CurrentTargetOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentTargetOffset_MetaData), NewProp_CurrentTargetOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_CurrentArmLength = { "CurrentArmLength", nullptr, (EPropertyFlags)0x0020080000020815, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraModifier, CurrentArmLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentArmLength_MetaData), NewProp_CurrentArmLength_MetaData) };
void Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_bHasMovementInput_SetBit(void* Obj)
{
	((UUGC_CameraModifier*)Obj)->bHasMovementInput = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_bHasMovementInput = { "bHasMovementInput", nullptr, (EPropertyFlags)0x0020080000020815, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UUGC_CameraModifier), &Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_bHasMovementInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasMovementInput_MetaData), NewProp_bHasMovementInput_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_PreviousMovementInput = { "PreviousMovementInput", nullptr, (EPropertyFlags)0x0020080000020815, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraModifier, PreviousMovementInput), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviousMovementInput_MetaData), NewProp_PreviousMovementInput_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_MovementInput = { "MovementInput", nullptr, (EPropertyFlags)0x0020080000020815, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraModifier, MovementInput), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovementInput_MetaData), NewProp_MovementInput_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_TimeSinceMovementInput = { "TimeSinceMovementInput", nullptr, (EPropertyFlags)0x0020080000020815, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraModifier, TimeSinceMovementInput), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimeSinceMovementInput_MetaData), NewProp_TimeSinceMovementInput_MetaData) };
void Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_bHasRotationInput_SetBit(void* Obj)
{
	((UUGC_CameraModifier*)Obj)->bHasRotationInput = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_bHasRotationInput = { "bHasRotationInput", nullptr, (EPropertyFlags)0x0020080000020815, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UUGC_CameraModifier), &Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_bHasRotationInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasRotationInput_MetaData), NewProp_bHasRotationInput_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_RotationInput = { "RotationInput", nullptr, (EPropertyFlags)0x0020080000020815, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraModifier, RotationInput), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotationInput_MetaData), NewProp_RotationInput_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_TimeSinceRotationInput = { "TimeSinceRotationInput", nullptr, (EPropertyFlags)0x0020080000020815, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraModifier, TimeSinceRotationInput), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimeSinceRotationInput_MetaData), NewProp_TimeSinceRotationInput_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUGC_CameraModifier_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_bPlayDuringCameraAnimations,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_UGCCameraManager,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_OwnerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_OwnerCharacter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_OwnerPawn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_SpringArm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_MovementComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_CurrentSocketOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_CurrentTargetOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_CurrentArmLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_bHasMovementInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_PreviousMovementInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_MovementInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_TimeSinceMovementInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_bHasRotationInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_RotationInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraModifier_Statics::NewProp_TimeSinceRotationInput,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraModifier_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UUGC_CameraModifier_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCameraModifier,
	(UObject* (*)())Z_Construct_UPackage__Script_AuroraDevs_UGC,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraModifier_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UUGC_CameraModifier_Statics::ClassParams = {
	&UUGC_CameraModifier::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UUGC_CameraModifier_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraModifier_Statics::PropPointers),
	0,
	0x009000A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraModifier_Statics::Class_MetaDataParams), Z_Construct_UClass_UUGC_CameraModifier_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UUGC_CameraModifier()
{
	if (!Z_Registration_Info_UClass_UUGC_CameraModifier.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUGC_CameraModifier.OuterSingleton, Z_Construct_UClass_UUGC_CameraModifier_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UUGC_CameraModifier.OuterSingleton;
}
template<> AURORADEVS_UGC_API UClass* StaticClass<UUGC_CameraModifier>()
{
	return UUGC_CameraModifier::StaticClass();
}
UUGC_CameraModifier::UUGC_CameraModifier(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UUGC_CameraModifier);
UUGC_CameraModifier::~UUGC_CameraModifier() {}
// End Class UUGC_CameraModifier

// Begin Class UUGC_CameraAddOnModifier Function SetSettings
struct UGC_CameraAddOnModifier_eventSetSettings_Parms
{
	UUGC_CameraAddOnModifierSettings* InSettings;
};
static const FName NAME_UUGC_CameraAddOnModifier_SetSettings = FName(TEXT("SetSettings"));
void UUGC_CameraAddOnModifier::SetSettings(UUGC_CameraAddOnModifierSettings* InSettings)
{
	UFunction* Func = FindFunctionChecked(NAME_UUGC_CameraAddOnModifier_SetSettings);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		UGC_CameraAddOnModifier_eventSetSettings_Parms Parms;
		Parms.InSettings=InSettings;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		SetSettings_Implementation(InSettings);
	}
}
struct Z_Construct_UFunction_UUGC_CameraAddOnModifier_SetSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Add On|Camera Modifiers" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InSettings;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUGC_CameraAddOnModifier_SetSettings_Statics::NewProp_InSettings = { "InSettings", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_CameraAddOnModifier_eventSetSettings_Parms, InSettings), Z_Construct_UClass_UUGC_CameraAddOnModifierSettings_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_CameraAddOnModifier_SetSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_CameraAddOnModifier_SetSettings_Statics::NewProp_InSettings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraAddOnModifier_SetSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_CameraAddOnModifier_SetSettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_CameraAddOnModifier, nullptr, "SetSettings", nullptr, nullptr, Z_Construct_UFunction_UUGC_CameraAddOnModifier_SetSettings_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraAddOnModifier_SetSettings_Statics::PropPointers), sizeof(UGC_CameraAddOnModifier_eventSetSettings_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_CameraAddOnModifier_SetSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_CameraAddOnModifier_SetSettings_Statics::Function_MetaDataParams) };
static_assert(sizeof(UGC_CameraAddOnModifier_eventSetSettings_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_CameraAddOnModifier_SetSettings()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_CameraAddOnModifier_SetSettings_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGC_CameraAddOnModifier::execSetSettings)
{
	P_GET_OBJECT(UUGC_CameraAddOnModifierSettings,Z_Param_InSettings);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSettings_Implementation(Z_Param_InSettings);
	P_NATIVE_END;
}
// End Class UUGC_CameraAddOnModifier Function SetSettings

// Begin Class UUGC_CameraAddOnModifier
void UUGC_CameraAddOnModifier::StaticRegisterNativesUUGC_CameraAddOnModifier()
{
	UClass* Class = UUGC_CameraAddOnModifier::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SetSettings", &UUGC_CameraAddOnModifier::execSetSettings },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUGC_CameraAddOnModifier);
UClass* Z_Construct_UClass_UUGC_CameraAddOnModifier_NoRegister()
{
	return UUGC_CameraAddOnModifier::StaticClass();
}
struct Z_Construct_UClass_UUGC_CameraAddOnModifier_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ClassGroupNames", "UGC|Add On|Camera Modifiers" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Base Camera Modifier Class for Add-on modifiers\n */" },
#endif
		{ "IncludePath", "Camera/Modifiers/UGC_CameraModifier.h" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base Camera Modifier Class for Add-on modifiers" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Settings_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraModifier.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Settings;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UUGC_CameraAddOnModifier_SetSettings, "SetSettings" }, // 3667719671
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUGC_CameraAddOnModifier>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUGC_CameraAddOnModifier_Statics::NewProp_Settings = { "Settings", nullptr, (EPropertyFlags)0x0114000000020805, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraAddOnModifier, Settings), Z_Construct_UClass_UUGC_CameraAddOnModifierSettings_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Settings_MetaData), NewProp_Settings_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUGC_CameraAddOnModifier_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraAddOnModifier_Statics::NewProp_Settings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraAddOnModifier_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UUGC_CameraAddOnModifier_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUGC_CameraModifier,
	(UObject* (*)())Z_Construct_UPackage__Script_AuroraDevs_UGC,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraAddOnModifier_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UUGC_CameraAddOnModifier_Statics::ClassParams = {
	&UUGC_CameraAddOnModifier::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UUGC_CameraAddOnModifier_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraAddOnModifier_Statics::PropPointers),
	0,
	0x009000A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraAddOnModifier_Statics::Class_MetaDataParams), Z_Construct_UClass_UUGC_CameraAddOnModifier_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UUGC_CameraAddOnModifier()
{
	if (!Z_Registration_Info_UClass_UUGC_CameraAddOnModifier.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUGC_CameraAddOnModifier.OuterSingleton, Z_Construct_UClass_UUGC_CameraAddOnModifier_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UUGC_CameraAddOnModifier.OuterSingleton;
}
template<> AURORADEVS_UGC_API UClass* StaticClass<UUGC_CameraAddOnModifier>()
{
	return UUGC_CameraAddOnModifier::StaticClass();
}
UUGC_CameraAddOnModifier::UUGC_CameraAddOnModifier(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UUGC_CameraAddOnModifier);
UUGC_CameraAddOnModifier::~UUGC_CameraAddOnModifier() {}
// End Class UUGC_CameraAddOnModifier

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraModifier_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UUGC_CameraModifier, UUGC_CameraModifier::StaticClass, TEXT("UUGC_CameraModifier"), &Z_Registration_Info_UClass_UUGC_CameraModifier, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUGC_CameraModifier), 149868180U) },
		{ Z_Construct_UClass_UUGC_CameraAddOnModifier, UUGC_CameraAddOnModifier::StaticClass, TEXT("UUGC_CameraAddOnModifier"), &Z_Registration_Info_UClass_UUGC_CameraAddOnModifier, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUGC_CameraAddOnModifier), 3846690640U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraModifier_h_2228908489(TEXT("/Script/AuroraDevs_UGC"),
	Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraModifier_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_TronRPGProject_TronRPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraModifier_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
