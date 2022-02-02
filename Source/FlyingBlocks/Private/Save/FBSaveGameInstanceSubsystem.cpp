// Fill out your copyright notice in the Description page of Project Settings.


#include "Save/FBSaveGameInstanceSubsystem.h"

#include "Blocks/BaseBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Save/BlocksSaveGame.h"

void UFBSaveGameInstanceSubsystem::SaveGame()
{
	UBlocksSaveGame* blocksDTO = NewObject<UBlocksSaveGame>();
	// get all blocks


	TArray<AActor*> ActorsToFind;
	if (UWorld* World = GetWorld())
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseBlock::StaticClass(), ActorsToFind);
	}
	for (AActor* block : ActorsToFind)
	{

	}


	// save
	FString SlotName = "Default";
	bool bSaved = UGameplayStatics::SaveGameToSlot(blocksDTO, SlotName, 0);
}

void UFBSaveGameInstanceSubsystem::LoadGame()
{

}
