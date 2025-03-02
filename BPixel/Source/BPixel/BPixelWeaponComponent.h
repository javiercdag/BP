// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "BPixelWeaponComponent.generated.h"

class ABPixelCharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWeaponReloadStarted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWeaponReloadEnded);

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BPIXEL_API UBPixelWeaponComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(Category="WeaponStats", EditAnywhere, BlueprintReadWrite)
	float Damage = 1.f;

	UPROPERTY(Category="WeaponStats", EditAnywhere, BlueprintReadWrite)
	float FireRate = 700.f;

	UPROPERTY(Category="WeaponStats", EditAnywhere, BlueprintReadWrite)
	float ReloadSeconds = 4.f;

	UPROPERTY(Category="WeaponStats", EditAnywhere, BlueprintReadWrite)
	int MaxMagazineSize = 31;

	UPROPERTY(Category="WeaponStats", EditAnywhere, BlueprintReadWrite)
	float Range = 400000.f;
	
	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category=Projectile)
	TSubclassOf<class ABPixelProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	USoundBase* FireSound;
	
	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UAnimMontage* FireAnimation;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector MuzzleOffset;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputMappingContext* FireMappingContext;

	/** Fire Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* FireAction;
	
	UPROPERTY(VisibleAnywhere, BlueprintAssignable, Category = Channels)
	FOnWeaponReloadStarted WeaponReloadStarted;

	UPROPERTY(VisibleAnywhere, BlueprintAssignable, Category = Channels)
	FOnWeaponReloadEnded WeaponReloadEnded;

	/** Sets default values for this component's properties */
	UBPixelWeaponComponent();
	
	/** Make the weapon Fire a Projectile */
	UFUNCTION(BlueprintCallable, Category="Weapon")
	void Fire();
	void EndFire();
	void FireSingleShot();
	void Reload();

protected:
	virtual void BeginPlay() override;
	
	/** Ends gameplay for this component. */
	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	/** Fire Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	int BulletsLeftInMagazine;

private:
	/** The Character holding this weapon*/
	ABPixelCharacter* Character;

	APlayerController* PlayerController;
	FTimerHandle AutoFireHandle;
	FTimerHandle ReloadHandle;
	FTimerHandle AttachWeaponHandle;

	bool AttachWeapon(ABPixelCharacter* TargetCharacter);
	void AttachWeaponPlayerDelayed();
};
