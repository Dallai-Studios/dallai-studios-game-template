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

void UDSGameGlobalEvents::AddItemToPlayerInventory(FString itemId) {
	if (this->playerInventory.Num() == 0) {
		UDSDebugTools::ShowDebugMessage(TEXT("Global key items has no elements"), FColor::Red);
		return;
	}

	bool* value = this->playerInventory.Find(itemId);
	if (value == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Item not found on player inventory"), FColor::Red);
		return;
	}

	if (*value) {
		UDSDebugTools::ShowDebugMessage(TEXT("Item already picked by the player"), FColor::Red);
		return;
	}

	*value = true;
}

void UDSGameGlobalEvents::ClearPlayerInventory() {
	for (auto& item : this->playerInventory) {
		item.Value = false;
	}
}

bool UDSGameGlobalEvents::ItemAlreadyPicked(FString itemId) const {
	if (this->playerInventory.Num() == 0) {
		UDSDebugTools::ShowDebugMessage(TEXT("Global key items has no elements"), FColor::Red);
		return false;
	}
	
	const bool* value = this->playerInventory.Find(itemId);
	if (value == NULL) return false;
	return *value;
}

void UDSGameGlobalEvents::ClearGameTriggers() {
	for (auto& trigger : this->gameEvents) {
		trigger.Value = false;
	}
}
