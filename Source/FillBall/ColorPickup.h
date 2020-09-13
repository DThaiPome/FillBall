// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectColor.h"
#include "ColorPickup.generated.h"

UCLASS()
class FILLBALL_API AColorPickup : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TEnumAsByte<ObjectColor> color;

public:	
	// Sets default values for this actor's properties
	AColorPickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "ColorPickup")
		void OnPickup();

protected:
	void SetActive(bool active);
};
