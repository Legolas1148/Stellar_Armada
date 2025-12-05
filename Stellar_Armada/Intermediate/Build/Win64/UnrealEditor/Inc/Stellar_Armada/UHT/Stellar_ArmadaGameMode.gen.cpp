// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Stellar_ArmadaGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeStellar_ArmadaGameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
STELLAR_ARMADA_API UClass* Z_Construct_UClass_AStellar_ArmadaGameMode();
STELLAR_ARMADA_API UClass* Z_Construct_UClass_AStellar_ArmadaGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_Stellar_Armada();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AStellar_ArmadaGameMode **************************************************
void AStellar_ArmadaGameMode::StaticRegisterNativesAStellar_ArmadaGameMode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_AStellar_ArmadaGameMode;
UClass* AStellar_ArmadaGameMode::GetPrivateStaticClass()
{
	using TClass = AStellar_ArmadaGameMode;
	if (!Z_Registration_Info_UClass_AStellar_ArmadaGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("Stellar_ArmadaGameMode"),
			Z_Registration_Info_UClass_AStellar_ArmadaGameMode.InnerSingleton,
			StaticRegisterNativesAStellar_ArmadaGameMode,
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
	return Z_Registration_Info_UClass_AStellar_ArmadaGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_AStellar_ArmadaGameMode_NoRegister()
{
	return AStellar_ArmadaGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AStellar_ArmadaGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple Game Mode for a top-down perspective game\n *  Sets the default gameplay framework classes\n *  Check the Blueprint derived class for the set values\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Stellar_ArmadaGameMode.h" },
		{ "ModuleRelativePath", "Stellar_ArmadaGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple Game Mode for a top-down perspective game\nSets the default gameplay framework classes\nCheck the Blueprint derived class for the set values" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStellar_ArmadaGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AStellar_ArmadaGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Stellar_Armada,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AStellar_ArmadaGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AStellar_ArmadaGameMode_Statics::ClassParams = {
	&AStellar_ArmadaGameMode::StaticClass,
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
	0x008003ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AStellar_ArmadaGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AStellar_ArmadaGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AStellar_ArmadaGameMode()
{
	if (!Z_Registration_Info_UClass_AStellar_ArmadaGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AStellar_ArmadaGameMode.OuterSingleton, Z_Construct_UClass_AStellar_ArmadaGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AStellar_ArmadaGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AStellar_ArmadaGameMode);
AStellar_ArmadaGameMode::~AStellar_ArmadaGameMode() {}
// ********** End Class AStellar_ArmadaGameMode ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_Stellar_ArmadaGameMode_h__Script_Stellar_Armada_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AStellar_ArmadaGameMode, AStellar_ArmadaGameMode::StaticClass, TEXT("AStellar_ArmadaGameMode"), &Z_Registration_Info_UClass_AStellar_ArmadaGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AStellar_ArmadaGameMode), 859249407U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_Stellar_ArmadaGameMode_h__Script_Stellar_Armada_1974791123(TEXT("/Script/Stellar_Armada"),
	Z_CompiledInDeferFile_FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_Stellar_ArmadaGameMode_h__Script_Stellar_Armada_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_Stellar_ArmadaGameMode_h__Script_Stellar_Armada_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
