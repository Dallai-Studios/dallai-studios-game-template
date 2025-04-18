// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DSInteractionDetectionComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DSGT_API UDSInteractionDetectionComponent : public UActorComponent {
	GENERATED_BODY()
	
protected:
	// =====================================================
	// Interaction Config
	// =====================================================
	UPROPERTY(EditAnywhere, Category="Interaction Config")
	TSubclassOf<class UUserWidget> interactionHudReference;

	UPROPERTY(BlueprintReadOnly, Category="Interaction Config")
	class UDSBaseInteractionHUD* interactionHudInstance;
	
	UPROPERTY(BlueprintReadOnly, Category="Interaction Config")
	bool isLookingForInteractable = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interaction Config")
	float detectionLineSize = 200;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interaction Config")
	TObjectPtr<class USoundBase> interactionSound;
	
	// =====================================================
	// Owner Data
	// =====================================================
	UPROPERTY(BlueprintReadOnly, Category="Owner Data")
	class UCameraComponent* ownerCamera;

	UPROPERTY(BlueprintReadWrite, Category="Cached Interactable Item")
	class AActor* cachedInteractableItem = NULL;
	
public:
	// =====================================================
	// Lifecycle Methods
	// =====================================================
	UDSInteractionDetectionComponent();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	// =====================================================
	// Component Methods
	// =====================================================
	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void SetOwnerCameraReference(UCameraComponent* ownerCameraComponent);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Component Methods")
	class AActor* GetCurrentInteractable();
	
	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void CheckForInteractable();

	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void ShowInteractableHud(FText interactionText);

	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void HideInteractableHud();

	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void PlayInteractionSound();
};