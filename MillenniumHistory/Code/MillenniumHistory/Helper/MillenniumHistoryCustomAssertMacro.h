///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/17 23:40)

#ifndef MILLENNIUM_HISTORY_MILLENNIUM_HISTORY_CUSTOM_ASSERT_MACRO_H
#define MILLENNIUM_HISTORY_MILLENNIUM_HISTORY_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCEPTION_ASSERT)

    #define MILLENNIUM_HISTORY_ASSERT_LEVEL 0

#endif  // OPEN_IMPORTANT_EXCEPTION_ASSERT

#if !defined(MILLENNIUM_HISTORY_ASSERT_LEVEL)

    #define MILLENNIUM_HISTORY_ASSERT_LEVEL 4

#endif  // MILLENNIUM_HISTORY_ASSERT_LEVEL

static_assert(MILLENNIUM_HISTORY_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= MILLENNIUM_HISTORY_ASSERT_LEVEL

    #define MILLENNIUM_HISTORY_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define MILLENNIUM_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

    #define MILLENNIUM_HISTORY_ASSERTION_DEBUG(condition, format, ...) \
        USER_ASSERTION_DEBUG((condition), (format), __VA_ARGS__)
    #define MILLENNIUM_HISTORY_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        USER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // MILLENNIUM_HISTORY_ASSERT_LEVEL < 0

    #define MILLENNIUM_HISTORY_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define MILLENNIUM_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define MILLENNIUM_HISTORY_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define MILLENNIUM_HISTORY_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= MILLENNIUM_HISTORY_ASSERT_LEVEL

#if 1 <= MILLENNIUM_HISTORY_ASSERT_LEVEL

    #define MILLENNIUM_HISTORY_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define MILLENNIUM_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // MILLENNIUM_HISTORY_ASSERT_LEVEL < 1

    #define MILLENNIUM_HISTORY_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define MILLENNIUM_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= MILLENNIUM_HISTORY_ASSERT_LEVEL

#if 2 <= MILLENNIUM_HISTORY_ASSERT_LEVEL

    #define MILLENNIUM_HISTORY_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define MILLENNIUM_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // MILLENNIUM_HISTORY_ASSERT_LEVEL < 2

    #define MILLENNIUM_HISTORY_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define MILLENNIUM_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= MILLENNIUM_HISTORY_ASSERT_LEVEL

#if 3 <= MILLENNIUM_HISTORY_ASSERT_LEVEL

    #define MILLENNIUM_HISTORY_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define MILLENNIUM_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // MILLENNIUM_HISTORY_ASSERT_LEVEL < 3

    #define MILLENNIUM_HISTORY_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define MILLENNIUM_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= MILLENNIUM_HISTORY_ASSERT_LEVEL

#if 4 <= MILLENNIUM_HISTORY_ASSERT_LEVEL

    #define MILLENNIUM_HISTORY_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define MILLENNIUM_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // MILLENNIUM_HISTORY_ASSERT_LEVEL < 4

    #define MILLENNIUM_HISTORY_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define MILLENNIUM_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= MILLENNIUM_HISTORY_ASSERT_LEVEL

#endif  // MILLENNIUM_HISTORY_MILLENNIUM_HISTORY_CUSTOM_ASSERT_MACRO_H
