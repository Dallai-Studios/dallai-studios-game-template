// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Structs/FDSDialogueEntry.h"
#include "DSDialogueContainerPDA.generated.h"

UCLASS()
class DSGT_API UDSDialogueContainerPDA : public UPrimaryDataAsset {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Dialogue Container")
	TMap<FString, TArray<FDSDialogueEntry>> dialogueContainer;

public:
	UFUNCTION(BlueprintCallable, Category="Dialogue Container")
	TArray<FDSDialogueEntry>* GetDialogue(FString dialogueId) const;
};
