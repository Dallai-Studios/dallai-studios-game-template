// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Actors/DSInteractableDoor.h"

#include "Data/DSGameGlobalEvents.h"
#include "Tools/DSDebugTools.h"

ADSInteractableDoor::ADSInteractableDoor() {
	PrimaryActorTick.bCanEverTick = false;
}

void ADSInteractableDoor::BeginPlay() {
	Super::BeginPlay();
}

FText ADSInteractableDoor::GetInteractionVerb_Implementation() {
	return this->interactionVerb;
}
