// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FBSaveGameInstanceSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class FLYINGBLOCKS_API UFBSaveGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	void SaveGame();
	void LoadGame();
};
