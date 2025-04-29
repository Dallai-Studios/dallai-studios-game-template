// Copyright (c) 2025 Dallai Studios. All Rights Reserved.


#include "Data/DSDialogueContainerPDA.h"
FDSDialogueEntry UDSDialogueContainerPDA::GetDialogue(FString dialogueId) const {
	auto entry = this->dialogueContainer.Find(dialogueId);
	return *entry;
}
