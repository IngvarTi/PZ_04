// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PZ_04GameMode.h"
#include "Components/PointLightComponent.h"
#include "MyActorParamListener.generated.h"

UCLASS()
class PZ_04_API AMyActorParamListener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActorParamListener();

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
	void EnableLightColorChange();

	UFUNCTION()
	void DisableLight();

	UFUNCTION()
	void DisableLightToFourSecond();

	UFUNCTION()
	void EnableLightToOneSecond();

	
};
