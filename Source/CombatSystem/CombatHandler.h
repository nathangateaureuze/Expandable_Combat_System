// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CombatHandler.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAddedFighter, UBaseFighterController*, fighterController, int, index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMainLoopExecuted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActiveFighterChanged, UBaseFighterController*, fighterController);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnQueueRefilled);

class UCombat;

/**
 * 
 */
UCLASS(BlueprintType)
class COMBATSYSTEM_API UCombatHandler : public UObject
{
	GENERATED_BODY()

public:

	void Initialize(UCombat* owner);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<UBaseFighterController*> GetFighters();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<UBaseFighterController*> GetQueue();

	UFUNCTION(BlueprintCallable)
	void StartTurn();



	UPROPERTY(BlueprintAssignable)
	FOnAddedFighter onAddedFighter;

	UPROPERTY(BlueprintAssignable)
	FOnMainLoopExecuted onMainLoopExecuted;

	UPROPERTY(BlueprintAssignable)
	FOnActiveFighterChanged onActiveFighterChanged;

	UPROPERTY(BlueprintAssignable)
	FOnQueueRefilled onQueueRefilled;

private:

	UCombat* combat;
	
};
