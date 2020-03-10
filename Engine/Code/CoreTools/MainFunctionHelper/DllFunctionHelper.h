// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 11:54)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_DLL_FUNCTION_HELPER_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_DLL_FUNCTION_HELPER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/SystemOutput/Fwd/SystemOutputFlagsFwd.h"

#include <string> 

namespace CoreTools
{
	class DllMutex;

	class CORE_TOOLS_DEFAULT_DECLARE DllFunctionHelper
	{
	public:
		using ClassType = DllFunctionHelper;

	public:
		static void InitializeMutex(DllMutex* mutex);
		static void DeleteMutex(DllMutex* mutex);

	private:
		static void JudgeUserSelectionWithTChar(const System::String& message);
		static void JudgeUserSelectionWithChar(const std::string& message);

	private:
		static void JudgeSelection(System::DialogBoxCommand selection);
	};
}

#endif // CORE_TOOLS_MAIN_FUNCTION_HELPER_DLL_FUNCTION_HELPER_H