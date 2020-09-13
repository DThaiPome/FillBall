// Fill out your copyright notice in the Description page of Project Settings.

#include "ColorActor.h"
#include "ObjectColor.h"

// Sets default values
AColorActor::AColorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AColorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AColorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AColorActor::RegisterColorActor(AColorSwitching* gameMode)
{
	gameMode->RegisterColorActor(this);
}

void AColorActor::ColorChanged(TEnumAsByte<ObjectColor> color)
{
	bool colorMatches = color == objectColor;
	SetActive(this, colorMatches);
}

void SetActive(AActor* actor, bool active)
{
	actor->SetActorHiddenInGame(!active);

	// Disables collision components
	actor->SetActorEnableCollision(active);

	// Stops the Actor from ticking
	actor->SetActorTickEnabled(active);
}

