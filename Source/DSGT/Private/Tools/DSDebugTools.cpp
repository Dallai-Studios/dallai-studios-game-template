// Copyright (c) 2025 Dallai Studios. All Rights Reserved.


#include "Tools/DSDebugTools.h"

void UDSDebugTools::ShowDebugMessage(FString message, FColor color) {
	GEngine->AddOnScreenDebugMessage(-1, 10, color, message);
}
