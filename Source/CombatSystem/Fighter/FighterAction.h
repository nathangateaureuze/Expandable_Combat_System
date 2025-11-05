// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FighterStats.h"
#include "FighterAction.generated.h"

class UFighter;
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class COMBATSYSTEM_API UFighterAction : public UObject
{
	GENERATED_BODY()

public:

	UFighterAction();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Trigger(UFighter* from, UFighter* target);
	virtual void Trigger_Implementation(UFighter* from, UFighter* target);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FText GetActionName();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FText GetActionDescription();

private:
	UPROPERTY(EditAnywhere)
	FText name = FText::FromString(TEXT("NONE"));

	UPROPERTY(EditAnywhere)
	FText description = FText::FromString(TEXT("NONE"));
};
