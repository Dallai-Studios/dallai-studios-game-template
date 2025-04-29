// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DSDialogueHUD.generated.h"

UCLASS()
class DSGT_API UDSDialogueHUD : public UUserWidget {
	GENERATED_BODY()

public:
	FTimerHandle dialogueTypingTimer;
	FString fullText;
	FString currentText;
	int32 currentIndex = 0;
	
public:
	UFUNCTION(BlueprintCallable)
	void BuildDialogueData(FText characterName, FString dialogueLine, float dialogueDuration);

	UFUNCTION(BlueprintCallable)
	void AnimateDialogue();
};
