// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FighterStats.h"
#include "Fighter.generated.h"

class UFighterAction;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnActionTriggered);

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class COMBATSYSTEM_API UFighter : public UObject
{
	GENERATED_BODY()

public:

	UFighter();

	/*	-------------------
	*	BP Initializer Values
	*	-------------------	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	TArray<TSubclassOf<UFighterAction>> initActionClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	FLinearColor initIconColor = FLinearColor(1, 0, 1, 1);
	//END of BP Initializer Values

	UFUNCTION(BlueprintCallable)
	virtual void Initialize();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetCurrentHealth();

	UFUNCTION(BlueprintCallable)
	void SetCurrentHealth(int value);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FFighterStats GetStats();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FLinearColor GetIconColor();

	//TEMP - Set player color
	UFUNCTION(BlueprintCallable)
	void SetColor(FLinearColor color);

	UFUNCTION(BlueprintCallable)
	int TakeDamage(int value);
	
	void TriggerAction(UFighter* target);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void LaunchAction(UFighter* target);
	virtual void LaunchAction_Implementation(UFighter* target);

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged onHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnActionTriggered onActionTriggered;

	
private:

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UFighterAction>> actionClass;

protected:

	UPROPERTY(EditAnywhere)
	FFighterStats stats;

	UPROPERTY(EditAnywhere)
	TArray<UFighterAction*> actions;

	UFighterAction* selectedAction;

	UPROPERTY()
	int currentHealth;

	UPROPERTY(EditAnywhere)
	FLinearColor iconColor = FLinearColor(1, 0, 1, 1);
};