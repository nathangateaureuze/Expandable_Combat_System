
// Fill out your copyright notice in the Description page of Project Settings.


#include "Fighter.h"
#include "../Combat.h"
#include "FighterController.h"
#include "FighterAction.h"

UFighter::UFighter()
{
	currentHealth = stats.maxHealth;
}

void UFighter::Initialize()
{
	controller = NewObject<UFighterController>();
	controller->Initialize(this);

	iconColor = initIconColor;
	actionClass = initActionClass;

	for (int i = 0; i < actionClass.Num(); i++)
	{
		if (!actionClass[i])
		{
			UE_LOG(LogTemp, Warning, TEXT("UFighter::Initialize - actionClass is invalid"));
			actionClass[i] = UFighterAction::StaticClass();
		}
		actions.Add(actions.Num(), NewObject<UFighterAction>(this, actionClass[i]));
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
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("UFighter::TriggerAction - invalid refs!"));
	}
	onActionTriggered.Broadcast();
	return;
}

void UFighter::LaunchAction_Implementation(UCombat* combat)
{
	UFighter* target = combat->GetFighters()[0];
	TriggerAction(target);
	return;
}

void UFighter::SetColor(FLinearColor color)
{
	iconColor = color;
}