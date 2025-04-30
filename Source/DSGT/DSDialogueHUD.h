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
	// This is the character name that will be showed to the player when the dialogue system opens
	// This dialogue system only works for NPC's. I really don't care about interactions. Not at this point.
	// Most probably, this game doesn't need a interaction system so bloated with features. -Dallai
	UPROPERTY(BlueprintReadOnly, Category="HUD Data")
	FText currentCharacterName;

	// this value will be what is actually showed to the player when animating the dialogue of the game. -Dallai
	UPROPERTY(BlueprintReadOnly, Category="HUD Data")
	FText finalDialogueText;

private:
	// this variable will hold the full text when the StartNewDialogue function is called. Unreal only can translate FText variables.
	// In order to make it work, I need to convert everything to FString because FString is the only "text" structure that can handle
	// things like lenght. Also, I can use array functions on it, so there is a lot easier to make things work and animate the text. -Dallai
	FString dialogueFullStringText;

	// This variable is responsable for creating the typing effect. -Dallai
	FString dialogueStringText;

	// This only serve for the animation. -Dallai
	int32 currentTextIndex = 0;
	FTimerHandle dialogueAnimationTimeHandle;

	// TODO: Remove this bit of code. This is garbage now. -Dallai
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FDialogueHudEvent OnFinishCurrentDialogue; // I dont know if I need this but, better safe then sorry. -Dallai
	
public:
	UFUNCTION(BlueprintCallable)
	void StartNewDialogue(FText characterNameToDisplay, FString originalDialogueText, float dialogueAnimationInterval);

private:
	void UpdateDialogueText();
};
