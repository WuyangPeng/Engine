/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:35)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_DLL_FUNCTION_HELPER_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_DLL_FUNCTION_HELPER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/SystemOutput/Fwd/SystemOutputFlagsFwd.h"
#include "CoreTools/Threading/ThreadingFwd.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE DllFunctionHelper final
    {
    public:
        using ClassType = DllFunctionHelper;

    public:
        static void InitializeMutex(DllMutex* mutex);
        static void DeleteMutex(DllMutex* mutex);

    private:
        static void JudgeUserSelectionWithTChar(const System::String& message) noexcept;
        static void JudgeUserSelectionWithChar(const std::string& message) noexcept;

    private:
        static void JudgeSelection(System::DialogBoxCommand selection) noexcept;
    };
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_DLL_FUNCTION_HELPER_H