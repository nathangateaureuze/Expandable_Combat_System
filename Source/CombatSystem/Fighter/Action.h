// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ActionInfos.h"
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

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Trigger(UFighter* from, UFighter* target, UCombat* combat);
	virtual void Trigger_Implementation(UFighter* from, UFighter* target, UCombat* combat);

	FActionInfos GetInfos();


private:

	UPROPERTY(EditAnywhere)
	FActionInfos infos = FActionInfos();


};
