// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Characters/DSFirstPersonCharacter.h"
#include "Camera/CameraComponent.h"
#include "Data/DSCharacterConfigurationPDA.h"
#include "Data/DSGameClientOptionsPDA.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Tools/DSDebugTools.h"


// ==============================================================
// Life Cycle:
// ==============================================================
ADSFirstPersonCharacter::ADSFirstPersonCharacter() {
	PrimaryActorTick.bCanEverTick = true;

	this->cameraSpringArm = this->CreateDefaultSubobject<USpringArmComponent>("Camera Sprint Arm");
	this->cameraSpringArm->SetupAttachment(this->GetRootComponent());
	this->cameraSpringArm->bUsePawnControlRotation = true;
	this->cameraSpringArm->bInheritRoll = false;
	
	this->camera = this->CreateDefaultSubobject<UCameraComponent>("Player Camera");
	this->camera->SetupAttachment(this->cameraSpringArm);
}

void ADSFirstPersonCharacter::BeginPlay() {
	Super::BeginPlay();
	this->StopRunning();
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

void ADSFirstPersonCharacter::StartRunning() {
	if (this->characterConfiguration == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Character Configuration is not defined on First Person Character"));
		return;
	}
	this->GetCharacterMovement()->MaxWalkSpeed = this->characterConfiguration->runningSpeed;
}

void ADSFirstPersonCharacter::StopRunning() {
	if (this->characterConfiguration == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Character Configuration is not defined on First Person Character"));
		return;
	}
	this->GetCharacterMovement()->MaxWalkSpeed = this->characterConfiguration->walkSpeed;
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

	const auto finalAxisX = this->gameClientOptions->bInvertMouseX ? (axisX * -1) : axisX;
	const auto finalAxisY = this->gameClientOptions->bInvertMouseY ? (axisY * -1) : axisY;
	
	this->AddControllerPitchInput(finalAxisX * this->gameClientOptions->mouseSensitivity);
	this->AddControllerYawInput(finalAxisY * this->gameClientOptions->mouseSensitivity);
}