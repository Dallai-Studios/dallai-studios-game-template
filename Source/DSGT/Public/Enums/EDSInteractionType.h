#pragma once

#include "CoreMinimal.h"
#include "EDSInteractionType.generated.h"

UENUM(BlueprintType, Blueprintable)
enum class EDSInteractionType : uint8 {
	DOOR, // used for any kind of door in the game.
	PICKABLE, // interactables that can be hold by the player.
	STATIC, // interactables that needs the player's atention, takes controls of the camera.
	NPC // special interactable, takes control of the camera to present the NPC dialog.
};
