// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 11:45)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_SCHEDULE_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_SCHEDULE_H 

#include "System/Helper/EnumMacro.h"

namespace Framework
{
	enum class MainFunctionSchedule
	{
		Failure = 0,
		UniqueID,
		Log,
		Memory,
		InitTerm,
		Environment,
		SmartPointer,
		Max,
	};

	enum class ConsoleMainFunctionSchedule
	{
		Failure = 0,
		ConsoleProcess,
		Max,
	};

	enum class WindowMainFunctionSchedule
	{
		Failure = 0,
		WindowProcess,
		Camera,
		RendererManager,
		Max,
	};

	enum class OpenGLGlutMainFunctionSchedule
	{
		Failure = 0,
		OpenGLGlutProcess,
		Camera,
		Max,
		InitComplete
	};

	enum class AndroidMainFunctionSchedule
	{
		Failure = 0,
		AndroidProcess, 
		Max, 
	};

	enum class MacintoshMainFunctionSchedule
	{
		Failure = 0,
		MacintoshProcess,
		Max,
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_SCHEDULE_H