// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"
#include "MoverComponent.h"
#include "RMarboR/Player/Marble.h"


UTriggerComponent::UTriggerComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super:: TickComponent(DeltaTime, TickType, ThisTickFunction);

    AActor* Actor = GetAcceptableActor();
    if(Actor)
    {   
        Mover->SetShouldMove(true);
        UE_LOG(LogTemp, Display, TEXT("Mover Set"));
        //GetOwner()->Destroy();

    }
    else
    {   
        Mover->SetShouldMove(false);
    }
}

void UTriggerComponent::SetMover(class UMoverComponent* NewMover)
{
    Mover = NewMover;
}

AActor* UTriggerComponent::GetAcceptableActor() const
{
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);

    for (AActor* Actor : Actors)
    {   
        //Actor = Cast<AMarble>(Actor->GetOwner());
        //UE_LOG(LogTemp, Display, TEXT("Actor Found"));
        bool HasAcceptableTag = Actor->ActorHasTag(ActorTag);
        if(HasAcceptableTag)
        {   
            return Actor;
            UE_LOG(LogTemp, Display, TEXT("Actor Returned"));

        }
    }
    return nullptr;
}

