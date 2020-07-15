// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector> 
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cap.generated.h"

using namespace::std;

UCLASS()
class FIGHTMYDEMON_API ACap : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	ACap();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	float RunningTime;
	
	TArray<FLinearColor> Colors = { FLinearColor(1, 1, 1, 0), FLinearColor(0, 1, 0, 0), FLinearColor::Yellow };
	
	int NumberofColors = Colors.Num();
	
	int ColorCounter = 0;

	UPROPERTY(EditAnywhere)
	int ChangeFreq = 10;

	class USceneComponent *RootScene;
	
	class UParticleSystemComponent *MyParticleSystem;
	
	class UStaticMeshComponent *flycone;
	
	class UMaterialInstanceDynamic* MaterialInstance;
};
