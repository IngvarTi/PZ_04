// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActorParamListenerGreen.h"


// Sets default values
AMyActorParamListenerGreen::AMyActorParamListenerGreen()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = PointLight;
	PointLight->SetVisibility(true);
	PointLight->SetLightColor(FLinearColor(0, 1, 0, 1));
}

// Called when the game starts or when spawned
void AMyActorParamListenerGreen::BeginPlay()
{
	Super::BeginPlay();
	AGameModeBase* StartGameMode = GetWorld()->GetAuthGameMode();
	APZ_04GameMode* MyGameMode = Cast<APZ_04GameMode>(StartGameMode);
	if (MyGameMode)
	{
		MyGameMode->MyParamDelegateGreen.BindUObject(this, &AMyActorParamListenerGreen::DisableLight);
	}
}

// Called every frame
void AMyActorParamListenerGreen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActorParamListenerGreen::DisableLight()
{
	PointLight->SetVisibility(false);
	UWorld* MyWorld = GetWorld();
	if (MyWorld)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, "Green Turn ON");
		MyWorld->GetTimerManager().SetTimer(Timer, this, &AMyActorParamListenerGreen::EnableLight, 6, false);
	}
}

void AMyActorParamListenerGreen::EnableLight()
{
	PointLight->SetVisibility(true);
}

//void AMyActorParamListenerGreen::ColorChange(FLinearColor ColorGreen)
//{
//	PointLight->SetLightColor(ColorGreen);
//}



