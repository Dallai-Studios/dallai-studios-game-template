// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/DSInteractableItemInterface.h"
#include "DSInteractableDoor.generated.h"

UCLASS()
class DSGT_API ADSInteractableDoor : public AActor, public IDSInteractableItemInterface {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<class UStaticMeshComponent> doorFrameMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	TObjectPtr<UStaticMeshComponent> doorMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Actor Configuration")
	TObjectPtr<class UDSGameGlobalEvents> gameGlobalEvents;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Actor Configuration")
	FText interactionVerb;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actor Configuration")
	bool playerNeedsKey = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actor Configuration", meta=(EditCondition="playerNeedsKey"))
	FString keyItemId;
	
	
public:
	ADSInteractableDoor();
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category="Interface Methods")
	FText GetInteractionVerb_Implementation();
};
