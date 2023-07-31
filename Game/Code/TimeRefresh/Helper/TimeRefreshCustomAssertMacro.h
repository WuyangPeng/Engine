///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:55)

#ifndef TIME_REFRESH_HELPER_CUSTOM_ASSERT_HELPER_H
#define TIME_REFRESH_HELPER_CUSTOM_ASSERT_HELPER_H

#include "UserMacro.h"
#include "CoreTools/Contract/Assertion.h"
#include "CoreTools/Helper/CustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCEPTION_ASSERT)

    #define TIME_REFRESH_ASSERT_LEVEL 0

#endif  // OPEN_IMPORTANT_EXCEPTION_ASSERT

#if !defined(TIME_REFRESH_ASSERT_LEVEL)

    #define TIME_REFRESH_ASSERT_LEVEL 4

#endif  // TIME_REFRESH_ASSERT_LEVEL

static_assert(TIME_REFRESH_ASSERT_LEVEL <= ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= TIME_REFRESH_ASSERT_LEVEL

    #define TIME_REFRESH_ASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
    #define TIME_REFRESH_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // TIME_REFRESH_ASSERT_LEVEL < 0

    #define TIME_REFRESH_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define TIME_REFRESH_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= TIME_REFRESH_ASSERT_LEVEL

#if 1 <= TIME_REFRESH_ASSERT_LEVEL

    #define TIME_REFRESH_ASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
    #define TIME_REFRESH_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // TIME_REFRESH_ASSERT_LEVEL < 1

    #define TIME_REFRESH_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define TIME_REFRESH_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= TIME_REFRESH_ASSERT_LEVEL

#if 2 <= TIME_REFRESH_ASSERT_LEVEL

    #define TIME_REFRESH_ASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
    #define TIME_REFRESH_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // TIME_REFRESH_ASSERT_LEVEL < 2

    #define TIME_REFRESH_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define TIME_REFRESH_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= TIME_REFRESH_ASSERT_LEVEL

#if 3 <= TIME_REFRESH_ASSERT_LEVEL

    #define TIME_REFRESH_ASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
    #define TIME_REFRESH_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // TIME_REFRESH_ASSERT_LEVEL < 3

    #define TIME_REFRESH_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define TIME_REFRESH_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= TIME_REFRESH_ASSERT_LEVEL

#if 4 <= TIME_REFRESH_ASSERT_LEVEL

    #define TIME_REFRESH_ASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
    #define TIME_REFRESH_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // TIME_REFRESH_ASSERT_LEVEL < 4

    #define TIME_REFRESH_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define TIME_REFRESH_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= TIME_REFRESH_ASSERT_LEVEL

#endif  // TIME_REFRESH_HELPER_CUSTOM_ASSERT_HELPER_H
