// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/DSInteractableItemInterface.h"
#include "DSInteractableItem.generated.h"

UCLASS()
class DSGT_API ADSInteractableItem : public AActor, public IDSInteractableItemInterface {
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Actor Configuration")
	FText interactionName;
	
public:
	// Sets default values for this actor's properties
	ADSInteractableItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual FText GetInteractionText_Implementation() override;
};
