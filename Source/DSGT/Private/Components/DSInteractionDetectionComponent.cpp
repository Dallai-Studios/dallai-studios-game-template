// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Components/DSInteractionDetectionComponent.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
#include "HUD/DSBaseInteractionHUD.h"
#include "Interfaces/DSInteractableItemInterface.h"
#include "Kismet/GameplayStatics.h"
#include "Tools/DSDebugTools.h"

// =====================================================
// Lifecycle Methods:
// =====================================================
UDSInteractionDetectionComponent::UDSInteractionDetectionComponent() {
	PrimaryComponentTick.bCanEverTick = true;
}

void UDSInteractionDetectionComponent::BeginPlay() {
	Super::BeginPlay();

	if (this->interactionHudReference == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("The Interaction HUD Reference is not defined on the Interaction Detection Component"));
		return;
	}

	this->interactionHudInstance = Cast<UDSBaseInteractionHUD>(CreateWidget(this->GetWorld(), this->interactionHudReference));
	this->interactionHudInstance->AddToViewport();
	this->interactionHudInstance->SetVisibility(ESlateVisibility::Collapsed);
}

void UDSInteractionDetectionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

// =====================================================
// Component Methods:
// =====================================================
void UDSInteractionDetectionComponent::SetOwnerCameraReference(UCameraComponent* ownerCameraComponent) {
	// the owner camera is really necessary because all the detection raycasts are casted from
	// the camera position. Maybe I can create a way later to make this cast any place from the owner
	// because the ray just need a start location and a direction to be casted.
	this->ownerCamera = ownerCameraComponent;
}

AActor* UDSInteractionDetectionComponent::GetCurrentInteractable() {
	return this->cachedInteractableItem;
}

void UDSInteractionDetectionComponent::CheckForInteractable() {
	if (this->ownerCamera == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Owner Camera Component is not defined on the the Interaction Detection Component"));
		this->HideInteractableHud();
		this->cachedInteractableItem = NULL;
		return;
	}
	
	FHitResult hitResult;
	FVector startLocation = this->ownerCamera->GetComponentLocation();
	FVector endLocation = startLocation + this->ownerCamera->GetForwardVector() * this->detectionLineSize;
	FCollisionQueryParams queryParams;
	queryParams.AddIgnoredActor(this->GetOwner());
	
	bool hit = this->GetWorld()->LineTraceSingleByChannel(hitResult, startLocation, endLocation, ECC_Visibility, queryParams);

	// This validation prevents the code bellow to try and check for a interface on null stuff. -Dallai
	if (!hit) {
		this->HideInteractableHud();
		this->cachedInteractableItem = NULL;
		return;
	};

	AActor* hitActor = hitResult.GetActor();
	
	if (IsValid(hitActor) && hitActor->Implements<UDSInteractableItemInterface>()) {
		if (this->interactionHudInstance == NULL) {
			UDSDebugTools::ShowDebugMessage(TEXT("Interaction HUD Instance is not defined"));
			return;
		}

		// If the interaction HUD is already visible, prevents the rest of the code to run. -Dallai
		if (this->interactionHudInstance->GetVisibility() == ESlateVisibility::Visible) return;

		this->cachedInteractableItem = hitActor; 
		FText interactionText = IDSInteractableItemInterface::Execute_GetInteractionVerb(hitActor);

		// TODO: Remove this debug info when the game is ready, or make a logic to only display that when a debug checkbox is active. -Dallai
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, interactionText.ToString());
		
		this->ShowInteractableHud(interactionText);
		return;
	}

	this->cachedInteractableItem = NULL;
	this->HideInteractableHud();
}

void UDSInteractionDetectionComponent::ShowInteractableHud(FText interactionText) {
	// This kind of validation is necessary, even been repetitive. unreal sometimes loses some references for no reason. -Dallai
	if (this->interactionHudInstance == NULL || this->interactionHudInstance->GetVisibility() == ESlateVisibility::Visible) return;
	this->interactionHudInstance->SetVisibility(ESlateVisibility::Visible);
	this->interactionHudInstance->interactionVerbText = interactionText;
}

void UDSInteractionDetectionComponent::HideInteractableHud() {
	// This validation is just to be safe. -Dallai
	if (this->interactionHudInstance == NULL || this->interactionHudInstance->GetVisibility() == ESlateVisibility::Collapsed) return;
	this->interactionHudInstance->SetVisibility(ESlateVisibility::Collapsed);
}

void UDSInteractionDetectionComponent::PlayInteractionSound() {
	// Maybe this is not the right place to play this sound, but it is better to centralize all the pick up item interactions
	// sounds on the same place. This will be called in a single blueprint, most probably on the player BP. -Dallai
	if (!this->interactionSound) {
		UDSDebugTools::ShowDebugMessage(TEXT("Interaction sound is not defined on the component"), FColor::Red);
		return;
	}

	UGameplayStatics::PlaySound2D(this->GetWorld(), this->interactionSound);
}
