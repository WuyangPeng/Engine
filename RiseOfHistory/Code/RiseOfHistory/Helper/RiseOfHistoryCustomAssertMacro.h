///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	历史的崛起版本：0.8.1.0 (2022/08/03 10:59)

#ifndef RISE_OF_HISTORY_RISE_OF_HISTORY_CUSTOM_ASSERT_MACRO_H
#define RISE_OF_HISTORY_RISE_OF_HISTORY_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define RISE_OF_HISTORY_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(RISE_OF_HISTORY_ASSERT_LEVEL)
    #define RISE_OF_HISTORY_ASSERT_LEVEL 4
#endif  // RISE_OF_HISTORY_ASSERT_LEVEL

static_assert(RISE_OF_HISTORY_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= RISE_OF_HISTORY_ASSERT_LEVEL

    #define RISE_OF_HISTORY_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define RISE_OF_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

    #define RISE_OF_HISTORY_ASSERTION_DEBUG(condition, format, ...) \
        USER_ASSERTION_DEBUG((condition), (format), __VA_ARGS__)
    #define RISE_OF_HISTORY_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        USER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // RISE_OF_HISTORY_ASSERT_LEVEL < 0

    #define RISE_OF_HISTORY_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define RISE_OF_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define RISE_OF_HISTORY_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define RISE_OF_HISTORY_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= RISE_OF_HISTORY_ASSERT_LEVEL

#if 1 <= RISE_OF_HISTORY_ASSERT_LEVEL

    #define RISE_OF_HISTORY_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define RISE_OF_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // RISE_OF_HISTORY_ASSERT_LEVEL < 1

    #define RISE_OF_HISTORY_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define RISE_OF_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= RISE_OF_HISTORY_ASSERT_LEVEL

#if 2 <= RISE_OF_HISTORY_ASSERT_LEVEL

    #define RISE_OF_HISTORY_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define RISE_OF_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // RISE_OF_HISTORY_ASSERT_LEVEL < 2

    #define RISE_OF_HISTORY_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define RISE_OF_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= RISE_OF_HISTORY_ASSERT_LEVEL

#if 3 <= RISE_OF_HISTORY_ASSERT_LEVEL

    #define RISE_OF_HISTORY_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define RISE_OF_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // RISE_OF_HISTORY_ASSERT_LEVEL < 3

    #define RISE_OF_HISTORY_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define RISE_OF_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= RISE_OF_HISTORY_ASSERT_LEVEL

#if 4 <= RISE_OF_HISTORY_ASSERT_LEVEL

    #define RISE_OF_HISTORY_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define RISE_OF_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // RISE_OF_HISTORY_ASSERT_LEVEL < 4

    #define RISE_OF_HISTORY_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define RISE_OF_HISTORY_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= RISE_OF_HISTORY_ASSERT_LEVEL

#endif  // RISE_OF_HISTORY_RISE_OF_HISTORY_CUSTOM_ASSERT_MACRO_H
