// Fill out your copyright notice in the Description page of Project Settings.


#include "ColorPickup.h"

// Sets default values
AColorPickup::AColorPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AColorPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AColorPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AColorPickup::OnPickup()
{
	SetActive(false);
}

void AColorPickup::SetActive(bool active)
{
	this->SetActorHiddenInGame(!active);

	// Disables collision components
	this->SetActorEnableCollision(active);

	// Stops the Actor from ticking
	this->SetActorTickEnabled(active);
}