// Copyright (c) 2025 Dallai Studios. All Rights Reserved.


#include "DSDialogueHUD.h"
void UDSDialogueHUD::BuildDialogueData(FText characterName, FString dialogueLine, float dialogueDuration) {
	this->cachedCharacterName = characterName;
	this->cachedDialogueLine = dialogueLine;
	this->cacehdDialogueDuration = dialogueDuration;
}

void UDSDialogueHUD::AnimateDialogue() {
	
}
