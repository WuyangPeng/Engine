///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/22 21:07)

#ifndef TCP_IP_PROTOCOL_SUITE_HELPER_TCP_IP_PROTOCOL_SUITE_CUSTOM_ASSERT_MACRO_H
#define TCP_IP_PROTOCOL_SUITE_HELPER_TCP_IP_PROTOCOL_SUITE_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL)
    #define TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL 4
#endif  // TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL

constexpr auto g_TCPIPProtocolSuiteAssert = TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL;

static_assert(TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL

    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_DEBUG(condition, format, ...) \
        USER_ASSERTION_DEBUG((condition), (format), __VA_ARGS__)
    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        USER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL < 0

    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL

#if 1 <= TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL

    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL < 1

    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL

#if 2 <= TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL

    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL < 2

    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL

#if 3 <= TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL

    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL < 3

    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL

#if 4 <= TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL

    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL < 4

    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define TCP_IP_PROTOCOL_SUITE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= TCP_IP_PROTOCOL_SUITE_ASSERT_LEVEL

#endif  // TCP_IP_PROTOCOL_SUITE_HELPER_TCP_IP_PROTOCOL_SUITE_CUSTOM_ASSERT_MACRO_H
