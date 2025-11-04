// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FighterController.generated.h"

class UFighter;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class COMBATSYSTEM_API UFighterController : public UObject
{
	GENERATED_BODY()

public:

	void Initialize(UFighter* owner);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TMap<int, FText> GetActionNames();

private:

	UFighter* fighter;
	
};
