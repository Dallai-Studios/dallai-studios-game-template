#pragma once

#include "CoreMinimal.h"
#include "EDSBaseGameClientHudState.generated.h"

UENUM(BlueprintType, Blueprintable)
enum class EdsBaseGameClientHudState : uint8 {
	GAME_SETTINGS,
	AUDIO_SETTINGS,
	VIDEO_SETTINGS
};
