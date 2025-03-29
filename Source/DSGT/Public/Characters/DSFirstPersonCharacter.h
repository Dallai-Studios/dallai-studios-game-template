// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DSFirstPersonCharacter.generated.h"

UCLASS()
class DSGT_API ADSFirstPersonCharacter : public ACharacter {
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
	UPROPERTY(EditAnywhere, Category="Components")
	TObjectPtr<class USpringArmComponent> cameraSpringArm;

	UPROPERTY(EditAnywhere, Category="Components")
	TObjectPtr<class UCameraComponent> camera;



	// ==============================================================
	// Character Configuration:
	// ==============================================================
	
	
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


	
	// ==============================================================
	// Aim Methods:
	// ==============================================================
	UFUNCTION(BlueprintCallable, Category="Aim")
	void MoveCamera(float axisX, float axisY);
};
