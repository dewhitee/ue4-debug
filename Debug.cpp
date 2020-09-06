// Fill out your copyright notice in the Description page of Project Settings.


#include "Debug/Debug.h"
#include "Engine/Engine.h"
#include "Benchmark/Timer.h"

DEFINE_LOG_CATEGORY(LogDebug);

namespace Debugging {

	Debug::Debug(const FString& str)
	{
		Log_Internal(str);
	}
	Debug::Debug(UObject* obj, const FString& str)
	{
		if (obj) Log_Internal(obj, str);
	}

	Debug::Debug(const FString& str, float duration)
	{
		Screen(str, duration);
	}

	Debug::Debug(UObject* obj, const FString& str, float duration)
	{
		Screen(obj, str, duration);
	}

	void Debug::Log_Internal(const FString& str)
	{
		UE_LOG(LogDebug, Display, TEXT("%s"), *str);
	}

	void Debug::Log_Internal(UObject* obj, const FString& str)
	{
		UE_LOG(LogDebug, Display, TEXT("%s: %s"), obj ? *obj->GetName() : *FString("None"), *str);
	}

	void Debug::LogWarning_Internal(const FString& str)
	{
		UE_LOG(LogDebug, Warning, TEXT("%s"), *str);
	}

	void Debug::LogWarning_Internal(UObject* obj, const FString& str)
	{
		UE_LOG(LogDebug, Warning, TEXT("%s: %s"), obj ? *obj->GetName() : *FString("None"), *str);
	}

	void Debug::LogError_Internal(const FString& str)
	{
		UE_LOG(LogDebug, Error, TEXT("%s"), *str);
	}

	void Debug::LogError_Internal(UObject* obj, const FString& str)
	{
		UE_LOG(LogDebug, Error, TEXT("%s: %s"), obj ? *obj->GetName() : *FString("None"), *str);
	}

	FString Debug::GetPrintOptions(const TArray<EPrintOption>& options)
	{
		FString str;
		for (auto i : options)
		{
			switch (i)
			{
			case EPrintOption::ShowLineNumber:
				str.Append(" line number: " + __LINE__);
				break;
			case EPrintOption::ShowFunctionName:
				break;
			case EPrintOption::ShowDate:
				str.Append(" date: " + FDateTime::Now().GetDay() + FDateTime::Now().GetMonth() + FDateTime::Now().GetYear());
				break;
			case EPrintOption::ShowTime:
				str.Append(" time: " + FDateTime::Now().GetTimeOfDay().ToString());
				break;
			}
		}
		return str;
	}

	FString Debug::GetPrintOptions(EPrintOption& options)
	{
		FString str;
		if (((int)EPrintOption::ShowLineNumber & (int)options) == (int)EPrintOption::ShowLineNumber)
		{
			str.Append(" line number: " + __LINE__);
		}
		if (((int)EPrintOption::ShowFunctionName & (int)options) == (int)EPrintOption::ShowFunctionName)
		{
			str.Append(FString(" function name: ") + __func__);
		}
		if (((int)EPrintOption::ShowDate & (int)options) == (int)EPrintOption::ShowDate)
		{
			str.Append(" date: " + FDateTime::Now().GetDay() + FDateTime::Now().GetMonth() + FDateTime::Now().GetYear());
		}
		if (((int)EPrintOption::ShowTime & (int)options) == (int)EPrintOption::ShowTime)
		{
			str.Append(" time: " + FDateTime::Now().GetTimeOfDay().ToString());
		}
		return str;
	}

	void Debug::Log(const FString& str)
	{
		UE_LOG(LogDebug, Display, TEXT("%s"), *str);
	}

	void Debug::Log(const FString& str, TArray<EPrintOption> options)
	{
		UE_LOG(LogDebug, Display, TEXT("%s"), *FString(str + GetPrintOptions(options)));
	}

	void Debug::Log(const FString& str, EPrintOption options)
	{
		UE_LOG(LogDebug, Display, TEXT("%s"), *FString(str + GetPrintOptions(options)));
	}

	void Debug::Log(const UObject* obj, const FString& str)
	{
		UE_LOG(LogDebug, Display, TEXT("%s: %s"), obj ? *obj->GetName() : *FString("None"), *str);
	}

	void Debug::Log(const UObject* const obj, const FString& str, TArray<EPrintOption> options)
	{
		UE_LOG(LogDebug, Display, TEXT("%s: %s"), obj ? *obj->GetName() : *FString("None"), *FString(str + GetPrintOptions(options)));
	}

	void Debug::Log(const UObject* const obj, const FString& str, EPrintOption options)
	{
		UE_LOG(LogDebug, Display, TEXT("%s: %s"), obj ? *obj->GetName() : *FString("None"), *FString(str + GetPrintOptions(options)));
	}

	void Debug::Log(const UActorComponent* const comp, const FString& str)
	{
		UE_LOG(LogDebug, Display, TEXT("%s [Owner: %s]: %s"), comp ? *comp->GetName() : *FString("None"), comp ? *comp->GetOwner()->GetName() : *FString("None"), *str);
	}

	void Debug::LogWarning(const FString& str)
	{
		UE_LOG(LogDebug, Warning, TEXT("%s"), *str);
	}

	void Debug::LogWarning(const FString& str, TArray<EPrintOption> options)
	{
		UE_LOG(LogDebug, Warning, TEXT("%s"), *FString(str + GetPrintOptions(options)));
	}

	void Debug::LogWarning(const FString& str, EPrintOption options)
	{
		UE_LOG(LogDebug, Warning, TEXT("%s"), *FString(str + GetPrintOptions(options)));
	}

	void Debug::LogWarning(const UObject* obj, const FString& str)
	{
		UE_LOG(LogDebug, Warning, TEXT("%s: %s"), obj ? *obj->GetName() : *FString("None"), *str);
	}

