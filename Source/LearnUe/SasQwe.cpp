// Fill out your copyright notice in the Description page of Project Settings.


#include "SasQwe.h"
#include "UObject/UnrealType.h"

// Sets default values
ASasQwe::ASasQwe()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Called when the game starts or when spawned
void ASasQwe::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASasQwe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASasQwe::GetValue(float qwe)
{

	if (qwe != NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("X: %f"), qwe);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No X Propery!"));
	}
}
