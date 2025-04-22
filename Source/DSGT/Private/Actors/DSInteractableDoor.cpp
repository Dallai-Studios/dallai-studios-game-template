// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Actors/DSInteractableDoor.h"

#include "Data/DSGameGlobalEvents.h"
#include "Tools/DSDebugTools.h"

ADSInteractableDoor::ADSInteractableDoor() {
	PrimaryActorTick.bCanEverTick = false;

	this->doorFrameMesh = this->CreateDefaultSubobject<UStaticMeshComponent>("Door Frame Mesh");
	this->doorFrameMesh->SetupAttachment(this->GetRootComponent());

	this->doorMesh = this->CreateDefaultSubobject<UStaticMeshComponent>("Door Mesh");
	this->doorMesh->SetupAttachment(this->doorFrameMesh);
}

void ADSInteractableDoor::BeginPlay() {
	Super::BeginPlay();
}

FText ADSInteractableDoor::GetInteractionVerb_Implementation() {
	return this->interactionVerb;
}
