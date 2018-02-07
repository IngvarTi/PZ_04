// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawnMovementComponent.h"
#include "MyFirstPawn.generated.h"

UCLASS()
class PZ_04_API AMyFirstPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyFirstPawn();

	UPROPERTY(EditAnywhere)
	USceneComponent* BaseVisibleComponent;

	UPROPERTY()
	UMyPawnMovementComponent* MyMoveComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FVector Velocity;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

};
