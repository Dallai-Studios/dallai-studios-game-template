// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DSInteractionDetectionComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DSGT_API UDSInteractionDetectionComponent : public UActorComponent {
	GENERATED_BODY()

private:
	// =====================================================
	// Interaction Config
	// =====================================================
	UPROPERTY(EditAnywhere, Category="Interacation Config")
	TSubclassOf<class UUserWidget> interactionHudReference;
	UUserWidget* interactionHudInstance;

	UPROPERTY(EditAnywhere, Category="Interaction Config")
	float detectionLineSize = 200;
	
	class UCameraComponent* ownerCamera;
	
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

	UFUNCTION(BlueprintCallable, Category="Component Methods")
	class AActor* GetCurrentInteractable();
	
	UFUNCTION(BlueprintCallable, Category="Component Methods")
	bool CheckForInteractable();

	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void ShowInteractableHud();

	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void HideInteractableHud();
};
