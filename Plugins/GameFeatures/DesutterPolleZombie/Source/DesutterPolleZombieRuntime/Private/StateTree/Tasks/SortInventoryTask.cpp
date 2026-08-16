// Fill out your copyright notice in the Description page of Project Settings.


#include "StateTree/Tasks/SortInventoryTask.h"

#include "HelperFunctions.h"
#include "Common/InventoryComponent.h"



EStateTreeRunStatus USortInventoryTask::EnterState(FStateTreeExecutionContext& Context,
                                                   const FStateTreeTransitionResult& Transition)
{
	if (!bShouldCallTick)
	{
		HelperFunctions::LogError("Sort Inventory: Failed To Enable Tick");
	}
	
	HelperFunctions::LogSuccess("Sort Inventory: Enter State");
	
	if (!Inventory)
	{
		HelperFunctions::LogError("Sort Inventory: Inventory Is Null");
		return EStateTreeRunStatus::Running;
	}
	
	if (IsInventoryEmpty())
	{
		HelperFunctions::LogWarning("Sort Inventory: Inventory Is Empty");
		return EStateTreeRunStatus::Running;
	}


	HelperFunctions::LogSuccess("Sort Inventory: Grab Item");
	Inventory->GrabItem(0, nullptr);	
	
	
	return EStateTreeRunStatus::Running;
}

void USortInventoryTask::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)
{
	HelperFunctions::LogSuccess("Inventory: Exit State");
	Super::ExitState(Context, Transition);
}

bool USortInventoryTask::IsInventoryEmpty() const
{
	for (const ABaseItem* Item : Inventory->GetInventory())
	{
		if (Item)
		{
			return false;
		}
	}
	
	return true;	
}

EStateTreeRunStatus USortInventoryTask::Tick(FStateTreeExecutionContext& Context, const float DeltaTime)
{
	HelperFunctions::LogError("Sort Inventory: Tick");
	return EStateTreeRunStatus::Running;
}
