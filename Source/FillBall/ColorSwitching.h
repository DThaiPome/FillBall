// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelManager.h"
#include "ColorSwitching.generated.h"

UENUM(BlueprintType)
enum ObjectColor
{
	RED, BLUE, GREEN, YELLOW
};

/**
 * 
 */
UCLASS(Blueprintable)
class FILLBALL_API AColorSwitching : public ALevelManager
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
		TEnumAsByte<ObjectColor> currentColor;

public:
	AColorSwitching();

public:
	UFUNCTION(BlueprintCallable, Category = "ColorSwitching")
		void ChangeColor(TEnumAsByte<ObjectColor> newColor);
	
public:


};
