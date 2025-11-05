// Fill out your copyright notice in the Description page of Project Settings.

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
