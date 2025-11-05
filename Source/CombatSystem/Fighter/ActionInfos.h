// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ActionInfos.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FActionInfos
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int maxHealth = 10;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int speed = 10;
	
};