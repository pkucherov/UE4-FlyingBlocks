// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Blocks/BaseBlock.h"
#include "BlocksSaveGame.generated.h"


USTRUCT()
struct FBlockDTO {
	GENERATED_BODY()

	UPROPERTY() EBlockPosInAllBlocks BlockType;
	UPROPERTY() FVector Location;

	FBlockDTO() : BlockType(EBlockPosInAllBlocks::BaseBlock), Location(0) {}
	FBlockDTO(EBlockPosInAllBlocks BlType, const FVector& loc): BlockType(BlType), Location(loc) {}
};
/**
 *
 */
UCLASS()
class FLYINGBLOCKS_API UBlocksSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FBlockDTO> BlockDTOs;

};
