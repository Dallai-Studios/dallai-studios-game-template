// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DSGameGlobalEvents.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGlobalEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGlobalEventOneParam, FText, itemName);

UCLASS()
class UDSGameGlobalEvents : public UPrimaryDataAsset {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Game Global Items")
	TMap<FString, bool> playerInventory;
	
protected:
	UPROPERTY(BlueprintReadOnly, Category="Game Global Data")
	bool bIsGamePaused = false;
	
public:
	UPROPERTY(BlueprintAssignable, Category="Game Global Events")
	FGlobalEvent OnOpenOptionsMenu;

	UPROPERTY(BlueprintAssignable, Category="Game Global Events")
	FGlobalEvent OnCloseOptionsMenu;

	UPROPERTY(BlueprintAssignable, Category="Game Global Events")
	FGlobalEventOneParam OnPickUpItem;

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsGamePaused() const;

	UFUNCTION(BlueprintCallable)
	void PauseGame();

	UFUNCTION(BlueprintCallable)
	void UnpauseGame();

	UFUNCTION(BlueprintCallable)
	void AddItemToPlayerInventory(FString itemId);

	UFUNCTION(BlueprintCallable, CallInEditor)
	void ClearPlayerInventory();
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool ItemAlreadyPicked(FString itemId) const;
};
