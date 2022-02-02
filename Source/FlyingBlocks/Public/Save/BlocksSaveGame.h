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
	UPROPERTY() double X;
	UPROPERTY() double Y;
	UPROPERTY() double Z;

	FBlockDTO() : BlockType(EBlockPosInAllBlocks::BaseBlock), X(0.0), Y(0.0), Z(0.0) {}
};
/**
 *
 */
UCLASS()
class FLYINGBLOCKS_API UBlocksSaveGame : public USaveGame
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FBlockDTO> BlockDTOs;

};
