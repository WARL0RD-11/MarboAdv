// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoverComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RMARBOR_API UMoverComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UMoverComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetShouldMove(bool NewShouldMove);

private:
	UPROPERTY(EditAnywhere, Category = "Mover Property")
	FVector MoveOffset;

	UPROPERTY(EditAnywhere, Category = "Mover Property")
	float MoveTime = 4;
	
	UPROPERTY(EditAnywhere, Category = "Mover Property")
	bool ShouldMove;

	FVector OriginalLocation;
	
};
