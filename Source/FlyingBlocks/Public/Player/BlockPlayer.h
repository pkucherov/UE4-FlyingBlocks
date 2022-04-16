// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BlockPlayer.generated.h"

UENUM(BlueprintType)
enum class ETouchState: uint8
{
	Delete = 0,
	Spawn = 1,
	Move = 2
};

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
	void SetSpawnOnTouchState(ETouchState State) { TouchState = State; }

	UFUNCTION(BlueprintCallable, Category = "Flying Blocks")
	ETouchState GetSpawnOnTouchState() const { return TouchState; }

private:
	ETouchState TouchState;
};
