// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DSBaseInteractionHUD.generated.h"

UCLASS()
class DSGT_API UDSBaseInteractionHUD : public UUserWidget {
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="Controls")
	FText interactionVerbText;

public:
	UFUNCTION(BlueprintCallable, Category="Widget Functions")
	void SetInteractionVerbText(FText newText);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Widget Functions")
	FText GetInteractionVerbText();
};
