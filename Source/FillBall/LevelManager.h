// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LevelManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameOverDelegate, bool, levelWon);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLevelLoadRequestDelegate, FName, levelName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLevelChangeRequestDelegate, FName, currentLevelName, FName, nextLevelName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLevelLoadedDelegate, FName, loadedLevelName);

/**
 * 
 */
UCLASS(Blueprintable)
class FILLBALL_API ALevelManager : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable, Category = "LevelManager")
		FGameOverDelegate OnGameOver;

	UPROPERTY(BlueprintAssignable, Category = "LevelManager")
		FLevelLoadRequestDelegate OnLevelLoadRequest;

	UPROPERTY(BlueprintAssignable, Category = "LevelManager")
		FLevelChangeRequestDelegate OnLevelChangeRequest;

	UPROPERTY(BlueprintAssignable, Category = "LevelManager")
		FLevelLoadedDelegate OnLevelLoaded;

	UPROPERTY(BlueprintReadOnly)
		bool isGameOver = false;

	UPROPERTY(BlueprintReadOnly)
		float timeElapsed = 0;

	UPROPERTY(BlueprintReadWrite)
		float delayBeforeReset = 2;

public:
	ALevelManager();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable, Category="LevelManager")
	void InitLevel();

	UFUNCTION(BlueprintCallable, Category = "LevelManager")
	void LevelLost();

	UFUNCTION(BlueprintCallable, Category = "LevelManager")
		void LevelWon();

	UFUNCTION(BlueprintCallable, Category = "LevelManager")
		FName GetNextLevel(TArray<FName> levelNames, FName endLevelName, FName currentLevelName);

	UFUNCTION(BlueprintCallable, Category = "LevelManager")
	void GameOver(bool levelWon)
	{
		OnGameOver.Broadcast(levelWon);
	}

	UFUNCTION(BlueprintCallable, Category = "LevelManager")
	void RequestLoadStreamLevel(FName levelName) {
		OnLevelLoadRequest.Broadcast(levelName);
	}

	UFUNCTION(BlueprintCallable, Category = "LevelManager")
	void RequestChangeStreamLevel(FName currentLevelName, FName nextLevelName)
	{
		OnLevelChangeRequest.Broadcast(currentLevelName, nextLevelName);
	}

	UFUNCTION(BlueprintCallable, Category = "LevelManager")
	void SignalLevelLoaded(FName loadedLevel) {
		isGameOver = false;
		OnLevelLoaded.Broadcast(loadedLevel);
	}

protected:
	void RestartLevel();
};
