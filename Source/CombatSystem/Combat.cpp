// Fill out your copyright notice in the Description page of Project Settings.


#include "Combat.h"
#include "Fighter/Fighter.h"
#include "Fighter/FighterAction.h"
#include "Misc.h"


UCombat::UCombat()
{
}

void UCombat::Initialize()
{
	TArray<UFighter*>sortedFighters = SortFighters(initFighters);

	for (int i = 0; i < sortedFighters.Num(); i++)
	{
		sortedFighters[i]->Initialize();
		AddFighter(sortedFighters[i], i);
	}
}

void UCombat::MainLoop()
{
	if (fightersQueue.IsEmpty())
	{ RefillQueue(); }

	SetActiveFighter(fightersQueue[0]);

	fightersQueue.RemoveAt(0);

	activeFighter->onActionTriggered.AddUniqueDynamic(this, &UCombat::OnActionTriggered);
	activeFighter->LaunchAction(this);
}

void UCombat::Start()
{
	this->MainLoop();
}

void UCombat::AddFighter(UFighter* fighter, int index)
{
	fighters.Insert(fighter, index);

	onAddedFighter.Broadcast(fighter, index);
}

void UCombat::SetActiveFighter(UFighter* fighter)
{
	activeFighter = fighter;
	onActiveFighterChanged.Broadcast(fighter->controller);
}

TArray<UFighter*> UCombat::GetFighters()
{
	return fighters;
}

void UCombat::RefillQueue()
{
	fightersQueue = fighters;
	onQueueRefilled.Broadcast();
}

void UCombat::OnActionTriggered()
{
	onMainLoopExecuted.Broadcast();
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
