// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterController.h"
#include "Fighter.h"
#include "FighterAction.h"


void UFighterController::Initialize(UFighter* owner)
{
	fighter = owner;
}

TMap<int, FText> UFighterController::GetActionNames()
{
	TMap<int, FText> names;
	TArray<int> keys = TArray<int>();
	fighter->actions.GenerateKeyArray(keys);

	for (int i = 0; i < keys.Num(); i++)
	{
		names.Add(keys[i], fighter->actions[keys[i]]->GetActionName());
	}

	return names;
}
