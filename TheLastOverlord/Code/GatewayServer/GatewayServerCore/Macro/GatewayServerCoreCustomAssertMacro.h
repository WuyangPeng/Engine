///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/23 13:30)

#ifndef GATEWAY_SERVER_CORE_MACRO_GATEWAY_SERVER_CORE_CUSTOM_ASSERT_MACRO_H
#define GATEWAY_SERVER_CORE_MACRO_GATEWAY_SERVER_CORE_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Contract/Assertion.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define GATEWAY_SERVER_CORE_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(GATEWAY_SERVER_CORE_ASSERT_LEVEL)
    #define GATEWAY_SERVER_CORE_ASSERT_LEVEL 4
#endif  // GATEWAY_SERVER_CORE_ASSERT_LEVEL

static_assert(GATEWAY_SERVER_CORE_ASSERT_LEVEL <= ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= GATEWAY_SERVER_CORE_ASSERT_LEVEL

    #define GATEWAY_SERVER_CORE_ASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
    #define GATEWAY_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // GATEWAY_SERVER_CORE_ASSERT_LEVEL < 0

    #define GATEWAY_SERVER_CORE_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define GATEWAY_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= GATEWAY_SERVER_CORE_ASSERT_LEVEL

#if 1 <= GATEWAY_SERVER_CORE_ASSERT_LEVEL

    #define GATEWAY_SERVER_CORE_ASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
    #define GATEWAY_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // GATEWAY_SERVER_CORE_ASSERT_LEVEL < 1

    #define GATEWAY_SERVER_CORE_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define GATEWAY_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= GATEWAY_SERVER_CORE_ASSERT_LEVEL

#if 2 <= GATEWAY_SERVER_CORE_ASSERT_LEVEL

    #define GATEWAY_SERVER_CORE_ASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
    #define GATEWAY_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // GATEWAY_SERVER_CORE_ASSERT_LEVEL < 2

    #define GATEWAY_SERVER_CORE_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define GATEWAY_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= GATEWAY_SERVER_CORE_ASSERT_LEVEL

#if 3 <= GATEWAY_SERVER_CORE_ASSERT_LEVEL

    #define GATEWAY_SERVER_CORE_ASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
    #define GATEWAY_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // GATEWAY_SERVER_CORE_ASSERT_LEVEL < 3

    #define GATEWAY_SERVER_CORE_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define GATEWAY_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= GATEWAY_SERVER_CORE_ASSERT_LEVEL

#if 4 <= GATEWAY_SERVER_CORE_ASSERT_LEVEL

    #define GATEWAY_SERVER_CORE_ASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
    #define GATEWAY_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // GATEWAY_SERVER_CORE_ASSERT_LEVEL < 4

    #define GATEWAY_SERVER_CORE_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define GATEWAY_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= GATEWAY_SERVER_CORE_ASSERT_LEVEL

#endif  // GATEWAY_SERVER_CORE_MACRO_GATEWAY_SERVER_CORE_CUSTOM_ASSERT_MACRO_H
