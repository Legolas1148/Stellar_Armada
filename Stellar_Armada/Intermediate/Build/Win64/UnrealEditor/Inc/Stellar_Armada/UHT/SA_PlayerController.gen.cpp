// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SA_PlayerController.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeSA_PlayerController() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
STELLAR_ARMADA_API UClass* Z_Construct_UClass_ASA_PlayerController();
STELLAR_ARMADA_API UClass* Z_Construct_UClass_ASA_PlayerController_NoRegister();
UPackage* Z_Construct_UPackage__Script_Stellar_Armada();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ASA_PlayerController Function BP_OnDeselected ****************************
struct SA_PlayerController_eventBP_OnDeselected_Parms
{
	AActor* Actor;
};
static FName NAME_ASA_PlayerController_BP_OnDeselected = FName(TEXT("BP_OnDeselected"));
void ASA_PlayerController::BP_OnDeselected(AActor* Actor)
{
	SA_PlayerController_eventBP_OnDeselected_Parms Parms;
	Parms.Actor=Actor;
	UFunction* Func = FindFunctionChecked(NAME_ASA_PlayerController_BP_OnDeselected);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ASA_PlayerController_BP_OnDeselected_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stellar Armada|Selection" },
		{ "ModuleRelativePath", "SA_PlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASA_PlayerController_BP_OnDeselected_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SA_PlayerController_eventBP_OnDeselected_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASA_PlayerController_BP_OnDeselected_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASA_PlayerController_BP_OnDeselected_Statics::NewProp_Actor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASA_PlayerController_BP_OnDeselected_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASA_PlayerController_BP_OnDeselected_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASA_PlayerController, nullptr, "BP_OnDeselected", Z_Construct_UFunction_ASA_PlayerController_BP_OnDeselected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASA_PlayerController_BP_OnDeselected_Statics::PropPointers), sizeof(SA_PlayerController_eventBP_OnDeselected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASA_PlayerController_BP_OnDeselected_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASA_PlayerController_BP_OnDeselected_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(SA_PlayerController_eventBP_OnDeselected_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASA_PlayerController_BP_OnDeselected()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASA_PlayerController_BP_OnDeselected_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ASA_PlayerController Function BP_OnDeselected ******************************

// ********** Begin Class ASA_PlayerController Function BP_OnSelected ******************************
struct SA_PlayerController_eventBP_OnSelected_Parms
{
	AActor* Actor;
};
static FName NAME_ASA_PlayerController_BP_OnSelected = FName(TEXT("BP_OnSelected"));
void ASA_PlayerController::BP_OnSelected(AActor* Actor)
{
	SA_PlayerController_eventBP_OnSelected_Parms Parms;
	Parms.Actor=Actor;
	UFunction* Func = FindFunctionChecked(NAME_ASA_PlayerController_BP_OnSelected);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ASA_PlayerController_BP_OnSelected_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stellar Armada|Selection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Lets your Blueprint add visuals like highlight rings\n" },
#endif
		{ "ModuleRelativePath", "SA_PlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lets your Blueprint add visuals like highlight rings" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASA_PlayerController_BP_OnSelected_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SA_PlayerController_eventBP_OnSelected_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASA_PlayerController_BP_OnSelected_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASA_PlayerController_BP_OnSelected_Statics::NewProp_Actor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASA_PlayerController_BP_OnSelected_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASA_PlayerController_BP_OnSelected_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASA_PlayerController, nullptr, "BP_OnSelected", Z_Construct_UFunction_ASA_PlayerController_BP_OnSelected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASA_PlayerController_BP_OnSelected_Statics::PropPointers), sizeof(SA_PlayerController_eventBP_OnSelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASA_PlayerController_BP_OnSelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASA_PlayerController_BP_OnSelected_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(SA_PlayerController_eventBP_OnSelected_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASA_PlayerController_BP_OnSelected()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASA_PlayerController_BP_OnSelected_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ASA_PlayerController Function BP_OnSelected ********************************

// ********** Begin Class ASA_PlayerController Function HandleLeftClick ****************************
struct Z_Construct_UFunction_ASA_PlayerController_HandleLeftClick_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SA_PlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASA_PlayerController_HandleLeftClick_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASA_PlayerController, nullptr, "HandleLeftClick", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASA_PlayerController_HandleLeftClick_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASA_PlayerController_HandleLeftClick_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ASA_PlayerController_HandleLeftClick()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASA_PlayerController_HandleLeftClick_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASA_PlayerController::execHandleLeftClick)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleLeftClick();
	P_NATIVE_END;
}
// ********** End Class ASA_PlayerController Function HandleLeftClick ******************************

// ********** Begin Class ASA_PlayerController *****************************************************
void ASA_PlayerController::StaticRegisterNativesASA_PlayerController()
{
	UClass* Class = ASA_PlayerController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "HandleLeftClick", &ASA_PlayerController::execHandleLeftClick },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ASA_PlayerController;
UClass* ASA_PlayerController::GetPrivateStaticClass()
{
	using TClass = ASA_PlayerController;
	if (!Z_Registration_Info_UClass_ASA_PlayerController.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("SA_PlayerController"),
			Z_Registration_Info_UClass_ASA_PlayerController.InnerSingleton,
			StaticRegisterNativesASA_PlayerController,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ASA_PlayerController.InnerSingleton;
}
UClass* Z_Construct_UClass_ASA_PlayerController_NoRegister()
{
	return ASA_PlayerController::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ASA_PlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "SA_PlayerController.h" },
		{ "ModuleRelativePath", "SA_PlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedActor_MetaData[] = {
		{ "Category", "Stellar Armada|Selection" },
		{ "ModuleRelativePath", "SA_PlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ASA_PlayerController_BP_OnDeselected, "BP_OnDeselected" }, // 1890572184
		{ &Z_Construct_UFunction_ASA_PlayerController_BP_OnSelected, "BP_OnSelected" }, // 2481713159
		{ &Z_Construct_UFunction_ASA_PlayerController_HandleLeftClick, "HandleLeftClick" }, // 2485791107
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASA_PlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASA_PlayerController_Statics::NewProp_SelectedActor = { "SelectedActor", nullptr, (EPropertyFlags)0x0124080000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASA_PlayerController, SelectedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedActor_MetaData), NewProp_SelectedActor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASA_PlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASA_PlayerController_Statics::NewProp_SelectedActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASA_PlayerController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ASA_PlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_Stellar_Armada,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASA_PlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASA_PlayerController_Statics::ClassParams = {
	&ASA_PlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ASA_PlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ASA_PlayerController_Statics::PropPointers),
	0,
	0x008003A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASA_PlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_ASA_PlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASA_PlayerController()
{
	if (!Z_Registration_Info_UClass_ASA_PlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASA_PlayerController.OuterSingleton, Z_Construct_UClass_ASA_PlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASA_PlayerController.OuterSingleton;
}
ASA_PlayerController::ASA_PlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASA_PlayerController);
ASA_PlayerController::~ASA_PlayerController() {}
// ********** End Class ASA_PlayerController *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_SA_PlayerController_h__Script_Stellar_Armada_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASA_PlayerController, ASA_PlayerController::StaticClass, TEXT("ASA_PlayerController"), &Z_Registration_Info_UClass_ASA_PlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASA_PlayerController), 3966197651U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_SA_PlayerController_h__Script_Stellar_Armada_1019358921(TEXT("/Script/Stellar_Armada"),
	Z_CompiledInDeferFile_FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_SA_PlayerController_h__Script_Stellar_Armada_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_SA_PlayerController_h__Script_Stellar_Armada_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
