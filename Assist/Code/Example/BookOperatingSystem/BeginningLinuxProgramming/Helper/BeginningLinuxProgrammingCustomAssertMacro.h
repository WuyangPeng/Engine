///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/21 20:59)

#ifndef BEGINNING_LINUX_PROGRAMMING_HELPER_BEGINNING_LINUX_PROGRAMMING_CUSTOM_ASSERT_MACRO_H
#define BEGINNING_LINUX_PROGRAMMING_HELPER_BEGINNING_LINUX_PROGRAMMING_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL)
    #define BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL 4
#endif  // BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL

constexpr auto g_BeginningLinuxProgrammingAssert = BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL;

static_assert(BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL

    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_DEBUG(condition, format, ...) \
        USER_ASSERTION_DEBUG((condition), (format), __VA_ARGS__)
    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        USER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL < 0

    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL

#if 1 <= BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL

    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL < 1

    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL

#if 2 <= BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL

    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL < 2

    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL

#if 3 <= BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL

    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL < 3

    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL

#if 4 <= BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL

    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL < 4

    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define BEGINNING_LINUX_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= BEGINNING_LINUX_PROGRAMMING_ASSERT_LEVEL

#endif  // BEGINNING_LINUX_PROGRAMMING_HELPER_BEGINNING_LINUX_PROGRAMMING_CUSTOM_ASSERT_MACRO_H
