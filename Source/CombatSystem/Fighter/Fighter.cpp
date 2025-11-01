
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
		selectedAction->Trigger(this, target);

		FString className = selectedAction->GetName();
		UE_LOG(LogTemp, Warning, TEXT("UFighter::TriggerAction - triggered action! : %s"), *className);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("UFighter::TriggerAction - invalid refs!"));
	}
	onActionTriggered.Broadcast();
	return;
}

void UFighter::LaunchAction_Implementation(UFighter* target)
{
	TriggerAction(target);
	UE_LOG(LogTemp, Warning, TEXT("UFighter::LaunchAction_Implementation - done!"));
	return;
}

void UFighter::SetColor(FLinearColor color)
{
	iconColor = color;
}