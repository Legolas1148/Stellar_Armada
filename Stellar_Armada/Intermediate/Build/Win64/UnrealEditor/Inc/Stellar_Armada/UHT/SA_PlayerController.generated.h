// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SA_PlayerController.h"

#ifdef STELLAR_ARMADA_SA_PlayerController_generated_h
#error "SA_PlayerController.generated.h already included, missing '#pragma once' in SA_PlayerController.h"
#endif
#define STELLAR_ARMADA_SA_PlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;

// ********** Begin Class ASA_PlayerController *****************************************************
#define FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_SA_PlayerController_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleLeftClick);


#define FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_SA_PlayerController_h_10_CALLBACK_WRAPPERS
STELLAR_ARMADA_API UClass* Z_Construct_UClass_ASA_PlayerController_NoRegister();

#define FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_SA_PlayerController_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASA_PlayerController(); \
	friend struct Z_Construct_UClass_ASA_PlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend STELLAR_ARMADA_API UClass* Z_Construct_UClass_ASA_PlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(ASA_PlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Stellar_Armada"), Z_Construct_UClass_ASA_PlayerController_NoRegister) \
	DECLARE_SERIALIZER(ASA_PlayerController)


#define FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_SA_PlayerController_h_10_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASA_PlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ASA_PlayerController(ASA_PlayerController&&) = delete; \
	ASA_PlayerController(const ASA_PlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASA_PlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASA_PlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASA_PlayerController) \
	NO_API virtual ~ASA_PlayerController();


#define FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_SA_PlayerController_h_7_PROLOG
#define FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_SA_PlayerController_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_SA_PlayerController_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_SA_PlayerController_h_10_CALLBACK_WRAPPERS \
	FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_SA_PlayerController_h_10_INCLASS_NO_PURE_DECLS \
	FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_SA_PlayerController_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ASA_PlayerController;

// ********** End Class ASA_PlayerController *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_Stellar_Armada_Stellar_Armada_Source_Stellar_Armada_SA_PlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
