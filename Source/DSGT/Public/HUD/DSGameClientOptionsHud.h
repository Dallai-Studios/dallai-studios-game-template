// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DSGameClientOptionsHud.generated.h"

UCLASS()
class DSGT_API UDSGameClientOptionsHud : public UUserWidget {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Client Options")
	TObjectPtr<class UDSGameClientOptionsPDA> gameClientOptions;

public:
	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void ApplyGameSettings();
};
