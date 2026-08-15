// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Blueprint/StateTreeConsiderationBlueprintBase.h"
#include "BaseConsideration.generated.h"

/**
 * 
 */
UCLASS()
class DESUTTERPOLLEZOMBIERUNTIME_API UBaseConsideration : public UStateTreeConsiderationBlueprintBase
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, Category="Context")
	AAIController* SurvivorController{};
	
	UPROPERTY(EditAnywhere, Category="Context")
	APawn* SurvivorCharacter{};
	
	
};
