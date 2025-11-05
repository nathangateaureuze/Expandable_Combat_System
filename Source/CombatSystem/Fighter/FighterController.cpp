// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterController.h"
#include "Fighter.h"
#include "FighterStats.h"
#include "FighterAction.h"


void UFighterController::Initialize(UFighter* owner)
{
	fighter = owner;
}

bool UFighterController::GetHasTurn()
{
	return fighter->GetHasTurn();
}

void UFighterController::TriggerAction(int actionId)
{
	if (GetHasTurn())
	{
		fighter->TriggerAction(actionId);
	}
}

FLinearColor UFighterController::GetColor()
{
	return fighter->GetIconColor();
}

int UFighterController::GetCurrentHealth()
{
	return fighter->GetCurrentHealth();
}

FFighterStats UFighterController::GetStats()
{
	return fighter->GetStats();
}

TMap<int, FText> UFighterController::GetActionNames()
{
	TMap<int, FText> names;
	TArray<int> keys = TArray<int>();
	fighter->actions.GenerateKeyArray(keys);

	for (int i = 0; i < keys.Num(); i++)
	{
		names.Add(keys[i], fighter->actions[keys[i]]->GetActionName());
	}

	return names;
}

FText UFighterController::GetActionDescription(int id)
{
	return fighter->actions[id]->GetActionDescription();
}

void UFighterController::GetTurn()
{
	onGetTurn.Broadcast();
}

void UFighterController::OnGetTurn_Implementation()
{
	TriggerAction(0);
}
