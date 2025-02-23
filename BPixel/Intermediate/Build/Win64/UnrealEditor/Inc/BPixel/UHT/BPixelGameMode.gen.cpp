// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BPixel/BPixelGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBPixelGameMode() {}

// Begin Cross Module References
BPIXEL_API UClass* Z_Construct_UClass_ABPixelGameMode();
BPIXEL_API UClass* Z_Construct_UClass_ABPixelGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_BPixel();
// End Cross Module References

// Begin Class ABPixelGameMode
void ABPixelGameMode::StaticRegisterNativesABPixelGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABPixelGameMode);
UClass* Z_Construct_UClass_ABPixelGameMode_NoRegister()
{
	return ABPixelGameMode::StaticClass();
}
struct Z_Construct_UClass_ABPixelGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "BPixelGameMode.h" },
		{ "ModuleRelativePath", "BPixelGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABPixelGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABPixelGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_BPixel,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABPixelGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABPixelGameMode_Statics::ClassParams = {
	&ABPixelGameMode::StaticClass,
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
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABPixelGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ABPixelGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABPixelGameMode()
{
	if (!Z_Registration_Info_UClass_ABPixelGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABPixelGameMode.OuterSingleton, Z_Construct_UClass_ABPixelGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABPixelGameMode.OuterSingleton;
}
template<> BPIXEL_API UClass* StaticClass<ABPixelGameMode>()
{
	return ABPixelGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABPixelGameMode);
ABPixelGameMode::~ABPixelGameMode() {}
// End Class ABPixelGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Javier_Documents_Unreal_Projects_BP_BPixel_Source_BPixel_BPixelGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABPixelGameMode, ABPixelGameMode::StaticClass, TEXT("ABPixelGameMode"), &Z_Registration_Info_UClass_ABPixelGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABPixelGameMode), 2332311903U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Javier_Documents_Unreal_Projects_BP_BPixel_Source_BPixel_BPixelGameMode_h_1519788820(TEXT("/Script/BPixel"),
	Z_CompiledInDeferFile_FID_Users_Javier_Documents_Unreal_Projects_BP_BPixel_Source_BPixel_BPixelGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Javier_Documents_Unreal_Projects_BP_BPixel_Source_BPixel_BPixelGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
