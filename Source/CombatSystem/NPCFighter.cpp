// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCFighter.h"

void UNPCFighter::LaunchAction_Implementation(UFighter* target)
{
	selectedAction = actions[(int)FMath::RandRange(0, actions.Num() - 1)];
	Super::LaunchAction_Implementation(target);
	UE_LOG(LogTemp, Warning, TEXT("UNPCFighter::LaunchAction_Implementation - done!"));
}
