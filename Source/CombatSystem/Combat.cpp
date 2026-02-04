// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.


#include "Combat.h"
#include "CombatHandler.h"
#include "Fighter/Fighter.h"
#include "Fighter/Action.h"
#include "Misc.h"


void UCombat::Initialize(TArray<UFighter*> initFighters)
{
	handler = NewObject<UCombatHandler>(this);
	handler->Initialize(this);

	fighters = SortFighters(initFighters);

	for (int i = 0; i < fighters.Num(); i++)
	{
		fighters[i]->Initialize(this);
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

void UCombat::End()
{
	handler->onCombatEnded.Broadcast();
}

void UCombat::AddFighter(UFighter* fighter)
{
	int speed = fighter->GetStats().speed;
	int index = 0;

	for (; index < fighters.Num(); index++)
	{
		if (fighters[index]->GetStats().speed < speed)
		{ break; }
	}
	fighters.Insert(fighter, index);

	handler->onFighterAdded.Broadcast(fighter->GetController(), index);
}

void UCombat::RemoveFighter(UFighter* fighter)
{
	int index = fighters.Find(fighter);

	if (index == INDEX_NONE)
	{ return; }

	fighters.RemoveAt(index);
	handler->onFighterRemoved.Broadcast(fighter->GetController());

	//TODO replace by: is N team winning?
	if (fighters.IsEmpty())
	{
		End();
	}
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

UFighter* UCombat::GetControllerFighter(UBaseFighterController* controller)
{
	for (int i = 0; i < fighters.Num(); i++)
	{
		if (fighters[i]->GetController() == controller)
		{
			return fighters[i];
		}
	}

	return nullptr;
}

void UCombat::RefillQueue()
{
	fightersQueue = fighters;
	handler->onQueueRefilled.Broadcast();
}

void UCombat::OnActionTriggered()
{
	activeFighter->SetHasTurn(false);
	handler->onMainLoopExecuted.Broadcast(activeFighter->GetController());
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
