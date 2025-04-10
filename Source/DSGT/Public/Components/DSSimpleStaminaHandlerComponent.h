// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DSSimpleStaminaHandlerComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DSGT_API UDSSimpleStaminaHandlerComponent : public UActorComponent {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Component Configuration")
	float maxStamina = 100;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Component Configuration")
	float amountToDecrease = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Component Configuration")
	float amountToRestore = 0.5;

	UPROPERTY(EditAnywhere, Category="Component Configuration")
	bool showDebugInfo = true;

private:
	float stamina;
	bool canRestoreStamina = true;
	
public:
	UDSSimpleStaminaHandlerComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Component Methods")
	bool HasStamina() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Component Methods")
	float GetCurrentStamina() const;
	
	UFUNCTION(BlueprintCallable, Category="Component Methods")
	void EnableStaminaRestoration();

	UFUNCTION(BlueprintCallable, Category="Componetn Methods")
	void DisableStaminaRestoration();

private:
	void DecreaseStamina(float deltaTime);
	void RestoreStamina(float deltaTime);
	void DisplayDebugInfoOnScreen();
};
