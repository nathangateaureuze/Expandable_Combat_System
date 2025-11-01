// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Fighter/Fighter.h"
#include "NPCFighter.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class COMBATSYSTEM_API UNPCFighter : public UFighter
{
	GENERATED_BODY()

public:

	void LaunchAction_Implementation(UFighter* target) override;
	
};
