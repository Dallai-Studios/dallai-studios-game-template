// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DSInteractableItemInterface.generated.h"

UINTERFACE(Blueprintable, BlueprintType)
class UDSInteractableItemInterface : public UInterface {
	GENERATED_BODY()
};

class DSGT_API IDSInteractableItemInterface {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	FText GetInteractionVerb();
};
