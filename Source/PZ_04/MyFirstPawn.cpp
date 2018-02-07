// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFirstPawn.h"
#include "Camera/CameraComponent.h"


// Sets default values
AMyFirstPawn::AMyFirstPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	BaseVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseVisibleComponent"));
	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	OurCamera->SetupAttachment(RootComponent);
	MyMoveComponent = CreateDefaultSubobject<UMyPawnMovementComponent>(TEXT("MovementCopmonent"));
	OurCamera->SetRelativeLocation(FVector(-250, 0.0f, 300.0f));
	OurCamera->SetRelativeRotation(FRotator(-45.0, 0.0f, 0.0f));
	BaseVisibleComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyFirstPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyFirstPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*if (!Velocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (Velocity * DeltaTime);
		SetActorLocation(NewLocation);
	}*/
}

// Called to bind functionality to input
void AMyFirstPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveForward", this, &AMyFirstPawn::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyFirstPawn::MoveRight);
}

void AMyFirstPawn::MoveForward(float AxisValue)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::SanitizeFloat(AxisValue));

	if (MyMoveComponent && (MyMoveComponent->UpdatedComponent == RootComponent))
	{
		MyMoveComponent->AddInputVector(GetActorForwardVector() * AxisValue);
	}

	//Velocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
	//Velocity.X = AxisValue * 100.0f;
}

void AMyFirstPawn::MoveRight(float AxisValue)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::SanitizeFloat(AxisValue));

	if (MyMoveComponent && (MyMoveComponent->UpdatedComponent == RootComponent))
	{
		MyMoveComponent->AddInputVector(GetActorRightVector() * AxisValue);
	}

	//Velocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
	//Velocity.Y = AxisValue * 100.0f;

}

