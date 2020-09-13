// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ColorSwitching.h"
#include "ObjectColor.h"
#include "ColorActor.generated.h"

UCLASS()
class FILLBALL_API AColorActor : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<ObjectColor> objectColor = ObjectColor::RED;

public:	
	// Sets default values for this actor's properties
	AColorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "ColorActor")
		void RegisterColorActor(AColorSwitching* gameMode);

	UFUNCTION(BlueprintCallable, Category = "ColorActor")
		void ColorChanged(TEnumAsByte<ObjectColor> newColor);

protected:
	void SetActive(bool active);
};
