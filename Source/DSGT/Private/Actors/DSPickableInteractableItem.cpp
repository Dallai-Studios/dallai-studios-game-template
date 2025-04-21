// Copyright (c) 2025 Dallai Studios. All Rights Reserved.


#include "Actors/DSPickableInteractableItem.h"

#include "Tools/DSDebugTools.h"

ADSPickableInteractableItem::ADSPickableInteractableItem() {
	PrimaryActorTick.bCanEverTick = false;

	this->pickableMesh = this->CreateDefaultSubobject<UStaticMeshComponent>("Pickable Item Mesh");
	this->pickableMesh->SetupAttachment(this->GetRootComponent());
}

void ADSPickableInteractableItem::BeginPlay() {
	Super::BeginPlay();
}

FText ADSPickableInteractableItem::GetInteractionVerb_Implementation() {
	return this->interactionVerb;
}

EDSInteractionType ADSPickableInteractableItem::GetInteractionType_Implementation() {
	return this->interactionType;
}

void ADSPickableInteractableItem::PerformInteraction_Implementation(AActor* instigatorActor) {
	// Maybe I can put the hole logic here. -Dallai
	UDSDebugTools::ShowDebugMessage(TEXT("I dont know what to do it this yet"), FColor::Magenta);	
}

void ADSPickableInteractableItem::OpenStaticInteractionHUD_Implementation() {
	UDSDebugTools::ShowDebugMessage(TEXT("Pickable Itens does not have interaction HUDS"), FColor::Cyan);
}

FString ADSPickableInteractableItem::GetItemId_Implementation() {
	return this->itemId;
}