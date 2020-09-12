// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LevelManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class FILLBALL_API ALevelManager : public AGameModeBase
{
	GENERATED_BODY()
	
public:
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

protected:
	void RestartLevel();
};
