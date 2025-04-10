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
	UPROPERTY(EditAnywhere, Category="Component Configuration")
	TSubclassOf<class UUserWidget> gameClientOptionsHUDWidgetReference;
	class UDSBaseGameClientOptionsHUD* gameClientOptionsHUDInstance;

	// ==============================================================
	// Sound to play when the HUD Opens:
	// ==============================================================
	UPROPERTY(EditAnywhere, Category="Component Configuration")
	TObjectPtr<class USoundBase> pauseMenuMusic;
	class UAudioComponent* audioComponent;

	UPROPERTY(EditAnywhere, Category="Component Configuration")
	TObjectPtr<class UCurveFloat> audioFadeOutCurve;

	UPROPERTY(EditAnywhere, Category="Component Configuration")
	TObjectPtr<class UTimelineComponent> audioFadeOutTimeline;

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
	
protected:
	UFUNCTION()
	void HandleAudioFadeOut(float value);

	UFUNCTION()
	void OnFadeOutFinish();
	
private:
	bool GameClientHudInstanceIsValid();
};
