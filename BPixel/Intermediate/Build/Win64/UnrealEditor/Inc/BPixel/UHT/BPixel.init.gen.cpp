// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBPixel_init() {}
	BPIXEL_API UFunction* Z_Construct_UDelegateFunction_BPixel_OnPickUp__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_BPixel;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_BPixel()
	{
		if (!Z_Registration_Info_UPackage__Script_BPixel.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_BPixel_OnPickUp__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/BPixel",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x245AA4E5,
				0x78CCA926,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_BPixel.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_BPixel.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_BPixel(Z_Construct_UPackage__Script_BPixel, TEXT("/Script/BPixel"), Z_Registration_Info_UPackage__Script_BPixel, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x245AA4E5, 0x78CCA926));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
