// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Data/DSGameUserSettings.h"

// ==============================================================
// Gameplay Getters and Setters:
// ==============================================================
float UDSGameUserSettings::GetMouseSensitivity() const {
	return this->mouseSensitivity;
}

void UDSGameUserSettings::SetMouseSensitivity(float value) {
	this->mouseSensitivity = value;
}

bool UDSGameUserSettings::GetInvertMouseAxisX() const {
	return this->bInvertMouseX;
}

void UDSGameUserSettings::SetInvertMouseAxisX(bool value) {
	this->bInvertMouseX = value;
}

bool UDSGameUserSettings::GetInvertMouseAxisY() const {
	return this->bInvertMouseY;
}

void UDSGameUserSettings::SetInvertMouseAxisY(bool value) {
	this->bInvertMouseY = value;	
}

bool UDSGameUserSettings::GetCameraHeadbob() {
	return this->bCameraHeadbob;
}

void UDSGameUserSettings::SetCameraHeadbob(bool value) {
	this->bCameraHeadbob = value;
}

// ==============================================================
// Audio Getters and Setters:
// ==============================================================
float UDSGameUserSettings::GetMasterVolume() const {
	return this->masterVolume;
}

void UDSGameUserSettings::SetMasterVolume(float value) {
	this->masterVolume = value;
	if (this->masterVolume < 0) this->masterVolume = 0;
}

float UDSGameUserSettings::GetMusicVolume() const {
	return this->musicVolume;
}

void UDSGameUserSettings::SetMusicVolume(float value) {
	this->musicVolume = value;
	if (this->musicVolume < 0) this->musicVolume = 0;
}

float UDSGameUserSettings::GetSFXVolume() const {
	return this->sfxVolume;
}

void UDSGameUserSettings::SetSFXVolume(float value) {
	this->sfxVolume = value;
	if (this->sfxVolume < 0) this->sfxVolume = 0;
}