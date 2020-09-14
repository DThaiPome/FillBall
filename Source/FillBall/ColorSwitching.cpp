// Fill out your copyright notice in the Description page of Project Settings.


#include "ColorSwitching.h"
#include "ObjectColor.h"



AColorSwitching::AColorSwitching() 
{
	currentColor = ObjectColor::RED;
}

void AColorSwitching::RegisterColorActor(AColorActor* newColorActor)
{
	colorActors->push_front(newColorActor);
}

void AColorSwitching::ChangeColor(TEnumAsByte<ObjectColor> newColor)
{
	currentColor = newColor;

	BroadcastChanged(newColor);
	//UpdateColorActors(newColor);
}

void AColorSwitching::UpdateColorActors(TEnumAsByte<ObjectColor> newColor)
{
	std::list<AColorActor*>::iterator it;

	for (it = colorActors->begin(); it != colorActors->end(); it++)
	{
		(*it)->ColorChanged(newColor);
	}
}

FLinearColor AColorSwitching::ColorToValue(TEnumAsByte<ObjectColor> color)
{
	switch (color)
	{
	case ObjectColor::RED :
		return FLinearColor(1.0f, 0.0f, 0.0f);
	case ObjectColor::BLUE :
		return FLinearColor(0.0f, 0.0f, 1.0f);
	case ObjectColor::GREEN :
		return FLinearColor(0.0f, 1.0f, 0.0f);
	case ObjectColor::YELLOW :
		return FLinearColor(1.0f, 1.0f, 0.0f);
	default:
		return FLinearColor(1.0f, 1.0f, 1.0f);
	}
}

