///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 19:27)

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