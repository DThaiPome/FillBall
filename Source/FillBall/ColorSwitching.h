// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelManager.h"
#include "ColorActor.h"
#include "ObjectColor.h"
#include "ColorSwitching.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class FILLBALL_API AColorSwitching : public ALevelManager
{
	GENERATED_BODY()

public:
	DECLARE_EVENT_OneParam(AColorSwitching, FColorChangedEvent, TEnumAsByte<ObjectColor>)
	FColorChangedEvent& OnColorChange(TEnumAsByte<ObjectColor> color) { return ColorChangedEvent; }

protected:
	void BroadcastChanged(TEnumAsByte<ObjectColor> color)
	{
		ColorChangedEvent.Broadcast(color);
	}

private:
	FColorChangedEvent ColorChangedEvent;

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
	
protected:
	void UpdateColorActors(TEnumAsByte<ObjectColor> newColor);
};
