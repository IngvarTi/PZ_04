// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTrafficLightWaal.h"
#include "PZ_04GameMode.h"
#include "MyTrafficWaalSpawner.generated.h"

UCLASS()
class PZ_04_API AMyTrafficWaalSpawner : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY()
	AMyTrafficLightWaal* CurrentPickup;

	UPROPERTY()
	USceneComponent* SpawnLocation;

	FTimerHandle Timer;
	// Sets default values for this actor's properties
	AMyTrafficWaalSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SpawnWaal();

	UFUNCTION()
	void OnTrafficWaal();

	UFUNCTION()
	void DestroyWaal();
	
};
