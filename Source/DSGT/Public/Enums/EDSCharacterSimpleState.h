#pragma once

#include "CoreMinimal.h"
#include "EDSCharacterSimpleState.generated.h"

UENUM(Blueprintable, BlueprintType)
enum class EDSCharacterSimpleState : uint8 {
	IDLE,
	WALKING,
	RUNNING,
	FALLING,
	DASHING,
	INTERACTING,
	TALKING
};
