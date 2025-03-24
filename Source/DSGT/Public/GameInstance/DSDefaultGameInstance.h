// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DSDefaultGameInstance.generated.h"

UCLASS()
class DSGT_API UDSDefaultGameInstance : public UGameInstance {
	GENERATED_BODY()

public:
	// ==============================================================
	// Game Data Settings:
	// ==============================================================
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Data")
	TObjectPtr<class UDSGameClientOptionsPDA> gameClientOptions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Data")
	TObjectPtr<class USoundMix> mainSoundMixer;
	
	
public:
	// ==============================================================
	// Save and Load Game:
	// ==============================================================
	virtual void Init() override;
	
	
	// ==============================================================
	// Save and Load Game:
	// ==============================================================
	UFUNCTION(BlueprintCallable, Category="Save and Load Game")
	void SaveGameClientOptions();

	UFUNCTION(BlueprintCallable, Category="Save and Load Game")
	void LoadGameClientOptions();



	// ==============================================================
	// Helper Functions:
	// ==============================================================
};
