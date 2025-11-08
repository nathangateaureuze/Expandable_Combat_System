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
	FText name = FText::FromString(TEXT("NONE"));

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText description = FText::FromString(TEXT("NONE"));
	
};