// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/StateTreeConditionBlueprintBase.h"
#include "IsEnemyClose.generated.h"

/**
 * 
 */
UCLASS(DisplayName="Is Enemy Close")
class DESUTTERPOLLEZOMBIERUNTIME_API UIsEnemyClose : public UStateTreeConditionBlueprintBase
{
	GENERATED_BODY()
	
	protected:
	virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;

	UPROPERTY(EditAnywhere, Category="Condition")
	bool bInvert = false;
};
