// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Barrack.h"




AMyPlayerController::AMyPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
	
}


void AMyPlayerController::BeginPlay()
{
	if (GetWorld())
	{
		auto Instance = GetGameInstance();
		if (Instance)
		{
			UMyGameInstance* GameInstance = Cast<UMyGameInstance>(Instance);
			if (GameInstance)
			{
				CurrGameInst = GameInstance;
			}
		}
	}
}

void AMyPlayerController::SetupInputComponent()
{
	// set up game play key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AMyPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AMyPlayerController::OnSetDestinationReleased);
}

void AMyPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Cyan, "Pressed");

	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Emerald, FString::Printf(TEXT("Location: %f, %f, %f"), Barrack.ComponentLocation.X, 
	//	ABarrack::ComponentLocation.Y, ABarrack::ComponentLocation.Z));

}

void AMyPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
	if (CurrGameInst)
		CurrGameInst->OnClickReleased.ExecuteIfBound(FVector(0.f,0.f,0.f));//replace FVector(0.f,0.f,0.f) to your location.
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Cyan, "Released");
}


