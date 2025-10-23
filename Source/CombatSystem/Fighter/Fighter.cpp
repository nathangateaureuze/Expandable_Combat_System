
// Fill out your copyright notice in the Description page of Project Settings.


#include "Fighter.h"
#include "FighterAction.h"
#include "Equipment.h"

UFighter::UFighter()
{
	currentHealth = stats.maxHealth;
}

void UFighter::Initialize()
{
	for (int i = 0; i < actionClass.Num(); i++)
	{
		if (!actionClass[i])
		{
			UE_LOG(LogTemp, Warning, TEXT("UFighter::Initialize - actionClass is invalid"));
			actionClass[i] = UFighterAction::StaticClass();
		}
		actions.Add(NewObject<UFighterAction>(this, actionClass[i]));
	}
}

int UFighter::GetCurrentHealth()
{
	return currentHealth;
}

void UFighter::SetCurrentHealth(int value)
{
	currentHealth = value;

	onHealthChanged.Broadcast();

	return;
}

FFighterStats UFighter::GetStats()
{
	return stats;
}

FLinearColor UFighter::GetIconColor()
{
	return iconColor;
}

int UFighter::TakeDamage(int value)
{
	int result = FMath::Max(currentHealth - value, 0);
	SetCurrentHealth(result);
	return 0;
}
