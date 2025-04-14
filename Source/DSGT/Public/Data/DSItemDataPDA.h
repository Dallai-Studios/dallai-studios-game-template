// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DSItemDataPDA.generated.h"

UCLASS()
class DSGT_API UDSItemDataPDA : public UPrimaryDataAsset {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Info")
	FString itemId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Info")
	FText itemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Info")
	TObjectPtr<class UTexture2D> itemImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Info")
	TObjectPtr<class UStaticMesh> itemMesh;
};
