// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.


#include "Action.h"
#include "Fighter.h"
#include "../Combat.h"

UAction::UAction()
{
}

void UAction::Trigger_Implementation(UFighter* from, UFighter* target, UCombat* combat)
{
	target->TakeDamage(1);
	return;
}

FText UAction::GetActionName()
{
	return name;
}

FText UAction::GetActionDescription()
{
	return description;
}