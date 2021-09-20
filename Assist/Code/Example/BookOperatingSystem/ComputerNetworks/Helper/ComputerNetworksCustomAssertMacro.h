///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.2 (2021/08/27 22:22)

#ifndef COMPUTER_NETWORKS_HELPER_COMPUTER_NETWORKS_CUSTOM_ASSERT_MACRO_H
#define COMPUTER_NETWORKS_HELPER_COMPUTER_NETWORKS_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define COMPUTER_NETWORKS_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(COMPUTER_NETWORKS_ASSERT_LEVEL)
    #define COMPUTER_NETWORKS_ASSERT_LEVEL 4
#endif  // COMPUTER_NETWORKS_ASSERT_LEVEL

constexpr auto g_ComputerNetworksAssert = COMPUTER_NETWORKS_ASSERT_LEVEL;

static_assert(COMPUTER_NETWORKS_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= COMPUTER_NETWORKS_ASSERT_LEVEL

    #define COMPUTER_NETWORKS_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define COMPUTER_NETWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

    #define COMPUTER_NETWORKS_ASSERTION_DEBUG(condition, format, ...) \
        USER_ASSERTION_DEBUG((condition), (format), __VA_ARGS__)
    #define COMPUTER_NETWORKS_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        USER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // COMPUTER_NETWORKS_ASSERT_LEVEL < 0

    #define COMPUTER_NETWORKS_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define COMPUTER_NETWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define COMPUTER_NETWORKS_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define COMPUTER_NETWORKS_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= COMPUTER_NETWORKS_ASSERT_LEVEL

#if 1 <= COMPUTER_NETWORKS_ASSERT_LEVEL

    #define COMPUTER_NETWORKS_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define COMPUTER_NETWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // COMPUTER_NETWORKS_ASSERT_LEVEL < 1

    #define COMPUTER_NETWORKS_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define COMPUTER_NETWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= COMPUTER_NETWORKS_ASSERT_LEVEL

#if 2 <= COMPUTER_NETWORKS_ASSERT_LEVEL

    #define COMPUTER_NETWORKS_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define COMPUTER_NETWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // COMPUTER_NETWORKS_ASSERT_LEVEL < 2

    #define COMPUTER_NETWORKS_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define COMPUTER_NETWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= COMPUTER_NETWORKS_ASSERT_LEVEL

#if 3 <= COMPUTER_NETWORKS_ASSERT_LEVEL

    #define COMPUTER_NETWORKS_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define COMPUTER_NETWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // COMPUTER_NETWORKS_ASSERT_LEVEL < 3

    #define COMPUTER_NETWORKS_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define COMPUTER_NETWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= COMPUTER_NETWORKS_ASSERT_LEVEL

#if 4 <= COMPUTER_NETWORKS_ASSERT_LEVEL

    #define COMPUTER_NETWORKS_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define COMPUTER_NETWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // COMPUTER_NETWORKS_ASSERT_LEVEL < 4

    #define COMPUTER_NETWORKS_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define COMPUTER_NETWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= COMPUTER_NETWORKS_ASSERT_LEVEL

#endif  // COMPUTER_NETWORKS_HELPER_COMPUTER_NETWORKS_CUSTOM_ASSERT_MACRO_H
