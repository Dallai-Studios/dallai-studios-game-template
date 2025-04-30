// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Components/DSPlayerDialogueComponent.h"

#include "Data/DSDialogueContainerPDA.h"
#include "DSGT/DSDialogueHUD.h"
#include "Tools/DSDebugTools.h"

UDSPlayerDialogueComponent::UDSPlayerDialogueComponent() {
	PrimaryComponentTick.bCanEverTick = true;
}

void UDSPlayerDialogueComponent::BeginPlay() {
	Super::BeginPlay();
	
	this->hasActiveDialogue = false;
	this->currentDialogueEntryIndex = 0;
	
	if (this->dialogueHudReference == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Dialogue Hud Reference is not defined on the Player Dialogue Interaction"));
		return;
	}
	
	this->dialogueHudInstance = Cast<UDSDialogueHUD>(CreateWidget(this->dialogueHudReference));
	
	if (dialogueHudInstance) {
		this->dialogueHudInstance->AddToViewport();
		this->dialogueHudInstance->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UDSPlayerDialogueComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UDSPlayerDialogueComponent::ShowDialogue(UDSDialogueContainerPDA* dialogueContainer) {
	if (this->dialogueHudInstance == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Dialogue HUD Instance is not defined on Player Dialogue Component"));
		return;
	}

	this->dialogueContainer = dialogueContainer;

	FDSDialogueEntry currentEntry = this->dialogueContainer->dialogueEntries[this->currentDialogueEntryIndex];
	
	if (this->dialogueHudInstance) {
		this->dialogueHudInstance->StartNewDialogue(currentEntry.characterName, currentEntry.dialogueText.ToString(), this->dialogueAnimationInterval);
	}
}

bool UDSPlayerDialogueComponent::HasActiveDialogue() const {
	return this->hasActiveDialogue;
}
