// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blocks/BaseBlock.h"
#include "GameFramework/GameModeBase.h"
#include "FBGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FLYINGBLOCKS_API AFBGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Classes)
	TSubclassOf<ABaseBlock> BaseBlockBPClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Classes)
		TSubclassOf<ABaseBlock> BrickBlockBPClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Classes)
		TSubclassOf<ABaseBlock> DirtBlockBPClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Classes)
		TSubclassOf<ABaseBlock> GrassBlockBPClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Classes)
		TSubclassOf<ABaseBlock> WoodBlockBPClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Classes)
		TSubclassOf<ABaseBlock> BlueBlockBPClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Classes)
		TSubclassOf<ABaseBlock> GoldBlockBPClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Classes)
		TSubclassOf<ABaseBlock> GreenBlockBPClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Classes)
		TSubclassOf<ABaseBlock> PurpleBlockBPClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Classes)
		TSubclassOf<ABaseBlock> RandomFlowerBlockBPClass;
	
};
