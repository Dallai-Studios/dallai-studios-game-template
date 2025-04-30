// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DSDialogueHUD.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDialogueHudEvent);

UCLASS()
class DSGT_API UDSDialogueHUD : public UUserWidget {
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="HUD Data")
	FText cachedCharacterName; // I can use this to create bind events to get the character name on the HUD itself

	UPROPERTY(BlueprintReadOnly, Category="HUD Data")
	FText finalDialogueText; // also for this value here

private:
	// this variable will hold the full string when the StartNewDialogue function is called. -Dallai
	FString dialogueFullStringText;

	// This variable is responsable for creating the typing effect. -Dallai
	FString dialogueStringText;

	// This only serve for the animation. -Dallai
	int32 currentTextIndex = 0;
	FTimerHandle dialogueAnimationTimeHandle;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FDialogueHudEvent OnFinishCurrentDialogue; // I dont know if I need this but, better safe then sorry. -Dallai
	
public:
	UFUNCTION(BlueprintCallable)
	void StartNewDialogue(FText characterNameToDisplay, FString originalDialogueText, float dialogueAnimationInterval);

private:
	void UpdateDialogueText();
};
