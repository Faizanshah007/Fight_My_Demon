// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector> 
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cap.generated.h"

using namespace::std;

UCLASS()
class ROCKET_CAP_API ACap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float RunningTime;

	vector<FColor> vibgyor = { FColor(148,0,211), FColor(75, 0, 130), FColor::Blue, FColor::Green, FColor::Yellow, FColor::Orange, FColor::Red };
	int ColorCount = 0;

	UPROPERTY(EditAnywhere)
	int ChangeFreq = 10;

	UPROPERTY(VisibleAnywhere)
	class USceneComponent *RootScene;
	
	UPROPERTY(VisibleAnywhere)
	class UParticleSystemComponent *MyParticleSystem;
	
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent *flycone;
	
	class UMaterialInstanceDynamic* MaterialInstance;
};
