// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BPixel/Zombie.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZombie() {}

// Begin Cross Module References
BPIXEL_API UClass* Z_Construct_UClass_AZombie();
BPIXEL_API UClass* Z_Construct_UClass_AZombie_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_BPixel();
// End Cross Module References

// Begin Class AZombie
void AZombie::StaticRegisterNativesAZombie()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AZombie);
UClass* Z_Construct_UClass_AZombie_NoRegister()
{
	return AZombie::StaticClass();
}
struct Z_Construct_UClass_AZombie_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Zombie.h" },
		{ "ModuleRelativePath", "Zombie.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZombie>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AZombie_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BPixel,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AZombie_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AZombie_Statics::ClassParams = {
	&AZombie::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AZombie_Statics::Class_MetaDataParams), Z_Construct_UClass_AZombie_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AZombie()
{
	if (!Z_Registration_Info_UClass_AZombie.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AZombie.OuterSingleton, Z_Construct_UClass_AZombie_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AZombie.OuterSingleton;
}
template<> BPIXEL_API UClass* StaticClass<AZombie>()
{
	return AZombie::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AZombie);
AZombie::~AZombie() {}
// End Class AZombie

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Javier_Documents_Unreal_Projects_BP_BPixel_Source_BPixel_Zombie_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AZombie, AZombie::StaticClass, TEXT("AZombie"), &Z_Registration_Info_UClass_AZombie, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZombie), 3274477060U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Javier_Documents_Unreal_Projects_BP_BPixel_Source_BPixel_Zombie_h_1492986670(TEXT("/Script/BPixel"),
	Z_CompiledInDeferFile_FID_Users_Javier_Documents_Unreal_Projects_BP_BPixel_Source_BPixel_Zombie_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Javier_Documents_Unreal_Projects_BP_BPixel_Source_BPixel_Zombie_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
