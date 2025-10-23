// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FighterStats.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FFighterStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int maxHealth = 10;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int speed = 10;
	
};