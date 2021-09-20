///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/12 16:58)

#ifndef WINDOWS_SYSTEM_PROGRAMMING_HELPER_WINDOWS_SYSTEM_PROGRAMMING_CUSTOM_ASSERT_MACRO_H
#define WINDOWS_SYSTEM_PROGRAMMING_HELPER_WINDOWS_SYSTEM_PROGRAMMING_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL)
    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL 4
#endif  // WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL

constexpr auto g_WindowsSystemProgrammingAssert = WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL;

static_assert(WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL

    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_DEBUG(condition, format, ...) \
        USER_ASSERTION_DEBUG((condition), (format), __VA_ARGS__)
    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        USER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL < 0

    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL

#if 1 <= WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL

    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL < 1

    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL

#if 2 <= WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL

    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL < 2

    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL

#if 3 <= WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL

    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL < 3

    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL

#if 4 <= WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL

    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL < 4

    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define WINDOWS_SYSTEM_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= WINDOWS_SYSTEM_PROGRAMMING_ASSERT_LEVEL

#endif  // WINDOWS_SYSTEM_PROGRAMMING_HELPER_WINDOWS_SYSTEM_PROGRAMMING_CUSTOM_ASSERT_MACRO_H
