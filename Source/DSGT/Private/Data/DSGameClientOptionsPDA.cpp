// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Data/DSGameClientOptionsPDA.h"

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
	this->frameRateLimit = 240;
	this->shadowQuality = 1;
	this->textureQuality = 1;
	this->postProcessQuality = 1;
	this->vfxQuality = 1;
	this->grassQuality = 1;
	this->globalIlluminationQuality = 1;
	this->antiAliasingQuality = 1;
}