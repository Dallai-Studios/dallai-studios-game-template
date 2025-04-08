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
	float floorDetectionLineSize; //define the size of the raycast to detect the floor.

	UPROPERTY(EditAnywhere, Category="Component Configuration")
	TObjectPtr<class USoundBase> concreteFootstepSound; // sound to play when the player is walking on concrete.

	UPROPERTY(EditAnywhere, Category="Component Configuration")
	TObjectPtr<USoundBase> woodFootstepSound; // sound to play when the player is walking on wood surfaces.

	UPROPERTY(EditAnywhere, Category="Component Configuration")
	TObjectPtr<USoundBase> grassFootstepSound; // sound to play when player is walking on grass surfaces.

	UPROPERTY(EditAnywhere, Category="Component Configuration")
	TObjectPtr<USoundBase> carpetFootstepSound;
	
	UPROPERTY(EditAnywhere, Category="Component Configuration")
	float walkTimerRate; // amount of time to perform the next floor detection when walking.

	UPROPERTY(EditAnywhere, Category="Component Configuration")
	float runningTimerRate; // amount of time to perform the next floor detection when running.

	UPROPERTY(EditAnywhere, Category="Component Configuration")
	float pitchVariationWhenCharacterIsRunning = 1.1; // define the pitch variation when the player is running.

	// ==================================================
	// Timer Handlers
	// ==================================================
	// this timers will handle the "tick" of the surface type detection when the player is walking or running; -Dallai
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

	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void StopAllFootstepSounds();

private:
	void DetectAndPlayWalkSoundBasedOnSurface();
	void DetectAndPlayRunningSoundBasedOnSurface();
	void PlayFootstepSound(EPhysicalSurface surface, bool characterIsRunning = false);
};
