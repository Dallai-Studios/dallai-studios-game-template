#pragma once

#include "CoreMinimal.h"
#include "FDSDialogueEntry.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct FDSDialogueEntry {
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText characterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FText> dialogueText;
};
