// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BPixelProjectile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef BPIXEL_BPixelProjectile_generated_h
#error "BPixelProjectile.generated.h already included, missing '#pragma once' in BPixelProjectile.h"
#endif
#define BPIXEL_BPixelProjectile_generated_h

#define FID_Users_Javier_Documents_Unreal_Projects_BP_BPixel_Source_BPixel_BPixelProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnHit);


#define FID_Users_Javier_Documents_Unreal_Projects_BP_BPixel_Source_BPixel_BPixelProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABPixelProjectile(); \
	friend struct Z_Construct_UClass_ABPixelProjectile_Statics; \
public: \
	DECLARE_CLASS(ABPixelProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BPixel"), NO_API) \
	DECLARE_SERIALIZER(ABPixelProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_Users_Javier_Documents_Unreal_Projects_BP_BPixel_Source_BPixel_BPixelProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ABPixelProjectile(ABPixelProjectile&&); \
	ABPixelProjectile(const ABPixelProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABPixelProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABPixelProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABPixelProjectile) \
	NO_API virtual ~ABPixelProjectile();


#define FID_Users_Javier_Documents_Unreal_Projects_BP_BPixel_Source_BPixel_BPixelProjectile_h_12_PROLOG
#define FID_Users_Javier_Documents_Unreal_Projects_BP_BPixel_Source_BPixel_BPixelProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Javier_Documents_Unreal_Projects_BP_BPixel_Source_BPixel_BPixelProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Javier_Documents_Unreal_Projects_BP_BPixel_Source_BPixel_BPixelProjectile_h_15_INCLASS_NO_PURE_DECLS \
	FID_Users_Javier_Documents_Unreal_Projects_BP_BPixel_Source_BPixel_BPixelProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BPIXEL_API UClass* StaticClass<class ABPixelProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Javier_Documents_Unreal_Projects_BP_BPixel_Source_BPixel_BPixelProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
