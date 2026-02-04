// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.


#include "Fighter.h"
#include "../Combat.h"
#include "BaseFighterController.h"
#include "Action.h"

UFighter::UFighter()
{
	currentHealth = stats.maxHealth;
}

void UFighter::Initialize(UCombat* owner)
{
	combat = owner; 
	controller = NewObject<UBaseFighterController>(this, controllerClass);
	controller->Initialize(this);

	iconColor = initIconColor;
	actionClass = initActionClass;

	for (int i = 0; i < actionClass.Num(); i++)
	{
		if (!actionClass[i])
		{
			UE_LOG(LogTemp, Warning, TEXT("UFighter::Initialize - actionClass is invalid"));
			actionClass[i] = UAction::StaticClass();
		}
		actions.Add(actions.Num(), NewObject<UAction>(this, actionClass[i]));
	}
}
UBaseFighterController* UFighter::GetController()
{
	return controller;
}

int UFighter::GetTeamIndex()
{
	return teamIndex;
}

bool UFighter::GetHasTurn()
{
	return hasTurn;
}

void UFighter::SetHasTurn(bool value)
{
	hasTurn = value;

	if (value)
	{
		controller->OnGetTurn();
	}
}

UCombat* UFighter::GetCombat()
{
	return combat;
}

int UFighter::GetCurrentHealth()
{
	return currentHealth;
}

void UFighter::SetCurrentHealth(int value)
{
	currentHealth = value;
	controller->onHealthChanged.Broadcast();

	if (currentHealth == 0)
	{
		Die();
	}

	return;
}

FFighterStats UFighter::GetStats()
{
	return stats;
}

FLinearColor UFighter::GetIconColor()
{
	return iconColor;
}

int UFighter::TakeDamage(int value)
{
	value = value < 0 ? 0 : value;
	int result = FMath::Max(currentHealth - value, 0);
	SetCurrentHealth(result);
	return 0;
}

void UFighter::TriggerAction(int actionId, UBaseFighterController* target)
{
	UAction* selectedAction = actions[actionId];

	if (selectedAction)
	{
		selectedAction->Trigger(this, combat->GetControllerFighter(target), combat);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("UFighter::TriggerAction - invalid refs!"));
	}

	EndTurn();
}

void UFighter::EndTurn()
{

	onTurnEnded.Broadcast();
}

void UFighter::Die()
{
	combat->RemoveFighter(this);
}
