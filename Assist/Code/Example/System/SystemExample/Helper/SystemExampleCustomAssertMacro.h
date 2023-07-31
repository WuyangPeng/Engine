///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 10:49)

#ifndef SYSTEM_EXAMPLE_HELPER_SYSTEM_EXAMPLE_CUSTOM_ASSERT_MACRO_H
#define SYSTEM_EXAMPLE_HELPER_SYSTEM_EXAMPLE_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCEPTION_ASSERT)

    #define SYSTEM_EXAMPLE_ASSERT_LEVEL 0

#endif  // OPEN_IMPORTANT_EXCEPTION_ASSERT

#if !defined(SYSTEM_EXAMPLE_ASSERT_LEVEL)

    #define SYSTEM_EXAMPLE_ASSERT_LEVEL 4

#endif  // SYSTEM_EXAMPLE_ASSERT_LEVEL

constexpr auto gSystemExampleAssert = SYSTEM_EXAMPLE_ASSERT_LEVEL;

static_assert(SYSTEM_EXAMPLE_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= SYSTEM_EXAMPLE_ASSERT_LEVEL

    #define SYSTEM_EXAMPLE_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define SYSTEM_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SYSTEM_EXAMPLE_ASSERT_LEVEL < 0

    #define SYSTEM_EXAMPLE_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define SYSTEM_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= SYSTEM_EXAMPLE_ASSERT_LEVEL

#if 1 <= SYSTEM_EXAMPLE_ASSERT_LEVEL

    #define SYSTEM_EXAMPLE_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define SYSTEM_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SYSTEM_EXAMPLE_ASSERT_LEVEL < 1

    #define SYSTEM_EXAMPLE_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define SYSTEM_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= SYSTEM_EXAMPLE_ASSERT_LEVEL

#if 2 <= SYSTEM_EXAMPLE_ASSERT_LEVEL

    #define SYSTEM_EXAMPLE_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define SYSTEM_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SYSTEM_EXAMPLE_ASSERT_LEVEL < 2

    #define SYSTEM_EXAMPLE_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define SYSTEM_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= SYSTEM_EXAMPLE_ASSERT_LEVEL

#if 3 <= SYSTEM_EXAMPLE_ASSERT_LEVEL

    #define SYSTEM_EXAMPLE_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define SYSTEM_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SYSTEM_EXAMPLE_ASSERT_LEVEL < 3

    #define SYSTEM_EXAMPLE_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define SYSTEM_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= SYSTEM_EXAMPLE_ASSERT_LEVEL

#if 4 <= SYSTEM_EXAMPLE_ASSERT_LEVEL

    #define SYSTEM_EXAMPLE_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define SYSTEM_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SYSTEM_EXAMPLE_ASSERT_LEVEL < 4

    #define SYSTEM_EXAMPLE_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define SYSTEM_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= SYSTEM_EXAMPLE_ASSERT_LEVEL

#endif  // SYSTEM_EXAMPLE_HELPER_SYSTEM_EXAMPLE_CUSTOM_ASSERT_MACRO_H
