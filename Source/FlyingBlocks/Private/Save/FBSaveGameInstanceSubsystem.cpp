// Fill out your copyright notice in the Description page of Project Settings.
#include "Save/FBSaveGameInstanceSubsystem.h"

#include "Blocks/BaseBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Save/BlocksSaveGame.h"

void UFBSaveGameInstanceSubsystem::SaveGame()
{
	UBlocksSaveGame* blocksSaveGame = NewObject<UBlocksSaveGame>();

	// get all blocks
	TArray<AActor*> ActorsToFind;
	if (UWorld* World = GetWorld())
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseBlock::StaticClass(), ActorsToFind);
	}

	for (AActor* actor : ActorsToFind)
	{
		ABaseBlock* block = Cast<ABaseBlock>(actor);
		if (block)
		{
			FVector location = block->GetActorLocation();
			FBlockDTO blockDTO(block->BlockType, location);
			blocksSaveGame->BlockDTOs.Add(blockDTO);
		}
	}
	
	// save
	FString SlotName = "Default";
	bool bSaved = UGameplayStatics::SaveGameToSlot(blocksSaveGame, SlotName, 0);
}

void UFBSaveGameInstanceSubsystem::LoadGame()
{
	if (UWorld* World = GetWorld())
	{
		FString SlotName = "Default";
		UBlocksSaveGame* blocksSave = Cast<UBlocksSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));

		if (blocksSave)
		{
			for (FBlockDTO blockDTO : blocksSave->BlockDTOs)
			{
				switch(blockDTO.BlockType)
				{
				case EBlockPosInAllBlocks::BaseBlock: break;
				case EBlockPosInAllBlocks::BrickBlock: break;
				case EBlockPosInAllBlocks::DirtBlock: break;
				case EBlockPosInAllBlocks::GrassBlock: break;
				case EBlockPosInAllBlocks::WoodBlock: break;
				case EBlockPosInAllBlocks::BlueBlock: break;
				case EBlockPosInAllBlocks::GoldBlock: break;
				case EBlockPosInAllBlocks::GreenBlock: break;
				case EBlockPosInAllBlocks::PurpleBlock: break;
				case EBlockPosInAllBlocks::RandomFlower: break;
				default: ;
				}
				//World->SpawnActor()
			}
		}
	}
}
