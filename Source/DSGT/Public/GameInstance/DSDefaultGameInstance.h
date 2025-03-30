// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DSDefaultGameInstance.generated.h"

UCLASS()
class UDSDefaultGameInstance : public UGameInstance {
	GENERATED_BODY()

public:
	// ==============================================================
	// Game Data Settings:
	// ==============================================================
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Data")
	TObjectPtr<class UDSGameClientOptionsPDA> gameClientOptions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Data")
	TObjectPtr<class USoundMix> mainSoundMixer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Data")
	TObjectPtr<class USoundClass> masterSoundClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Data")
	TObjectPtr<USoundClass> musicSoundClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Data")
	TObjectPtr<USoundClass> sfxSoundClass;
	
public:
	// ==============================================================
	// Save and Load Game:
	// ==============================================================
	virtual void Init() override;
	

	
	// ==============================================================
	// Save and Load Game:
	// ==============================================================
	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void SaveGameClientOptions();

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void LoadGameClientOptions();

	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void UpdateClientSoundOptions();


	
	// ==============================================================
	// Helper Functions:
	// ==============================================================
	EWindowMode::Type ConvertWindowMode(int windowModeValue);
};
