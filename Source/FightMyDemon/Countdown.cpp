// Fill out your copyright notice in the Description page of Project Settings.


#include "Countdown.h"
#include "GameFramework/Actor.h"
#include "Components/TextRenderComponent.h"
#include "TimerManager.h"
#include <fstream>

void ACountdown::AdvanceTimer()
{
	--CountdownTime;
	if (CountdownTime == -1)
	{
		ClearCountdownDisplay();
	}
	else
	{
		CountdownText->SetText(StrArr[CountdownTime]);
	}
}

void ACountdown::ClearCountdownDisplay_Implementation()
{
	CountdownText->SetText(TEXT(""));
	GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
	ACap *Capinstance = GetWorld()->SpawnActor<ACap>(ACap::StaticClass(), FVector(-181.0f, 1.0f, 200.0f), FRotator::ZeroRotator);
}

// Sets default values
ACountdown::ACountdown()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("DisplayText"));
	CountdownText->TextRenderColor = FColor(255,0,0);
	CountdownText->SetHorizontalAlignment(EHTA_Center);
	CountdownText->SetWorldSize(250.0f);
	RootComponent = CountdownText;
	CountdownTime = 4;

}

// Called when the game starts or when spawned
void ACountdown::BeginPlay()
{
	Super::BeginPlay();
	CountdownText->SetText(TEXT(""));
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ACountdown::AdvanceTimer, 1.0f, true);
}

/*
// Called every frame
void ACountdown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
*/

