// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BPixelPickUpComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class ABPixelCharacter;
class UPrimitiveComponent;
struct FHitResult;
#ifdef BPIXEL_BPixelPickUpComponent_generated_h
#error "BPixelPickUpComponent.generated.h already included, missing '#pragma once' in BPixelPickUpComponent.h"
#endif
#define BPIXEL_BPixelPickUpComponent_generated_h

#define FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_BPixelPickUpComponent_h_12_DELEGATE \
BPIXEL_API void FOnPickUp_DelegateWrapper(const FMulticastScriptDelegate& OnPickUp, ABPixelCharacter* PickUpCharacter);


#define FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_BPixelPickUpComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnSphereBeginOverlap);


#define FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_BPixelPickUpComponent_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBPixelPickUpComponent(); \
	friend struct Z_Construct_UClass_UBPixelPickUpComponent_Statics; \
public: \
	DECLARE_CLASS(UBPixelPickUpComponent, USphereComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BPixel"), NO_API) \
	DECLARE_SERIALIZER(UBPixelPickUpComponent)


#define FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_BPixelPickUpComponent_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UBPixelPickUpComponent(UBPixelPickUpComponent&&); \
	UBPixelPickUpComponent(const UBPixelPickUpComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBPixelPickUpComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBPixelPickUpComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UBPixelPickUpComponent) \
	NO_API virtual ~UBPixelPickUpComponent();


#define FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_BPixelPickUpComponent_h_14_PROLOG
#define FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_BPixelPickUpComponent_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_BPixelPickUpComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_BPixelPickUpComponent_h_17_INCLASS_NO_PURE_DECLS \
	FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_BPixelPickUpComponent_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BPIXEL_API UClass* StaticClass<class UBPixelPickUpComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_BPixelPickUpComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
