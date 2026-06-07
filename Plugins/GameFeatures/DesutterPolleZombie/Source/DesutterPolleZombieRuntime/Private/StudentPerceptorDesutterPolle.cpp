// Fill out your copyright notice in the Description page of Project Settings.


#include "StudentPerceptorDesutterPolle.h"


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
}

void UStudentPerceptorDesutterPolle::OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	GEngine->AddOnScreenDebugMessage(5, 1.f, FColor::Green, 
	FString::Printf(TEXT("Saw Something!")));
	
		
}
