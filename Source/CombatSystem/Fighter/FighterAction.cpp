// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterAction.h"
#include "Fighter.h"

UFighterAction::UFighterAction()
{
}

void UFighterAction::Trigger_Implementation(UFighter* from, UFighter* target)
{
	return;
}

FText UFighterAction::GetName()
{
	return name;
}

FText UFighterAction::GetDescription()
{
	return description;
}