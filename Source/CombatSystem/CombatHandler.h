// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CombatHandler.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMainLoopExecuted, UBaseFighterController*, fighterController);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActiveFighterChanged, UBaseFighterController*, fighterController);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFighterAdded, UBaseFighterController*, fighterController, int, index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFighterRemoved, UBaseFighterController*, fighterController);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnQueueRefilled);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCombatEnded);

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
	FOnMainLoopExecuted onMainLoopExecuted;

	UPROPERTY(BlueprintAssignable)
	FOnActiveFighterChanged onActiveFighterChanged;

	UPROPERTY(BlueprintAssignable)
	FOnFighterAdded onFighterAdded;

	UPROPERTY(BlueprintAssignable)
	FOnFighterRemoved onFighterRemoved;

	UPROPERTY(BlueprintAssignable)
	FOnQueueRefilled onQueueRefilled;

	UPROPERTY(BlueprintAssignable)
	FOnCombatEnded onCombatEnded;


private:

	UCombat* combat;
	

};
