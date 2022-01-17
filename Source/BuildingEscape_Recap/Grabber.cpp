// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/ActorComponent.h"
#include "DrawDebugHelpers.h"
#include "Grabber.h"

#define OUT
// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("Vrode Rabotaet"));

	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (!PhysicsHandle)
	{
		FString MissingComponent = GetOwner()->GetName();
		UE_LOG(LogTemp, Error, TEXT("there is no physHandle On: %s"), *MissingComponent);
	}
	else
	{
		//something
	}
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	FVector LineTraceDirection;
	FVector LineTraceEnd;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);
	
	LineTraceDirection = PlayerViewPointRotation.Vector();
	
	LineTraceEnd = PlayerViewPointLocation + LineTraceDirection * Reach;
	/*
	UE_LOG(LogTemp, Warning, TEXT("Begin: %s End: %s "),
		*LineTraceDirection.ToString(),
		*LineTraceEnd.ToString()
	);
	*/

	//Нарисовать дебаг лазер
	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(0, 255, 0),
		false,
		0,
		0,
		5.f
	);

	FHitResult Hit;

	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);

	/*
	AActor* ActorThatHit = Hit.GetActor();
	if (ActorThatHit) {
		UE_LOG(LogTemp, Warning, TEXT("%s"), *(ActorThatHit->GetName()));
	}
	*/
}

