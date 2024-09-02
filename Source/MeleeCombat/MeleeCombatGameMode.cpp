// Copyright Epic Games, Inc. All Rights Reserved.

#include "MeleeCombatGameMode.h"
#include "MeleeCombatCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMeleeCombatGameMode::AMeleeCombatGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
