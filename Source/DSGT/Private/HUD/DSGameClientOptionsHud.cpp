// Copyright (c) 2025 Dallai Studios. All Rights Reserved.


#include "HUD/DSGameClientOptionsHud.h"
#include "GameInstance/DSDefaultGameInstance.h"

class UDSDefaultGameInstance;

void UDSGameClientOptionsHud::ApplyGameSettings() {
	if (UDSDefaultGameInstance* gameInstance = Cast<UDSDefaultGameInstance>(this->GetGameInstance())) {
		gameInstance->ApplyGameClientOptions();
		gameInstance->SaveGameClientOptions();
	}
}
