// Fill out your copyright notice in the Description page of Project Settings.


#include "StateTree/Condition/HasFoundUsefulItem.h"

#include "AIController.h"
#include "StateTree/Condition/HasPistol.h"
#include "StateTree/Condition/IsEnemyClose.h"


bool UHasFoundUsefulItem::TestCondition(FStateTreeExecutionContext& Context) const
{
	AActor* Owner = GetOwnerActor(Context);
	APawn* Pawn = Cast<APawn>(Owner);
	AAIController* AIController = Cast<AAIController>(Pawn->GetController());	
	UBlackboardComponent* BlackBoardComponent = AIController->GetBlackboardComponent();
	
	
	bool HasFoundUsefulItem = false;
	if (bInvert)
	{
		return !HasFoundUsefulItem;
	}
	return HasFoundUsefulItem;
}

