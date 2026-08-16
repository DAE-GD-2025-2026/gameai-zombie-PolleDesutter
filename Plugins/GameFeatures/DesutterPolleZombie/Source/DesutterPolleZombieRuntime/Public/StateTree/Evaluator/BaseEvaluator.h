// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Blueprint/StateTreeEvaluatorBlueprintBase.h"
#include "BaseEvaluator.generated.h"


USTRUCT()
struct FBaseEvaluatorInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Context")
	TObjectPtr<AAIController> SurvivorController{};

	UPROPERTY(EditAnywhere, Category = "Context")
	TObjectPtr<APawn> SurvivorCharacter{};
};


USTRUCT()
struct DESUTTERPOLLEZOMBIERUNTIME_API FBaseEvaluator : public FStateTreeEvaluatorCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FBaseEvaluatorInstanceData;
	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
};

