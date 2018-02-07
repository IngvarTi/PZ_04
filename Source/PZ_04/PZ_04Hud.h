// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/HUD.h"
#include "PZ_04Hud.generated.h"


UCLASS(config = Game)
class APZ_04Hud : public AHUD
{
	GENERATED_BODY()

public:
	APZ_04Hud();

	/** Font used to render the vehicle info */
	UPROPERTY()
	UFont* HUDFont;

	// Begin AHUD interface
	virtual void DrawHUD() override;
	// End AHUD interface
};
