#include "HelperFunctions.h"


void HelperFunctions::LogCustom(const FString& StringText, const FColor& Color)
{
	UE_LOGFMT(LogTemp, Warning, "{Text}", StringText);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, Color, StringText);
}

void HelperFunctions::LogSuccess(const FString& StringText)
{	
	UE_LOGFMT(LogTemp, Warning, "{Text}", StringText);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, StringText);
}

void HelperFunctions::LogWarning(const FString& StringText)
{
	UE_LOGFMT(LogTemp, Warning, "{Text}", StringText);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Orange, StringText);
}

void HelperFunctions::LogError(const FString& StringText)
{
	UE_LOGFMT(LogTemp, Error, "{Text}", StringText);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, StringText);
}

