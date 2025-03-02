#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DSSimCameraCharacter.generated.h"

UCLASS()
class DSGT_API ADSSimCameraCharacter : public ACharacter {
	GENERATED_BODY()

public:
	// ===========================================================================================
	// Components:
	// ===========================================================================================
	UPROPERTY(EditAnywhere, Category="Components")
	TObjectPtr<class UCameraComponent> cameraComponent;
	
	UPROPERTY(EditAnywhere, Category="Components")
	TObjectPtr<class USpringArmComponent> springArmComponent;

	UPROPERTY(EditAnywhere, Category="Components")
	TObjectPtr<class UStaticMeshComponent> buildPreviewMesh;



	// ===========================================================================================
	// Player Camera Control:
	// ===========================================================================================
	UPROPERTY(EditAnywhere, Category="Camera Control")
	TObjectPtr<class UCCT_GameConfigPDA> gameConfig;

	UPROPERTY(EditAnywhere, Category="Camera Control")
	float cameraLinetraceSize;
	
	UPROPERTY(EditAnywhere, Category="Camera Control")
	float zoomPaceAmount = 150;

	UPROPERTY(EditAnywhere, Category="Camera Control")
	float springArmMaxSize = 5000;

	UPROPERTY(EditAnywhere, Category="Camera Control")
	float springArmMinSize = 200;

	UPROPERTY(EditAnywhere, Category="Camera Control")
	float zoomLerpSpeed = 5;

	UPROPERTY(EditAnywhere, Category="Camera Control")
	float mouseRotationPaceAmount = 5;

	UPROPERTY(EditAnywhere, Category="Camera Control")
	float mouseRotationSpeed = 5;

	UPROPERTY(EditAnywhere, Category="Camera Control")
	float cameraRotationMinPitch = -70;

	UPROPERTY(EditAnywhere, Category="Camera Control")
	float cameraRotationMaxPitch = -5;

	UPROPERTY(EditAnywhere, Category="Camera Control")
	float mouseRotationYawSpeedRedution = 0.5f;

	
public:
	// ===========================================================================================
	// Life Cycle Methods:
	// ===========================================================================================
	ADSSimCameraCharacter();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
