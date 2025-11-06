// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.


#include "Combat.h"
#include "CombatHandler.h"
#include "Fighter/Fighter.h"
#include "Fighter/Action.h"
#include "Misc.h"


UCombat::UCombat()
{
}

void UCombat::Initialize()
{
	handler = NewObject<UCombatHandler>(this);
	handler->Initialize(this);

	TArray<UFighter*>sortedFighters = SortFighters(initFighters);

	for (int i = 0; i < sortedFighters.Num(); i++)
	{
		sortedFighters[i]->Initialize(this);
		AddFighter(sortedFighters[i], i);
	}
}

UCombatHandler* UCombat::GetHandler()
{
	return handler;
}

void UCombat::MainLoop()
{
	if (fightersQueue.IsEmpty())
	{ RefillQueue(); }

	SetActiveFighter(fightersQueue[0]);

	fightersQueue.RemoveAt(0);

	activeFighter->onTurnEnded.AddUniqueDynamic(this, &UCombat::OnActionTriggered);
	activeFighter->SetHasTurn(true);
}

void UCombat::AddFighter(UFighter* fighter, int index)
{
	fighters.Insert(fighter, index);

	handler->onAddedFighter.Broadcast(fighter->GetController(), index);
}

void UCombat::SetActiveFighter(UFighter* fighter)
{
	activeFighter = fighter;
	handler->onActiveFighterChanged.Broadcast(fighter->GetController());
}

TArray<UFighter*> UCombat::GetFighters()
{
	return fighters;
}

TArray<UFighter*> UCombat::GetQueue()
{
	return fightersQueue;
}

void UCombat::RefillQueue()
{
	fightersQueue = fighters;
	handler->onQueueRefilled.Broadcast();
}

void UCombat::OnActionTriggered()
{
	activeFighter->SetHasTurn(false);
	handler->onMainLoopExecuted.Broadcast();
}

TArray<UFighter*> UCombat::SortFighters(TArray<UFighter*> fighters)
{
    TArray<float> speeds;

	for (int i = 0; i < fighters.Num(); i++)
	{
		speeds.Add(fighters[i]->GetStats().speed);
	}

    return Misc::BubbleSortInvert<UFighter*>(fighters, speeds);
}
