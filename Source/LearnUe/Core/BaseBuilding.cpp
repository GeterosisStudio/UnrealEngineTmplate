// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseBuilding.h"
#include "BaseUnitConfig.h"
#include "Misc/OutputDeviceNull.h"
#include "UObject/UnrealType.h"
#include "UObject/UnrealTypePrivate.h"

class ABaseUnit;

// Sets default values
ABaseBuilding::ABaseBuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMeshComp"));
	BaseMesh->SetupAttachment(RootComp);

	BaseSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("BaseSpawnPoint"));
	BaseSpawnPoint->SetupAttachment(RootComp);

	BaseSpawnPointArrow = CreateDefaultSubobject<UArrowComponent>("Arrow");
	BaseSpawnPointArrow->SetupAttachment(BaseSpawnPoint);

}

// Called when the game starts or when spawned
void ABaseBuilding::BeginPlay()
{
	if(UnitConfig)
		CurrentUnitConfig = NewObject<UBaseUnitConfig>(this, UnitConfig);

	FFloatProperty* FloatProp = FindFProperty<FFloatProperty>(this->GetClass(), TEXT("NewVar_s"));
	if (FloatProp != nullptr)
	{
		float FloatValue = FloatProp->GetPropertyValue_InContainer(this);
		UE_LOG(LogTemp, Warning, TEXT("Float: %S"), FloatValue);
	}
	Super::BeginPlay();
}

// Called every frame
void ABaseBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

 ABaseUnit* ABaseBuilding::Create_Unit(UBaseUnitConfig* config)
{
	 UWorld* CurrentWorld = config->GetWorld();
	 ABaseUnit* Unit = Cast<ABaseUnit>(CurrentWorld->SpawnActor(config->UnitClass));
	 Unit->Init(config->Health, config->Armor, config->Damage);
	 return Unit;
}

 void ABaseBuilding::SpawnUnit()
{
	 ABaseUnit* SpawnUnit = ABaseBuilding::Create_Unit(CurrentUnitConfig);
	 SpawnUnit->SetActorLocation(BaseSpawnPoint->GetComponentLocation());
	 SpawnUnit->SetActorRotation(BaseSpawnPoint->GetComponentRotation());
	 OnSpawnUnitChanged.Broadcast(SpawnUnit);
}
