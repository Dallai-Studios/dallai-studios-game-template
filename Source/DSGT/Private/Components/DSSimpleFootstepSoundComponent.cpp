// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Components/DSSimpleFootstepSoundComponent.h"
#include "Kismet/GameplayStatics.h"

// ==============================================================
// Lifecycle Methods:
// ==============================================================
UDSSimpleFootstepSoundComponent::UDSSimpleFootstepSoundComponent() {
	PrimaryComponentTick.bCanEverTick = false;
}

void UDSSimpleFootstepSoundComponent::BeginPlay() {
	Super::BeginPlay();
}



// ==============================================================
// Component Methods:
// ==============================================================
void UDSSimpleFootstepSoundComponent::PlayWalkFootstepSound() {
	
}

void UDSSimpleFootstepSoundComponent::PlayRunningFootstepSound() {
	
}

void UDSSimpleFootstepSoundComponent::PlayStartJumpSound() {
	
}

void UDSSimpleFootstepSoundComponent::PlayFallLandSound() {
	
}