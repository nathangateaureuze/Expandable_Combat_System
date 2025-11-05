// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.


#include "BaseFighterController.h"
#include "Fighter.h"
#include "FighterStats.h"
#include "Action.h"
#include "../Combat.h"


void UBaseFighterController::Initialize(UFighter* owner)
{
	fighter = owner;
}

bool UBaseFighterController::GetHasTurn()
{
	return fighter->GetHasTurn();
}

void UBaseFighterController::TriggerAction(int actionId, UBaseFighterController* target)
{
	if (GetHasTurn())
	{
		fighter->TriggerAction(actionId, target);
	}
}

FLinearColor UBaseFighterController::GetColor()
{
	return fighter->GetIconColor();
}

int UBaseFighterController::GetCurrentHealth()
{
	return fighter->GetCurrentHealth();
}

FFighterStats UBaseFighterController::GetStats()
{
	return fighter->GetStats();
}

TMap<int, FText> UBaseFighterController::GetActionNames()
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

FText UBaseFighterController::GetActionDescription(int id)
{
	return fighter->actions[id]->GetActionDescription();
}

void UBaseFighterController::GetTurn()
{
	onGetTurn.Broadcast();
}

UBaseFighterController* UBaseFighterController::GetTarget()
{
	TArray<UBaseFighterController*> f = fighter->GetCombat()->GetFighters();
	return f[0];
}

void UBaseFighterController::OnGetTurn_Implementation()
{
	TriggerAction(0, GetTarget());
}
