// Copyright (c) 2025 Dallai Studios. All Rights Reserved.


#include "HUD/DSBaseGameClientOptionsHUD.h"

#include "GameInstance/DSDefaultGameInstance.h"
#include "Tools/DSDebugTools.h"

void UDSBaseGameClientOptionsHUD::ApplyGameClientOptionOnGameInstance() {
	UDSDefaultGameInstance* gameInstance = Cast<UDSDefaultGameInstance>(this->GetWorld()->GetGameInstance());

	if (!gameInstance) {
		UDSDebugTools::ShowDebugMessage(TEXT("Game Instance is null or invalid"), FColor::Red);
		return;
	}

	gameInstance->SaveGameClientOptions();
}
