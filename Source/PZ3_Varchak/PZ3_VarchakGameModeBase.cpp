// Fill out your copyright notice in the Description page of Project Settings.

#include "PZ3_VarchakGameModeBase.h"
#include "MyPlayerController.h"




APZ3_VarchakGameModeBase::APZ3_VarchakGameModeBase()
{
	// use our custom PlayerController class
	PlayerControllerClass = AMyPlayerController::StaticClass();
}
