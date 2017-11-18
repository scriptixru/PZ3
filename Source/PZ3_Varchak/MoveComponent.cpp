// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveComponent.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"


// Sets default values for this component's properties
UMoveComponent::UMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	if (GetOwner())
	{
		FinallyPoint = GetOwner()->GetActorLocation();
	}
	// ...
}


// Called when the game starts
void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveParent();
	// ...
}

void UMoveComponent::MoveParent()
{
	AActor* Parent = this->GetOwner();
	if (Parent)
	{

		FVector ParentLoc = Parent->GetActorLocation();
		FVector DoMove(UKismetMathLibrary::SignOfFloat(FinallyPoint.X - ParentLoc.X), UKismetMathLibrary::SignOfFloat(FinallyPoint.Y - ParentLoc.Y), UKismetMathLibrary::SignOfFloat(FinallyPoint.Z - ParentLoc.Z));//SIGN(round(FinallyPoint.X - ParentLoc.X)), SIGN(FinallyPoint.Y - ParentLoc.Y), SIGN(FinallyPoint.Z - ParentLoc.Z)
		if ((UKismetMathLibrary::Abs(DoMove.X) < 1) && (UKismetMathLibrary::Abs(DoMove.Y) < 1) && (UKismetMathLibrary::Abs(DoMove.Z) < 1)) DestroyComponent();
		Parent->SetActorLocation(ParentLoc + DoMove);
	}
}

