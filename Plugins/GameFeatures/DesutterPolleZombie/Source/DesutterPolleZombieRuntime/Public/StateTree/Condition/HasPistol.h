// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/StateTreeConditionBlueprintBase.h"
#include "HasPistol.generated.h"

/**
 * 
 */
UCLASS(DisplayName="Has Pistol")
class DESUTTERPOLLEZOMBIERUNTIME_API UHasPistol : public UStateTreeConditionBlueprintBase
{
	GENERATED_BODY()
	
	virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;

	UPROPERTY(EditAnywhere, Category="Condition")
	bool bInvert = false;
};
