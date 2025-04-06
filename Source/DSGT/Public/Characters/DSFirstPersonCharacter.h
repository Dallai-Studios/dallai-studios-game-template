// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Enums/EDSCharacterSimpleState.h"
#include "GameFramework/Character.h"
#include "DSFirstPersonCharacter.generated.h"

UCLASS()
class ADSFirstPersonCharacter : public ACharacter {
	GENERATED_BODY()

public:
	// ==============================================================
	// Game Data and Events:
	// ==============================================================
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Game Data And Events")
	TObjectPtr<class UDSGameClientOptionsPDA> gameClientOptions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Game Data and Events")
	TObjectPtr<class UDSGameGlobalEvents> gameGlobalEvents;
	
	// ==============================================================
	// Character Components:
	// ==============================================================
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<class USpringArmComponent> cameraSpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<class UCameraComponent> camera;

	// ==============================================================
	// Character Configuration:
	// ==============================================================
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Configuration")
	TObjectPtr<class UDSCharacterConfigurationPDA> characterConfiguration;

private:
	// variables to store the movement values for some strafe action. -Renan
	float forwardMovementValue = 0;
	float rightMovementValue = 0;

	// variables to store the camera input values for any reason. -Renan
	float cameraUpValue = 0;
	float cameraRightValue = 0;

public:
	// ==============================================================
	// Life Cycle Methods:
	// ==============================================================
	ADSFirstPersonCharacter();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	// ==============================================================
	// Movement Methods:
	// ==============================================================
	UFUNCTION(BlueprintCallable, Category="Movement")
	void MoveCharacter(float axisX, float axisY);

	UFUNCTION(BlueprintCallable, Category="Movement")
	void StartRunning();

	UFUNCTION(BlueprintCallable, Category="Movement")
	void StopRunning();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Movement")
	float GetForwardMovementValue() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Movement")
	float GetRightMovementValue() const;
	
	// ==============================================================
	// Aim Methods:
	// ==============================================================
	UFUNCTION(BlueprintCallable, Category="Aim")
	void MoveCamera(float axisX, float axisY);
};
