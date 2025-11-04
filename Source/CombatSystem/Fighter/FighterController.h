// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FighterController.generated.h"

class UFighter;
struct FFighterStats;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthChanged);

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
	FLinearColor GetColor();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetCurrentHealth();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FFighterStats GetStats();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TMap<int, FText> GetActionNames();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FText GetActionDescription(int id);

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged onHealthChanged;

private:

	UFighter* fighter;
	
};
