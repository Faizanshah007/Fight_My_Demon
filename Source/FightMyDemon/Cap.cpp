// Fill out your copyright notice in the Description page of Project Settings.


#include "Cap.h"
#include <random>
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "Materials/MaterialInterface.h"
#include "ConstructorHelpers.h"

// Sets default values
ACap::ACap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Finding Objects
	static ConstructorHelpers::FObjectFinder<UParticleSystem> PS(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> PS1(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MeshMaterial(TEXT("Material'/Game/Meshes/CapMaterial.CapMaterial'"));
	// Root
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("DummyRootScene"));
	// Floating Cone
	flycone = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("NewCap"));
	flycone->SetStaticMesh(PS1.Object);
	flycone->AttachTo(RootScene);
	// Particle System
	MyParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MyPSC"));	
	MyParticleSystem->SetTemplate(PS.Object);
	MyParticleSystem->AttachTo(RootScene);
	MyParticleSystem->SetRelativeLocation(FVector(0.0f, 0.0f, -100.0f));
	// Applying Material
	MaterialInstance = UMaterialInstanceDynamic::Create(MeshMaterial.Object, MeshMaterial.Object);
	flycone->SetMaterial(0, MaterialInstance);
	
}

// Called when the game starts or when spawned
void ACap::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Random Generator
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(0.6000000000000000888, 1.4);
	// Modifying DeltaTime
	DeltaTime *= dist(mt);

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	float xcomp = (FMath::Cos(RunningTime + DeltaTime) - FMath::Cos(RunningTime));
	
	NewLocation.Z += DeltaHeight * 20.0f;       //Scale our height by a factor of 20
	NewLocation.Y += DeltaHeight * 60.0f;
	NewLocation.X += xcomp * 60.0f;
	RunningTime += DeltaTime;
	
	SetActorLocation(NewLocation);
	
	if (FMath::Sqrt(FMath::Pow((NewLocation.X + 181.0f),2) + FMath::Pow((NewLocation.Y - 1.0f), 2)) <= 1.0f)
	{
		MyParticleSystem->ActivateSystem(true);
	}

	// Colour Changing Effect
	if (ColorCounter >= NumberofColors * ChangeFreq)
	{
		ColorCounter = 0;
	}

	MaterialInstance->SetVectorParameterValue("MultiColor_Dark", Colors[int(ColorCounter++/ChangeFreq)]);
}

