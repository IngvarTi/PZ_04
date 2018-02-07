// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "PZ_04GameMode.h"
#include "PZ_04Pawn.h"
#include "PZ_04Hud.h"

APZ_04GameMode::APZ_04GameMode()
{
	DefaultPawnClass = APZ_04Pawn::StaticClass();
	HUDClass = APZ_04Hud::StaticClass();
}
