// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Enums/EDSInteractionType.h"
#include "GameFramework/Actor.h"
#include "Interfaces/DSInteractableItemInterface.h"
#include "DSInteractableItem.generated.h"

UCLASS(BlueprintType, Blueprintable)
class DSGT_API ADSInteractableItem : public AActor, public IDSInteractableItemInterface {
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	TObjectPtr<class UStaticMeshComponent> staticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	TObjectPtr<class UCameraComponent> staticCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actor Cofiguration")
	bool needsToValidateBeforeSpawn = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actor Configuration")
	FText interactionName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actor Configuration")
	TObjectPtr<class UDSPlayerInventoryPDA> playerInventory;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actor Configuration")
	bool needsItemToPerformInteraction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actor Configuration", meta=(EditCondition="needsItemToPerformInteraction"))
	FString itemId;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actor Configuration")
	EDSInteractionType interactionType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actor Configuration")
	TSubclassOf<class UUserWidget> interactableHud;

	UPROPERTY(BlueprintReadOnly, Category="Actor Configuration")
	UUserWidget* interactableHUDInstance;

public:
	ADSInteractableItem();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	FText GetInteractionVerb_Implementation();
	EDSInteractionType GetInteractionType_Implementation();
	void PerformInteraction_Implementation(AActor* instigatorActor);
	void OpenStaticInteractionHUD_Implementation();
	FString GetItemId_Implementation();
	class UStaticMesh* GetItemHoldableStaticMesh_Implementation();

protected:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Component Functions")
	bool IsPlayerInventoryValid() const;
};
