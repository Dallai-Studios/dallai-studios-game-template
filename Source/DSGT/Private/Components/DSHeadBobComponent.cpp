// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Components/DSHeadBobComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Tools/DSDebugTools.h"

// ==============================================================
// Lifecycle Methods:
// ==============================================================
UDSHeadBobComponent::UDSHeadBobComponent() {
	PrimaryComponentTick.bCanEverTick = false;
}

void UDSHeadBobComponent::BeginPlay() {
	Super::BeginPlay();

	if (this->idleCameraShake == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Idle Camera Shake is not defined inside the Camera Headbob Component"));
		return;
	}

	if (this->walkCameraShake == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Walk Camera Shake is not defined inside the Camera Headbob Component"));
		return;
	}
	
	if (this->runCameraShake == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Running Camera Shake is not defined inside the Camera Headbob Component"));
		return;
	}
}



// ==============================================================
// Component Methods:
// ==============================================================
void UDSHeadBobComponent::PlayIdleHeadBob() {
	if (this->idleCameraShake == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Idle Camera Shake is not defined inside the Camera Headbob Component"));
		return;
	}
	
	UGameplayStatics::GetPlayerCameraManager(this->GetWorld(), 0)->StartCameraShake(this->idleCameraShake);
}

void UDSHeadBobComponent::PlayWalkHeadBob() {
	if (this->walkCameraShake == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Walk Camera Shake is not defined inside the Camera Headbob Component"));
		return;
	}
	
	UGameplayStatics::GetPlayerCameraManager(this->GetWorld(), 0)->StartCameraShake(this->walkCameraShake);
}

void UDSHeadBobComponent::PlayRunningHeadBob() {
	if (this->runCameraShake == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Running Camera Shake is not defined inside the Camera Headbob Component"));
		return;
	}
	
	UGameplayStatics::GetPlayerCameraManager(this->GetWorld(), 0)->StartCameraShake(this->runCameraShake);
}
