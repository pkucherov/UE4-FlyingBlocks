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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flying Block classes")
	TArray<TSubclassOf<ABaseBlock>> BlockBPClasses;
};
