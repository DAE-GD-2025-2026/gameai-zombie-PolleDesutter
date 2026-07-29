// Fill out your copyright notice in the Description page of Project Settings.


#include "StateTree/Condition/IsEnemyClose.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "StateTree/BlackboardKeys.h"

bool UIsEnemyClose::TestCondition(FStateTreeExecutionContext& Context) const
{
	AActor* Owner = GetOwnerActor(Context);
	APawn* Pawn = Cast<APawn>(Owner);
	AAIController* AIController = Cast<AAIController>(Pawn->GetController());	
	UBlackboardComponent* BlackBoardComponent = AIController->GetBlackboardComponent();
	
	const FVector EnemyPosition = BlackBoardComponent->GetValueAsVector(BlackboardKeys::ClosestEnemyPosition);
	
	const float DistanceToEnemy = FVector::Distance(EnemyPosition, Pawn->GetActorLocation());
	
	const bool IsEnemyClose = DistanceToEnemy < 100.f;

	if (bInvert)
	{
		return !IsEnemyClose;
	}
	return IsEnemyClose;
}
