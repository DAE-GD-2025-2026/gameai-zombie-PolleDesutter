// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Blueprint/StateTreeTaskBlueprintBase.h"
#include "BaseTask.generated.h"

/**
 * 
 */
UCLASS(ABSTRACT)
class DESUTTERPOLLEZOMBIERUNTIME_API UBaseTask : public UStateTreeTaskBlueprintBase
{
	GENERATED_BODY()
public:
	
UBaseTask(const FObjectInitializer& ObjectInitializer);
protected:
	UPROPERTY(EditAnywhere, Category="Context")
	AAIController* SurvivorController{};
	
	UPROPERTY(EditAnywhere, Category="Context")
	APawn* SurvivorCharacter{};
	
	
};
