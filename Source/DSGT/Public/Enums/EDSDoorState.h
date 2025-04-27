#pragma once

#include "CoreMinimal.h"
#include "EDSDoorState.generated.h"

UENUM(Blueprintable, BlueprintType)
enum class EDSDoorState : uint8 {
	CLOSED,
	OPEN_FORWARD,
	OPEN_BACKWARDS
};
