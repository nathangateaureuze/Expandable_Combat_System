// Fill out your copyright notice in the Description page of Project Settings.


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