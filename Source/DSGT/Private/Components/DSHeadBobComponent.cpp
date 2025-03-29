// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Components/DSHeadBobComponent.h"
#include "Kismet/GameplayStatics.h"

// ==============================================================
// Lifecycle Methods:
// ==============================================================
UDSHeadBobComponent::UDSHeadBobComponent() {
	PrimaryComponentTick.bCanEverTick = false;
}

void UDSHeadBobComponent::BeginPlay() {
	Super::BeginPlay();
}



// ==============================================================
// Component Methods:
// ==============================================================
void UDSHeadBobComponent::PlayIdleHeadBob() {
	UGameplayStatics::GetPlayerCameraManager(this->GetWorld(), 0)->StartCameraShake(this->idleCameraShake);
}

void UDSHeadBobComponent::PlayWalkHeadBob() {
	UGameplayStatics::GetPlayerCameraManager(this->GetWorld(), 0)->StartCameraShake(this->walkCameraShake);
}

void UDSHeadBobComponent::PlayRunningHeadBob() {
	UGameplayStatics::GetPlayerCameraManager(this->GetWorld(), 0)->StartCameraShake(this->runCameraShake);
}