// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BPixelWeaponComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ABPixelCharacter;
#ifdef BPIXEL_BPixelWeaponComponent_generated_h
#error "BPixelWeaponComponent.generated.h already included, missing '#pragma once' in BPixelWeaponComponent.h"
#endif
#define BPIXEL_BPixelWeaponComponent_generated_h

#define FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_BPixelWeaponComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execEndPlay); \
	DECLARE_FUNCTION(execFire); \
	DECLARE_FUNCTION(execAttachWeapon);


#define FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_BPixelWeaponComponent_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBPixelWeaponComponent(); \
	friend struct Z_Construct_UClass_UBPixelWeaponComponent_Statics; \
public: \
	DECLARE_CLASS(UBPixelWeaponComponent, USkeletalMeshComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BPixel"), NO_API) \
	DECLARE_SERIALIZER(UBPixelWeaponComponent)


#define FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_BPixelWeaponComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UBPixelWeaponComponent(UBPixelWeaponComponent&&); \
	UBPixelWeaponComponent(const UBPixelWeaponComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBPixelWeaponComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBPixelWeaponComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UBPixelWeaponComponent) \
	NO_API virtual ~UBPixelWeaponComponent();


#define FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_BPixelWeaponComponent_h_11_PROLOG
#define FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_BPixelWeaponComponent_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_BPixelWeaponComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_BPixelWeaponComponent_h_14_INCLASS_NO_PURE_DECLS \
	FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_BPixelWeaponComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BPIXEL_API UClass* StaticClass<class UBPixelWeaponComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_BPixelWeaponComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
