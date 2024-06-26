/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 10:58)

#ifndef CORE_TOOLS_HELPER_SAFETY_LIMIT_MACRO_H
#define CORE_TOOLS_HELPER_SAFETY_LIMIT_MACRO_H

#include "ExceptionMacro.h"

namespace CoreTools
{
    constexpr auto gSafetyLimit100 = 100;
    constexpr auto gSafetyLimit1000 = 1000;
    constexpr auto gSafetyLimit10000 = 10000;
    constexpr auto gSafetyLimit100000 = 100000;
}

#ifdef CORE_TOOLS_USE_SAFETY_LIMIT

    #define SAFETY_WHILE_BEGIN(expression, maxCounter)                                         \
        {                                                                                      \
            auto safetyCounter = 0;                                                            \
            while (expression)                                                                 \
            {                                                                                  \
                if (SYSTEM_CONCATENATOR(CoreTools::gSafetyLimit, maxCounter) <= safetyCounter) \
                {                                                                              \
                    THROW_EXCEPTION(SYSTEM_TEXT("内部错误：违反安全计数器。"s))                \
                }

    #define SAFETY_WHILE_END \
        ++safetyCounter;     \
        }                    \
        }

#else  // !CORE_TOOLS_USE_SAFETY_LIMIT

    #define SAFETY_WHILE_BEGIN(expression，maxCounter) \
        while (expression)                             \
        {
    #define SAFETY_WHILE_END }

#endif  // CORE_TOOLS_USE_SAFETY_LIMIT

#endif  // CORE_TOOLS_HELPER_SAFETY_LIMIT_MACRO_H