	void Debug::LogWarning(const UObject* const obj, const FString& str, TArray<EPrintOption> options)
	{
		UE_LOG(LogDebug, Warning, TEXT("%s: %s"), obj ? *obj->GetName() : *FString("None"), *FString(str + GetPrintOptions(options)));
	}

	void Debug::LogWarning(const UObject* const obj, const FString& str, EPrintOption options)
	{
		UE_LOG(LogDebug, Warning, TEXT("%s: %s"), obj ? *obj->GetName() : *FString("None"), *FString(str + GetPrintOptions(options)));
	}

	void Debug::LogWarning(const UActorComponent* const comp, const FString& str)
	{
		UE_LOG(LogDebug, Warning, TEXT("%s [Owner: %s]: %s"), comp ? *comp->GetName() : *FString("None"), comp ? *comp->GetOwner()->GetName() : *FString("None"), *str);
	}

	void Debug::LogError(const FString& str)
	{
		UE_LOG(LogDebug, Error, TEXT("%s"), *str);
	}

	void Debug::LogError(const FString& str, TArray<EPrintOption> options)
	{
		UE_LOG(LogDebug, Error, TEXT("%s"), *FString(str + GetPrintOptions(options)));
	}

	void Debug::LogError(const FString& str, EPrintOption options)
	{
		UE_LOG(LogDebug, Error, TEXT("%s"), *FString(str + GetPrintOptions(options)));
	}

	void Debug::LogError(const UObject* obj, const FString& str)
	{
		UE_LOG(LogDebug, Error, TEXT("%s: %s"), obj ? *obj->GetName() : *FString("None"), *str);
	}

	void Debug::LogError(const UObject* const obj, const FString& str, TArray<EPrintOption> options)
	{
		UE_LOG(LogDebug, Error, TEXT("%s: %s"), obj ? *obj->GetName() : *FString("None"), *FString(str + GetPrintOptions(options)));
	}

	void Debug::LogError(const UObject* const obj, const FString& str, EPrintOption options)
	{
		UE_LOG(LogDebug, Error, TEXT("%s: %s"), obj ? *obj->GetName() : *FString("None"), *FString(str + GetPrintOptions(options)));
	}

	void Debug::LogError(const UActorComponent* const comp, const FString& str)
	{
		UE_LOG(LogDebug, Error, TEXT("%s [Owner: %s]: %s"), comp ? *comp->GetName() : *FString("None"), comp ? *comp->GetOwner()->GetName() : *FString("None"), *str);
	}

	void Debug::LogBench(const FString& str)
	{
		UE_LOG(LogBenchmark, Display, TEXT("<NO_OBJECT_NAME>: %s"), *str);
	}

	void Debug::LogBench(const UObject* obj, const FString& str)
	{
		UE_LOG(LogBenchmark, Display, TEXT("%s: %s"), obj ? *obj->GetName() : *FString("None"), *str);
	}

	void Debug::LogBenchWarning(const FString& str)
	{
		UE_LOG(LogBenchmark, Warning, TEXT("%s"), *str);
	}

	void Debug::LogBenchWarning(const UObject* obj, const FString& str)
	{
		UE_LOG(LogBenchmark, Warning, TEXT("%s: %s"), obj ? *obj->GetName() : *FString("None"), *str);
	}

	void Debug::LogBenchError(const FString& str)
	{
		UE_LOG(LogBenchmark, Error, TEXT("%s"), *str);
	}

	void Debug::LogBenchError(const UObject* obj, const FString& str)
	{
		UE_LOG(LogBenchmark, Error, TEXT("%s: %s"), obj ? *obj->GetName() : *FString("None"), *str);
	}

	void Debug::Screen(const FString& str)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, str);
	}

	void Debug::Screen(const FString& str, float duration)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, duration, FColor::White, str);
	}

	void Debug::Screen(const UObject* const  obj, const FString& str)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, obj ? obj->GetName() : "None" + str);
	}

	void Debug::Screen(const UObject* const  obj, const FString& str, float duration)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, duration, FColor::White, obj ? obj->GetName() : "None" + str);
	}

	void Debug::Screen(const FString& str, FColor color)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, color, str);
	}

	void Debug::Screen(const FString& str, float duration, FColor color)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, duration, color, str);
	}

	void Debug::Screen(const UObject* const obj, const FString& str, FColor color)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, color, obj ? obj->GetName() : "None" + str);
	}

	void Debug::Screen(const UObject* const obj, const FString& str, float duration, FColor color)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, duration, color, obj ? obj->GetName() : "None" + str);
	}

	void Debug::ScreenRed(const FString& str)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, str);
	}

	void Debug::ScreenBlue(const FString& str)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, str);
	}

	void Debug::ScreenGreen(const FString& str)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, str);
	}

	void Debug::ScreenRed(const UObject* const obj, const FString& str)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, obj ? obj->GetName() : "None" + str);
	}

	void Debug::ScreenBlue(const UObject* const obj, const FString& str)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, obj ? obj->GetName() : "None" + str);
	}

	void Debug::ScreenGreen(const UObject* const obj, const FString& str)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, obj ? obj->GetName() : "None" + str);
	}

	void Debug::ScreenRed(const UObject* const obj, const FString& str, float duration)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, duration, FColor::Red, obj ? obj->GetName() : "None" + str);
	}

	void Debug::ScreenBlue(const UObject* const  obj, const FString& str, float duration)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, duration, FColor::Blue, obj ? obj->GetName() : "None" + str);
	}

	void Debug::ScreenGreen(const UObject* const  obj, const FString& str, float duration)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, duration, FColor::Green, obj ? obj->GetName() : "None" + str);
	}

}
