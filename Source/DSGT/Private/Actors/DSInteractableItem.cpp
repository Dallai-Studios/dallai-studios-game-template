// Copyright (c) 2025 Dallai Studios. All Rights Reserved.


#include "Actors/DSInteractableItem.h"

#include "Camera/CameraComponent.h"

// Sets default values
ADSInteractableItem::ADSInteractableItem() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->staticMesh = this->CreateDefaultSubobject<UStaticMeshComponent>("Interacatable Static Mesh");
	this->staticMesh->SetupAttachment(this->GetRootComponent());

	this->staticCamera = this->CreateDefaultSubobject<UCameraComponent>("Static Camera");
	this->staticCamera->SetupAttachment(this->staticMesh);
}

// Called when the game starts or when spawned
void ADSInteractableItem::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void ADSInteractableItem::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

FText ADSInteractableItem::GetInteractionVerb_Implementation() {
	return this->interactionName;
}
