// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include"Cap.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Countdown.generated.h"

UCLASS()
class ROCKET_CAP_API ACountdown : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ACountdown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//How long, in seconds, the countdown will run
	UPROPERTY(EditAnywhere)
	int32 CountdownTime;
	class UTextRenderComponent* CountdownText;
	void UpdateTimerDisplay();
	
	void AdvanceTimer();
	
	UFUNCTION(BlueprintNativeEvent)
	void ClearCountdownDisplay();
	virtual void ClearCountdownDisplay_Implementation();
	
	virtual void CountdownHasFinished();
	
	FTimerHandle CountdownTimerHandle;
	
};
