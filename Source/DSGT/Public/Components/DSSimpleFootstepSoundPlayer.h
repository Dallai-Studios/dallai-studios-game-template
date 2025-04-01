// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DSSimpleFootstepSoundPlayer.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DSGT_API UDSSimpleFootstepSoundPlayer : public UActorComponent {
	GENERATED_BODY()

private:
	// ==================================================
	// Component Configuration
	// ==================================================
	UPROPERTY(EditAnywhere, Category="Component Configuration")
	float floorDetectionLineSize;

	UPROPERTY(EditAnywhere, Category="Component Configuration")
	TObjectPtr<class USoundBase> concreteFootstepSound;

	UPROPERTY(EditAnywhere, Category="Component Configuration")
	TObjectPtr<USoundBase> woodFootstepSound;

	UPROPERTY(EditAnywhere, Category="Component Configuration")
	TObjectPtr<USoundBase> grassFootstepSound;

	UPROPERTY(EditAnywhere, Category="Component Configuration")
	float walkTimerRate;

	UPROPERTY(EditAnywhere, Category="Component Configuration")
	float runningTimerRate;

	UPROPERTY(EditAnywhere, Category="Component Configuration")
	float pitchVariationWhenCharacterIsRunning = 1;

	// ==================================================
	// Timer Handlers
	// ==================================================
	FTimerHandle walkSoundTimeHandler;
	FTimerHandle runningSoundTimeHandler;
	
public:
	// ==================================================
	// Lifecycle Methods
	// ==================================================
	UDSSimpleFootstepSoundPlayer();
	virtual void BeginPlay() override;
	
	// ==================================================
	// Component Methods
	// ==================================================
	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void PlayWalkFootstepSound();

	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void PlayRunningFootstepSound();

private:
	void DetectAndPlayWalkSoundBasedOnSurface();
	void DetectAndPlayRunningSoundBasedOnSurface();
	void PlayFootstepSound(EPhysicalSurface surface, bool characterIsRunning = false);
};
