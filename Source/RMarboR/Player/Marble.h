// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Marble.generated.h"

UCLASS()
class RMARBOR_API AMarble : public APawn
{
	GENERATED_BODY()

public:
	AMarble();

	UFUNCTION(BlueprintCallable)
	int32 GetScore();

	UFUNCTION(BlueprintCallable)
	bool GetMarbleDeath();

	UFUNCTION(BlueprintCallable)
	void SetMarbleDeath(bool Value);

	void SetScore(int32 Value);

	UPROPERTY(EditAnywhere)
	FVector SpawnLocation;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

 	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* MarbleMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    class USpringArmComponent* SpringArm;

private:

	void MoveForward(float AxisValue);

	UPROPERTY(EditAnywhere)
    float MoveSpeed = 500000.0f;
	
	UPROPERTY(EditAnywhere)
    float MoveMulti = 50000.0f;

	void TurnRight(float AxisValue);

	UPROPERTY(EditAnywhere)
    float TurnSpeed = 500000.0f;
	
	UPROPERTY(EditAnywhere)
    float TurnMulti = 50000.0f;

	UPROPERTY(EditAnywhere)
	int32 ScoreAchieved;

	UPROPERTY(EditAnywhere)
	bool bIsActivated;

	void MarbleDeath();

};
