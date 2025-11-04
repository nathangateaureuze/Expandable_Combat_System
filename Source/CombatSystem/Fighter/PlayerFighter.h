// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Fighter.h"
#include "PlayerFighter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWaitingForInput);

/**
 * 
 */
UCLASS()
class COMBATSYSTEM_API UPlayerFighter : public UFighter
{
	GENERATED_BODY()

	void LaunchAction_Implementation(UCombat* combat) override;

public:

	FWaitingForInput waitingForInput;

};
