// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Enums/EDSGameClientOptionsChangeType.h"
#include "DSBaseGameClientOptionsHUD.generated.h"


UCLASS()
class DSGT_API UDSBaseGameClientOptionsHUD : public UUserWidget {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Client Options")
	TObjectPtr<class UDSGameClientOptionsPDA> gameClientOptions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Configuration")
	bool bUseDefaultButtonHoverFontTransformation = true;

public:
	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void UpdateMouseSensitivity(float value);

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void ToggleInvertMouseX();

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void ToggleInvertMouseY();
	
	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void UpdateMasterVolume(float value);

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void UpdateMusicVolume(float value);

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void UpdateSfxVolume(float value);

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
