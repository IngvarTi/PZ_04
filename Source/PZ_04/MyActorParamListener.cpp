// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActorParamListener.h"


// Sets default values
AMyActorParamListener::AMyActorParamListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = PointLight;
	PointLight->SetVisibility(false);
	PointLight->SetLightColor(FLinearColor(1, 1, 0, 1));
}

// Called when the game starts or when spawned
void AMyActorParamListener::BeginPlay()
{
	Super::BeginPlay();
	AGameModeBase* StartGameMode = GetWorld()->GetAuthGameMode();
	APZ_04GameMode* MyGameMode = Cast<APZ_04GameMode>(StartGameMode);
	if (MyGameMode)
	{
		MyGameMode->MyParamDelegate.BindUObject(this, &AMyActorParamListener::EnableLightColorChange);
	}
}

// Called every frame
void AMyActorParamListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActorParamListener::EnableLightColorChange()
{
	PointLight->SetVisibility(true);
	UWorld* MyWorld = GetWorld();
	if (MyWorld)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, "Yelow Turn ON");
		MyWorld->GetTimerManager().SetTimer(Timer, this, &AMyActorParamListener::DisableLightToFourSecond, 1, false);
	}
}

void AMyActorParamListener::DisableLight()
{
	PointLight->SetVisibility(false);
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, "Yelow Turn OF");
}

void AMyActorParamListener::DisableLightToFourSecond()
{
	PointLight->SetVisibility(false);
	UWorld* MyWorld = GetWorld();
	if (MyWorld)
	{
		MyWorld->GetTimerManager().SetTimer(Timer, this, &AMyActorParamListener::EnableLightToOneSecond, 4, false);
	}
}


void AMyActorParamListener::EnableLightToOneSecond()
{
	PointLight->SetVisibility(true);
	UWorld* MyWorld = GetWorld();
	if (MyWorld)
	{
		MyWorld->GetTimerManager().SetTimer(Timer, this, &AMyActorParamListener::DisableLight, 1, false);
	}
}
