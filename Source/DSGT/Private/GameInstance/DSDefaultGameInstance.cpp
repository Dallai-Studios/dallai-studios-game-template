// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "GameInstance/DSDefaultGameInstance.h"
#include "Data/DSGameClientOptionsPDA.h"
#include "Data/DSGameUserSettings.h"
#include "Data/DSPlayerInventoryPDA.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/GameplayStatics.h"
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
	gameSettings->SetInvertMouseAxisX(this->gameClientOptions->bInvertMouseX);
	gameSettings->SetInvertMouseAxisY(this->gameClientOptions->bInvertMouseY);

	// audio settings
	gameSettings->SetMasterVolume(this->gameClientOptions->masterVolume);
	gameSettings->SetMusicVolume(this->gameClientOptions->musicVolume);
	gameSettings->SetSFXVolume(this->gameClientOptions->sfxVolume);

	this->UpdateClientSoundOptions();

	// video settings
	FIntPoint gameResolution = FIntPoint(this->gameClientOptions->resolutionX, this->gameClientOptions->resolutionY);

	gameSettings->SetScreenResolution(gameResolution);
	gameSettings->SetFrameRateLimit(this->gameClientOptions->frameRateLimit);
	gameSettings->SetFullscreenMode(this->ConvertWindowMode(this->gameClientOptions->windowMode));
	gameSettings->SetVSyncEnabled(this->gameClientOptions->bEnableVSync);
	gameSettings->SetShadowQuality(this->gameClientOptions->shadowQuality);
	gameSettings->SetGlobalIlluminationQuality(this->gameClientOptions->globalIlluminationQuality);
	gameSettings->SetTextureQuality(this->gameClientOptions->textureQuality);
	gameSettings->SetPostProcessingQuality(this->gameClientOptions->postProcessQuality);
	gameSettings->SetAntiAliasingQuality(this->gameClientOptions->antiAliasingQuality);
	gameSettings->SetVisualEffectQuality(this->gameClientOptions->vfxQuality);
	gameSettings->SetFoliageQuality(this->gameClientOptions->grassQuality);
	gameSettings->SetShadingQuality(this->gameClientOptions->shaderQuality);
	gameSettings->SetViewDistanceQuality(this->gameClientOptions->viewDistanceQuality);
	gameSettings->SetReflectionQuality(this->gameClientOptions->reflectionQuality);

	// aplica e salva as configurações no arquivo
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

	UDSGameUserSettings* gameSettings = Cast<UDSGameUserSettings>(GEngine->GetGameUserSettings());
	
	gameSettings->LoadSettings();

	// load the gameplay settings
	this->gameClientOptions->mouseSensitivity = gameSettings->GetMouseSensitivity();
	this->gameClientOptions->bInvertMouseX = gameSettings->GetInvertMouseAxisX();
	this->gameClientOptions->bInvertMouseY = gameSettings->GetInvertMouseAxisY();
	this->gameClientOptions

	// load the audio settings
	this->gameClientOptions->masterVolume = gameSettings->GetMasterVolume();
	this->gameClientOptions->musicVolume = gameSettings->GetMusicVolume();
	this->gameClientOptions->sfxVolume = gameSettings->GetSFXVolume();

	// load the video settings
	this->gameClientOptions->resolutionX = gameSettings->GetScreenResolution().X;
	this->gameClientOptions->resolutionY = gameSettings->GetScreenResolution().Y;
	this->gameClientOptions->windowMode = gameSettings->GetFullscreenMode();
	this->gameClientOptions->frameRateLimit = gameSettings->GetFrameRateLimit();
	this->gameClientOptions->bEnableVSync = gameSettings->IsVSyncEnabled();
	this->gameClientOptions->frameRateLimit = gameSettings->GetFrameRateLimit();
	this->gameClientOptions->shadowQuality = gameSettings->GetShadowQuality();
	this->gameClientOptions->globalIlluminationQuality = gameSettings->GetGlobalIlluminationQuality();
	this->gameClientOptions->textureQuality = gameSettings->GetTextureQuality();
	this->gameClientOptions->postProcessQuality = gameSettings->GetPostProcessingQuality();
	this->gameClientOptions->antiAliasingQuality = gameSettings->GetAntiAliasingQuality();
	this->gameClientOptions->vfxQuality = gameSettings->GetVisualEffectQuality();
	this->gameClientOptions->grassQuality = gameSettings->GetFoliageQuality();
	this->gameClientOptions->shaderQuality = gameSettings->GetShadingQuality();
	this->gameClientOptions->viewDistanceQuality = gameSettings->GetViewDistanceQuality();
	this->gameClientOptions->reflectionQuality = gameSettings->GetReflectionQuality();

	this->UpdateClientSoundOptions();

	gameSettings->ApplyResolutionSettings(false);
	gameSettings->ApplyNonResolutionSettings();
	gameSettings->ApplySettings(false);

	UDSDebugTools::ShowDebugMessage(TEXT("All settings have been loaded and applied!"), FColor::Green);
}

void UDSDefaultGameInstance::UpdateClientSoundOptions() {
	if (this->mainSoundMixer == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Main sound mixer is null on the game instance. Please define a sound mixer to the game inside the game instance"), FColor::Red);
		return;
	}

	if (this->masterSoundClass == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Master sound class is not defined on the game instance. Please define the master sound class inside the game instance"), FColor::Red);
	}
	
	if (this->musicSoundClass == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Music sound class is not defined on the game instance. Please define the music sound class inside the game instance"), FColor::Red);
		return;
	}

	if (this->sfxSoundClass == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("SFX sound class is not defined on the game instance. Please define the SFX sound class inside the game instance"), FColor::Red);
		return;
	}
	
	UGameplayStatics::SetSoundMixClassOverride(this->GetWorld(), this->mainSoundMixer, this->masterSoundClass, this->gameClientOptions->masterVolume);
	UGameplayStatics::SetSoundMixClassOverride(this->GetWorld(), this->mainSoundMixer, this->musicSoundClass, this->gameClientOptions->masterVolume	);
	UGameplayStatics::SetSoundMixClassOverride(this->GetWorld(), this->mainSoundMixer, this->sfxSoundClass, this->gameClientOptions->masterVolume);
	UGameplayStatics::SetBaseSoundMix(this->GetWorld(), this->mainSoundMixer);
}

// ==============================================================
// Helper Functions:
// ==============================================================
EWindowMode::Type UDSDefaultGameInstance::ConvertWindowMode(int windowModeValue) {
	if (windowModeValue == 0) return EWindowMode::Type::Fullscreen;
	if (windowModeValue == 1) return EWindowMode::Type::WindowedFullscreen;
	if (windowModeValue == 2) return EWindowMode::Type::Windowed;
	return EWindowMode::Type::Fullscreen;
}

void UDSDefaultGameInstance::GiveItem(FString itemId) {
	if (!this->playerInventory) {
		UDSDebugTools::ShowDebugMessage(TEXT("Player Inventory is not defined on game instance"), FColor::Red);
		return;
	}
	this->playerInventory->AddNewItemToPlayerInventory(itemId);
}

void UDSDefaultGameInstance::ClearInventory() {
	if (!this->playerInventory) {
		UDSDebugTools::ShowDebugMessage(TEXT("Player Inventory is not defined on game instance"), FColor::Red);
		return;
	}
	this->playerInventory->ClearPlayerInventory();
}