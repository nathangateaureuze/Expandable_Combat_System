// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.


#include "FighterAction.h"
#include "Fighter.h"

UFighterAction::UFighterAction()
{
}

void UFighterAction::Trigger_Implementation(UFighter* from, UFighter* target)
{
	target->TakeDamage(1);
	return;
}

FText UFighterAction::GetActionName()
{
	return name;
}

FText UFighterAction::GetActionDescription()
{
	return description;
}