// Fill out your copyright notice in the Description page of Project Settings.

#include "MyRedLightListener.h"


// Sets default values
AMyRedLightListener::AMyRedLightListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = PointLight;
	PointLight->SetVisibility(false);
	PointLight->SetLightColor(FLinearColor(1, 0, 0, 1));
}

// Called when the game starts or when spawned
void AMyRedLightListener::BeginPlay()
{
	Super::BeginPlay();
	AGameModeBase* StartGameMode = GetWorld()->GetAuthGameMode();
	APZ_04GameMode* MyGameMode = Cast<APZ_04GameMode>(StartGameMode);
	if (MyGameMode)
	{
		MyGameMode->MyParamDelegateRed.BindUObject(this, &AMyRedLightListener::EnableLight);
	}
}

// Called every frame
void AMyRedLightListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyRedLightListener::EnableLight()
{
	UWorld* MyWorld = GetWorld();
	if (MyWorld)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, "Red Turn ON after one second");
		MyWorld->GetTimerManager().SetTimer(Timer, this, &AMyRedLightListener::TurnOnLight, 1, false);
	}
}

void AMyRedLightListener::TurnOnLight()
{
	PointLight->SetVisibility(true);
	UWorld* MyWorld = GetWorld();
	if (MyWorld)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, "Red Turn ON");
		MyWorld->GetTimerManager().SetTimer(Timer, this, &AMyRedLightListener::DisableLight, 5, false);
	}
}

void AMyRedLightListener::DisableLight()
{
	PointLight->SetVisibility(false);
}

