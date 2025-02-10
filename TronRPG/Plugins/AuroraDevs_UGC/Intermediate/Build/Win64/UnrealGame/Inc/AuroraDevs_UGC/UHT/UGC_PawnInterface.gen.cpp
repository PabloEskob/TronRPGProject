// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AuroraDevs_UGC/Public/Pawn/UGC_PawnInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUGC_PawnInterface() {}

// Begin Cross Module References
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_PawnInterface();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_PawnInterface_NoRegister();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_PawnMovementInterface();
AURORADEVS_UGC_API UClass* Z_Construct_UClass_UUGC_PawnMovementInterface_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
UPackage* Z_Construct_UPackage__Script_AuroraDevs_UGC();
// End Cross Module References

// Begin Interface UUGC_PawnInterface Function GetMovementInput
struct UGC_PawnInterface_eventGetMovementInput_Parms
{
	FVector ReturnValue;

	/** Constructor, initializes return property only **/
	UGC_PawnInterface_eventGetMovementInput_Parms()
		: ReturnValue(ForceInit)
	{
	}
};
FVector IUGC_PawnInterface::GetMovementInput() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetMovementInput instead.");
	UGC_PawnInterface_eventGetMovementInput_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UUGC_PawnInterface_GetMovementInput = FName(TEXT("GetMovementInput"));
FVector IUGC_PawnInterface::Execute_GetMovementInput(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UUGC_PawnInterface::StaticClass()));
	UGC_PawnInterface_eventGetMovementInput_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UUGC_PawnInterface_GetMovementInput);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UUGC_PawnInterface_GetMovementInput_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Interface" },
		{ "Comment", "// Get the value of the movement input (usually WASD or the left thumbstick).\n" },
		{ "ModuleRelativePath", "Public/Pawn/UGC_PawnInterface.h" },
		{ "ToolTip", "Get the value of the movement input (usually WASD or the left thumbstick)." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_PawnInterface_GetMovementInput_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_PawnInterface_eventGetMovementInput_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_PawnInterface_GetMovementInput_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PawnInterface_GetMovementInput_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PawnInterface_GetMovementInput_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_PawnInterface_GetMovementInput_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_PawnInterface, nullptr, "GetMovementInput", nullptr, nullptr, Z_Construct_UFunction_UUGC_PawnInterface_GetMovementInput_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PawnInterface_GetMovementInput_Statics::PropPointers), sizeof(UGC_PawnInterface_eventGetMovementInput_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C820800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PawnInterface_GetMovementInput_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_PawnInterface_GetMovementInput_Statics::Function_MetaDataParams) };
static_assert(sizeof(UGC_PawnInterface_eventGetMovementInput_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_PawnInterface_GetMovementInput()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_PawnInterface_GetMovementInput_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Interface UUGC_PawnInterface Function GetMovementInput

// Begin Interface UUGC_PawnInterface Function GetRotationInput
struct UGC_PawnInterface_eventGetRotationInput_Parms
{
	FRotator ReturnValue;

	/** Constructor, initializes return property only **/
	UGC_PawnInterface_eventGetRotationInput_Parms()
		: ReturnValue(ForceInit)
	{
	}
};
FRotator IUGC_PawnInterface::GetRotationInput() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetRotationInput instead.");
	UGC_PawnInterface_eventGetRotationInput_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UUGC_PawnInterface_GetRotationInput = FName(TEXT("GetRotationInput"));
FRotator IUGC_PawnInterface::Execute_GetRotationInput(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UUGC_PawnInterface::StaticClass()));
	UGC_PawnInterface_eventGetRotationInput_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UUGC_PawnInterface_GetRotationInput);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UUGC_PawnInterface_GetRotationInput_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Camera Interface" },
		{ "Comment", "// Get the value of the camera rotation input (usually the right thumbstick or the mouse).\n" },
		{ "ModuleRelativePath", "Public/Pawn/UGC_PawnInterface.h" },
		{ "ToolTip", "Get the value of the camera rotation input (usually the right thumbstick or the mouse)." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_PawnInterface_GetRotationInput_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_PawnInterface_eventGetRotationInput_Parms, ReturnValue), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_PawnInterface_GetRotationInput_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PawnInterface_GetRotationInput_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PawnInterface_GetRotationInput_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_PawnInterface_GetRotationInput_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_PawnInterface, nullptr, "GetRotationInput", nullptr, nullptr, Z_Construct_UFunction_UUGC_PawnInterface_GetRotationInput_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PawnInterface_GetRotationInput_Statics::PropPointers), sizeof(UGC_PawnInterface_eventGetRotationInput_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C820800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PawnInterface_GetRotationInput_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_PawnInterface_GetRotationInput_Statics::Function_MetaDataParams) };
