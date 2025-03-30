// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DSGamePauseComponent.generated.h"


UCLASS(BlueprintType, Blueprintable, ClassGroup=(Components), meta=(BlueprintSpawnableComponent))
class UDSGamePauseComponent : public UActorComponent {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Options HUD")
	TSubclassOf<class UUserWidget> gameClientOptionsHUDWidgetReference;

private:
	class UDSBaseGameClientOptionsHUD* gameClientOptionsHUDInstance;
	
public:
	UDSGamePauseComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void OpenPauseMenu();

	UFUNCTION(BlueprintCallable, Category="Component Methods")
	bool IsPauseMenuOpen();

	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void ClosePauseMenu();

private:
	bool GameClientHudInstanceIsValid();
};
