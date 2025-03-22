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
	// Game Client Settings:
	// ==============================================================
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Client Options")
	TObjectPtr<class UDSGameClientOptionsPDA> gameClientOptions;

	
public:
	// ==============================================================
	// Save and Load Game:
	// ==============================================================
	UFUNCTION(BlueprintCallable, Category="Save and Load Game")
	void SaveGameClientOptions();

	UFUNCTION(BlueprintCallable, Category="Save and Load Game")
	void LoadGameClientOptions();

	UFUNCTION(BlueprintCallable, Category="Save and Load Game")
	void ApplyGameClientOptions();
};
