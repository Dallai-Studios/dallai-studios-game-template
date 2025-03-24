// Copyright (c) 2025 Dallai Studios. All Rights Reserved.
#include "GameInstance/DSDefaultGameInstance.h"

#include "Data/DSGameClientOptionsPDA.h"
#include "Data/DSGameUserSettings.h"
#include "GameFramework/GameUserSettings.h"
#include "Tools/DSDebugTools.h"


// ==============================================================
// Life Cycle:
// ==============================================================
void UDSDefaultGameInstance::Init() {
	Super::Init();
	this->LoadGameClientOptions();
}

// ==============================================================
// Save and Load Game:
// ==============================================================
void UDSDefaultGameInstance::SaveGameClientOptions() {
	if (this->gameClientOptions == nullptr) {
		UDSDebugTools::ShowDebugMessage(TEXT("Game Client Options is null inside the game instance. Please create it and set on the game instance!"), FColor::Red);
		return;
	}
	
	UDSGameUserSettings* gameSettings = Cast<UDSGameUserSettings>(GEngine->GetGameUserSettings());
	
	// gameplaye settings
	gameSettings->SetMouseSensitivity(this->gameClientOptions->mouseSensitivity);
	gameSettings->SetInvertMouseAxisX(this->gameClientOptions->invertMouseX);
	gameSettings->SetInvertMouseAxisY(this->gameClientOptions->invertMouseY);

	// audio settings
	gameSettings->SetMasterVolume(this->gameClientOptions->masterVolume);
	gameSettings->SetMusicVolume(this->gameClientOptions->MusicVolume);
	gameSettings->SetSFXVolume(this->gameClientOptions->SFXVolume);

	// video settings
	FIntPoint gameResolution = FIntPoint(this->gameClientOptions->resolutionX, this->gameClientOptions->resolutionY);

	gameSettings->SetScreenResolution(gameResolution);
	gameSettings->SetFullscreenMode(EWindowMode::Type::Fullscreen);
	gameSettings->SetVSyncEnabled(this->gameClientOptions->bEnableVSync);
	gameSettings->SetShadowQuality(this->gameClientOptions->shadowQuality);
	gameSettings->SetGlobalIlluminationQuality(this->gameClientOptions->globalIlluminationQuality);
	gameSettings->SetTextureQuality(this->gameClientOptions->textureQuality);
	gameSettings->SetPostProcessingQuality(this->gameClientOptions->postProcessQuality);
	gameSettings->SetAntiAliasingQuality(this->gameClientOptions->antiAliasingQuality);
	gameSettings->SetVisualEffectQuality(this->gameClientOptions->vfxQuality);
	gameSettings->SetFoliageQuality(this->gameClientOptions->grassQuality);

	gameSettings->ApplyResolutionSettings(false);
	gameSettings->ApplyNonResolutionSettings();
	gameSettings->ApplySettings(false);
	gameSettings->SaveSettings();

	UDSDebugTools::ShowDebugMessage(TEXT("New settings applied and saved!"), FColor::Green);
}

void UDSDefaultGameInstance::LoadGameClientOptions() {
	if (!IsValid(this->gameClientOptions)) {
		UDSDebugTools::ShowDebugMessage(TEXT("Game Client Options is null inside the game instance. Please create it and set on the game instance!"), FColor::Red);
		return;
	}

	UGameUserSettings* gameSettings = GEngine->GetGameUserSettings();

	gameSettings->LoadSettings();
	this->gameClientOptions->resolutionX = gameSettings->GetScreenResolution().X;
	this->gameClientOptions->resolutionY = gameSettings->GetScreenResolution().Y;
	this->gameClientOptions->bEnableVSync = gameSettings->IsVSyncEnabled();
	this->gameClientOptions->shadowQuality = gameSettings->GetShadowQuality();
	this->gameClientOptions->globalIlluminationQuality = gameSettings->GetGlobalIlluminationQuality();
	this->gameClientOptions->textureQuality = gameSettings->GetTextureQuality();
	this->gameClientOptions->postProcessQuality = gameSettings->GetPostProcessingQuality();
	this->gameClientOptions->antiAliasingQuality = gameSettings->GetAntiAliasingQuality();
	this->gameClientOptions->vfxQuality = gameSettings->GetVisualEffectQuality();
	this->gameClientOptions->grassQuality = gameSettings->GetFoliageQuality();

	
}