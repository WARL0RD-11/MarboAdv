// Fill out your copyright notice in the Description page of Project Settings.


#include "Gem.h"
#include "Components/SphereComponent.h"
#include "Components/TimelineComponent.h"
#include "RMarboR/Player/Marble.h"
#include "Kismet/GameplayStatics.h"

AGem::AGem()
{
	PrimaryActorTick.bCanEverTick = true;
 	
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    RootComponent = SphereComponent;

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AGem::OnOverlapBegin);

	UpperMesh = CreateDefaultSubobject<UStaticMeshComponent>("UpperMesh");
	UpperMesh->SetupAttachment(SphereComponent);

	LowerMesh = CreateDefaultSubobject<UStaticMeshComponent>("LowerMesh");
	LowerMesh->SetupAttachment(UpperMesh);
}

void AGem::BeginPlay()
{
	Super::BeginPlay();
}

void AGem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(bIsCollected)
	{
		Destroy();
		bIsCollected = false;
	}
}

void AGem::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
						class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
						bool bFromSweep, const FHitResult& SweepResult)
{
	AMarble* MarblePawn = Cast<AMarble>(OtherActor);
    if (MarblePawn)
    {
        bIsCollected = true;
		//UE_LOG(LogTemp, Warning, TEXT("Marble oveerlappping"));
		MarblePawn->SetScore(10);
		//UE_LOG(LogTemp, Display, TEXT("Your Score is - %d"),MarblePawn->GetScore());
		UGameplayStatics::PlaySoundAtLocation(this, CollectSound, GetActorLocation());
    }
}


