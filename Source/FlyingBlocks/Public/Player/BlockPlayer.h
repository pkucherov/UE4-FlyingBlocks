// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BlockPlayer.generated.h"

UCLASS()
class FLYINGBLOCKS_API ABlockPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABlockPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Flying Blocks")
	void SetSpawnOnTouchState(bool bSpawn) { bSpawnBlock = bSpawn; }

	UFUNCTION(BlueprintCallable, Category = "Flying Blocks")
	bool GetSpawnOnTouchState() const { return bSpawnBlock; }

private:
	bool bSpawnBlock;

};
