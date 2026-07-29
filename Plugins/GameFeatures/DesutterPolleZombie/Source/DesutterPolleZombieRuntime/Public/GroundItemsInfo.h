#pragma once

#include "CoreMinimal.h"
#include "GroundItemsInfo.generated.h" 


USTRUCT(BlueprintType)
struct FGroundItemsInfo
{
	GENERATED_BODY()
	
	UPROPERTY()
	TArray<FVector> FoodLocations{};
	UPROPERTY()
	TArray<FVector> MedKitLocations{};
	UPROPERTY()
	TArray<FVector> ShotgunLocations{};
	UPROPERTY()
	TArray<FVector> PistolLocations{};
	
};
