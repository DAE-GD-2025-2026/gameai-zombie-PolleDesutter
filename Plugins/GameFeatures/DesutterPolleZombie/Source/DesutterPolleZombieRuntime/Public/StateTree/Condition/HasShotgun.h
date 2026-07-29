// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/StateTreeConditionBlueprintBase.h"
#include "HasShotgun.generated.h"

/**
 * 
 */
UCLASS(DisplayName="Has Shotgun")
class DESUTTERPOLLEZOMBIERUNTIME_API UHasShotgun : public UStateTreeConditionBlueprintBase
{
	GENERATED_BODY()
	
	virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;

	UPROPERTY(EditAnywhere, Category="Condition")
	bool bInvert = false;
};
