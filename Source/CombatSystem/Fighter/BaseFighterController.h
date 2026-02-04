// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseFighterController.generated.h"

class UFighter;
struct FFighterStats;
struct FActionInfos;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGetTurn);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class COMBATSYSTEM_API UBaseFighterController : public UObject
{
	GENERATED_BODY()


public:

	void Initialize(UFighter* owner);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool GetHasTurn();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetTeamIndex();

	UFUNCTION(BlueprintCallable)
	void TriggerAction(int actionId, UBaseFighterController* target);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FLinearColor GetColor();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetCurrentHealth();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FFighterStats GetStats();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TMap<int, FActionInfos> GetActionsInfos();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UBaseFighterController* GetTarget();

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged onHealthChanged;

	void GetTurn();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnGetTurn();
	virtual void OnGetTurn_Implementation();

	FOnGetTurn onGetTurn;


private:

	UFighter* fighter;

	
};
