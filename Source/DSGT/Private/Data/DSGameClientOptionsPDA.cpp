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
	this->frameRateLimit = 0;
	this->shadowQuality = 2;
	this->textureQuality = 2;
	this->postProcessQuality = 2;
	this->vfxQuality = 2;
	this->grassQuality = 2;
	this->globalIlluminationQuality = 2;
	this->antiAliasingQuality = 2;
	this->shaderQuality = 2;
	this->reflectionQuality = 2;
	this->viewDistanceQuality = 2;

	this->resolutionSelectedIndex = 4;
	this->framerateSelectedIndex = 0;
}