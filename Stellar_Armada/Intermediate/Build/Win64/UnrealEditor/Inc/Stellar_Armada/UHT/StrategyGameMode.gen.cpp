// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "StrategyGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeStrategyGameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
STELLAR_ARMADA_API UClass* Z_Construct_UClass_AStrategyGameMode();
STELLAR_ARMADA_API UClass* Z_Construct_UClass_AStrategyGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_Stellar_Armada();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AStrategyGameMode ********************************************************
void AStrategyGameMode::StaticRegisterNativesAStrategyGameMode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_AStrategyGameMode;
UClass* AStrategyGameMode::GetPrivateStaticClass()
{
	using TClass = AStrategyGameMode;
	if (!Z_Registration_Info_UClass_AStrategyGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("StrategyGameMode"),
			Z_Registration_Info_UClass_AStrategyGameMode.InnerSingleton,
			StaticRegisterNativesAStrategyGameMode,
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
	return Z_Registration_Info_UClass_AStrategyGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_AStrategyGameMode_NoRegister()
{
	return AStrategyGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AStrategyGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple GameMode for a top down strategy game.\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Variant_Strategy/StrategyGameMode.h" },
		{ "ModuleRelativePath", "Variant_Strategy/StrategyGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple GameMode for a top down strategy game." },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStrategyGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AStrategyGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Stellar_Armada,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AStrategyGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AStrategyGameMode_Statics::ClassParams = {
	&AStrategyGameMode::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AStrategyGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AStrategyGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AStrategyGameMode()
{
	if (!Z_Registration_Info_UClass_AStrategyGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AStrategyGameMode.OuterSingleton, Z_Construct_UClass_AStrategyGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AStrategyGameMode.OuterSingleton;
}
AStrategyGameMode::AStrategyGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AStrategyGameMode);
AStrategyGameMode::~AStrategyGameMode() {}
// ********** End Class AStrategyGameMode **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_Variant_Strategy_StrategyGameMode_h__Script_Stellar_Armada_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AStrategyGameMode, AStrategyGameMode::StaticClass, TEXT("AStrategyGameMode"), &Z_Registration_Info_UClass_AStrategyGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AStrategyGameMode), 358339334U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_Variant_Strategy_StrategyGameMode_h__Script_Stellar_Armada_1292070435(TEXT("/Script/Stellar_Armada"),
	Z_CompiledInDeferFile_FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_Variant_Strategy_StrategyGameMode_h__Script_Stellar_Armada_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_Variant_Strategy_StrategyGameMode_h__Script_Stellar_Armada_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
