// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.


#include "CombatHandler.h"
#include "Combat.h"
#include "Fighter/Fighter.h"
#include "Fighter/BaseFighterController.h"

void UCombatHandler::Initialize(UCombat* owner)
{
	combat = owner;
}

TArray<UBaseFighterController*> UCombatHandler::GetFighters()
{
	TArray<UFighter*> fighters = combat->GetFighters();
	TArray<UBaseFighterController*> controllers;

	for (int i = 0; i < fighters.Num(); i++)
	{
		controllers.Add(fighters[i]->GetController());
	}

	return controllers;
}

TArray<UBaseFighterController*> UCombatHandler::GetQueue()
{
	TArray<UFighter*> queue = combat->GetQueue();
	TArray<UBaseFighterController*> controllers;

	for (int i = 0; i < queue.Num(); i++)
	{
		controllers.Add(queue[i]->GetController());
	}

	return controllers;
}

void UCombatHandler::StartTurn()
{
	combat->MainLoop();
}