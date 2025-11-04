// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFighter.h"

void UPlayerFighter::LaunchAction_Implementation(UCombat* combat)
{
	waitingForInput.Broadcast();
}
