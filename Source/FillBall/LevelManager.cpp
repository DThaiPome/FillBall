// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelManager.h"
#include "Kismet/GameplayStatics.h"

ALevelManager::ALevelManager() 
{
	ALevelManager::InitLevel();
}

void ALevelManager::BeginPlay() 
{
	Super::BeginPlay();
}

void ALevelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	timeElapsed += DeltaTime;
}

void ALevelManager::InitLevel() 
{
	ALevelManager::isGameOver = false;
	UE_LOG(LogTemp, Warning, TEXT("Level Manager Initialized"))
}

void ALevelManager::LevelLost()
{
	isGameOver = true;
}