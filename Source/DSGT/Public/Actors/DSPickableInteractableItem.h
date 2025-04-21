// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Enums/EDSInteractionType.h"
#include "GameFramework/Actor.h"
#include "Interfaces/DSInteractableItemInterface.h"
#include "DSPickableInteractableItem.generated.h"

UCLASS(Blueprintable, BlueprintType)
class DSGT_API ADSPickableInteractableItem : public AActor, public IDSInteractableItemInterface {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<class UStaticMeshComponent> pickableMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actor Configuration")
	TObjectPtr<class UDSGameGlobalEvents> gameGlobalEvents;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actor Configuration")
	FText itemName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actor Configuration")
	FString itemId;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actor Configuration")
	FText interactionVerb;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actor Configuration")
	EDSInteractionType interactionType = EDSInteractionType::PICKABLE;
	
public:
	ADSPickableInteractableItem();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category="Interface Methods")
	FText GetInteractionVerb_Implementation();

	UFUNCTION(BlueprintCallable, Category="Interface Methods")
	EDSInteractionType GetInteractionType_Implementation();

	UFUNCTION(BlueprintCallable, Category="Interface Methods")
	void PerformInteraction_Implementation(AActor* instigatorActor);

	UFUNCTION(BlueprintCallable, Category="Interface Methods")
	void OpenStaticInteractionHUD_Implementation();

	UFUNCTION(BlueprintCallable, Category="Interface Methods")
	FString GetItemId_Implementation();
};
