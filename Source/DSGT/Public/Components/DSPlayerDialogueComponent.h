// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DSPlayerDialogueComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DSGT_API UDSPlayerDialogueComponent : public UActorComponent {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Component Configuration")
	TObjectPtr<class UUserWidget> dialogueHudReference;
	class UDSDialogueHUD* dialogueHudInstance;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Component Configuration")
	float dialogueAnimationInterval;

private:
	class UDSDialogueContainerPDA* dialogueContainer;
	bool hasActiveDialogue;
	int32 currentDialogueEntryIndex;
	
public:
	UDSPlayerDialogueComponent();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category="Component Functions")
	void ShowDialogue(UDSDialogueContainerPDA* dialogueContainer);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Component Functions")
	bool HasActiveDialogue() const;
};
