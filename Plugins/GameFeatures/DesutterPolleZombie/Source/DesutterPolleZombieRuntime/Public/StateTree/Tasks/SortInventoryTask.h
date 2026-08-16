// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateTree/Tasks/BaseTask.h"
#include "SortInventoryTask.generated.h"


class UInventoryComponent;
/**
 * 
 */
UCLASS()
class DESUTTERPOLLEZOMBIERUNTIME_API USortInventoryTask final : public UBaseTask
{
	GENERATED_BODY()
	
public:
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context,
		const FStateTreeTransitionResult& Transition) override;
	
	virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) override;
	
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) override;
	
	
	UPROPERTY(EditAnywhere, Category="Input")
	UInventoryComponent* Inventory{};
	
private:
	bool IsInventoryEmpty() const;

};
