// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DSGameClientOptionsPDA.generated.h"

UCLASS()
class DSGT_API UDSGameClientOptionsPDA : public UPrimaryDataAsset {
	GENERATED_BODY()
	
public:
	// ==============================================================
	// Gameplay Settings:
	// ==============================================================
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Options")
	float mouseSensitivity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Options")
	bool bInvertMouseX = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Options")
	bool bInvertMouseY = false;
	

	
	// ==============================================================
	// Audio Settings:
	// ==============================================================
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio Options")
	float masterVolume = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio Options")
	float musicVolume = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio Options")
	float sfxVolume = 1;


	
	// ==============================================================
	// Video Settings:
	// ==============================================================
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Video Options")
	int resolutionX = 1920;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Video Options")
	int resolutionY = 1080;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Video Options")
	int windowMode = EWindowMode::Fullscreen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Video Options")
	bool bEnableVSync = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Video Options")
	int frameRateLimit = 60;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Video Options")
	int shadowQuality = 2; // 0 = Low, 1 = Medium, 2 = High, 3 = Very High, 4 = Ultra

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Video Options")
	int textureQuality = 2; // 0 = Low, 1 = Medium, 2 = High, 3 = Very High, 4 = Ultra

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Video Options")
	int postProcessQuality = 2; // 0 = Low, 1 = Medium, 2 = High, 3 = Very High, 4 = Ultra

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Video Options")
	int vfxQuality = 2; // 0 = Low, 1 = Medium, 2 = High, 3 = Very High, 4 = Ultra

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Video Options")
	int grassQuality = 2; // 0 = Low, 1 = Medium, 2 = High, 3 = Very High, 4 = Ultra

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Video Options")
	int globalIlluminationQuality = 2; // 0 = Low, 1 = Medium, 2 = High, 3 = Very High, 4 = Ultra
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Video Options")
	int antiAliasingQuality = 2; // 0 = Low, 1 = Medium, 2 = High, 3 = Very High, 4 = Ultra



	// ==============================================================
	// Aux Data:
	// ==============================================================
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aux Data")
	TArray<FIntPoint> resolutionPresets;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aux Data")
	TMap<FString, int> frameRateLimits;


	
public:
	// ==============================================================
	// Helper Functions:
	// ==============================================================
	UFUNCTION(BlueprintCallable, CallInEditor, Category="Game Client Options Functions")
	void ResetClientOptions();
};
