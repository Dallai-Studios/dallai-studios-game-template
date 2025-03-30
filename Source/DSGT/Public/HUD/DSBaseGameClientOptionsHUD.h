// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Enums/EDSGameClientOptionsChangeType.h"
#include "DSBaseGameClientOptionsHUD.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameClientOptionsHudEvent)

UCLASS()
class UDSBaseGameClientOptionsHUD : public UUserWidget {
	GENERATED_BODY()

public:
	// ==============================================================
	// Game Client Options:
	// ==============================================================
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Client Options")
	TObjectPtr<class UDSGameClientOptionsPDA> gameClientOptions;

	/// Define if the HUD must use the default font behavior when hovering over the buttons.
	/// Unreal only change the button style but does not change the text inside of it.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Configuration")
	bool bUseDefaultButtonHoverFontTransformation = true;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnGameClientOptionsHudEvent OnCloseGameClientOptionsHUD;

public:
	// ==============================================================
	// Gameplay Options Hanlder Functions:
	// ==============================================================
	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void UpdateMouseSensitivity(float value);

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void ToggleInvertMouseX();

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void ToggleInvertMouseY();



	// ==============================================================
	// Audio Options Handler Functions:
	// ==============================================================
	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void UpdateMasterVolume(float value);

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void UpdateMusicVolume(float value);

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void UpdateSfxVolume(float value);


	// ==============================================================
	// Video Options Handler Functions:
	// ==============================================================
	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void ChangeWindowMode(EDSGameClientOptionsChangeType type);

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void ChangeResolution(EDSGameClientOptionsChangeType type);

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void ToggleVsync(bool value);

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void ChangeFramerate(EDSGameClientOptionsChangeType type);

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void ChangeShadowQuality(EDSGameClientOptionsChangeType type);

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void ChangeTextureQuality(EDSGameClientOptionsChangeType type);

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void ChangeGlobalIlluminationQuality(EDSGameClientOptionsChangeType type);

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void ChangePostProcessQuality(EDSGameClientOptionsChangeType type);

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void ChangeVFXQuality(EDSGameClientOptionsChangeType type);

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void ChangeAntiAliasingQuality(EDSGameClientOptionsChangeType type);

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void ApplyGameClientOptionOnGameInstance();
};
