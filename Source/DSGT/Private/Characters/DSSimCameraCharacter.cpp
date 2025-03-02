#include "Characters/DSSimCameraCharacter.h"

// ===========================================================================================
// Life Cycle Methods:
// ===========================================================================================
ADSSimCameraCharacter::ADSSimCameraCharacter() {
	PrimaryActorTick.bCanEverTick = true;
}

void ADSSimCameraCharacter::BeginPlay() {
	Super::BeginPlay();
}

void ADSSimCameraCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}