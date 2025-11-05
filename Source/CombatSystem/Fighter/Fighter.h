// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FighterStats.h"
#include "Fighter.generated.h"

class UCombat;
class UFighterController;
class UFighterAction;

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
	TSubclassOf<UFighterController> controllerClass;

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
	
	void TriggerAction(int actionId);

	UPROPERTY(BlueprintAssignable)
	FOnActionTriggered onActionTriggered;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TMap<int, UFighterAction*> actions;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UFighterController* GetController();

	UFUNCTION()
	bool GetHasTurn();

	UFUNCTION()
	void SetHasTurn(bool value);

	
private:

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UFighterAction>> actionClass;

	UPROPERTY()
	UFighterController* controller;

	bool hasTurn;

protected:

	UPROPERTY(EditAnywhere)
	FFighterStats stats;

	UPROPERTY()
	int currentHealth;

	UPROPERTY(EditAnywhere)
	FLinearColor iconColor = FLinearColor(1, 0, 1, 1);
};