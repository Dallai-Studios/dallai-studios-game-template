// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Components/DSGamePauseComponent.h"
#include "Blueprint/UserWidget.h"
#include "HUD/DSBaseGameClientOptionsHUD.h"
#include "Tools/DSDebugTools.h"

// ==============================================================
// Lifecycle Methods:
// ==============================================================
UDSGamePauseComponent::UDSGamePauseComponent() {
	PrimaryComponentTick.bCanEverTick = false;
}

void UDSGamePauseComponent::BeginPlay() {
	Super::BeginPlay();

	if (!this->GameClientHudInstanceIsValid()) return;
	
	this->gameClientOptionsHUDInstance = Cast<UDSBaseGameClientOptionsHUD>(CreateWidget(this, this->gameClientOptionsHUDWidgetReference));
	this->gameClientOptionsHUDInstance->OnCloseGameClientOptionsHUD.AddDynamic(this, &UDSGamePauseComponent::ClosePauseMenu);
	this->gameClientOptionsHUDInstance->AddToViewport();
	this->gameClientOptionsHUDInstance->SetVisibility(ESlateVisibility::Hidden);
}



// ==============================================================
// Component Methods:
// ==============================================================
void UDSGamePauseComponent::OpenPauseMenu() {
	if (!this->GameClientHudInstanceIsValid()) return;
	auto playerController = this->GetWorld()->GetFirstPlayerController();
	playerController->SetInputMode(FInputModeUIOnly());
	playerController->SetShowMouseCursor(true);
	this->gameClientOptionsHUDInstance->SetVisibility(ESlateVisibility::Visible);
}

bool UDSGamePauseComponent::IsPauseMenuOpen() {
	return this->gameClientOptionsHUDInstance->IsVisible();
}

void UDSGamePauseComponent::ClosePauseMenu() {
	if (!this->GameClientHudInstanceIsValid()) return;
	auto playerController = this->GetWorld()->GetFirstPlayerController();
	playerController->SetInputMode(FInputModeGameAndUI());
	playerController->SetShowMouseCursor(false);
	this->gameClientOptionsHUDInstance->SetVisibility(ESlateVisibility::Hidden);
}

bool UDSGamePauseComponent::GameClientHudInstanceIsValid() {
	if (this->gameClientOptionsHUDWidgetReference == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("The Game Client Options HUD Reference is not defined on the GamePauseComponent"));
		return false;
	}
	return true;
}
