// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FighterStats.h"
#include "Fighter.generated.h"

class UCombat;
class UBaseFighterController;
class UAction;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTurnEnded);

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
	TArray<TSubclassOf<UAction>> initActionClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	TSubclassOf<UBaseFighterController> controllerClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	FLinearColor initIconColor = FLinearColor(1, 0, 1, 1);
	//END of BP Initializer Values

	virtual void Initialize(UCombat* owner);

	int GetCurrentHealth();

	void SetCurrentHealth(int value);

	FFighterStats GetStats();

	FLinearColor GetIconColor();

	UFUNCTION(BlueprintCallable)
	int TakeDamage(int value);
	
	void TriggerAction(int actionId, UBaseFighterController* target);

	void EndTurn();

	FOnTurnEnded onTurnEnded;

	TMap<int, UAction*> actions;

	UBaseFighterController* GetController();

	bool GetHasTurn();

	void SetHasTurn(bool value);

	UCombat* GetCombat();

	
private:

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UAction>> actionClass;

	UPROPERTY(EditAnywhere)
	UBaseFighterController* controller;

	UCombat* combat;

	bool hasTurn;

protected:

	UPROPERTY(EditAnywhere)
	FFighterStats stats;

	int currentHealth;

	UPROPERTY(EditAnywhere)
	FLinearColor iconColor;
};