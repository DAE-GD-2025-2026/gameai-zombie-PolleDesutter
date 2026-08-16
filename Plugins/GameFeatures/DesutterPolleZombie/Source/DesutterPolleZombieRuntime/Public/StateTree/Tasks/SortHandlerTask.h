// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <set>

#include "CoreMinimal.h"
#include "StateTree/Tasks/BaseTask.h"
#include "SortHandlerTask.generated.h"


enum class EItemType : uint8;
class UInventoryComponent;

USTRUCT()
struct FInventoryHandlerTaskInstanceData : public FBaseTaskInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Input")
	UInventoryComponent* Inventory{};
	
	UPROPERTY(EditAnywhere, Category = "Input")
	 AActor* AcquiredItem{};
};


USTRUCT()
struct DESUTTERPOLLEZOMBIERUNTIME_API FSortHandlerTask final : public FBaseTask
{
	GENERATED_BODY()
	
	using FInstanceDataType = FInventoryHandlerTaskInstanceData;
	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
	
	
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context,
		const FStateTreeTransitionResult& Transition) const override;
	
	virtual void ExitState(FStateTreeExecutionContext& Context,
		const FStateTreeTransitionResult& Transition) const override;
	
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
	
	
private:
	static void CleanUpInventory(FInstanceDataType& InstanceData);
	static void HandleGrabItem(FInstanceDataType& InstanceData);	
	
	
	static bool IsInventoryEmpty(const UInventoryComponent& Inventory);
	static bool IsInventoryFull(const UInventoryComponent& Inventory);
	

	static std::set<int> GetItemSlotsByType(const UInventoryComponent& Inventory, EItemType ItemType);
	static std::optional<int> GetFreeItemSlot(const UInventoryComponent& Inventory);
	static std::set<int> GetFreeItemSlots(const UInventoryComponent& Inventory);

	static void RemoveGarbage(UInventoryComponent& Inventory);
	
};
