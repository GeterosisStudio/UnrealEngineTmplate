// Copyright Epic Games, Inc. All Rights Reserved.

#include "LearnUeGameMode.h"
#include "LearnUeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALearnUeGameMode::ALearnUeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
