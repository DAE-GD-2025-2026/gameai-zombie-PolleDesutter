// Fill out your copyright notice in the Description page of Project Settings.


#include "StateTree/Condition/HasShotgunAmmo.h"

#include "Common/InventoryComponent.h"


bool UHasShotgunAmmo::TestCondition(FStateTreeExecutionContext& Context) const
{
	const AActor* Owner = GetOwnerActor(Context);
	
	const UInventoryComponent* InventoryComponent = Owner->FindComponentByClass<UInventoryComponent>();
	TArray<ABaseItem*> Items = InventoryComponent->GetInventory();
	
	bool HasShotgunAmmo = false;
	for (const auto* Item : Items)
	{
		if (!Item)
		{
			continue;
		}
		
		if (Item->GetItemType() == EItemType::Shotgun && Item->GetValue() > 0)
		{
			HasShotgunAmmo = true;
			break;
		}
	}
	
	
	if (bInvert)
	{
		return !HasShotgunAmmo;
	}
	return HasShotgunAmmo;
}
