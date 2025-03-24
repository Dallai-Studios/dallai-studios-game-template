// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DSDebugTools.generated.h"

UCLASS()
class DSGT_API UDSDebugTools : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	void static ShowDebugMessage(FString message, FColor color = FColor::Orange);
};
