// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FighterController.generated.h"

class UFighter;
struct FFighterStats;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGetTurn);

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
	bool GetHasTurn();

	UFUNCTION(BlueprintCallable)
	void TriggerAction(int actionId);

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

	void GetTurn();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnGetTurn();
	virtual void OnGetTurn_Implementation();

	FOnGetTurn onGetTurn;

private:

	UFighter* fighter;
	
};
