/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:15)

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