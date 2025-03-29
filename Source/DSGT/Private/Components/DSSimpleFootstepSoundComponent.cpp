// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Components/DSSimpleFootstepSoundComponent.h"

#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Tools/DSDebugTools.h"

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
	if (this->createdWalkSound == NULL) {
		this->createdWalkSound = UGameplayStatics::CreateSound2D(this->GetWorld(), this->walkSound);
	}

	if (this->createdRunningSound != NULL) this->createdRunningSound->Stop();
	
	this->createdWalkSound->Play();
}

void UDSSimpleFootstepSoundComponent::PlayRunningFootstepSound() {
	if (this->createdRunningSound == NULL) {
		this->createdRunningSound = UGameplayStatics::CreateSound2D(this->GetWorld(), this->runningSound);
	}

	if (this->createdWalkSound != NULL) this->createdWalkSound->Stop();
	
	this->createdWalkSound->Play();
}

void UDSSimpleFootstepSoundComponent::PlayStartJumpSound() {
	UGameplayStatics::PlaySound2D(this->GetWorld(), this->jumpStartSound);	
}

void UDSSimpleFootstepSoundComponent::PlayFallLandSound() {
	UGameplayStatics::PlaySound2D(this->GetWorld(), this->fallLandSound);	
}

void UDSSimpleFootstepSoundComponent::StopAllSounds() {
	if (this->createdWalkSound != NULL) this->createdWalkSound->Stop();
	if (this->createdRunningSound != NULL) this->createdRunningSound->Stop();
}
