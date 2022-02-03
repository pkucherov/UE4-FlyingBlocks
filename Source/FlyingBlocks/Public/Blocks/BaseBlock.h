// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseBlock.generated.h"


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

UCLASS(BlueprintType, Blueprintable)
class FLYINGBLOCKS_API ABaseBlock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseBlock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EBlockPosInAllBlocks  BlockType;

};
