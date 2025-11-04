// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCFighter.h"

void UNPCFighter::LaunchAction_Implementation(UCombat* combat)
{
	selectedAction = actions[0];
	Super::LaunchAction_Implementation(combat);
}
