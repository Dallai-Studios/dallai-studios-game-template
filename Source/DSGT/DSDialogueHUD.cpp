// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "DSDialogueHUD.h"

void UDSDialogueHUD::StartNewDialogue(FText characterName, FString& dialogueText, float dialogueAnimationInterval) {
	this->cachedCharacterName = characterName;
	this->dialogueStringText = "";
	this->dialogueFullStringText = dialogueFullStringText;
	this->currentTextIndex = 0;

	this->GetWorld()->GetTimerManager().ClearTimer(this->dialogueTypingHandle);

	this->GetWorld()->GetTimerManager().SetTimer(
		this->dialogueTypingHandle,
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
	} else {
		this->GetWorld()->GetTimerManager().ClearTimer(this->dialogueTypingHandle);
	}
}

