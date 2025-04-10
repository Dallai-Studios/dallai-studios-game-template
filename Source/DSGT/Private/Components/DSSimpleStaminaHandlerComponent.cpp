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

	if (!this->canRestoreStamina) {
		this->DecreaseStamina(DeltaTime);
		return;
	}

	this->RestoreStamina(DeltaTime);
}

bool UDSSimpleStaminaHandlerComponent::HasStamina() const {
	return this->stamina > this->amountToDecrease;
}

float UDSSimpleStaminaHandlerComponent::GetCurrentStamina() const {
	return this->stamina;
}

void UDSSimpleStaminaHandlerComponent::EnableStaminaRestoration() {
	this->canRestoreStamina = true;
}

void UDSSimpleStaminaHandlerComponent::DisableStaminaRestoration() {
	this->canRestoreStamina = false;
}

void UDSSimpleStaminaHandlerComponent::DecreaseStamina(float deltaTime) {
	if (this->stamina == 0.f) return;
	this->stamina -= this->amountToDecrease * deltaTime;
	if (this->stamina <= 0.f) this->stamina = 0.f;
}

void UDSSimpleStaminaHandlerComponent::RestoreStamina(float deltaTime) {
	if (this->stamina == this->maxStamina) return;
	this->stamina += this->amountToRestore * deltaTime;
	if (this->stamina >= this->maxStamina) this->stamina = this->maxStamina;
}

void UDSSimpleStaminaHandlerComponent::DisplayDebugInfoOnScreen() {
	UDSDebugTools::ShowDebugMessage(FString::Printf(TEXT("Stamina: %f / %f"), this->stamina, this->maxStamina), FColor::Green, 0);
	UDSDebugTools::ShowDebugMessage(FString::Printf(TEXT("Restoring Stamina: %d"), this->canRestoreStamina), FColor::Green, 0);
}

