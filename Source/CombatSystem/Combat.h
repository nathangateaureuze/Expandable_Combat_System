// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Combat.generated.h"

class UCombatHandler;
class UFighter;
class UBaseFighterController;
class UAction;

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

	void MainLoop();
	
	UFUNCTION(BlueprintCallable)
	void AddFighter(UFighter* fighter, int index);

	TArray<UFighter*> GetFighters();

	TArray<UFighter*> GetQueue();

	UFighter* GetControllerFighter(UBaseFighterController* controller);


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
