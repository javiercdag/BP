// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BPixel/DamageReceiver.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDamageReceiver() {}

// Begin Cross Module References
BPIXEL_API UClass* Z_Construct_UClass_UDamageReceiver();
BPIXEL_API UClass* Z_Construct_UClass_UDamageReceiver_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_BPixel();
// End Cross Module References

// Begin Class UDamageReceiver
void UDamageReceiver::StaticRegisterNativesUDamageReceiver()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDamageReceiver);
UClass* Z_Construct_UClass_UDamageReceiver_NoRegister()
{
	return UDamageReceiver::StaticClass();
}
struct Z_Construct_UClass_UDamageReceiver_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "DamageReceiver.h" },
		{ "ModuleRelativePath", "DamageReceiver.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDamageReceiver>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDamageReceiver_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_BPixel,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDamageReceiver_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDamageReceiver_Statics::ClassParams = {
	&UDamageReceiver::StaticClass,
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
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDamageReceiver_Statics::Class_MetaDataParams), Z_Construct_UClass_UDamageReceiver_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDamageReceiver()
{
	if (!Z_Registration_Info_UClass_UDamageReceiver.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDamageReceiver.OuterSingleton, Z_Construct_UClass_UDamageReceiver_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDamageReceiver.OuterSingleton;
}
template<> BPIXEL_API UClass* StaticClass<UDamageReceiver>()
{
	return UDamageReceiver::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDamageReceiver);
UDamageReceiver::~UDamageReceiver() {}
// End Class UDamageReceiver

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_DamageReceiver_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDamageReceiver, UDamageReceiver::StaticClass, TEXT("UDamageReceiver"), &Z_Registration_Info_UClass_UDamageReceiver, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDamageReceiver), 206194756U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_DamageReceiver_h_1517220755(TEXT("/Script/BPixel"),
	Z_CompiledInDeferFile_FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_DamageReceiver_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Javier_Documents_Unreal_Projects_BPixel_Source_BPixel_DamageReceiver_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
