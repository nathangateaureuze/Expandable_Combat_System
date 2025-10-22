// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FighterStats.h"
#include "Fighter.generated.h"

class UFighterAction;
class UEquipment;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthChanged);

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class COMBATSYSTEM_API UFighter : public UObject
{
	GENERATED_BODY()

public:

	UFighter();

	UFUNCTION(BlueprintCallable)
	virtual void Initialize();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetCurrentHealth();

	UFUNCTION(BlueprintCallable)
	void SetCurrentHealth(int value);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FFighterStats GetStats();

	UFUNCTION(BlueprintCallable)
	int TakeDamage(int value);

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged onHealthChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	TSubclassOf<UFighterAction> actionClass;

	UPROPERTY(BlueprintReadWrite)
	UFighterAction* actions;
	
private:

	UPROPERTY()
	FFighterStats stats;

	UPROPERTY()
	int currentHealth;

	UPROPERTY()
	UEquipment* equipment;
};