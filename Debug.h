// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class UActorComponent;
DECLARE_LOG_CATEGORY_EXTERN(LogDebug, Log, All);

namespace Debugging {

	enum class EPrintOption : uint8
	{
		None = 0,
		ShowLineNumber = 1 << 0, // 00001 == 1
		ShowFunctionName = 1 << 1, // 00010 == 2
		ShowDate = 1 << 2, // 00100 == 4
		ShowTime = 1 << 3, // 01000 == 8
	};

	inline EPrintOption operator| (EPrintOption lhs, EPrintOption rhs)
	{
		using T = std::underlying_type_t<EPrintOption>;
		return static_cast<EPrintOption>(static_cast<T>(lhs) | static_cast<T>(rhs));
	}

	inline EPrintOption operator|= (EPrintOption& lhs, EPrintOption rhs)
	{
		lhs = lhs | rhs;
		return lhs;
	}

	/**
	 *
	 */
	class THEXGAME_API Debug final
	{
	public:
#pragma region Constructors
		Debug() = delete;
		Debug(const Debug&) = delete;

		// Print message to log.
		Debug(const FString& str);
		// Print message to log with the name of the object attached.
		Debug(UObject* obj, const FString& str);
		// Print message to the viewport with the specified duration.
		Debug(const FString& str, float duration);
		// Print message to the viewport with the specified duration and the name of the object attached.
		Debug(UObject* obj, const FString& str, float duration);
#pragma endregion

	private:
#pragma region Internal Log
		// Print message to the log.
		void Log_Internal(const FString& str);
		// Print message to the log with the name of the object attached.
		void Log_Internal(UObject* obj, const FString& str);
		// Print message to the log WARNING category.
		void LogWarning_Internal(const FString& str);
		// Print message to the log WARNING category with the name of the object attached.
		void LogWarning_Internal(UObject* obj, const FString& str);
		// Print message to the log ERROR category.
		void LogError_Internal(const FString& str);
		// Print message to the log ERROR category with the name of the object attached.
		void LogError_Internal(UObject* obj, const FString& str);
#pragma endregion Printing messages to the Log

		static FString GetPrintOptions(const TArray<EPrintOption>& options);
		static FString GetPrintOptions(EPrintOption& options);

	public:
#pragma region Static Log
		// Print message to the log (static method).
		static void Log(const FString& str);
		// Print message to the log with the custom print options.
		static void Log(const FString& str, TArray<EPrintOption> options);
		// Print message to the log with the custom print options.
		static void Log(const FString& str, EPrintOption options);
		// Print message to the log with the name of the object attached (static method).
		static void Log(const UObject* const obj, const FString& str);
		// Print message to the log with the name of the object attached and custom print options.
		static void Log(const UObject* const obj, const FString& str, TArray<EPrintOption> options);
		// Print message to the log with the name of the object attached and custom print options.
		static void Log(const UObject* const obj, const FString& str, EPrintOption options);
		// Print message to the log with the name of the component and it's owner attached.
		static void Log(const UActorComponent* const comp, const FString& str);
		// Print message to the log WARNING category (static method).
		static void LogWarning(const FString& str);
		// Print message to the log WARNING category with the custom print options.
		static void LogWarning(const FString& str, TArray<EPrintOption> options);
		// Print message to the log WARNING category with the custom print options.
		static void LogWarning(const FString& str, EPrintOption options);
		// Print message to the log WARNING category with the name of the object attached (static method).
		static void LogWarning(const UObject* obj, const FString& str);
		// Print message to the log WARNING category with the name of the object attached and custom print options.
		static void LogWarning(const UObject* const obj, const FString& str, TArray<EPrintOption> options);
		// Print message to the log WARNING category with the name of the object attached and custom print options.
		static void LogWarning(const UObject* const obj, const FString& str, EPrintOption options);
		// Print message to the log WARNING category with the name of the component and it's owner attached.
		static void LogWarning(const UActorComponent* const comp, const FString& str);
		// Print message to the log ERROR category (static method).
		static void LogError(const FString& str);
		// Print message to the log ERROR category with the custom print options.
		static void LogError(const FString& str, TArray<EPrintOption> options);
		// Print message to the log ERROR category with the custom print options.
		static void LogError(const FString& str, EPrintOption options);
		// Print message to the log ERROR category with the name of the object attached (static method).
		static void LogError(const UObject* obj, const FString& str);
		// Print message to the log ERROR category with the name of the object attached and custom print options.
		static void LogError(const UObject* const obj, const FString& str, TArray<EPrintOption> options);
		// Print message to the log ERROR category with the name of the object attached and custom print options.
		static void LogError(const UObject* const obj, const FString& str, EPrintOption options);
		// Print message to the log ERROR category with the name of the component and it's owner attached.
		static void LogError(const UActorComponent* const comp, const FString& str);
#pragma endregion Printing messages to the Log by static methods

#pragma region Screen
		// Print message to the viewport with the duration of 5 seconds till the message disappear.
		static void Screen(const FString& str);
		// Print message to the viweport with the specified duration.
		static void Screen(const FString& str, float duration);
		// Print message to the viewport with the name of the object attached and the duration of 5 seconds.
		static void Screen(const UObject* const obj, const FString& str);
		// Print message to the viewport with the name of the object attached and the specified duration.
		static void Screen(const UObject* const obj, const FString& str, float duration);
		// Print message to the viewport with the duration of 5 seconds and specified color.
		static void Screen(const FString& str, FColor color);
		// Print message to the viewport with the specified duration and color.
		static void Screen(const FString& str, float duration, FColor color);
		// Print message to the viewport with the name of the object attached for the duration of 5 seconds and specified color.
		static void Screen(const UObject* const obj, const FString& str, FColor color);
		// Print message to the viewport with the name of the object attached with the specified duration and color.
		static void Screen(const UObject* const obj, const FString& str, float duration, FColor color);
		// Print message to the viewport with the red color.
		static void ScreenRed(const FString& str);
		// Print message to the viewport with the blue color.
		static void ScreenBlue(const FString& str);
		// Print message to the viewport with the green color.
		static void ScreenGreen(const FString& str);
		// Print message to the viewport with the name of the object attached with the red color.
		static void ScreenRed(const UObject* const obj, const FString& str);
		// Print message to the viewport with the name of the object attached with the blue color.
		static void ScreenBlue(const UObject* const obj, const FString& str);
		// Print message to the viewport with the name of the object attached with the green color.
		static void ScreenGreen(const UObject* const obj, const FString& str);
		// Print message to the viewport with the name of the object attached and the specified duration with the red color.
		static void ScreenRed(const UObject* const obj, const FString& str, float duration);
		// Print message to the viewport with the name of the object attached and the specified duration with the blue color.
		static void ScreenBlue(const UObject* const obj, const FString& str, float duration);
		// Print message to the viewport with the name of the object attached and the specified duration with the green color.
		static void ScreenGreen(const UObject* const obj, const FString& str, float duration);
#pragma endregion Printing messages to the Viewport

	};

}
