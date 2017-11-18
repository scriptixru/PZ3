// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Components/ArrowComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "GameFramework/Actor.h"

#include "BarrackUnit.h"
#include "MoveComponent.h"
#include "MyGameInstance.h"

#include "Barrack.generated.h"

UCLASS()
class PZ3_VARCHAK_API ABarrack : public AActor
{
	GENERATED_BODY()

	
public:
	// Sets default values for this actor's properties

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* StartPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* FinPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector ComponentLocation;

	ABarrack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void MySpawnBarrackUnit();

	UFUNCTION()
	void SetFinPointLocation(FVector V);
	
};
