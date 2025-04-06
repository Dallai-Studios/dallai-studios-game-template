#pragma once

#include "CoreMinimal.h"
#include "EDSInteractionType.generated.h"

UENUM(BlueprintType, Blueprintable)
enum class EDSInteractionType : uint8 {
	PICKABLE,
	STATIC,
	NPC
};
