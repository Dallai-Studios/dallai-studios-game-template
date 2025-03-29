// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Characters/DSFirstPersonCharacter.h"

#include "Data/DSGameClientOptionsPDA.h"
#include "Tools/DSDebugTools.h"


// ==============================================================
// Life Cycle:
// ==============================================================
ADSFirstPersonCharacter::ADSFirstPersonCharacter() {
	PrimaryActorTick.bCanEverTick = true;
}

void ADSFirstPersonCharacter::BeginPlay() {
	Super::BeginPlay();
}

void ADSFirstPersonCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}



// ==============================================================
// Character Movement:
// ==============================================================
void ADSFirstPersonCharacter::MoveCharacter(float axisX, float axisY) {
	if (axisX == 0 && axisY == 0) return;
	this->AddMovementInput(this->GetActorForwardVector(), axisX);
	this->AddMovementInput(this->GetActorRightVector(), axisY);
}



// ==============================================================
// Character Aim:
// ==============================================================
void ADSFirstPersonCharacter::MoveCamera(float axisX, float axisY) {
	if (axisX == 0 && axisY == 0) return;

	if (this->gameClientOptions == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Game Client Options is not Defined at First Person Character"));
		return;
	} 
	
	this->AddControllerPitchInput(this->gameClientOptions->bInvertMouseX ? axisX * -1 : axisX);
	this->AddControllerYawInput(this->gameClientOptions->bInvertMouseY ? axisY * -1 : axisY);
}