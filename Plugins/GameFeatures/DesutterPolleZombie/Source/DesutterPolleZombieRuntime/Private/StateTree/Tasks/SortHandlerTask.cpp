// Fill out your copyright notice in the Description page of Project Settings.


#include "StateTree/Tasks/SortHandlerTask.h"

#include "StateTreeExecutionContext.h"

#include "HelperFunctions.h"
#include "Common/InventoryComponent.h"
#include "Items/BaseItem.h"
// #include "Common/InventoryComponent.h"



EStateTreeRunStatus FSortHandlerTask::EnterState(FStateTreeExecutionContext& Context,
                                                   const FStateTreeTransitionResult& Transition) const
{
	if (!bShouldCallTick)
	{
		HelperFunctions::LogError("Inventory: Failed To Enable Tick");
		return EStateTreeRunStatus::Failed;	
	}
	
	HelperFunctions::LogSuccess("Inventory: Enter State");
	
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	if (!InstanceData.Inventory)
	{
		HelperFunctions::LogError("Inventory: Inventory Is Null");
		return EStateTreeRunStatus::Failed;	
	}
	
	if (IsInventoryEmpty(*InstanceData.Inventory))
	{
		HelperFunctions::LogWarning("Inventory: Inventory Is Empty");
		return EStateTreeRunStatus::Running;
	}


	return EStateTreeRunStatus::Running;
}

void FSortHandlerTask::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	HelperFunctions::LogSuccess("Inventory: Exit State");
	Super::ExitState(Context, Transition);
}

EStateTreeRunStatus FSortHandlerTask::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	CleanUpInventory(InstanceData);
	HandleGrabItem(InstanceData);
	
	return EStateTreeRunStatus::Running;
}

void FSortHandlerTask::CleanUpInventory(FInstanceDataType& InstanceData)
{
	// CleanUp Inventory
	if (IsInventoryEmpty(*InstanceData.Inventory))
	{
		HelperFunctions::LogVerbose("Inventory: Empty");
		return;
	}
	
	RemoveGarbage(*InstanceData.Inventory);
}

void FSortHandlerTask::HandleGrabItem(FInstanceDataType& InstanceData)
{
	// Grab Item	
	if (!InstanceData.AcquiredItem)
	{
		// HelperFunctions::LogWarning("Inventory: Acquired Item is Null");
		return;
	}
	if (!Cast<ABaseItem>(InstanceData.AcquiredItem))
	{
		HelperFunctions::LogError("Inventory: Acquired Item is Not BaseItem");
		return;
	}
	
	ABaseItem* AcquiredItem = Cast<ABaseItem>(InstanceData.AcquiredItem);
	if (!AcquiredItem)
	{
		HelperFunctions::LogError("Bad");
	}
	const float DistanceToItem = FVector::Distance(AcquiredItem->GetActorLocation(), 
		InstanceData.SurvivorCharacter->GetActorLocation());
	
	if (DistanceToItem > InstanceData.Inventory->GetPickupRange())
	{
	
	// HelperFunctions::LogSuccess("Too far");
		return;
	}	
	
	HelperFunctions::LogSuccess("Close enough to item");
	const std::optional<int> FreeItemSlot = GetFreeItemSlot(*InstanceData.Inventory);
	if (FreeItemSlot.has_value())
	{
		bool PickedUp = InstanceData.Inventory->GrabItem(FreeItemSlot.value(), AcquiredItem);
		if (PickedUp)
		{
			InstanceData.AcquiredItem = nullptr;
			HelperFunctions::LogSuccess("Picked Up Item\n\n\n");
		}
		
	}
}


bool FSortHandlerTask::IsInventoryEmpty(const UInventoryComponent& Inventory)
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

bool FSortHandlerTask::IsInventoryFull(const UInventoryComponent& Inventory)
{
	for (const ABaseItem* Item :  Inventory.GetInventory())
	{
		if (!Item)
		{
			return false;
		}
	}
	
	return true;	
}

std::set<int> FSortHandlerTask::GetItemSlotsByType(const UInventoryComponent& Inventory, EItemType ItemType)
{
	std::set<int> ItemSlotsSet{};
	
	TArray<ABaseItem*> InventoryArray = Inventory.GetInventory();
	for (int Index{}; Index < InventoryArray.Num(); ++Index)
	{
		const ABaseItem* Item = InventoryArray[Index];
		if (!Item)
		{
			continue;
		}
		
		if (ItemType == Item->GetItemType())
		{
			ItemSlotsSet.insert(Index);
		}
		
	}
	
	return ItemSlotsSet;
}

std::optional<int> FSortHandlerTask::GetFreeItemSlot(const UInventoryComponent& Inventory)
{
	const std::set<int> FreeItemSlotsSet = GetFreeItemSlots(Inventory);
	if (FreeItemSlotsSet.empty())
	{
		return std::nullopt;
	}
	
	return *FreeItemSlotsSet.begin();
}

std::set<int> FSortHandlerTask::GetFreeItemSlots(const UInventoryComponent& Inventory)
{
	std::set<int> ItemSlotsSet{};
	
	TArray<ABaseItem*> InventoryArray = Inventory.GetInventory();
	for (int Index{}; Index < InventoryArray.Num(); ++Index)
	{
		if (!InventoryArray[Index])
		{
			ItemSlotsSet.insert(Index);
		}
	}
	
	return ItemSlotsSet;
}

void FSortHandlerTask::RemoveGarbage(UInventoryComponent& Inventory)
{
	const std::set<int> GarbageItemSlotsSet = GetItemSlotsByType(Inventory, EItemType::Garbage);
	if (!GarbageItemSlotsSet.empty())
	{
		HelperFunctions::LogSuccess("Sort Inventory: No Garbage found");
	}
	
	for (const int GarbageItemSlot: GarbageItemSlotsSet)
	{
		FString Test = "wow" + GarbageItemSlot;
		HelperFunctions::LogSuccess("Sort Inventory: Remove Garbage");
		Inventory.RemoveItem(GarbageItemSlot);
	}
	
}


