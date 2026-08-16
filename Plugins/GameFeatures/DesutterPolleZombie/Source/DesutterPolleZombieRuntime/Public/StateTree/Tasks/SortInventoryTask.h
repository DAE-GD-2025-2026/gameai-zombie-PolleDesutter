// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateTree/Tasks/BaseTask.h"
#include "SortInventoryTask.generated.h"


class UInventoryComponent;

USTRUCT()
struct FSortInventoryTaskInstanceData : public FBaseTaskInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Input")
	UInventoryComponent* Inventory{};
};


USTRUCT()
struct DESUTTERPOLLEZOMBIERUNTIME_API FSortInventoryTask final : public FBaseTask
{
	GENERATED_BODY()
	
	using FInstanceDataType = FSortInventoryTaskInstanceData;
	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
	
	
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context,
		const FStateTreeTransitionResult& Transition) const override;
	
	virtual void ExitState(FStateTreeExecutionContext& Context,
		const FStateTreeTransitionResult& Transition) const override;
	
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
	
	
private:
	static bool IsInventoryEmpty(const UInventoryComponent& Inventory);

};
