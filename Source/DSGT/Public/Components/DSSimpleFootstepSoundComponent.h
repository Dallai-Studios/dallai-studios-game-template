// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DSSimpleFootstepSoundComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DSGT_API UDSSimpleFootstepSoundComponent : public UActorComponent {
	GENERATED_BODY()

public:
	// ==============================================================
	// Sound To Play:
	// ==============================================================
	UPROPERTY(EditAnywhere, Category="Sounds To Play")
	TObjectPtr<class USoundBase> walkSound;

	UPROPERTY(EditAnywhere, Category="Sounds To Play")
	TObjectPtr<USoundBase> runningSound;

	UPROPERTY(EditAnywhere, Category="Sounds To Play")
	TObjectPtr<USoundBase> jumpStartSound;

	UPROPERTY(EditAnywhere, Category="Sounds To Play")
	TObjectPtr<USoundBase> fallLandSound;
	

	
public:
	// ==============================================================
	// Lifecycle Methods:
	// ==============================================================
	UDSSimpleFootstepSoundComponent();
	virtual void BeginPlay() override;



	// ==============================================================
	// Component Methods:
	// ==============================================================
	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void PlayWalkFootstepSound();

	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void PlayRunningFootstepSound();

	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void PlayStartJumpSound();

	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void PlayFallLandSound();
};
