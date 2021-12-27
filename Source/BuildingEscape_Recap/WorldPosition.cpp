// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPosition.h"

// Sets default values for this component's properties
UWorldPosition::UWorldPosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldPosition::BeginPlay()
{
	Super::BeginPlay();
	/*
	FString message = TEXT("Message");
	FString* messagePtr = &message;

	UE_LOG(LogTemp, Warning, TEXT("%s"), **messagePtr);

	FString ObjectName = GetOwner()->GetName()
	*/

	//Получить расположение объекта

	
	FString Owner = GetOwner()->GetName();
	FString Position = GetOwner()->GetActorLocation().ToString();

	UE_LOG(LogTemp, Warning, TEXT("i'm mighty %s, my position is %s"), *Owner, *Position);
}


// Called every frame
void UWorldPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

