// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.


#include "BaseFighterController.h"
#include "Fighter.h"
#include "FighterStats.h"
#include "Action.h"
#include "ActionInfos.h"
#include "../Combat.h"
#include "../CombatHandler.h"


void UBaseFighterController::Initialize(UFighter* owner)
{
	fighter = owner;
}

bool UBaseFighterController::GetHasTurn()
{
	return fighter->GetHasTurn();
}

int UBaseFighterController::GetTeamIndex()
{
	return fighter->GetTeamIndex();
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

TMap<int, FActionInfos> UBaseFighterController::GetActionsInfos()
{
	TMap<int, FActionInfos> infos;

	for (int i = 0; i < fighter->actions.Num(); i++)
	{
		infos.Add(i, fighter->actions[i]->GetInfos());
	}

	return infos;
}

void UBaseFighterController::GetTurn()
{
	onGetTurn.Broadcast();
}

UBaseFighterController* UBaseFighterController::GetTarget()
{
	TArray<UBaseFighterController*> f = fighter->GetCombat()->GetHandler()->GetFighters();
	if (f.Num() == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("UBaseFighterController::GetTarget -No fighter found"));
	}
	return f[FMath::Rand() % f.Num()];
}

void UBaseFighterController::OnGetTurn_Implementation()
{
	TriggerAction(0, GetTarget());
}
