// Copyright (c) 2025 Dallai Studios. All Rights Reserved.


#include "Actors/DSPickableInteractableItem.h"

#include "Data/DSGameGlobalEvents.h"
#include "Tools/DSDebugTools.h"

ADSPickableInteractableItem::ADSPickableInteractableItem() {
	PrimaryActorTick.bCanEverTick = false;

	this->pickableMesh = this->CreateDefaultSubobject<UStaticMeshComponent>("Pickable Item Mesh");
	this->pickableMesh->SetupAttachment(this->GetRootComponent());
}

void ADSPickableInteractableItem::BeginPlay() {
	Super::BeginPlay();

	if (!this->gameGlobalEvents) {
		UDSDebugTools::ShowDebugMessage(TEXT("Game Global Events is not defined for the interactable item"), FColor::Red);
		return;
	}

	if (this->gameGlobalEvents->ItemAlreadyPicked(this->itemId)) {
		this->Destroy();
		UDSDebugTools::ShowDebugMessage(TEXT("Player already have this item. Skipping it"), FColor::Blue);
	}
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

	if (this->gameGlobalEvents == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Game Global Events is not defined. Define it first!"), FColor::Red);
		return;
	}

	this->gameGlobalEvents->AddItemToPlayerInventory(this->itemId);
	
	this->gameGlobalEvents->OnPickUpItem.Broadcast(this->itemName);
	
	if (this->Destroy()) {
		UDSDebugTools::ShowDebugMessage(TEXT("Pickable item destroyed"), FColor::Green);
	} else {
		UDSDebugTools::ShowDebugMessage(TEXT("Pickable Item cant be destroyed. Maybe is set to be indestroctable"), FColor::Red);
	}
}

void ADSPickableInteractableItem::OpenStaticInteractionHUD_Implementation() {
	UDSDebugTools::ShowDebugMessage(TEXT("Pickable Itens does not have interaction HUDS"), FColor::Cyan);
}

FString ADSPickableInteractableItem::GetItemId_Implementation() {
	return this->itemId;
}