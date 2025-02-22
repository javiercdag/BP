// Copyright Epic Games, Inc. All Rights Reserved.

#include "BPixelProjectile.h"

#include "DamageReceiver.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"

class UDamageReceiver;

ABPixelProjectile::ABPixelProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(0.5f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &ABPixelProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 100000.f;
	ProjectileMovement->MaxSpeed = 100000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->ProjectileGravityScale = 0;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void ABPixelProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if (OtherActor && OtherActor != this)
	{
		if (UDamageReceiver* DamageReceiver = OtherActor->FindComponentByClass<UDamageReceiver>())
		{
			DamageReceiver->ApplyHitDamage(DamageAmount);
		}
		
		Destroy();
	}
}