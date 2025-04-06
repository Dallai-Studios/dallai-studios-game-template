// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/DSInteractableItemInterface.h"
#include "DSInteractableItem.generated.h"

UCLASS(BlueprintType, Blueprintable)
class DSGT_API ADSInteractableItem : public AActor {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	TObjectPtr<class UStaticMeshComponent> staticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	TObjectPtr<class UCameraComponent> staticCamera;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actor Configuration")
	FText interactionName;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actor Configuration")
	bool hasStaticInteraction = false;

public:
	ADSInteractableItem();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
