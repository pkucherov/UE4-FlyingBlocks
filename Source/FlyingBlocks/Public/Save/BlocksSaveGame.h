// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Blocks/BaseBlock.h"
#include "BlocksSaveGame.generated.h"


USTRUCT()
struct FBlockDTO {
	GENERATED_BODY()

	UPROPERTY() int BlockIndex;
	UPROPERTY() FVector Location;

	FBlockDTO() : BlockIndex(0), Location(0) {}
	FBlockDTO(int BlIndex, const FVector& loc): BlockIndex(BlIndex), Location(loc) {}
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
