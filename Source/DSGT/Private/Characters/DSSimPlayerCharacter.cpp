// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Characters/DSSimPlayerCharacter.h"

ADSSimPlayerCharacter::ADSSimPlayerCharacter() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADSSimPlayerCharacter::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void ADSSimPlayerCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}