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
	ALevelManager::GameOver(false);
}

void ALevelManager::LevelWon()
{
	isGameOver = true;
	ALevelManager::GameOver(true);
}

FName ALevelManager::GetNextLevel(TArray<FName> levelNames, FName endLevelName, FName currentLevelName)
{
	int levelCount = levelNames.Num();
	for(int i = 0; i < levelCount - 1; i++)
	{
		FName name = levelNames[i];
		if (name.Compare(currentLevelName) == 0)
		{
			return levelNames[i + 1];
		}
	}
	return endLevelName;
}