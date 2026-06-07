// Fill out your copyright notice in the Description page of Project Settings.


#include "StudentPerceptorDesutterPolle.h"

#include "GameplayTagContainer.h"
#include "StateTreeExecutionTypes.h"
#include "SurvivorAIController.h"
#include "BehaviorTree/ValueOrBBKey.h"
#include "Items/BaseItem.h"
#include "Village/House/House.h"
#include "Zombies/BaseZombie.h"


UStudentPerceptorDesutterPolle::UStudentPerceptorDesutterPolle()
{
	PrimaryComponentTick.bCanEverTick = true;
	
	// TODO add stuff here
	
}

void UStudentPerceptorDesutterPolle::BeginPlay()
{
	Super::BeginPlay();
	
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

		UClass* StateTree = BlackboardComponent->GetValueAsClass("StateTree");
		if (!StateTree)
		{
			GEngine->AddOnScreenDebugMessage(5, 1.f, FColor::Green, 
	FString::Printf(TEXT("shit!")));
			
		}

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
		
		// FBlackboard::TryGetBlackboardKeyValue<AActor>();
		
	}
	const auto House = Cast<AHouse>(Actor);
	if (Zombie)
	{
		GEngine->AddOnScreenDebugMessage(5, 1.f, FColor::Green, 
	FString::Printf(TEXT("House!")));
		
		// FBlackboard::TryGetBlackboardKeyValue<AActor>();
		
	}
	
	if (!Item && !Zombie && !House)
	{
		UE_LOGFMT(LogTemp, Warning, "IDK Spotted");	
			GEngine->AddOnScreenDebugMessage(5, 1.f, FColor::Green, 
	FString::Printf(TEXT("IDK Spotted!")));
	}
	
		
}
