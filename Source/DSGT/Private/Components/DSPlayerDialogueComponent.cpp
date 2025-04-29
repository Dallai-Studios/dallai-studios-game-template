// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Components/DSPlayerDialogueComponent.h"

UDSPlayerDialogueComponent::UDSPlayerDialogueComponent() {
	PrimaryComponentTick.bCanEverTick = true;
}

void UDSPlayerDialogueComponent::BeginPlay() {
	Super::BeginPlay();
}

void UDSPlayerDialogueComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}