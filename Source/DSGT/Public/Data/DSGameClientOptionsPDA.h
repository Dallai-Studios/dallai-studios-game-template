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
	// Audio Settings:
	// ==============================================================
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio Options")
	float masterVolume = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio Options")
	float MusicVolume = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio Options")
	float SFXVolume = 1;


	
	// ==============================================================
	// Video Settings:
	// ==============================================================


	
	// ==============================================================
	// Input Settings:
	// ==============================================================


	
	// ==============================================================
	// Camera Settings:
	// ==============================================================
};
