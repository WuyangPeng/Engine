/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:15)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_SCHEDULE_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_SCHEDULE_H

#include "System/Helper/EnumOperator.h"

namespace Framework
{
    enum class MainFunctionSchedule
    {
        Failure = 0,
        UniqueId,
        Log,
        InitTerm,
        JsonAnalysis,
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
        Max,
    };

    enum class OpenGLGlutMainFunctionSchedule
    {
        Failure = 0,
        OpenGLGlutProcess,
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

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_SCHEDULE_H