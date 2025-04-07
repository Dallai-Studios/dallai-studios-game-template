// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Actors/DSInteractableItem.h"

#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
#include "Tools/DSDebugTools.h"

ADSInteractableItem::ADSInteractableItem() {
	PrimaryActorTick.bCanEverTick = true;

	this->staticMesh = this->CreateDefaultSubobject<UStaticMeshComponent>("Interacatable Static Mesh");
	this->staticMesh->SetupAttachment(this->GetRootComponent());

	this->staticCamera = this->CreateDefaultSubobject<UCameraComponent>("Static Camera");
	this->staticCamera->SetupAttachment(this->staticMesh);
}

void ADSInteractableItem::BeginPlay() {
	Super::BeginPlay();

	if (this->interactionType == EDSInteractionType::STATIC) {
		if (this->interactableHud != NULL) {
			this->interactableHUDInstance = CreateWidget(this->GetWorld(), this->interactableHud);
			this->interactableHUDInstance->AddToViewport();
			this->interactableHUDInstance->SetVisibility(ESlateVisibility::Collapsed);	
		} else {
			UDSDebugTools::ShowDebugMessage(TEXT("Interactable HUD Reference is not defined on the Interactable Item"));
		}
	}
}

void ADSInteractableItem::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

FText ADSInteractableItem::GetInteractionVerb_Implementation() {
	return this->interactionName;
}

EDSInteractionType ADSInteractableItem::GetInteractionType_Implementation() {
	return this->interactionType;
}

void ADSInteractableItem::PerformInteraction_Implementation(AActor* instigatorActor) {
	// I don't think any behavior here will be good at this point. But who knows.
	// I Believe that, at some point I'll need some form of basic behaior to handle some general
	// interactions, but at this point, it is not necessary. -Dallai
	UDSDebugTools::ShowDebugMessage(TEXT("Interaction Performed. Override this methods to make something usefull out of it"));
}

void ADSInteractableItem::OpenStaticInteractionHUD_Implementation() {
	if (this->interactableHUDInstance == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Interactable HUD is not defined on the Interactable Item"));
		return;
	}
	this->interactableHUDInstance->SetVisibility(ESlateVisibility::Visible);
}
