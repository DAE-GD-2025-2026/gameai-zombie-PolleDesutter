#pragma once


namespace HelperFunctions
{
	void LogCustom(const FString& StringText, const FColor& Color);
	
	void LogSuccess(const FString& StringText);
	void LogWarning(const FString& StringText);
	void LogError(const FString& StringText);
	void LogVerbose(const FString& StringText);
};

