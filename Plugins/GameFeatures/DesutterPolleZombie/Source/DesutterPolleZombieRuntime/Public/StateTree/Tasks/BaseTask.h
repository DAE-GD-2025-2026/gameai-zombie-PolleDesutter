// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Blueprint/StateTreeTaskBlueprintBase.h"
#include "BaseTask.generated.h"


USTRUCT()
struct FBaseTaskInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Context")
	TObjectPtr<AAIController> SurvivorController{};

	UPROPERTY(EditAnywhere, Category = "Context")
	TObjectPtr<APawn> SurvivorCharacter{};
};

USTRUCT()
struct DESUTTERPOLLEZOMBIERUNTIME_API FBaseTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FBaseTaskInstanceData;
	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
};