static_assert(sizeof(UGC_PawnInterface_eventGetRotationInput_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_PawnInterface_GetRotationInput()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_PawnInterface_GetRotationInput_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Interface UUGC_PawnInterface Function GetRotationInput

// Begin Interface UUGC_PawnInterface
void UUGC_PawnInterface::StaticRegisterNativesUUGC_PawnInterface()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUGC_PawnInterface);
UClass* Z_Construct_UClass_UUGC_PawnInterface_NoRegister()
{
	return UUGC_PawnInterface::StaticClass();
}
struct Z_Construct_UClass_UUGC_PawnInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pawn/UGC_PawnInterface.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UUGC_PawnInterface_GetMovementInput, "GetMovementInput" }, // 3110929998
		{ &Z_Construct_UFunction_UUGC_PawnInterface_GetRotationInput, "GetRotationInput" }, // 2903923111
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IUGC_PawnInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UUGC_PawnInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_AuroraDevs_UGC,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_PawnInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UUGC_PawnInterface_Statics::ClassParams = {
	&UUGC_PawnInterface::StaticClass,
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
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_PawnInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UUGC_PawnInterface_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UUGC_PawnInterface()
{
	if (!Z_Registration_Info_UClass_UUGC_PawnInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUGC_PawnInterface.OuterSingleton, Z_Construct_UClass_UUGC_PawnInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UUGC_PawnInterface.OuterSingleton;
}
template<> AURORADEVS_UGC_API UClass* StaticClass<UUGC_PawnInterface>()
{
	return UUGC_PawnInterface::StaticClass();
}
UUGC_PawnInterface::UUGC_PawnInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UUGC_PawnInterface);
UUGC_PawnInterface::~UUGC_PawnInterface() {}
// End Interface UUGC_PawnInterface

// Begin Interface UUGC_PawnMovementInterface Function GetOwnerVelocity
struct UGC_PawnMovementInterface_eventGetOwnerVelocity_Parms
{
	FVector ReturnValue;

	/** Constructor, initializes return property only **/
	UGC_PawnMovementInterface_eventGetOwnerVelocity_Parms()
		: ReturnValue(ForceInit)
	{
	}
};
FVector IUGC_PawnMovementInterface::GetOwnerVelocity() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetOwnerVelocity instead.");
	UGC_PawnMovementInterface_eventGetOwnerVelocity_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UUGC_PawnMovementInterface_GetOwnerVelocity = FName(TEXT("GetOwnerVelocity"));
FVector IUGC_PawnMovementInterface::Execute_GetOwnerVelocity(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UUGC_PawnMovementInterface::StaticClass()));
	UGC_PawnMovementInterface_eventGetOwnerVelocity_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UUGC_PawnMovementInterface_GetOwnerVelocity);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UUGC_PawnMovementInterface_GetOwnerVelocity_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Movement Interface" },
		{ "ModuleRelativePath", "Public/Pawn/UGC_PawnInterface.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGC_PawnMovementInterface_GetOwnerVelocity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGC_PawnMovementInterface_eventGetOwnerVelocity_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_PawnMovementInterface_GetOwnerVelocity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PawnMovementInterface_GetOwnerVelocity_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PawnMovementInterface_GetOwnerVelocity_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_PawnMovementInterface_GetOwnerVelocity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_PawnMovementInterface, nullptr, "GetOwnerVelocity", nullptr, nullptr, Z_Construct_UFunction_UUGC_PawnMovementInterface_GetOwnerVelocity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PawnMovementInterface_GetOwnerVelocity_Statics::PropPointers), sizeof(UGC_PawnMovementInterface_eventGetOwnerVelocity_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C820800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PawnMovementInterface_GetOwnerVelocity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_PawnMovementInterface_GetOwnerVelocity_Statics::Function_MetaDataParams) };
static_assert(sizeof(UGC_PawnMovementInterface_eventGetOwnerVelocity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_PawnMovementInterface_GetOwnerVelocity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_PawnMovementInterface_GetOwnerVelocity_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Interface UUGC_PawnMovementInterface Function GetOwnerVelocity

// Begin Interface UUGC_PawnMovementInterface Function IsOwnerFalling
struct UGC_PawnMovementInterface_eventIsOwnerFalling_Parms
{
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	UGC_PawnMovementInterface_eventIsOwnerFalling_Parms()
		: ReturnValue(false)
	{
	}
};
bool IUGC_PawnMovementInterface::IsOwnerFalling() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_IsOwnerFalling instead.");
	UGC_PawnMovementInterface_eventIsOwnerFalling_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UUGC_PawnMovementInterface_IsOwnerFalling = FName(TEXT("IsOwnerFalling"));
bool IUGC_PawnMovementInterface::Execute_IsOwnerFalling(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UUGC_PawnMovementInterface::StaticClass()));
	UGC_PawnMovementInterface_eventIsOwnerFalling_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UUGC_PawnMovementInterface_IsOwnerFalling);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerFalling_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Movement Interface" },
		{ "ModuleRelativePath", "Public/Pawn/UGC_PawnInterface.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerFalling_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((UGC_PawnMovementInterface_eventIsOwnerFalling_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerFalling_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGC_PawnMovementInterface_eventIsOwnerFalling_Parms), &Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerFalling_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerFalling_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerFalling_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerFalling_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerFalling_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_PawnMovementInterface, nullptr, "IsOwnerFalling", nullptr, nullptr, Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerFalling_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerFalling_Statics::PropPointers), sizeof(UGC_PawnMovementInterface_eventIsOwnerFalling_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerFalling_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerFalling_Statics::Function_MetaDataParams) };
static_assert(sizeof(UGC_PawnMovementInterface_eventIsOwnerFalling_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerFalling()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerFalling_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Interface UUGC_PawnMovementInterface Function IsOwnerFalling

// Begin Interface UUGC_PawnMovementInterface Function IsOwnerMovingOnGround
struct UGC_PawnMovementInterface_eventIsOwnerMovingOnGround_Parms
{
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	UGC_PawnMovementInterface_eventIsOwnerMovingOnGround_Parms()
		: ReturnValue(false)
	{
	}
};
bool IUGC_PawnMovementInterface::IsOwnerMovingOnGround() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_IsOwnerMovingOnGround instead.");
	UGC_PawnMovementInterface_eventIsOwnerMovingOnGround_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UUGC_PawnMovementInterface_IsOwnerMovingOnGround = FName(TEXT("IsOwnerMovingOnGround"));
bool IUGC_PawnMovementInterface::Execute_IsOwnerMovingOnGround(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UUGC_PawnMovementInterface::StaticClass()));
	UGC_PawnMovementInterface_eventIsOwnerMovingOnGround_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UUGC_PawnMovementInterface_IsOwnerMovingOnGround);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerMovingOnGround_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Movement Interface" },
		{ "ModuleRelativePath", "Public/Pawn/UGC_PawnInterface.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerMovingOnGround_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((UGC_PawnMovementInterface_eventIsOwnerMovingOnGround_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerMovingOnGround_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGC_PawnMovementInterface_eventIsOwnerMovingOnGround_Parms), &Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerMovingOnGround_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerMovingOnGround_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerMovingOnGround_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerMovingOnGround_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerMovingOnGround_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_PawnMovementInterface, nullptr, "IsOwnerMovingOnGround", nullptr, nullptr, Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerMovingOnGround_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerMovingOnGround_Statics::PropPointers), sizeof(UGC_PawnMovementInterface_eventIsOwnerMovingOnGround_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerMovingOnGround_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerMovingOnGround_Statics::Function_MetaDataParams) };
static_assert(sizeof(UGC_PawnMovementInterface_eventIsOwnerMovingOnGround_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerMovingOnGround()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerMovingOnGround_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Interface UUGC_PawnMovementInterface Function IsOwnerMovingOnGround

// Begin Interface UUGC_PawnMovementInterface Function IsOwnerStrafing
struct UGC_PawnMovementInterface_eventIsOwnerStrafing_Parms
{
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	UGC_PawnMovementInterface_eventIsOwnerStrafing_Parms()
		: ReturnValue(false)
	{
	}
};
bool IUGC_PawnMovementInterface::IsOwnerStrafing() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_IsOwnerStrafing instead.");
	UGC_PawnMovementInterface_eventIsOwnerStrafing_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UUGC_PawnMovementInterface_IsOwnerStrafing = FName(TEXT("IsOwnerStrafing"));
bool IUGC_PawnMovementInterface::Execute_IsOwnerStrafing(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UUGC_PawnMovementInterface::StaticClass()));
	UGC_PawnMovementInterface_eventIsOwnerStrafing_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UUGC_PawnMovementInterface_IsOwnerStrafing);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerStrafing_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UGC|Movement Interface" },
		{ "ModuleRelativePath", "Public/Pawn/UGC_PawnInterface.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerStrafing_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((UGC_PawnMovementInterface_eventIsOwnerStrafing_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerStrafing_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGC_PawnMovementInterface_eventIsOwnerStrafing_Parms), &Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerStrafing_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerStrafing_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerStrafing_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerStrafing_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerStrafing_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUGC_PawnMovementInterface, nullptr, "IsOwnerStrafing", nullptr, nullptr, Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerStrafing_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerStrafing_Statics::PropPointers), sizeof(UGC_PawnMovementInterface_eventIsOwnerStrafing_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerStrafing_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerStrafing_Statics::Function_MetaDataParams) };
static_assert(sizeof(UGC_PawnMovementInterface_eventIsOwnerStrafing_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerStrafing()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerStrafing_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Interface UUGC_PawnMovementInterface Function IsOwnerStrafing

// Begin Interface UUGC_PawnMovementInterface
void UUGC_PawnMovementInterface::StaticRegisterNativesUUGC_PawnMovementInterface()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUGC_PawnMovementInterface);
UClass* Z_Construct_UClass_UUGC_PawnMovementInterface_NoRegister()
{
	return UUGC_PawnMovementInterface::StaticClass();
}
struct Z_Construct_UClass_UUGC_PawnMovementInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pawn/UGC_PawnInterface.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UUGC_PawnMovementInterface_GetOwnerVelocity, "GetOwnerVelocity" }, // 405801052
		{ &Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerFalling, "IsOwnerFalling" }, // 3763486129
		{ &Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerMovingOnGround, "IsOwnerMovingOnGround" }, // 1020625389
		{ &Z_Construct_UFunction_UUGC_PawnMovementInterface_IsOwnerStrafing, "IsOwnerStrafing" }, // 2431829465
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IUGC_PawnMovementInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UUGC_PawnMovementInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_AuroraDevs_UGC,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_PawnMovementInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UUGC_PawnMovementInterface_Statics::ClassParams = {
	&UUGC_PawnMovementInterface::StaticClass,
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
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUGC_PawnMovementInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UUGC_PawnMovementInterface_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UUGC_PawnMovementInterface()
{
	if (!Z_Registration_Info_UClass_UUGC_PawnMovementInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUGC_PawnMovementInterface.OuterSingleton, Z_Construct_UClass_UUGC_PawnMovementInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UUGC_PawnMovementInterface.OuterSingleton;
}
template<> AURORADEVS_UGC_API UClass* StaticClass<UUGC_PawnMovementInterface>()
{
	return UUGC_PawnMovementInterface::StaticClass();
}
UUGC_PawnMovementInterface::UUGC_PawnMovementInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UUGC_PawnMovementInterface);
UUGC_PawnMovementInterface::~UUGC_PawnMovementInterface() {}
// End Interface UUGC_PawnMovementInterface

// Begin Registration
struct Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UUGC_PawnInterface, UUGC_PawnInterface::StaticClass, TEXT("UUGC_PawnInterface"), &Z_Registration_Info_UClass_UUGC_PawnInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUGC_PawnInterface), 3518816450U) },
		{ Z_Construct_UClass_UUGC_PawnMovementInterface, UUGC_PawnMovementInterface::StaticClass, TEXT("UUGC_PawnMovementInterface"), &Z_Registration_Info_UClass_UUGC_PawnMovementInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUGC_PawnMovementInterface), 971378509U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_1840846015(TEXT("/Script/AuroraDevs_UGC"),
	Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AuroraDevs_UGC_Source_AuroraDevs_UGC_Public_Pawn_UGC_PawnInterface_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
