// Fill out your copyright notice in the Description page of Project Settings.


#include "StateTree/Tasks/BaseTask.h"


UBaseTask::UBaseTask(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bShouldCallTick = true;
}