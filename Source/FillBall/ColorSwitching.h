// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelManager.h"
#include "ColorActor.h"
#include "ObjectColor.h"
#include "ColorSwitching.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FColorChangeDelegate, TEnumAsByte<ObjectColor>, color);

/**
 * 
 */
UCLASS(Blueprintable)
class FILLBALL_API AColorSwitching : public ALevelManager
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintAssignable, Category = "ColorSwitching")
		FColorChangeDelegate OnColorChange;

protected:
	void BroadcastChanged(TEnumAsByte<ObjectColor> color)
	{
		OnColorChange.Broadcast(color);
	}

public:
	UPROPERTY(BlueprintReadOnly)
		TEnumAsByte<ObjectColor> currentColor;

private:
	std::list<AColorActor*>* colorActors = new std::list<AColorActor*>();

public:
	AColorSwitching();

public:
	UFUNCTION(BlueprintCallable, Category = "ColorSwitching")
		void RegisterColorActor(AColorActor* newColorActor);
	UFUNCTION(BlueprintCallable, Category = "ColorSwitching")
		void ChangeColor(TEnumAsByte<ObjectColor> newColor);
	UFUNCTION(BlueprintCallable, Category = "ColorSwitching")
	static FLinearColor ColorToValue(TEnumAsByte<ObjectColor> color);
	
protected:
	void UpdateColorActors(TEnumAsByte<ObjectColor> newColor);
};
