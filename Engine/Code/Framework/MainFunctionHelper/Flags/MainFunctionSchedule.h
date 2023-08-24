///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/08 19:27)

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
        Environment,
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

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_SCHEDULE_H