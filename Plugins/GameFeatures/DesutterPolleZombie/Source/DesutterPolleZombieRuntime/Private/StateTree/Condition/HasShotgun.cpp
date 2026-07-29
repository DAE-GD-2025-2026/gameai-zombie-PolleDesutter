// Fill out your copyright notice in the Description page of Project Settings.


#include "StateTree/Condition/HasShotgun.h"

#include "Common/InventoryComponent.h"


bool UHasShotgun::TestCondition(FStateTreeExecutionContext& Context) const
{
	const AActor* Owner = GetOwnerActor(Context);
	
	const UInventoryComponent* InventoryComponent = Owner->FindComponentByClass<UInventoryComponent>();
	TArray<ABaseItem*> Items = InventoryComponent->GetInventory();
	
	bool HasShotgun = false;
	for (const auto* Item : Items)
	{
		if (!Item)
		{
			continue;
		}
		
		if (Item->GetItemType() == EItemType::Shotgun)
		{
			HasShotgun = true;
			break;
		}
		
	}
	

	if (bInvert)
	{
		return !HasShotgun;
	}
	return HasShotgun;
}
