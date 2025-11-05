// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Action.generated.h"

class UFighter;
class UCombat;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class COMBATSYSTEM_API UAction : public UObject
{
	GENERATED_BODY()

public:

	UAction();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Trigger(UFighter* from, UFighter* target, UCombat* combat);
	virtual void Trigger_Implementation(UFighter* from, UFighter* target, UCombat* combat);

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
