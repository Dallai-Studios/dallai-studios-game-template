// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "DSDialogueHUD.h"

void UDSDialogueHUD::StartNewDialogue(FText characterNameToDisplay, FString originalDialogueText, float dialogueAnimationInterval) {
	this->cachedCharacterName = characterNameToDisplay;
	this->dialogueStringText = "";
	this->dialogueFullStringText = originalDialogueText;
	this->currentTextIndex = 0;

	this->GetWorld()->GetTimerManager().ClearTimer(this->dialogueAnimationTimeHandle);

	this->GetWorld()->GetTimerManager().SetTimer(
		this->dialogueAnimationTimeHandle,
		this,
		&UDSDialogueHUD::UpdateDialogueText,
		dialogueAnimationInterval,
		true
	);
}

void UDSDialogueHUD::UpdateDialogueText() {
	if (this->currentTextIndex < this->dialogueFullStringText.Len()) {
		this->dialogueStringText += this->dialogueFullStringText[currentTextIndex++];
		this->finalDialogueText = FText::FromString(this->dialogueStringText);
		return;
	} 

	this->GetWorld()->GetTimerManager().ClearTimer(this->dialogueAnimationTimeHandle);
}

