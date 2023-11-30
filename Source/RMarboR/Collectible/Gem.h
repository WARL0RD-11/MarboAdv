// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gem.generated.h"

UCLASS()
class RMARBOR_API AGem : public AActor
{
	GENERATED_BODY()
	
public:	
	AGem();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")    
	class USphereComponent* SphereComponent;

 	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* UpperMesh;

 	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* LowerMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
	class USoundBase* CollectSound;

public:	
	virtual void Tick(float DeltaTime) override;
 	
	UFUNCTION()
    void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
                        class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                        bool bFromSweep, const FHitResult& SweepResult);

private:
    bool bIsCollected;
};
