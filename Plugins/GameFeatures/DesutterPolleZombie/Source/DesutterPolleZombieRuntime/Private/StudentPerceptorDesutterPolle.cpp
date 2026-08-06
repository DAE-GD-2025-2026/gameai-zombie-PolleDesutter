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
}
