
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
UFighterController* UFighter::GetController()
{
	return controller;
}

bool UFighter::GetHasTurn()
{
	return hasTurn;
}

void UFighter::SetHasTurn(bool value)
{
	hasTurn = value;
	controller->OnGetTurn();
}

int UFighter::GetCurrentHealth()
{
	return currentHealth;
}

void UFighter::SetCurrentHealth(int value)
{
	currentHealth = value;

	controller->onHealthChanged.Broadcast();

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

void UFighter::TriggerAction(int actionId)
{
	UFighterAction* selectedAction = actions[actionId];

	if (selectedAction)
	{
		selectedAction->Trigger(this, this);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("UFighter::TriggerAction - invalid refs!"));
	}
	onActionTriggered.Broadcast();
	return;
}

void UFighter::SetColor(FLinearColor color)
{
	iconColor = color;
}