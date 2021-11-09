///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/07 23:22)

#ifndef ADVANCED_WINDOWS_DEBUGGING_HELPER_ADVANCED_WINDOWS_DEBUGGING_CUSTOM_ASSERT_MACRO_H
#define ADVANCED_WINDOWS_DEBUGGING_HELPER_ADVANCED_WINDOWS_DEBUGGING_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL)
    #define ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL 4
#endif  // ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL

constexpr auto g_AdvancedWindowsDebuggingAssert = ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL;

static_assert(ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL

    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_DEBUG(condition, format, ...) \
        USER_ASSERTION_DEBUG((condition), (format), __VA_ARGS__)
    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        USER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL < 0

    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL

#if 1 <= ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL

    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL < 1

    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL

#if 2 <= ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL

    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL < 2

    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL

#if 3 <= ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL

    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL < 3

    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL

#if 4 <= ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL

    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL < 4

    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define ADVANCED_WINDOWS_DEBUGGING_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= ADVANCED_WINDOWS_DEBUGGING_ASSERT_LEVEL

#endif  // ADVANCED_WINDOWS_DEBUGGING_HELPER_ADVANCED_WINDOWS_DEBUGGING_CUSTOM_ASSERT_MACRO_H
