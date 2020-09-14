// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectColor.h"
#include "Components/ActorComponent.h"
#include "ColorActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FILLBALL_API UColorActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<ObjectColor> objectColor = ObjectColor::RED;

public:	
	// Sets default values for this component's properties
	UColorActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable, Category = "ColorActor")
		void ColorChanged(TEnumAsByte<ObjectColor> newColor);

protected:
	void SetActive(bool active);
};
