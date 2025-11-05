// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Combat.generated.h"

class UCombatHandler;
class UFighter;
class UBaseFighterController;
class UAction;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAddedFighter, UBaseFighterController*, fighterController, int, index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMainLoopExecuted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActiveFighterChanged, UBaseFighterController*, fighterController);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnQueueRefilled);

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class COMBATSYSTEM_API UCombat : public UObject
{
	GENERATED_BODY()

public:

	UCombat();

	/*	-------------------
	*	BP Initializer Values
	*	-------------------	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	TArray<UFighter*> initFighters;
	//END of BP Initializer Values

	UFUNCTION(BlueprintCallable)
	void Initialize();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UCombatHandler* GetHandler();

	UFUNCTION(BlueprintCallable)
	void MainLoop();

	UFUNCTION(BlueprintCallable)
	void Start();
	
	UFUNCTION(BlueprintCallable)
	void AddFighter(UFighter* fighter, int index);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<UBaseFighterController*> GetFighters();

	UPROPERTY(BlueprintAssignable)
	FOnAddedFighter onAddedFighter;

	UPROPERTY(BlueprintAssignable)
	FOnMainLoopExecuted onMainLoopExecuted;

	UPROPERTY(BlueprintAssignable)
	FOnActiveFighterChanged onActiveFighterChanged;

	UPROPERTY(BlueprintAssignable)
	FOnQueueRefilled onQueueRefilled;


private:

	UCombatHandler* handler;

	TArray<UFighter*> fighters;
	TArray<UFighter*> fightersQueue;

	UFighter* activeFighter;

	UFUNCTION()
	void SetActiveFighter(UFighter* fighter);

	void RefillQueue();

	UFUNCTION()
	virtual void OnActionTriggered();

	static TArray<UFighter*> SortFighters(TArray<UFighter*> fighters);
};
