// Copyright (c) 2025 Dallai Studios. All Rights Reserved.


#include "Data/DSDialogueContainerPDA.h"
TArray<FDSDialogueEntry>* UDSDialogueContainerPDA::GetDialogue(FString dialogueId) const {
	auto dialogueEntries = this->dialogueContainer.Find(dialogueId);
}
