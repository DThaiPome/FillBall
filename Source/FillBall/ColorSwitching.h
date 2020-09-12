// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelManager.h"
#include "ColorSwitching.generated.h"

/**
 * 
 */
UCLASS()
class FILLBALL_API AColorSwitching : public ALevelManager
{
	GENERATED_BODY()
	
public:
	enum Color 
	{
		RED, BLUE, GREEN, YELLOW
	};

public:
	UPROPERTY(BlueprintReadOnly)
		AColorSwitching::Color currentColor;

public:
	AColorSwitching();

public:
	UFUNCTION(BlueprintCallable, Category = "ColorSwitching")
		void ChangeColor(Color newColor);

public:


};
