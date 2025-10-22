
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
	if (!actionClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("UFighter::Initialize - actionClass is invalid"));
		actionClass = UFighterAction::StaticClass();
	}
	actions = NewObject<UFighterAction>(this, actionClass);
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

int UFighter::TakeDamage(int value)
{
	int result = FMath::Max(currentHealth - value, 0);
	SetCurrentHealth(result);
	return 0;
}
