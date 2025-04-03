// Copyright (c) 2025 Dallai Studios. All Rights Reserved.


#include "Actors/DSInteractableItem.h"


// Sets default values
ADSInteractableItem::ADSInteractableItem() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADSInteractableItem::BeginPlay() {
	Super::BeginPlay();
	
}

// Called every frame
void ADSInteractableItem::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

FText ADSInteractableItem::GetInteractableVerb_Implementation() {
	return this->interactionName;
}
