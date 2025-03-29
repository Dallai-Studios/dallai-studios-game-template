// Copyright (c) 2025 Dallai Studios. All Rights Reserved.


#include "Components/DSGamePauseComponent.h"

UDSGamePauseComponent::UDSGamePauseComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void UDSGamePauseComponent::BeginPlay() {
	Super::BeginPlay();
}

void UDSGamePauseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

