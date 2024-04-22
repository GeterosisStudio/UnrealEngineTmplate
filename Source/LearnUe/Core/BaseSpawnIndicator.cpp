// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSpawnIndicator.h"
#include "BaseBuilding.h"
#include "EngineUtils.h"


// Sets default values
ABaseSpawnIndicator::ABaseSpawnIndicator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);

	BaseIndicatorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMeshComp"));
	BaseIndicatorMesh->SetupAttachment(RootComp);

	SpawnHandler.BindUObject(this, &ABaseSpawnIndicator::OnUnitCreated);

}

// Called when the game starts or when spawned
void ABaseSpawnIndicator::BeginPlay()
{
	Super::BeginPlay();

	for(TActorIterator<AActor>Itr(GetWorld()); Itr; ++Itr)
	{
		if(Cast<ABaseBuilding>(*Itr))
		{
			ABaseBuilding* CurrentBarracs = Cast<ABaseBuilding>(*Itr);
			CurrentBarracs->OnSpawnUnit().Add(SpawnHandler);
		}
	}


	
}

// Called every frame
void ABaseSpawnIndicator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseSpawnIndicator::OnUnitCreated(ABaseUnit* Unit)
{
	UMaterialInstanceDynamic* Mat = UMaterialInstanceDynamic::Create(IndicatorMaterial, this);
	BaseIndicatorMesh->SetMaterial(0, Mat);
	UE_LOG(LogTemp, Warning, TEXT("Unit Name is: %S"), *Unit->GetName());
}