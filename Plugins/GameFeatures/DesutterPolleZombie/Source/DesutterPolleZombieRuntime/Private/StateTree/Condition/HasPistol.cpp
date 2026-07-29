// Fill out your copyright notice in the Description page of Project Settings.


#include "StateTree/Condition/HasPistol.h"

#include "Common/InventoryComponent.h"


bool UHasPistol::TestCondition(FStateTreeExecutionContext& Context) const
{
	const AActor* Owner = GetOwnerActor(Context);
	
	const UInventoryComponent* InventoryComponent = Owner->FindComponentByClass<UInventoryComponent>();
	TArray<ABaseItem*> Items = InventoryComponent->GetInventory();
	
	bool HasPistol = false;
	for (const auto* Item : Items)
	{
		if (!Item)
		{
			continue;
		}
		
		if (Item->GetItemType() == EItemType::Pistol)
		{
			HasPistol = true;
			break;
		}
		
	}
	

	if (bInvert)
	{
		return !HasPistol;
	}
	return HasPistol;
}
