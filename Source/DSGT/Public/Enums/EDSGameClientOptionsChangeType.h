#pragma once

#include "CoreMinimal.h"
#include "EDSGameClientOptionsChangeType.generated.h"

UENUM(Blueprintable, BlueprintType)
enum class EDSGameClientOptionsChangeType : uint8 {
	NEXT,
	PREVIUS
};
