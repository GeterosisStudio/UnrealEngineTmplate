// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseUnit.h"

// Sets default values
ABaseUnit::ABaseUnit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	BaseSkeletalComp = CreateDefaultSubobject < USkeletalMeshComponent>("BaseSkeletalMesh");
	SetRootComponent(BaseSkeletalComp);

}

// Called when the game starts or when spawned
void ABaseUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseUnit::Init(float _Health, float _Armor, float _Damage)
{
	Health = _Health;
	Armor = _Armor;
	Damage = _Damage;
}