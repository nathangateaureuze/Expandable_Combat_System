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
		AddFighter(sortedFighters[i], i);
	}
}

void UCombat::MainLoop()
{
	if (fightersQueue.IsEmpty())
	{ RefillQueue(); }

	activeFighter = fightersQueue[0];

	targetedFighter = fighters[(int)FMath::RandRange(0,fighters.Num()-1)];

	activeFighter->onActionTriggered.AddUniqueDynamic(this, &UCombat::OnActionTriggered);
	activeFighter->LaunchAction(activeFighter);
}

void UCombat::AddFighter(UFighter* fighter, int index)
{
	fighters.Insert(fighter, index);

	onAddedFighter.Broadcast(fighter, index);
}

void UCombat::SetTargetedFighter(UFighter* target)
{
	targetedFighter = target;

	onTargetChanged.Broadcast();
}

TArray<UFighter*> UCombat::GetFighters()
{
	return fighters;
}

void UCombat::LaunchAction()
{
	activeFighter->LaunchAction(targetedFighter);
	return;
}

void UCombat::RefillQueue()
{
	fightersQueue = fighters;
	onQueueRefilled.Broadcast();
}

void UCombat::OnActionTriggered()
{
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
