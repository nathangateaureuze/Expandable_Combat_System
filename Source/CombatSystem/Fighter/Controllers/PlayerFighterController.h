// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

#pragma once

#include "CoreMinimal.h"
#include "../BaseFighterController.h"
#include "PlayerFighterController.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class COMBATSYSTEM_API UPlayerFighterController : public UBaseFighterController
{
	GENERATED_BODY()

	void OnGetTurn_Implementation() override;
	
};
