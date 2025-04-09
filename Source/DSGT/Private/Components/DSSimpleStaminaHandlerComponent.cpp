// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Components/DSSimpleStaminaHandlerComponent.h"

#include "Tools/DSDebugTools.h"

UDSSimpleStaminaHandlerComponent::UDSSimpleStaminaHandlerComponent() {
	PrimaryComponentTick.bCanEverTick = true;
}

void UDSSimpleStaminaHandlerComponent::BeginPlay() {
	Super::BeginPlay();
	this->stamina = this->maxStamina;
}

void UDSSimpleStaminaHandlerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (this->showDebugInfo) this->DisplayDebugInfoOnScreen();
}

bool UDSSimpleStaminaHandlerComponent::HasStamina() const {
	return this->stamina > 0;
}

float UDSSimpleStaminaHandlerComponent::GetCurrentStamina() const {
	return this->stamina;
}

void UDSSimpleStaminaHandlerComponent::DecreaseStamina() {
	this->stamina -= this->amountToDecrease;
	if (this->stamina <= 0) this->stamina = 0;
}

void UDSSimpleStaminaHandlerComponent::EnableStaminaRestoration() {
	this->canRestoreStamina = true;
}

void UDSSimpleStaminaHandlerComponent::DisableStaminaRestoration() {
	this->canRestoreStamina = false;
}

void UDSSimpleStaminaHandlerComponent::RestoreStamina(float deltaTime) {
	if (this->stamina == this->maxStamina) return;
	this->stamina -= this->amountToDecrease * deltaTime;
	if (this->stamina >= this->maxStamina) this->stamina = this->maxStamina;
}

void UDSSimpleStaminaHandlerComponent::DisplayDebugInfoOnScreen() {
	UDSDebugTools::ShowDebugMessage(FString::Printf(TEXT("Stamina: %d / %d"), this->stamina, this->maxStamina), FColor::Green, 0);
}

