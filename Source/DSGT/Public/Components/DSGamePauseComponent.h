// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DSGamePauseComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, ClassGroup=(Components), meta=(BlueprintSpawnableComponent))
class UDSGamePauseComponent : public UActorComponent {
	GENERATED_BODY()

public:
	// ==============================================================
	// HUD Reference:
	// ==============================================================
	UPROPERTY(EditAnywhere, Category="Options HUD")
	TSubclassOf<class UUserWidget> gameClientOptionsHUDWidgetReference;
	UUserWidget* gameClientOptionsHUDInstance;
	
public:
	// ==============================================================
	// Lifecycle Methods:
	// ==============================================================
	UDSGamePauseComponent();
	virtual void BeginPlay() override;
	
	// ==============================================================
	// Component Methods:
	// ==============================================================
	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void OpenPauseMenu();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Component Methods")
	bool IsPauseMenuOpen();

	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void ClosePauseMenu();

private:
	bool GameClientHudInstanceIsValid();
};
