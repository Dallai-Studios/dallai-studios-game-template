// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Data/DSPlayerInventoryPDA.h"
#include "Data/DSItemDataPDA.h"
#include "Tools/DSDebugTools.h"

bool UDSPlayerInventoryPDA::PlayerHasItem(FString itemId) const {
	if (this->items.Num() == 0) return false;

	for (auto item : this->items) {
		if (item->itemId == itemId) return true;
	}
	
	return false;
}

void UDSPlayerInventoryPDA::AddNewItemToPlayerInventory(UDSItemDataPDA* newItem) {
	this->items.Push(newItem);
}

void UDSPlayerInventoryPDA::RemoveItemFromInventory(FString itemId) {
	if (this->items.Num() == 0) return;
	
	UDSItemDataPDA* foundItem = NULL;
	
	for (auto item : this->items) {
		if (item->itemId == itemId) {
			foundItem = item;
			break;
		}
	}

	if (!foundItem) {
		UDSDebugTools::ShowDebugMessage(TEXT("Item not found to remove on the player inventory Data Asset"), FColor::Red);
		return;
	}
	
	this->items.Remove(foundItem);
}

void UDSPlayerInventoryPDA::ClearPlayerInventory() {
	this->items.Empty();
}