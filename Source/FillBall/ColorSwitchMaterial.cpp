// Fill out your copyright notice in the Description page of Project Settings.


#include "ColorSwitchMaterial.h"
#include "ColorSwitching.h"

// Sets default values for this component's properties
UColorSwitchMaterial::UColorSwitchMaterial()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UColorSwitchMaterial::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UColorSwitchMaterial::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UColorSwitchMaterial::SetColor(TEnumAsByte<ObjectColor> newColor)
{
	color = newColor;
}

void UColorSwitchMaterial::UpdateMaterialColor()
{
	UMeshComponent* mesh = GetOwner()->FindComponentByClass<UStaticMeshComponent>();
	UMaterialInstanceDynamic* material = UMaterialInstanceDynamic::Create(mesh->GetMaterial(0), this);
	FLinearColor newColor = AColorSwitching::ColorToValue(color);
	material->SetVectorParameterValue(FName(TEXT("Color")), newColor);
	mesh->SetMaterial(0, material);
}

