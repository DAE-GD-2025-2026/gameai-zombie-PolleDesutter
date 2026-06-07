// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeEvents.h"
#include "Components/ActorComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Damage.h"
#include "GameplayTagContainer.h"
#include "Perception/AISense_Damage.h"
#include "StudentPerceptorDesutterPolle.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DESUTTERPOLLEZOMBIERUNTIME_API UStudentPerceptorDesutterPolle : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UStudentPerceptorDesutterPolle();
	
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
	
	
private:
	
	const FGameplayTag OnFoundItemTag{ FGameplayTag::RequestGameplayTag(FName("Survivor.OnFoundItem"))};
	const FGameplayTag OnFoundHouseTag{ FGameplayTag::RequestGameplayTag(FName("Survivor.OnFoundHouse"))};
	const FGameplayTag OnSpottedZombieTag{ FGameplayTag::RequestGameplayTag(FName("Survivor.OnSpottedZombie"))};
	const FGameplayTag OnHitTag{ FGameplayTag::RequestGameplayTag(FName("Survivor.OnHit"))};
	
	const FStateTreeEvent OnSpottedZombie{ OnSpottedZombieTag };
	const FStateTreeEvent OnFoundHouse{ OnFoundHouseTag };
	const FStateTreeEvent OnFoundItem{ OnFoundItemTag };
	const FStateTreeEvent OnHit{ OnHitTag };
	
	UBlackboardComponent* BlackboardComponent{};
	
};
