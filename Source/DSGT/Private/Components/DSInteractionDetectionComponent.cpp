// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Components/DSInteractionDetectionComponent.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
#include "HUD/DSBaseInteractionHUD.h"
#include "Interfaces/DSInteractableItemInterface.h"
#include "Tools/DSDebugTools.h"

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
}

void UDSInteractionDetectionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UDSInteractionDetectionComponent::SetOwnerCameraReference(UCameraComponent* ownerCameraComponent) {
	this->ownerCamera = ownerCameraComponent;
}

AActor* UDSInteractionDetectionComponent::GetCurrentInteractable() {
	if (this->ownerCamera == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Owner Camera Component is not defined on the the Interaction Detection Component"));
		return NULL;
	}
	
	FHitResult hitResult;
	FVector startLocation = this->ownerCamera->GetComponentLocation();
	FVector endLocation = startLocation + this->ownerCamera->GetForwardVector() * this->detectionLineSize;
	FCollisionQueryParams queryParams;
	queryParams.AddIgnoredActor(this->GetOwner());
	
	bool hit = this->GetWorld()->LineTraceSingleByChannel(hitResult, startLocation, endLocation, ECC_Visibility, queryParams);

	if (!hit) return NULL;

	AActor* hitActor = hitResult.GetActor();
	
	if (IsValid(hitActor) && hitActor->Implements<UDSInteractableItemInterface>()) return hitActor;

	return NULL;
}

void UDSInteractionDetectionComponent::CheckForInteractable() {
	if (this->ownerCamera == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("Owner Camera Component is not defined on the the Interaction Detection Component"));
		this->HideInteractableHud();
		return;
	}
	
	FHitResult hitResult;
	FVector startLocation = this->ownerCamera->GetComponentLocation();
	FVector endLocation = startLocation + this->ownerCamera->GetForwardVector() * this->detectionLineSize;
	FCollisionQueryParams queryParams;
	queryParams.AddIgnoredActor(this->GetOwner());
	
	bool hit = this->GetWorld()->LineTraceSingleByChannel(hitResult, startLocation, endLocation, ECC_Visibility, queryParams);

	if (!hit) {
		this->HideInteractableHud();
		return;
	};

	AActor* hitActor = hitResult.GetActor();
	
	if (IsValid(hitActor) && hitActor->Implements<UDSInteractableItemInterface>()) {
		if (this->interactionHudInstance->IsVisible()) return;

		FText interactionText = Cast<IDSInteractableItemInterface>(hitActor)->GetInteractionText_Implementation();

		if (this->interactionHudInstance != NULL) {
			this->interactionHudInstance->SetInteractionVerbText(interactionText);
			this->ShowInteractableHud();
		}
		
		return;
	}

	this->HideInteractableHud();
}

void UDSInteractionDetectionComponent::ShowInteractableHud() {
	if (this->interactionHudInstance == NULL || this->interactionHudInstance->IsVisible()) return;
	this->interactionHudInstance->SetVisibility(ESlateVisibility::Visible);
}

void UDSInteractionDetectionComponent::HideInteractableHud() {
	if (this->interactionHudInstance == NULL || !this->interactionHudInstance->IsVisible()) return;
	this->interactionHudInstance->SetVisibility(ESlateVisibility::Collapsed);
}