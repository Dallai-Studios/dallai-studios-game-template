// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DSSimPlayerCharacter.generated.h"

UCLASS()
class ADSSimPlayerCharacter : public ACharacter {
	GENERATED_BODY()

public:
	ADSSimPlayerCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
