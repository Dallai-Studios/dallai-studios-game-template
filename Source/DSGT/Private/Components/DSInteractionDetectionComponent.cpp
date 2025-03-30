// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Components/DSInteractionDetectionComponent.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
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

	this->interactionHudInstance = CreateWidget(this->GetWorld(), this->interactionHudReference);
	this->interactionHudInstance->AddToViewport();
	this->interactionHudInstance->SetVisibility(ESlateVisibility::Hidden);
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
	
	
	this->GetWorld()->LineTraceSingleByChannel(hitResult, startLocation, endLocation, ECC_Visibility, queryParams);
}

void UDSInteractionDetectionComponent::ShowInteractableHud() {
	if (this->interactionHudInstance != NULL) this->interactionHudInstance->SetVisibility(ESlateVisibility::Visible);
}

void UDSInteractionDetectionComponent::HideInteractableHud() {
	if (this->interactionHudInstance !=  NULL) this->interactionHudInstance->SetVisibility(ESlateVisibility::Hidden);
}