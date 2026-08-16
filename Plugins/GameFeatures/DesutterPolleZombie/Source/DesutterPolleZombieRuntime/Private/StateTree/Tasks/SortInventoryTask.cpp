// Fill out your copyright notice in the Description page of Project Settings.


#include "StateTree/Tasks/SortInventoryTask.h"

#include "Common/InventoryComponent.h"


EStateTreeRunStatus USortInventoryTask::EnterState(FStateTreeExecutionContext& Context,
                                                   const FStateTreeTransitionResult& Transition)
{
	
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Sort Inventory"));
	if (!Inventory)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Sort Inventory: Inventory Not Valid"));
		UE_LOG(LogTemp, Warning, TEXT("Inventory is null"));
		return EStateTreeRunStatus::Running;
	}
	
	if (IsInventoryEmpty())
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Orange, TEXT("Sort Inventory: Inventory Is Empty"));
		return EStateTreeRunStatus::Running;
	}
	
	
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Sort Inventory: Grab Item"));
	Inventory->GrabItem(0, nullptr);	
	
	
	return Super::EnterState(Context, Transition);
}

void USortInventoryTask::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)
{
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
