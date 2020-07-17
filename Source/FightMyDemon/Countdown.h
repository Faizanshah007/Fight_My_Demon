// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include"Cap.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Countdown.generated.h"

UCLASS()
class FIGHTMYDEMON_API ACountdown : public AActor
{
	GENERATED_BODY()

public:	
	
	// Sets default values for this actor's properties
	ACountdown();

	// Called every frame
	/*virtual void Tick(float DeltaTime) override;*/

	//How long, in seconds, the countdown will run
	UPROPERTY(EditAnywhere)
	int32 CountdownTime;

	UPROPERTY(EditAnywhere)
	TArray<FString> StrArr = { TEXT("!!!!"), TEXT("Here"), TEXT("is"), TEXT("Devil") };

protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Default implementation for ClearCountdownDisplay
	virtual void ClearCountdownDisplay_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void ClearCountdownDisplay();

private:
	
	class UTextRenderComponent* CountdownText;

	void AdvanceTimer();

	FTimerHandle CountdownTimerHandle;
	
};
