// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyGameInstance.h"
#include "MyPlayerController.generated.h"


/**
 * 
 */
UCLASS(Blueprintable)
class PZ3_VARCHAK_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMyPlayerController();

	UMyGameInstance* CurrGameInst;

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	virtual void BeginPlay() override;

	uint32 bMoveToMouseCursor : 1;
	// Begin PlayerController interface
	virtual void SetupInputComponent() override;

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
	
};
