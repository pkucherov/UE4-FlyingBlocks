// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "BlocksSaveGame.generated.h"


UENUM()
enum class EBlockPosInAllBlocks : uint8
{
	BaseBlock = 0,
	BrickBlock = 1,
	DirtBlock = 2,
	GrassBlock = 3,
	WoodBlock = 4,
	BlueBlock = 5,
	GoldBlock = 6,
	GreenBlock = 7,
	PurpleBlock = 8,
	RandomFlower = 9,
};

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
