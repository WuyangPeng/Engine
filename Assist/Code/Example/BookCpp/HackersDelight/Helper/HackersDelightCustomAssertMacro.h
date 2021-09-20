///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/09 14:57)

#ifndef HACKERS_DELIGHT_HELPER_HACKERS_DELIGHT_CUSTOM_ASSERT_MACRO_H
#define HACKERS_DELIGHT_HELPER_HACKERS_DELIGHT_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define HACKERS_DELIGHT_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(HACKERS_DELIGHT_ASSERT_LEVEL)
    #define HACKERS_DELIGHT_ASSERT_LEVEL 4
#endif  // HACKERS_DELIGHT_ASSERT_LEVEL

constexpr auto g_HackersDelightAssert = HACKERS_DELIGHT_ASSERT_LEVEL;

static_assert(HACKERS_DELIGHT_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= HACKERS_DELIGHT_ASSERT_LEVEL

    #define HACKERS_DELIGHT_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define HACKERS_DELIGHT_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // HACKERS_DELIGHT_ASSERT_LEVEL < 0

    #define HACKERS_DELIGHT_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define HACKERS_DELIGHT_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= HACKERS_DELIGHT_ASSERT_LEVEL

#if 1 <= HACKERS_DELIGHT_ASSERT_LEVEL

    #define HACKERS_DELIGHT_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define HACKERS_DELIGHT_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // HACKERS_DELIGHT_ASSERT_LEVEL < 1

    #define HACKERS_DELIGHT_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define HACKERS_DELIGHT_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= HACKERS_DELIGHT_ASSERT_LEVEL

#if 2 <= HACKERS_DELIGHT_ASSERT_LEVEL

    #define HACKERS_DELIGHT_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define HACKERS_DELIGHT_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // HACKERS_DELIGHT_ASSERT_LEVEL < 2

    #define HACKERS_DELIGHT_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define HACKERS_DELIGHT_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= HACKERS_DELIGHT_ASSERT_LEVEL

#if 3 <= HACKERS_DELIGHT_ASSERT_LEVEL

    #define HACKERS_DELIGHT_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define HACKERS_DELIGHT_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // HACKERS_DELIGHT_ASSERT_LEVEL < 3

    #define HACKERS_DELIGHT_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define HACKERS_DELIGHT_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= HACKERS_DELIGHT_ASSERT_LEVEL

#if 4 <= HACKERS_DELIGHT_ASSERT_LEVEL

    #define HACKERS_DELIGHT_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define HACKERS_DELIGHT_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // HACKERS_DELIGHT_ASSERT_LEVEL < 4

    #define HACKERS_DELIGHT_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define HACKERS_DELIGHT_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= HACKERS_DELIGHT_ASSERT_LEVEL

#endif  // HACKERS_DELIGHT_HELPER_HACKERS_DELIGHT_CUSTOM_ASSERT_MACRO_H
