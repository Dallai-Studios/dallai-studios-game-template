// Copyright (c) 2025 Dallai Studios. All Rights Reserved.


#include "Tools/DSDebugTools.h"

void UDSDebugTools::ShowDebugMessage(FString message, FColor color, float time) {
	GEngine->AddOnScreenDebugMessage(-1, time, color, message);
}
