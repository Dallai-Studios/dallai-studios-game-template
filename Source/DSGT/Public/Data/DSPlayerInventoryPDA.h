// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DSPlayerInventoryPDA.generated.h"

UCLASS()
class DSGT_API UDSPlayerInventoryPDA : public UPrimaryDataAsset {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Items On Inventory")
	TArray<FString> inventory;

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Inventory Functions")
	bool PlayerHasItem(FString itemId) const;
	
	UFUNCTION(BlueprintCallable, Category="Inventory Functions")
	void AddNewItemToPlayerInventory(FString newItemId);

	UFUNCTION(BlueprintCallable, Category="Inventory Functions")
	void RemoveItemFromInventory(FString itemId);

	UFUNCTION(BlueprintCallable, CallInEditor, Category="Inventory Functions")
	void ClearPlayerInventory();
};
