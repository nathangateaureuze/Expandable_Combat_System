
// Fill out your copyright notice in the Description page of Project Settings.


#include "Fighter.h"
#include "FighterAction.h"

UFighter::UFighter()
{
	currentHealth = stats.maxHealth;
}

void UFighter::Initialize()
{
	iconColor = initIconColor;
	actionClass = initActionClass;

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
	value = value < 0 ? 0 : value;
	int result = FMath::Max(currentHealth - value, 0);
	SetCurrentHealth(result);
	return 0;
}

void UFighter::TriggerAction(UFighter* target)
{
	if (selectedAction && target)
	{
		selectedAction->Trigger_Implementation(this, target);
	}
	onActionTriggered.Broadcast();
	return;
}

void UFighter::LaunchAction(UFighter* target)
{
	TriggerAction(target);
	return;
}

void UFighter::SetColor(FLinearColor color)
{
	iconColor = color;
}