// Fill out your copyright notice in the Description page of Project Settings.


#include "StateTree/Condition/HasPistolAmmo.h"

#include "Common/InventoryComponent.h"


bool UHasPistolAmmo::TestCondition(FStateTreeExecutionContext& Context) const
{
	const AActor* Owner = GetOwnerActor(Context);
	
	const UInventoryComponent* InventoryComponent = Owner->FindComponentByClass<UInventoryComponent>();
	TArray<ABaseItem*> Items = InventoryComponent->GetInventory();
	
	bool HasPistolAmmo = false;
	for (const auto* Item : Items)
	{
		if (!Item)
		{
			continue;
		}
		
		if (Item->GetItemType() == EItemType::Pistol && Item->GetValue() > 0)
		{
			HasPistolAmmo = true;
			break;
		}
	}
	
	
	if (bInvert)
	{
		return !HasPistolAmmo;
	}
	return HasPistolAmmo;
}
