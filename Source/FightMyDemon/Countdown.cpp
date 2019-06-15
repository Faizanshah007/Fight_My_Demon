// Fill out your copyright notice in the Description page of Project Settings.


#include "Countdown.h"
#include "GameFramework/Actor.h"
#include "Components/TextRenderComponent.h"
#include "TimerManager.h"
#include <fstream>
void ACountdown::UpdateTimerDisplay()
{
	CountdownText->SetText(FString::FromInt(FMath::Max(CountdownTime, 0)));
}

void ACountdown::AdvanceTimer()
{
	--CountdownTime;
	if (CountdownTime == 0)
	{
		CountdownHasFinished();
	}
	else if (CountdownTime == -1)
	{
		ClearCountdownDisplay();
	}
	else
	{
		UpdateTimerDisplay();
	}
}
void ACountdown::CountdownHasFinished()
{
	//Change to a special readout
	CountdownText->SetText(TEXT("GO!"));
}

void ACountdown::ClearCountdownDisplay_Implementation()
{
	std::ofstream myfile;
	myfile.open("D:\\faiza\\Desktop\\example.txt");
	myfile << "Writing this to a file.\n";
	myfile.close();

	CountdownText->SetText(TEXT(""));
	GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
	ACap *Capinstance = GetWorld()->SpawnActor<ACap>(ACap::StaticClass(), FVector(-181.0f, 1.0f, 200.0f), FRotator::ZeroRotator);
}

// Sets default values
ACountdown::ACountdown()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountdownNumber"));
	CountdownText->SetHorizontalAlignment(EHTA_Center);
	CountdownText->SetWorldSize(150.0f);
	RootComponent = CountdownText;
	CountdownTime = 3;

}

// Called when the game starts or when spawned
void ACountdown::BeginPlay()
{
	Super::BeginPlay();
	UpdateTimerDisplay();
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ACountdown::AdvanceTimer, 1.0f, true);	
}

// Called every frame
void ACountdown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

