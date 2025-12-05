// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStellar_Armada_init() {}
	STELLAR_ARMADA_API UFunction* Z_Construct_UDelegateFunction_Stellar_Armada_OnUnitMoveCompletedDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Stellar_Armada;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Stellar_Armada()
	{
		if (!Z_Registration_Info_UPackage__Script_Stellar_Armada.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_Stellar_Armada_OnUnitMoveCompletedDelegate__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Stellar_Armada",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x11B0EC48,
				0x8F7BB2B6,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Stellar_Armada.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Stellar_Armada.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Stellar_Armada(Z_Construct_UPackage__Script_Stellar_Armada, TEXT("/Script/Stellar_Armada"), Z_Registration_Info_UPackage__Script_Stellar_Armada, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x11B0EC48, 0x8F7BB2B6));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
