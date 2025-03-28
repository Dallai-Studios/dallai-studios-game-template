// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DSGameGlobalEvents.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGlobalEvent);

UCLASS()
class DSGT_API UDSGameGlobalEvents : public UPrimaryDataAsset {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="Game Global Events")
	FGlobalEvent OnOpenOptionsMenu;

	UPROPERTY(BlueprintAssignable, Category="Game Global Events")
	FGlobalEvent OnCloseOptionsMenu;
};
