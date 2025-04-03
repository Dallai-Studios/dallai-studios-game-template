// Copyright (c) 2025 Dallai Studios. All Rights Reserved.


#include "HUD/DSBaseInteractionHUD.h"
void UDSBaseInteractionHUD::SetInteractionVerbText(FText newText) {
	this->interactionVerbText = newText;
}

FText UDSBaseInteractionHUD::GetInteractionVerbText() {
	return this->interactionVerbText;
}

