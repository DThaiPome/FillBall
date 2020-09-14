// Fill out your copyright notice in the Description page of Project Settings.


#include "ColorActorComponent.h"

// Sets default values for this component's properties
UColorActorComponent::UColorActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UColorActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UColorActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UColorActorComponent::ColorChanged(TEnumAsByte<ObjectColor> color)
{
	bool colorMatches = color == objectColor;
	SetActive(colorMatches);
}

void UColorActorComponent::SetActive(bool active)
{
	GetOwner()->SetActorHiddenInGame(!active);

	// Disables collision components
	GetOwner()->SetActorEnableCollision(active);

	// Stops the Actor from ticking
	GetOwner()->SetActorTickEnabled(active);
}