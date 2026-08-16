#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseEvaluator.h"
#include "Blueprint/StateTreeEvaluatorBlueprintBase.h"
#include "Perception/AIPerceptionTypes.h"
#include "PerceptionEvaluator.generated.h"

class UInventoryComponent;

USTRUCT()
struct FPerceptionEvaluatorInstanceData : public FBaseEvaluatorInstanceData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "Context")
	TObjectPtr<UAIPerceptionComponent> PerceptionComponent{};

	FDelegateHandle TargetUpdatedHandle;
	FDelegateHandle TargetForgottenHandle;
};


USTRUCT()
struct DESUTTERPOLLEZOMBIERUNTIME_API FPerceptionEvaluator final : public FBaseEvaluator
{
	GENERATED_BODY()
	
	using FInstanceDataType = FPerceptionEvaluatorInstanceData;
	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
	
	virtual void TreeStart(FStateTreeExecutionContext& Context) const override;
	virtual void TreeStop(FStateTreeExecutionContext& Context) const override;
	virtual void Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
	
private:
	static void HandleTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
	static void HandleTargetPerceptionForgotten(AActor* Actor);
	
};
