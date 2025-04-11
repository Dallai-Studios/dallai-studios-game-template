// Copyright (c) 2025 Dallai Studios. All Rights Reserved.


#include "Data/DSGameGlobalEvents.h"
bool UDSGameGlobalEvents::IsGamePaused() const {
	return this->bIsGamePaused;
}

void UDSGameGlobalEvents::PauseGame() {
	this->bIsGamePaused = true;
}

void UDSGameGlobalEvents::UnpauseGame() {
	this->bIsGamePaused = true;
}