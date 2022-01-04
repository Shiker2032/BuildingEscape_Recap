// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;	
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();		
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	
	if ((PressurePlate) && (PressurePlate->IsOverlappingActor(ActorThatOpens))) {
		OpenDoor(DeltaTime);
		DoorLastOpened = GetWorld()->GetTimeSeconds();
		
	}
	else if (DoorLastOpened + CloseDelay < GetWorld()->GetTimeSeconds()) {
		CloseDoor(DeltaTime);
	}
}

void UOpenDoor::OpenDoor(float DeltaTime)
{
	FRotator Rotation = GetOwner()->GetActorRotation();
	CurrentYaw = FMath::Lerp(CurrentYaw, TargetYaw, DeltaTime * 1.f);
	Rotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(Rotation);
}

void UOpenDoor::CloseDoor(float DeltaTime)
{
	FRotator Rotation = GetOwner()->GetActorRotation();
	CurrentYaw = FMath::Lerp(CurrentYaw, InitialYaw, DeltaTime * 1.f);
	Rotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(Rotation);
}
