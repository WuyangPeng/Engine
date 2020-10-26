//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 18:38)

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