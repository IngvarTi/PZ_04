// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameModeBase.h"
#include "PZ_04GameMode.generated.h"


DECLARE_DELEGATE(FMyStandartDelegate) // void Func();
//DECLARE_DELEGATE_OneParam(FMyStandartDelParam, FLinearColor)

UCLASS(minimalapi)
class APZ_04GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APZ_04GameMode();

	FMyStandartDelegate MyDelegate;
	FMyStandartDelegate MyParamDelegateGreen;
	FMyStandartDelegate MyParamDelegateRed;
	FMyStandartDelegate MyTrafficWaalDelegate;

	FMyStandartDelegate MyParamDelegate;

};



