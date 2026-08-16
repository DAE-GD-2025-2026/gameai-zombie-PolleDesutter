#include "StateTree/Evaluator/PerceptionEvaluator.h"


#include "StateTreeExecutionContext.h"

#include "HelperFunctions.h"
#include "Perception/AIPerceptionComponent.h"


void FPerceptionEvaluator::TreeStart(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	
	AActor* SurvivorCharacter = InstanceData.SurvivorCharacter.Get();
	if (!IsValid(SurvivorCharacter))
	{
		return;
	}

	UAIPerceptionComponent* PerceptionComponent = SurvivorCharacter->FindComponentByClass<UAIPerceptionComponent>();
	if (!IsValid(PerceptionComponent))
	{
		return;
	}

	InstanceData.PerceptionComponent = PerceptionComponent;

	// PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, 
		// &FPerceptionEvaluator::HandleTargetPerceptionUpdated);
	
}

void FPerceptionEvaluator::TreeStop(FStateTreeExecutionContext& Context) const
{
	
}

void FPerceptionEvaluator::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	
	
}

void FPerceptionEvaluator::HandleTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
}

void FPerceptionEvaluator::HandleTargetPerceptionForgotten(AActor* Actor)
{
}
