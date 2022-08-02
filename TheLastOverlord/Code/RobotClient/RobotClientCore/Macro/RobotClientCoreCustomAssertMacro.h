///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/22 15:30)

#ifndef ROBOT_CLIENT_CORE_MACRO_ROBOT_CLIENT_CORE_CUSTOM_ASSERT_MACRO_H
#define ROBOT_CLIENT_CORE_MACRO_ROBOT_CLIENT_CORE_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Contract/Assertion.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define ROBOT_CLIENT_CORE_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(ROBOT_CLIENT_CORE_ASSERT_LEVEL)
    #define ROBOT_CLIENT_CORE_ASSERT_LEVEL 4
#endif  // ROBOT_CLIENT_CORE_ASSERT_LEVEL

static_assert(ROBOT_CLIENT_CORE_ASSERT_LEVEL <= ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= ROBOT_CLIENT_CORE_ASSERT_LEVEL

    #define ROBOT_CLIENT_CORE_ASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
    #define ROBOT_CLIENT_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ROBOT_CLIENT_CORE_ASSERT_LEVEL < 0

    #define ROBOT_CLIENT_CORE_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define ROBOT_CLIENT_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= ROBOT_CLIENT_CORE_ASSERT_LEVEL

#if 1 <= ROBOT_CLIENT_CORE_ASSERT_LEVEL

    #define ROBOT_CLIENT_CORE_ASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
    #define ROBOT_CLIENT_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ROBOT_CLIENT_CORE_ASSERT_LEVEL < 1

    #define ROBOT_CLIENT_CORE_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define ROBOT_CLIENT_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= ROBOT_CLIENT_CORE_ASSERT_LEVEL

#if 2 <= ROBOT_CLIENT_CORE_ASSERT_LEVEL

    #define ROBOT_CLIENT_CORE_ASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
    #define ROBOT_CLIENT_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ROBOT_CLIENT_CORE_ASSERT_LEVEL < 2

    #define ROBOT_CLIENT_CORE_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define ROBOT_CLIENT_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= ROBOT_CLIENT_CORE_ASSERT_LEVEL

#if 3 <= ROBOT_CLIENT_CORE_ASSERT_LEVEL

    #define ROBOT_CLIENT_CORE_ASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
    #define ROBOT_CLIENT_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ROBOT_CLIENT_CORE_ASSERT_LEVEL < 3

    #define ROBOT_CLIENT_CORE_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define ROBOT_CLIENT_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= ROBOT_CLIENT_CORE_ASSERT_LEVEL

#if 4 <= ROBOT_CLIENT_CORE_ASSERT_LEVEL

    #define ROBOT_CLIENT_CORE_ASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
    #define ROBOT_CLIENT_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ROBOT_CLIENT_CORE_ASSERT_LEVEL < 4

    #define ROBOT_CLIENT_CORE_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define ROBOT_CLIENT_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= ROBOT_CLIENT_CORE_ASSERT_LEVEL

#endif  // ROBOT_CLIENT_CORE_MACRO_ROBOT_CLIENT_CORE_CUSTOM_ASSERT_MACRO_H
