// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Enums/EDSInteractionType.h"
#include "UObject/Interface.h"
#include "DSInteractableItemInterface.generated.h"

UINTERFACE(Blueprintable, BlueprintType)
class UDSInteractableItemInterface : public UInterface {
	GENERATED_BODY()
};

class DSGT_API IDSInteractableItemInterface {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FText GetInteractionVerb();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	EDSInteractionType GetInteractionType();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PerformInteraction(class AActor* instigatorActor);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OpenStaticInteractionHUD();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FString GetItemId();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	class UStaticMesh* GetItemHoldableStaticMesh();
};
