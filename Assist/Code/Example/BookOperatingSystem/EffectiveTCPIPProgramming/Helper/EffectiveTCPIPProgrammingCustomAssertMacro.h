///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.2 (2021/08/27 22:22)

#ifndef EFFECTIVE_TCP_IP_PROGRAMMING_HELPER_EFFECTIVE_TCP_IP_PROGRAMMING_CUSTOM_ASSERT_MACRO_H
#define EFFECTIVE_TCP_IP_PROGRAMMING_HELPER_EFFECTIVE_TCP_IP_PROGRAMMING_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL)
    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL 4
#endif  // EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL

constexpr auto g_EffectiveTCPIPProgrammingAssert = EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL;

static_assert(EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL

    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_DEBUG(condition, format, ...) \
        USER_ASSERTION_DEBUG((condition), (format), __VA_ARGS__)
    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        USER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL < 0

    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL

#if 1 <= EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL

    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL < 1

    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL

#if 2 <= EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL

    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL < 2

    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL

#if 3 <= EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL

    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL < 3

    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL

#if 4 <= EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL

    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL < 4

    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define EFFECTIVE_TCP_IP_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= EFFECTIVE_TCP_IP_PROGRAMMING_ASSERT_LEVEL

#endif  // EFFECTIVE_TCP_IP_PROGRAMMING_HELPER_EFFECTIVE_TCP_IP_PROGRAMMING_CUSTOM_ASSERT_MACRO_H
