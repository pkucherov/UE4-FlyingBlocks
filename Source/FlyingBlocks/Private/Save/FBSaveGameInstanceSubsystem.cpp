// Fill out your copyright notice in the Description page of Project Settings.
#include "Save/FBSaveGameInstanceSubsystem.h"

#include "FBGameMode.h"
#include "Blocks/BaseBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Save/BlocksSaveGame.h"

void UFBSaveGameInstanceSubsystem::SaveGame()
{
	if (!GetWorld() || !Cast<AFBGameMode>(GetWorld()->GetAuthGameMode())) return;

	const UWorld* World = GetWorld();
	AFBGameMode* gameMode = Cast<AFBGameMode>(World->GetAuthGameMode());

	TMap<FString, int>  MapBlockNamesToIndex;

	for (int i = 0; i < gameMode->BlockBPClasses.Num(); i++)
	{
		const auto& Block = gameMode->BlockBPClasses[i];
		const FString& BaseBlockName = Block->ClassDefaultObject->GetClass()->GetName();
		MapBlockNamesToIndex.Add(BaseBlockName, i);
	}

	UBlocksSaveGame* BlocksSaveGame = NewObject<UBlocksSaveGame>();

	// get all blocks
	TArray<AActor*> ActorsToFind;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseBlock::StaticClass(), ActorsToFind);

	for (AActor* Actor : ActorsToFind)
	{
		ABaseBlock* Block = Cast<ABaseBlock>(Actor);
		if (Block)
		{
			FString ClassName = Actor->GetClass()->GetName();

			const int* PtrIndex = MapBlockNamesToIndex.Find(ClassName);
			if (PtrIndex)
			{
				const int Index = *PtrIndex;
				FVector Location = Block->GetActorLocation();
				FBlockDTO BlockDTO(Index, Location);
				BlocksSaveGame->BlockDTOs.Add(BlockDTO);
			}
		}
	}

	// save
	const FString SlotName = "Default";
	bool bSaved = UGameplayStatics::SaveGameToSlot(BlocksSaveGame, SlotName, 0);
}


void UFBSaveGameInstanceSubsystem::LoadGame()
{
	if (!GetWorld() || !Cast<AFBGameMode>(GetWorld()->GetAuthGameMode())) return;

	UWorld* World = GetWorld();
	AFBGameMode* gameMode = Cast<AFBGameMode>(World->GetAuthGameMode());

	const FString SlotName = "Default";
	UBlocksSaveGame* BlocksSave = Cast<UBlocksSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));

	if (BlocksSave)
	{
		for (FBlockDTO BlockDTO : BlocksSave->BlockDTOs)
		{
			const int i = BlockDTO.BlockIndex;
			if (i >= 0 && i < gameMode->BlockBPClasses.Num())
			{
				const auto& Block = gameMode->BlockBPClasses[i];
				World->SpawnActor(Block->ClassDefaultObject->GetClass(), &BlockDTO.Location);
			}
		}
	}
}
