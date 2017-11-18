// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"
//#include "Barrack.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PZ3_VARCHAK_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMyPlayerController();
	//UPROPERTY()
	//ABarrack* CurrBarrack;


protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;
	// Begin PlayerController interface
	virtual void SetupInputComponent() override;

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
	
};
