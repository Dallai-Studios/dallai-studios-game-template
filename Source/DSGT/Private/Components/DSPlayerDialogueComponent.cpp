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

void UDSPlayerDialogueComponent::ShowDialogue(FString& dialogueId) {
	if (this->dialogueContainer == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Dialogue Container is not defined on Player Dialogue Component"));
		return;
	}

	if (this->dialogueHudInstance == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Dialogue HUD Instance is not defined on Player Dialogue Component"));
		return;
	}
	
	FDSDialogueEntry dialogue = this->dialogueContainer->GetDialogue(dialogueId);

	if (this->dialogueHudInstance) {
	}
}
