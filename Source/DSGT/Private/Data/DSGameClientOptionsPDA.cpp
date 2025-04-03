// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Data/DSGameClientOptionsPDA.h"

#include "GameInstance/DSDefaultGameInstance.h"

void UDSGameClientOptionsPDA::ResetClientOptions() {
	this->mouseSensitivity = 1;
	this->bInvertMouseX = false;
	this->bInvertMouseY = false;
	
	this->masterVolume = 1;
	this->musicVolume = 1;
	this->sfxVolume = 1;

	this->resolutionX = 1920;
	this->resolutionY = 1080;
	this->windowMode = EWindowMode::Type::Fullscreen;
	this->bEnableVSync = false;
	this->frameRateLimit = 0;
	this->shadowQuality = 3;
	this->textureQuality = 3;
	this->postProcessQuality = 3;
	this->vfxQuality = 3;
	this->grassQuality = 3;
	this->globalIlluminationQuality = 3;
	this->antiAliasingQuality = 3;
	this->shaderQuality = 3;
	this->reflectionQuality = 3;
	this->viewDistanceQuality = 3;

	this->resolutionSelectedIndex = 4;
	this->framerateSelectedIndex = 0;
}