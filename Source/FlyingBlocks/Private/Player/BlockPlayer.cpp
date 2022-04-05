// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/BlockPlayer.h"

// Sets default values
ABlockPlayer::ABlockPlayer(): TouchState(ETouchState::Move)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABlockPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlockPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABlockPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

