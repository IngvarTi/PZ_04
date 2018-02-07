// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActorListener.h"


// Sets default values
AMyActorListener::AMyActorListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = PointLight;
	PointLight->SetVisibility(false);
}

// Called when the game starts or when spawned
void AMyActorListener::BeginPlay()
{
	Super::BeginPlay();
	AGameModeBase* StartGameMode = GetWorld()->GetAuthGameMode();
	APZ_04GameMode* MyGameMode = Cast<APZ_04GameMode>(StartGameMode);
	if (MyGameMode)
	{
		MyGameMode->MyDelegate.BindUObject(this, &AMyActorListener::EnableLight);
	}
} 

// Called every frame
void AMyActorListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActorListener::EnableLight()
{
	
	UWorld* MyWorld = GetWorld();
	if (MyWorld)
	{
		PointLight->SetVisibility(true);
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, "Spawn Wall");
		MyWorld->GetTimerManager().SetTimer(Timer, this, &AMyActorListener::DisableLight, 5, false);
	}
		//PointLight->SetVisibility(true);
		//GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, "Spawn                        Wall");
		//MyWorld->GetTimerManager().SetTimer(Timer, this, &AMyActorListener::DisableLight, 1, false);
	
}

void AMyActorListener::DisableLight()
{
	PointLight->SetVisibility(false);
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, "Yelow Turn Of");
}

