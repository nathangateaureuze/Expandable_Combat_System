// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Combat.generated.h"

class UFighter;
class UFighterAction;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTargetChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAddedFighter, UFighter*, fighter, int, index);
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

	UFUNCTION(BlueprintCallable)
	void MainLoop();
	
	UFUNCTION(BlueprintCallable)
	void AddFighter(UFighter* fighter, int index);

	void SetTargetedFighter(UFighter* target);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<UFighter*> GetFighters();

	UPROPERTY(BlueprintAssignable)
	FOnTargetChanged onTargetChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAddedFighter onAddedFighter;

	UPROPERTY(BlueprintAssignable)
	FOnQueueRefilled onQueueRefilled;


private:
	TArray<UFighter*> fighters;
	TArray<UFighter*> fightersQueue;

	UFighter* activeFighter;
	UFighter* targetedFighter;

	void LaunchAction();

	void RefillQueue();

	UFUNCTION()
	void OnActionTriggered();

	static TArray<UFighter*> SortFighters(TArray<UFighter*> fighters);
};
