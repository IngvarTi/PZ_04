// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTriggerActor.h"


// Sets default values
AMyTriggerActor::AMyTriggerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerZone = CreateDefaultSubobject<UBoxComponent>("RootTrigger");
}

void AMyTriggerActor::NotifyActorBeginOverlap(AActor * OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, *(OtherActor->GetName()));
	AGameModeBase* StartGameMode = GetWorld()->GetAuthGameMode();
	APZ_04GameMode* MyGameMode = Cast<APZ_04GameMode>(StartGameMode);
	if (MyGameMode)
	{
		MyGameMode->MyTrafficWaalDelegate.ExecuteIfBound();
		MyGameMode->MyDelegate.ExecuteIfBound();
		MyGameMode->MyParamDelegateRed.ExecuteIfBound();
		MyGameMode->MyParamDelegateGreen.ExecuteIfBound();
		MyGameMode->MyParamDelegate.ExecuteIfBound();
	}
}

void AMyTriggerActor::NotifyActorEndOverlap(AActor * OtherActor)
{
}

// Called when the game starts or when spawned
void AMyTriggerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTriggerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

