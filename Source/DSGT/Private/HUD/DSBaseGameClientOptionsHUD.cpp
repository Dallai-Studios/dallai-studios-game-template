// Copyright (c) 2025 Dallai Studios. All Rights Reserved.


#include "HUD/DSBaseGameClientOptionsHUD.h"

#include "Data/DSGameClientOptionsPDA.h"
#include "GameInstance/DSDefaultGameInstance.h"
#include "Tools/DSDebugTools.h"

void UDSBaseGameClientOptionsHUD::UpdateMouseSensitivity(float value) {
	if (value == this->gameClientOptions->mouseSensitivity) return;
	if (value < 0) value = 0;
	if (value > 2) value = 2;
	this->gameClientOptions->mouseSensitivity = value;
}

void UDSBaseGameClientOptionsHUD::ToggleInvertMouseX() {
	this->gameClientOptions->bInvertMouseX = !this->gameClientOptions->bInvertMouseX;
}

void UDSBaseGameClientOptionsHUD::ToggleInvertMouseY() {
	this->gameClientOptions->bInvertMouseY = !this->gameClientOptions->bInvertMouseY;
}

void UDSBaseGameClientOptionsHUD::UpdateMasterVolume(float value) {
	if (value == this->gameClientOptions->masterVolume) return;
	if (value < 0) value = 0;
	if (value > 1) value = 1;
	this->gameClientOptions->masterVolume = value;
}

void UDSBaseGameClientOptionsHUD::UpdateMusicVolume(float value) {
	if (value == this->gameClientOptions->musicVolume) return;
	if (value < 0) value = 0;
	if (value > 1) value = 1;
	this->gameClientOptions->musicVolume = value;
}

void UDSBaseGameClientOptionsHUD::UpdateSfxVolume(float value) {
	if (value == this->gameClientOptions->sfxVolume) return;
	if (value < 0) value = 0;
	if (value > 1) value = 1;
	this->gameClientOptions->sfxVolume = value;
}

void UDSBaseGameClientOptionsHUD::ChangeWindowMode(EDSGameClientOptionsChangeType type) {
	
}

void UDSBaseGameClientOptionsHUD::ChangeResolution(EDSGameClientOptionsChangeType type) {
	
}

void UDSBaseGameClientOptionsHUD::ToggleVsync(bool value) {
	this->gameClientOptions->bEnableVSync = !this->gameClientOptions->bEnableVSync;
}

void UDSBaseGameClientOptionsHUD::ChangeFramerate(EDSGameClientOptionsChangeType type) {
	if (type == EDSGameClientOptionsChangeType::NEXT) {

		return;
	}

	
}

void UDSBaseGameClientOptionsHUD::ChangeShadowQuality(EDSGameClientOptionsChangeType type) {
	if (type == EDSGameClientOptionsChangeType::NEXT) {
		if (this->gameClientOptions->shadowQuality == 4) return;
		this->gameClientOptions->shadowQuality++;
		return;
	}

	if (this->gameClientOptions->shadowQuality == 0) return;
	this->gameClientOptions->shadowQuality--;
}

void UDSBaseGameClientOptionsHUD::ChangeTextureQuality(EDSGameClientOptionsChangeType type) {
	if (type == EDSGameClientOptionsChangeType::NEXT) {
		if (this->gameClientOptions->textureQuality == 4) return;
		this->gameClientOptions->textureQuality++;
		return;
	}

	if (this->gameClientOptions->textureQuality == 0) return;
	this->gameClientOptions->textureQuality--;
}

void UDSBaseGameClientOptionsHUD::ChangeGlobalIlluminationQuality(EDSGameClientOptionsChangeType type) {
	if (type == EDSGameClientOptionsChangeType::NEXT) {
		if (this->gameClientOptions->globalIlluminationQuality == 4) return;
		this->gameClientOptions->globalIlluminationQuality++;
		return;
	}

	if (this->gameClientOptions->globalIlluminationQuality == 0) return;
	this->gameClientOptions->globalIlluminationQuality--;
}

void UDSBaseGameClientOptionsHUD::ChangePostProcessQuality(EDSGameClientOptionsChangeType type) {
	if (type == EDSGameClientOptionsChangeType::NEXT) {
		if (this->gameClientOptions->postProcessQuality == 4) return;
		this->gameClientOptions->postProcessQuality++;
		return;
	}

	if (this->gameClientOptions->postProcessQuality == 0) return;
	this->gameClientOptions->postProcessQuality--;
}

void UDSBaseGameClientOptionsHUD::ChangeVFXQuality(EDSGameClientOptionsChangeType type) {
	if (type == EDSGameClientOptionsChangeType::NEXT) {
		if (this->gameClientOptions->vfxQuality == 4) return;
		this->gameClientOptions->vfxQuality++;
		return;
	}

	if (this->gameClientOptions->vfxQuality == 0) return;
	this->gameClientOptions->vfxQuality--;
}

void UDSBaseGameClientOptionsHUD::ChangeAntiAliasingQuality(EDSGameClientOptionsChangeType type) {
	if (type == EDSGameClientOptionsChangeType::NEXT) {
		if (this->gameClientOptions->antiAliasingQuality == 4) return;
		this->gameClientOptions->antiAliasingQuality++;
		return;
	}

	if (this->gameClientOptions->antiAliasingQuality == 0) return;
	this->gameClientOptions->antiAliasingQuality--;
}

void UDSBaseGameClientOptionsHUD::ApplyGameClientOptionOnGameInstance() {
	UDSDefaultGameInstance* gameInstance = Cast<UDSDefaultGameInstance>(this->GetWorld()->GetGameInstance());

	if (!gameInstance) {
		UDSDebugTools::ShowDebugMessage(TEXT("Game Instance is null or invalid"), FColor::Red);
		return;
	}

	gameInstance->SaveGameClientOptions();
}
