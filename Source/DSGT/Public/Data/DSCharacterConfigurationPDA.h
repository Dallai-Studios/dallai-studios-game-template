// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DSCharacterConfigurationPDA.generated.h"

UCLASS()
class UDSCharacterConfigurationPDA : public UPrimaryDataAsset {
	GENERATED_BODY()

public:
	// ==============================================================
	// Character Configuration:
	// ==============================================================
	UPROPERTY(EditAnywhere, Category="Character Movement")
	float walkSpeed;

	UPROPERTY(EditAnywhere, Category="Character Movement")
	float runningSpeed;
};
