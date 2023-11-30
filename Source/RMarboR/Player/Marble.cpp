// Fill out your copyright notice in the Description page of Project Settings.


#include "Marble.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "RMarboR/Collectible/Gem.h"

AMarble::AMarble()
{
	PrimaryActorTick.bCanEverTick = true;
	
	MarbleMesh = CreateDefaultSubobject<UStaticMeshComponent>("MarbleMesh");
    RootComponent = MarbleMesh;

    SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 600.0f; 

    Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
    Camera->SetupAttachment(SpringArm);

	ScoreAchieved = 0;
	bIsActivated = false;
	SpawnLocation = GetActorLocation();

}

void AMarble::BeginPlay()
{
	Super::BeginPlay();
	MarbleMesh->SetSimulatePhysics(true);
}

void AMarble::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMarble::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMarble::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("TurnRight"), this, &AMarble::TurnRight);
}

void AMarble::MoveForward(float AxisValue)
{
	FVector TorqueToAdd = FVector::ZeroVector;
	TorqueToAdd.Y = AxisValue * MoveMulti * MoveSpeed * (UGameplayStatics::GetWorldDeltaSeconds(this));
	MarbleMesh->AddTorqueInDegrees(TorqueToAdd);
}

void AMarble::TurnRight(float AxisValue)
{
	FVector TorqueToAdd = FVector::ZeroVector;
	TorqueToAdd.X = AxisValue * MoveMulti * MoveSpeed * (UGameplayStatics::GetWorldDeltaSeconds(this));
	MarbleMesh->AddTorqueInDegrees(TorqueToAdd);
}

void AMarble::MarbleDeath()
{
	SetActorLocation(SpawnLocation);
}

int32 AMarble::GetScore()
{
	return ScoreAchieved;
}

bool AMarble::GetMarbleDeath()
{
	return bIsActivated;
}

void AMarble::SetMarbleDeath(bool Value)
{
	bIsActivated = Value;
}

void AMarble::SetScore(int32 Value)
{
	ScoreAchieved = ScoreAchieved + Value;
}