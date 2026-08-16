// Fill out your copyright notice in the Description page of Project Settings.


#include "StateTree/Tasks/SortInventoryTask.h"
#include "StateTreeExecutionContext.h"

#include "HelperFunctions.h"
#include "Common/InventoryComponent.h"



EStateTreeRunStatus FSortInventoryTask::EnterState(FStateTreeExecutionContext& Context,
                                                   const FStateTreeTransitionResult& Transition) const
{
	if (!bShouldCallTick)
	{
		HelperFunctions::LogError("Sort Inventory: Failed To Enable Tick");
	}
	
	HelperFunctions::LogSuccess("Sort Inventory: Enter State");
	
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	if (!InstanceData.Inventory)
	{
		HelperFunctions::LogError("Sort Inventory: Inventory Is Null");
		return EStateTreeRunStatus::Failed;	
	}
	
	if (IsInventoryEmpty(*InstanceData.Inventory))
	{
		HelperFunctions::LogWarning("Sort Inventory: Inventory Is Empty");
		return EStateTreeRunStatus::Running;
	}


	HelperFunctions::LogSuccess("Sort Inventory: Grab Item");
	InstanceData.Inventory->GrabItem(0, nullptr);	
	
	return EStateTreeRunStatus::Running;
}

void FSortInventoryTask::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	HelperFunctions::LogSuccess("Inventory: Exit State");
	Super::ExitState(Context, Transition);
}

EStateTreeRunStatus FSortInventoryTask::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	// HelperFunctions::LogError("Sort Inventory: Tick");
	return EStateTreeRunStatus::Running;
}

bool FSortInventoryTask::IsInventoryEmpty(const UInventoryComponent& Inventory)
{
	for (const ABaseItem* Item :  Inventory.GetInventory())
	{
		if (Item)
		{
			return false;
		}
	}
	
	return true;	
}

