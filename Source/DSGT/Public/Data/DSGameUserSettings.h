// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "DSGameUserSettings.generated.h"

UCLASS()
class DSGT_API UDSGameUserSettings : public UGameUserSettings {
	GENERATED_BODY()

protected:
	// ==============================================================
	// Gameplay Settings:
	// ==============================================================
	UPROPERTY(Config)
	float mouseSensitivity = 1 ;

	UPROPERTY(Config)
	bool bInvertMouseX = false;

	UPROPERTY(Config)
	bool bInvertMouseY = false;



	// ==============================================================
	// Audio Settings:
	// ==============================================================
	UPROPERTY(Config)
	float masterVolume = 1;

	UPROPERTY(Config)
	float musicVolume = 1;

	UPROPERTY(Config)
	float sfxVolume = 1;

	

public:
	// ==============================================================
	// Gameplay Getters and Setters:
	// ==============================================================
	UFUNCTION(BlueprintCallable, Category="DS Game User Settings")
	float GetMouseSensitivity() const;

	UFUNCTION(BlueprintCallable, Category="DS Game User Settings")
	void SetMouseSensitivity(float value);
	
	UFUNCTION(BlueprintCallable, Category="DS Game User Settings")
	bool GetInvertMouseAxisX() const;

	UFUNCTION(BlueprintCallable, Category="DS Game User Settings")
	void SetInvertMouseAxisX(bool value);

	UFUNCTION(BlueprintCallable, Category="DS Game User Settings")
	bool GetInvertMouseAxisY() const;

	UFUNCTION(BlueprintCallable, Category="DS Game User Settings")
	void SetInvertMouseAxisY(bool value);	


	
	// ==============================================================
	// Audio Getters and Setters:
	// ==============================================================
	UFUNCTION(BlueprintCallable, Category="DS Game User Settings")
	float GetMasterVolume() const;

	UFUNCTION(BlueprintCallable, Category="DS Game User Settings")
	void SetMasterVolume(float value);	
	
	UFUNCTION(BlueprintCallable, Category="DS Game User Settings")
	float GetMusicVolume() const;

	UFUNCTION(BlueprintCallable, Category="DS Game User Settings")
	void SetMusicVolume(float value);
	
	UFUNCTION(BlueprintCallable, Category="DS Game User Settings")
	float GetSFXVolume() const;

	UFUNCTION(BlueprintCallable, Category="DS Game User Settings")
	void SetSFXVolume(float value);
};
