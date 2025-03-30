// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DSHeadBobComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UDSHeadBobComponent : public UActorComponent {
	GENERATED_BODY()

public:
	// ==============================================================
	// Game Client Options:
	// ==============================================================
	UPROPERTY(EditAnywhere, Category="Game Options")
	TObjectPtr<class UDSGameClientOptionsPDA> gameClientOptions;

	
	
	// ==============================================================
	// Camera Shakes:
	// ==============================================================
	UPROPERTY(EditAnywhere, Category="Camera Shakes")
	TSubclassOf<class UCameraShakeBase> idleCameraShake;

	UPROPERTY(EditAnywhere, Category="Camera Shakes")
	TSubclassOf<UCameraShakeBase> walkCameraShake;
	
	UPROPERTY(EditAnywhere, Category="Camera Shakes")
	TSubclassOf<UCameraShakeBase> runCameraShake;
	

	
public:
	// ==============================================================
	// Lifecycle Methods:
	// ==============================================================
	UDSHeadBobComponent();
	virtual void BeginPlay() override;


	
	// ==============================================================
	// Component Methods:
	// ==============================================================
	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void PlayIdleHeadBob();

	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void PlayWalkHeadBob();

	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void PlayRunningHeadBob();
};
