// Fill out your copyright notice in the Description page of Project Settings.

#include "Monster.h"
#include "Engine/World.h"
#include "Kid.h"

// Sets default values
AMonster::AMonster()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMonster::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Teleport Check
	if (TeleportNow)
	{
		//Face towards the kid
		UWorld* WorldRef = GetWorld();
		AKid *KidRef = Cast<AKid>(WorldRef->GetFirstPlayerController()->GetCharacter());
		SetActorLocation(GetActorLocation() + TeleportHere);
		TeleportNow = false;
	}

}

// Called to bind functionality to input
void AMonster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

