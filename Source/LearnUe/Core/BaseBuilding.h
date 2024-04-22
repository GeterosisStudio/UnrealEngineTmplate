// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/Classes/Components/ArrowComponent.h"
#include "BaseUnitConfig.h"
#include "BaseUnit.h"

#include "BaseBuilding.generated.h"



UCLASS()
class LEARNUE_API ABaseBuilding : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseBuilding();



	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere)
		USceneComponent* RootComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USceneComponent* BaseSpawnPoint;

	UPROPERTY(VisibleAnywhere)
		UArrowComponent* BaseSpawnPointArrow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UBaseUnitConfig> UnitConfig;

	static ABaseUnit* Create_Unit(UBaseUnitConfig* config);

	UFUNCTION(BlueprintCallable)
		void SpawnUnit();

	DECLARE_EVENT_OneParam(ABaseBuilding, FOnSpawnUnit, ABaseUnit*)
	FOnSpawnUnit& OnSpawnUnit()
	{
		return OnSpawnUnitChanged;
	}



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
		UBaseUnitConfig* CurrentUnitConfig;


	FOnSpawnUnit OnSpawnUnitChanged;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
