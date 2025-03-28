// Copyright (c) 2025 Dallai Studios. All Rights Reserved.


#include "Characters/DSFirstPersonCharacter.h"


// Sets default values
ADSFirstPersonCharacter::ADSFirstPersonCharacter() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADSFirstPersonCharacter::BeginPlay() {
	Super::BeginPlay();
	
}

// Called every frame
void ADSFirstPersonCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ADSFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

