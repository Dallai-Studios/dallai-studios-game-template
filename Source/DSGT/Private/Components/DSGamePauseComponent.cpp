// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Components/DSGamePauseComponent.h"
#include "Blueprint/UserWidget.h"
#include "Components/AudioComponent.h"
#include "Components/TimelineComponent.h"
#include "HUD/DSBaseGameClientOptionsHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Tools/DSDebugTools.h"

// ==============================================================
// Lifecycle Methods:
// ==============================================================
UDSGamePauseComponent::UDSGamePauseComponent() {
	PrimaryComponentTick.bCanEverTick = false;
	this->audioFadeOutTimeline = this->CreateDefaultSubobject<UTimelineComponent>("Audio Fade Out Timeline");
}

void UDSGamePauseComponent::BeginPlay() {
	Super::BeginPlay();

	if (this->audioFadeOutCurve && this->pauseMenuMusic) {
		FOnTimelineFloat updateTimelineFunction;
		updateTimelineFunction.BindUFunction(this, FName("HandleAudioFadeOut"));
		this->audioFadeOutTimeline->AddInterpFloat(this->audioFadeOutCurve, updateTimelineFunction);

		FOnTimelineEvent timelineFinishEvent;
		timelineFinishEvent.BindUFunction(this, FName("OnFadeOutFinish"));
		this->audioFadeOutTimeline->SetTimelineFinishedFunc(timelineFinishEvent);
	}
	
	if (!this->GameClientHudInstanceIsValid()) return;

	this->gameClientOptionsHUDInstance = Cast<UDSBaseGameClientOptionsHUD>(CreateWidget(this->GetWorld(), this->gameClientOptionsHUDWidgetReference));

	if (this->GameClientHudInstanceIsValid()) {
		this->gameClientOptionsHUDInstance->OnCloseGameClientOptionsHUD.AddDynamic(this, &UDSGamePauseComponent::ClosePauseMenu);
		this->gameClientOptionsHUDInstance->AddToViewport();
		this->gameClientOptionsHUDInstance->SetVisibility(ESlateVisibility::Collapsed);
	}
}

// ==============================================================
// Component Methods:
// ==============================================================
void UDSGamePauseComponent::OpenPauseMenu() {
	if (!this->GameClientHudInstanceIsValid()) return;
	auto playerController = this->GetWorld()->GetFirstPlayerController();
	playerController->SetShowMouseCursor(true);
	this->gameClientOptionsHUDInstance->SetVisibility(ESlateVisibility::Visible);

	// I can define a music to play when the player press the menu button.
	// I also have a timeline to fade out the music when the player close the game pause HUD. -Dallai
	if (this->pauseMenuMusic) {
		this->audioComponent = UGameplayStatics::CreateSound2D(this->GetWorld(), this->pauseMenuMusic);
		this->audioComponent->Play();
	}
}

bool UDSGamePauseComponent::IsPauseMenuOpen() {
	return this->gameClientOptionsHUDInstance->IsVisible();
}

void UDSGamePauseComponent::ClosePauseMenu() {
	if (!this->GameClientHudInstanceIsValid()) return;
	auto playerController = this->GetWorld()->GetFirstPlayerController();
	playerController->SetShowMouseCursor(false);
	this->gameClientOptionsHUDInstance->SetVisibility(ESlateVisibility::Collapsed);

	if (this->audioComponent && this->audioFadeOutCurve) {
		this->audioFadeOutTimeline->PlayFromStart();
	}
}

void UDSGamePauseComponent::HandleAudioFadeOut(float value) {
	if (this->audioComponent) this->audioComponent->SetVolumeMultiplier(value);
}

void UDSGamePauseComponent::OnFadeOutFinish() {
	if (this->audioComponent) this->audioComponent->Stop();
}

bool UDSGamePauseComponent::GameClientHudInstanceIsValid() {
	if (this->gameClientOptionsHUDWidgetReference == NULL) {
		UDSDebugTools::ShowDebugMessage(TEXT("The Game Client Options HUD Reference is not defined on the GamePauseComponent"));
		return false;
	}
	return true;
}
