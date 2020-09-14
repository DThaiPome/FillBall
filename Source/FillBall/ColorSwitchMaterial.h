// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectColor.h"
#include "Components/ActorComponent.h"
#include "ColorSwitchMaterial.generated.h"


UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FILLBALL_API UColorSwitchMaterial : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<ObjectColor> color;

public:	
	// Sets default values for this component's properties
	UColorSwitchMaterial();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable, Category = "ColorSwitchMaterial")
		void SetColor(TEnumAsByte<ObjectColor> newColor);
	UFUNCTION(BlueprintCallable, Category = "ColorSwitchMaterial")
		void UpdateMaterialColor();
		
};
