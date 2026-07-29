// Fill out your copyright notice in the Description page of Project Settings.


#include "StudentPerceptorDesutterPolle.h"

#include "SurvivorAIController.h"
#include "BehaviorTree/ValueOrBBKey.h"
#include "Items/BaseItem.h"
#include "Village/House/House.h"
#include "Zombies/BaseZombie.h"

#include "Components/StateTreeComponent.h"
#include "StateTree/BlackboardKeys.h"

UStudentPerceptorDesutterPolle::UStudentPerceptorDesutterPolle()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStudentPerceptorDesutterPolle::BeginPlay()
{
	Super::BeginPlay();
	
	// Get StateTree
	APawn* Pawn = Cast<APawn>(GetOwner());
	if (AAIController* AIController = Cast<AAIController>(Pawn->GetOwner()))
	{
		UStateTreeComponent* StateTreeComponent = AIController->FindComponentByClass<UStateTreeComponent>();
		if (!StateTreeComponent)
		{
			UE_LOG(LogTemp, Warning, TEXT("StateTreeComponent not found!"));
			return;
		}
		
		StateTreeComp = StateTreeComponent;
	}
	
	// Setup Perception System
	if (auto PerceptionComp = GetOwner()->GetComponentByClass<UAIPerceptionComponent>())
	{
		PerceptionComp->OnTargetPerceptionUpdated.AddDynamic(this, &UStudentPerceptorDesutterPolle::OnPerceptionUpdated);
	}
	
	
	if (auto SurvivorController = Cast<ASurvivorAIController>(GetOwner()->GetInstigatorController()))
	{
		BlackboardComponent = SurvivorController->GetBlackboardComponent();
		if (!BlackboardComponent)
		{
			GEngine->AddOnScreenDebugMessage(5, 1.f, FColor::Green, 
	FString::Printf(TEXT("FUCKED!")));
			
		}
	
	}
	
}

void UStudentPerceptorDesutterPolle::OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	GEngine->AddOnScreenDebugMessage(5, 1.f, FColor::Green, 
	FString::Printf(TEXT("Saw Something!")));

	const auto Item = Cast<ABaseItem>(Actor);
	if (Item)
	{
		GEngine->AddOnScreenDebugMessage(5, 1.f, FColor::Green, 
	FString::Printf(TEXT("Item!")));

	}
	
	const auto Zombie = Cast<ABaseZombie>(Actor);
	if (Zombie)
	{
		GEngine->AddOnScreenDebugMessage(5, 1.f, FColor::Green, 
	FString::Printf(TEXT("Zombie!")));
		
		FStateTreeEvent Event{ OnSpottedZombieTag };	
		
		BlackboardComponent->SetValueAsBool(BlackboardKeys::HasSeenEnemyRecently, true);
		BlackboardComponent->SetValueAsFloat(BlackboardKeys::TimeSinceLastSeenEnemy, 0.0f);
		
		BlackboardComponent->SetValueAsVector(BlackboardKeys::ClosestEnemyPosition, Zombie->GetActorLocation());
		
		StateTreeComp->SendStateTreeEvent(Event);
	}
	const auto House = Cast<AHouse>(Actor);
	if (House)
	{
		GEngine->AddOnScreenDebugMessage(5, 1.f, FColor::Green, 
	FString::Printf(TEXT("House!")));
		
		FStateTreeEvent Event{ OnFoundHouseTag };	
		
		BlackboardComponent->SetValueAsBool(BlackboardKeys::HasSeenEnemyRecently, true);
		BlackboardComponent->SetValueAsFloat(BlackboardKeys::TimeSinceLastSeenEnemy, 0.0f);
		
		BlackboardComponent->SetValueAsVector(BlackboardKeys::ClosestEnemyPosition, Zombie->GetActorLocation());
		
		StateTreeComp->SendStateTreeEvent(Event);
		
	}
	
	if (!Item && !Zombie && !House)
	{
		UE_LOGFMT(LogTemp, Warning, "IDK Spotted");	
			GEngine->AddOnScreenDebugMessage(5, 1.f, FColor::Green, 
	FString::Printf(TEXT("IDK Spotted!")));
	}
	
		
}
