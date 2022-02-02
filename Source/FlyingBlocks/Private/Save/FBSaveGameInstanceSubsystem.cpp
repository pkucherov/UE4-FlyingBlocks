// Fill out your copyright notice in the Description page of Project Settings.


#include "Save/FBSaveGameInstanceSubsystem.h"

#include "Kismet/GameplayStatics.h"
#include "Save/BlocksSaveGame.h"

void UFBSaveGameInstanceSubsystem::SaveGame()
{
	UBlocksSaveGame* blocksDTO = NewObject<UBlocksSaveGame>();
	// get all blocks

	// save
	FString SlotName = "Default";
	bool bSaved = UGameplayStatics::SaveGameToSlot(blocksDTO, SlotName, 0);
}

void UFBSaveGameInstanceSubsystem::LoadGame()
{

}
