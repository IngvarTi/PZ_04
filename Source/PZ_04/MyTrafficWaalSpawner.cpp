// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTrafficWaalSpawner.h"


// Sets default values
AMyTrafficWaalSpawner::AMyTrafficWaalSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnLocation = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = SpawnLocation;
	
}

// Called when the game starts or when spawned
void AMyTrafficWaalSpawner::BeginPlay()
{
	Super::BeginPlay();
	AGameModeBase* StartGameMode = GetWorld()->GetAuthGameMode();
	APZ_04GameMode* MyGameMode = Cast<APZ_04GameMode>(StartGameMode);
	if (MyGameMode)
	{
		MyGameMode->MyDelegate.BindUObject(this, &AMyTrafficWaalSpawner::OnTrafficWaal);
	}
}

// Called every frame
void AMyTrafficWaalSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTrafficWaalSpawner::SpawnWaal()
{
	UWorld* MyWorld = GetWorld();
	if (MyWorld)
	{
		CurrentPickup = MyWorld->SpawnActor<AMyTrafficLightWaal>(AMyTrafficLightWaal::StaticClass(), GetTransform());
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, "Spawn Wall");
		MyWorld->GetTimerManager().SetTimer(Timer, this, &AMyTrafficWaalSpawner::DestroyWaal, 5, false);
	}
}

void AMyTrafficWaalSpawner::OnTrafficWaal()
{
	UWorld* MyWorld = GetWorld();
	if (MyWorld)
	{
		MyWorld->GetTimerManager().SetTimer(Timer, this, &AMyTrafficWaalSpawner::SpawnWaal, 1, false);
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, "Waal spawn after 1 sec");
	}
}

void AMyTrafficWaalSpawner::DestroyWaal()
{
	UWorld* MyWorld = GetWorld();
	if (MyWorld)
	{
		CurrentPickup->Destroy();
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, "Destroy Wall");
	}
}

