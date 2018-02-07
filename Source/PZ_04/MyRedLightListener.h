// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PZ_04GameMode.h"
#include "Components/PointLightComponent.h"
#include "MyRedLightListener.generated.h"

UCLASS()
class PZ_04_API AMyRedLightListener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyRedLightListener();

	UPROPERTY()
	UPointLightComponent* PointLight;

	FTimerHandle Timer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void EnableLight();

	UFUNCTION()
	void DisableLight();

	UFUNCTION()
	void TurnOnLight();
	
};
