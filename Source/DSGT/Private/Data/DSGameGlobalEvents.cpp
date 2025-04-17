// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Data/DSGameGlobalEvents.h"

#include "Tools/DSDebugTools.h"

bool UDSGameGlobalEvents::IsGamePaused() const {
	return this->bIsGamePaused;
}

void UDSGameGlobalEvents::PauseGame() {
	this->bIsGamePaused = true;
}

void UDSGameGlobalEvents::UnpauseGame() {
	this->bIsGamePaused = false;
}

bool UDSGameGlobalEvents::ItemAlreadyPicked(FString itemId) const {
	if (this->gameKeyItemsAlreadyPicked.Num() == 0) {
		UDSDebugTools::ShowDebugMessage(TEXT("Global key items has no elements"), FColor::Red);
		return false;
	}
	
	const bool* value = this->gameKeyItemsAlreadyPicked.Find(itemId);
	if (value == NULL) return false;
	return *value;
}