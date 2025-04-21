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

	// I call this function just to set the character MaxWalkSpeed to the
	// configured default movement speed. This function does a validation for the
	// character configuration data asset, that's the hole reason. -Dallai
	this->StopRunning();
}

void ADSFirstPersonCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// ==============================================================
// Character Movement:
// ==============================================================
void ADSFirstPersonCharacter::MoveCharacter(float axisX, float axisY) {
	// this function is responsable for moving the player.
	// I prefer to abstract a little bit more the movement, just to made some
	// validations on the values and I save these values to use for any reason. -Dallai
	if (axisX == 0 && axisY == 0) return;

	this->forwardMovementValue = axisX;
	this->rightMovementValue = axisY;
	
	this->AddMovementInput(this->GetActorForwardVector(), axisX);
	this->AddMovementInput(this->GetActorRightVector(), axisY);
}

void ADSFirstPersonCharacter::StartRunning() {
	// This character configurations could be inside of this class, but I dont want to handle with a bunch
	// of separeted places with configurations. These configurations just work for first person characters
	// and third person characters. This is just a way to make everything in just one place, I just need
	// to remember to create the data asset. -Dallai
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

float ADSFirstPersonCharacter::GetForwardMovementValue() const {
	return this->forwardMovementValue;
}

float ADSFirstPersonCharacter::GetRightMovementValue() const {
	return this->rightMovementValue;
}

// ==============================================================
// Character Aim:
// ==============================================================
void ADSFirstPersonCharacter::MoveCamera(float axisX, float axisY) {
	// same thing for camera aim movement. Validation and data storage. -Dallai
	if (axisX == 0 && axisY == 0) return;

	this->cameraUpValue = axisY;
	this->cameraRightValue = axisX;
	
	// this configuractions are set by the player on the options menu. -Dallai
	if (this->gameClientOptions == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Game Client Options is not Defined at First Person Character"));
		return;
	} 

	// some aux variables just to save some space on the function calls. -Dallai
	const auto finalAxisX = this->gameClientOptions->bInvertMouseX ? (axisX * -1) : axisX;
	const auto finalAxisY = this->gameClientOptions->bInvertMouseY ? (axisY * -1) : axisY;
	
	this->AddControllerPitchInput(finalAxisX * this->gameClientOptions->mouseSensitivity);
	this->AddControllerYawInput(finalAxisY * this->gameClientOptions->mouseSensitivity);
}