// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Data/DSPlayerInventoryPDA.h"
#include "Data/DSItemDataPDA.h"
#include "Tools/DSDebugTools.h"

bool UDSPlayerInventoryPDA::PlayerHasItem(FString itemId) const {
	if (this->inventory.Num() == 0) return false;
	for (FString onInventoryItemId : this->inventory) {
		if (onInventoryItemId == itemId) return true;
	}
	return false;
}

void UDSPlayerInventoryPDA::AddNewItemToPlayerInventory(FString newItem) {
	this->inventory.Push(newItem);
}

void UDSPlayerInventoryPDA::RemoveItemFromInventory(FString itemId) {
	if (this->inventory.Remove(itemId) == 0) {
		UDSDebugTools::ShowDebugMessage(TEXT("Item not found to remove on the player inventory"));
		return;
	}
}

void UDSPlayerInventoryPDA::ClearPlayerInventory() {
	this->inventory.Empty();
}