// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

#pragma once

#include "CoreMinimal.h"
#include "FighterController.h"
#include "FighterPlayerController.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class COMBATSYSTEM_API UFighterPlayerController : public UFighterController
{
	GENERATED_BODY()

	void OnGetTurn_Implementation() override;
	
};
