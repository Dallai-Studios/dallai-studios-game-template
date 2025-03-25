// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DSBaseGameClientOptionsHUD.generated.h"


UCLASS()
class DSGT_API UDSBaseGameClientOptionsHUD : public UUserWidget {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Client Options")
	TObjectPtr<class UDSGameClientOptionsPDA> gameClientOptions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Configuration")
	bool bUseDefaultButtonHoverFontTransformation = true;

public:
	UFUNCTION(BlueprintCallable, Category="Game Client Options")
	void ApplyGameClientOptionOnGameInstance();
};
