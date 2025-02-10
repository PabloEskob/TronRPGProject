// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AuroraDevs_UGC/Public/Camera/Modifiers/UGC_CameraDitheringModifier.h"
#include "AuroraDevs_UGC/Public/Camera/Data/UGC_CameraData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUGC_CameraDitheringModifier() {}

// Begin Cross Module References
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_CameraDitheringModifier();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_CameraDitheringModifier_NoRegister();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_CameraModifier();
AURORADEVS_UGC_API UEnum* Z_Construct_UEnum_AuroraDevs_UGC_EDitherType();
AURORADEVS_UGC_API UScriptStruct* Z_Construct_UScriptStruct_FCameraDitheringSettings();
AURORADEVS_UGC_API UScriptStruct* Z_Construct_UScriptStruct_FDitheredActorState();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialParameterCollection_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialParameterCollectionInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_AuroraDevs_UGC();
// End Cross Module References

// Begin Enum EDitherType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDitherType;
static UEnum* EDitherType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDitherType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDitherType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_AuroraDevs_UGC_EDitherType, (UObject*)Z_Construct_UPackage__Script_AuroraDevs_UGC(), TEXT("EDitherType"));
	}
	return Z_Registration_Info_UEnum_EDitherType.OuterSingleton;
}
template<> AURORADEVS_UGC_API UEnum* StaticEnum<EDitherType>()
{
	return EDitherType_StaticEnum();
}
struct Z_Construct_UEnum_AuroraDevs_UGC_EDitherType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlockingLOS.Name", "EDitherType::BlockingLOS" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraDitheringModifier.h" },
		{ "None.Name", "EDitherType::None" },
		{ "OverlappingCamera.Name", "EDitherType::OverlappingCamera" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDitherType::None", (int64)EDitherType::None },
		{ "EDitherType::BlockingLOS", (int64)EDitherType::BlockingLOS },
		{ "EDitherType::OverlappingCamera", (int64)EDitherType::OverlappingCamera },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_AuroraDevs_UGC_EDitherType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_AuroraDevs_UGC,
	nullptr,
	"EDitherType",
	"EDitherType",
	Z_Construct_UEnum_AuroraDevs_UGC_EDitherType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_AuroraDevs_UGC_EDitherType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_AuroraDevs_UGC_EDitherType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_AuroraDevs_UGC_EDitherType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_AuroraDevs_UGC_EDitherType()
{
	if (!Z_Registration_Info_UEnum_EDitherType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDitherType.InnerSingleton, Z_Construct_UEnum_AuroraDevs_UGC_EDitherType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDitherType.InnerSingleton;
}
// End Enum EDitherType

// Begin ScriptStruct FDitheredActorState
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_DitheredActorState;
class UScriptStruct* FDitheredActorState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_DitheredActorState.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_DitheredActorState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDitheredActorState, (UObject*)Z_Construct_UPackage__Script_AuroraDevs_UGC(), TEXT("DitheredActorState"));
	}
	return Z_Registration_Info_UScriptStruct_DitheredActorState.OuterSingleton;
}
template<> AURORADEVS_UGC_API UScriptStruct* StaticStruct<FDitheredActorState>()
{
	return FDitheredActorState::StaticStruct();
}
struct Z_Construct_UScriptStruct_FDitheredActorState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraDitheringModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Actor_MetaData[] = {
		{ "Category", "UGC|Modifiers|Camera Dithering" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraDitheringModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentOpacity_MetaData[] = {
		{ "Category", "UGC|Modifiers|Camera Dithering" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraDitheringModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionTime_MetaData[] = {
		{ "Category", "UGC|Modifiers|Camera Dithering" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraDitheringModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsDitheringIn_MetaData[] = {
		{ "Category", "UGC|Modifiers|Camera Dithering" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraDitheringModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsDitheringOut_MetaData[] = {
		{ "Category", "UGC|Modifiers|Camera Dithering" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraDitheringModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DitherType_MetaData[] = {
		{ "Category", "UGC|Modifiers|Camera Dithering" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraDitheringModifier.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentOpacity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CollisionTime;
	static void NewProp_bIsDitheringIn_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsDitheringIn;
	static void NewProp_bIsDitheringOut_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsDitheringOut;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DitherType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DitherType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDitheredActorState>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDitheredActorState_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDitheredActorState, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Actor_MetaData), NewProp_Actor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDitheredActorState_Statics::NewProp_CurrentOpacity = { "CurrentOpacity", nullptr, (EPropertyFlags)0x0010000000020805, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDitheredActorState, CurrentOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentOpacity_MetaData), NewProp_CurrentOpacity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDitheredActorState_Statics::NewProp_CollisionTime = { "CollisionTime", nullptr, (EPropertyFlags)0x0010000000020805, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDitheredActorState, CollisionTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionTime_MetaData), NewProp_CollisionTime_MetaData) };
void Z_Construct_UScriptStruct_FDitheredActorState_Statics::NewProp_bIsDitheringIn_SetBit(void* Obj)
{
	((FDitheredActorState*)Obj)->bIsDitheringIn = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDitheredActorState_Statics::NewProp_bIsDitheringIn = { "bIsDitheringIn", nullptr, (EPropertyFlags)0x0010000000020805, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDitheredActorState), &Z_Construct_UScriptStruct_FDitheredActorState_Statics::NewProp_bIsDitheringIn_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsDitheringIn_MetaData), NewProp_bIsDitheringIn_MetaData) };
void Z_Construct_UScriptStruct_FDitheredActorState_Statics::NewProp_bIsDitheringOut_SetBit(void* Obj)
{
	((FDitheredActorState*)Obj)->bIsDitheringOut = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDitheredActorState_Statics::NewProp_bIsDitheringOut = { "bIsDitheringOut", nullptr, (EPropertyFlags)0x0010000000020805, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDitheredActorState), &Z_Construct_UScriptStruct_FDitheredActorState_Statics::NewProp_bIsDitheringOut_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsDitheringOut_MetaData), NewProp_bIsDitheringOut_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FDitheredActorState_Statics::NewProp_DitherType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FDitheredActorState_Statics::NewProp_DitherType = { "DitherType", nullptr, (EPropertyFlags)0x0010000000020805, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDitheredActorState, DitherType), Z_Construct_UEnum_AuroraDevs_UGC_EDitherType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DitherType_MetaData), NewProp_DitherType_MetaData) }; // 3695556539
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDitheredActorState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDitheredActorState_Statics::NewProp_Actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDitheredActorState_Statics::NewProp_CurrentOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDitheredActorState_Statics::NewProp_CollisionTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDitheredActorState_Statics::NewProp_bIsDitheringIn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDitheredActorState_Statics::NewProp_bIsDitheringOut,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDitheredActorState_Statics::NewProp_DitherType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDitheredActorState_Statics::NewProp_DitherType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDitheredActorState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDitheredActorState_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_AuroraDevs_UGC,
	nullptr,
	&NewStructOps,
	"DitheredActorState",
	Z_Construct_UScriptStruct_FDitheredActorState_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDitheredActorState_Statics::PropPointers),
	sizeof(FDitheredActorState),
	alignof(FDitheredActorState),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDitheredActorState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDitheredActorState_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDitheredActorState()
{
	if (!Z_Registration_Info_UScriptStruct_DitheredActorState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_DitheredActorState.InnerSingleton, Z_Construct_UScriptStruct_FDitheredActorState_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_DitheredActorState.InnerSingleton;
}
// End ScriptStruct FDitheredActorState

// Begin Class UUGC_CameraDitheringModifier
void UUGC_CameraDitheringModifier::StaticRegisterNativesUUGC_CameraDitheringModifier()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUGC_CameraDitheringModifier);
UClass* Z_Construct_UClass_UUGC_CameraDitheringModifier_NoRegister()
{
	return UUGC_CameraDitheringModifier::StaticClass();
}
struct Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UGC Camera Modifier used to dither objects colliding with the camera\n */" },
#endif
		{ "IncludePath", "Camera/Modifiers/UGC_CameraDitheringModifier.h" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraDitheringModifier.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UGC Camera Modifier used to dither objects colliding with the camera" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DitheringSettings_MetaData[] = {
		{ "Category", "UGC|Modifiers|Dithering" },
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraDitheringModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DitheringMPC_MetaData[] = {
		{ "Category", "UGC|Modifiers|Dithering" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Material Parameter Collection for everything dithering-related */" },
#endif
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraDitheringModifier.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Material Parameter Collection for everything dithering-related" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DitheringMPCInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraDitheringModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DitheredActorStates_MetaData[] = {
		{ "ModuleRelativePath", "Public/Camera/Modifiers/UGC_CameraDitheringModifier.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_DitheringSettings;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DitheringMPC;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DitheringMPCInstance;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DitheredActorStates_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DitheredActorStates;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUGC_CameraDitheringModifier>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::NewProp_DitheringSettings = { "DitheringSettings", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraDitheringModifier, DitheringSettings), Z_Construct_UScriptStruct_FCameraDitheringSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DitheringSettings_MetaData), NewProp_DitheringSettings_MetaData) }; // 2892054441
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::NewProp_DitheringMPC = { "DitheringMPC", nullptr, (EPropertyFlags)0x0024080000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraDitheringModifier, DitheringMPC), Z_Construct_UClass_UMaterialParameterCollection_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DitheringMPC_MetaData), NewProp_DitheringMPC_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::NewProp_DitheringMPCInstance = { "DitheringMPCInstance", nullptr, (EPropertyFlags)0x0024080000002000, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraDitheringModifier, DitheringMPCInstance), Z_Construct_UClass_UMaterialParameterCollectionInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DitheringMPCInstance_MetaData), NewProp_DitheringMPCInstance_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::NewProp_DitheredActorStates_Inner = { "DitheredActorStates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDitheredActorState, METADATA_PARAMS(0, nullptr) }; // 3283012216
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::NewProp_DitheredActorStates = { "DitheredActorStates", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGC_CameraDitheringModifier, DitheredActorStates), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DitheredActorStates_MetaData), NewProp_DitheredActorStates_MetaData) }; // 3283012216
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::NewProp_DitheringSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::NewProp_DitheringMPC,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::NewProp_DitheringMPCInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::NewProp_DitheredActorStates_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::NewProp_DitheredActorStates,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUGC_CameraModifier,
	(UObject* (*)())Z_Construct_UPackage__Script_AuroraDevs_UGC,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::ClassParams = {
	&UUGC_CameraDitheringModifier::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::Class_MetaDataParams), Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UUGC_CameraDitheringModifier()
{
	if (!Z_Registration_Info_UClass_UUGC_CameraDitheringModifier.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUGC_CameraDitheringModifier.OuterSingleton, Z_Construct_UClass_UUGC_CameraDitheringModifier_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UUGC_CameraDitheringModifier.OuterSingleton;
}
template<> AURORADEVS_UGC_API UClass* StaticClass<UUGC_CameraDitheringModifier>()
{
	return UUGC_CameraDitheringModifier::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UUGC_CameraDitheringModifier);
UUGC_CameraDitheringModifier::~UUGC_CameraDitheringModifier() {}
// End Class UUGC_CameraDitheringModifier

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraDitheringModifier_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EDitherType_StaticEnum, TEXT("EDitherType"), &Z_Registration_Info_UEnum_EDitherType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3695556539U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FDitheredActorState::StaticStruct, Z_Construct_UScriptStruct_FDitheredActorState_Statics::NewStructOps, TEXT("DitheredActorState"), &Z_Registration_Info_UScriptStruct_DitheredActorState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDitheredActorState), 3283012216U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UUGC_CameraDitheringModifier, UUGC_CameraDitheringModifier::StaticClass, TEXT("UUGC_CameraDitheringModifier"), &Z_Registration_Info_UClass_UUGC_CameraDitheringModifier, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUGC_CameraDitheringModifier), 2148298019U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraDitheringModifier_h_2502633659(TEXT("/Script/AuroraDevs_UGC"),
	Z_CompiledInDeferFile_FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraDitheringModifier_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraDitheringModifier_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraDitheringModifier_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraDitheringModifier_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraDitheringModifier_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_RPG_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Camera_Modifiers_UGC_CameraDitheringModifier_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
