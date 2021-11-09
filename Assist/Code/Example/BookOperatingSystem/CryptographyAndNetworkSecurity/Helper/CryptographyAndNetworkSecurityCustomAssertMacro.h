///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/22 21:07)

#ifndef CRYPTOGRAPHY_AND_NETWORK_SECURITY_HELPER_CRYPTOGRAPHY_AND_NETWORK_SECURITY_CUSTOM_ASSERT_MACRO_H
#define CRYPTOGRAPHY_AND_NETWORK_SECURITY_HELPER_CRYPTOGRAPHY_AND_NETWORK_SECURITY_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL)
    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL 4
#endif  // CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL

constexpr auto g_CryptographyAndNetworkSecurityAssert = CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL;

static_assert(CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL

    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_DEBUG(condition, format, ...) \
        USER_ASSERTION_DEBUG((condition), (format), __VA_ARGS__)
    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        USER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL < 0

    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL

#if 1 <= CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL

    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL < 1

    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL

#if 2 <= CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL

    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL < 2

    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL

#if 3 <= CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL

    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL < 3

    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL

#if 4 <= CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL

    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL < 4

    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= CRYPTOGRAPHY_AND_NETWORK_SECURITY_ASSERT_LEVEL

#endif  // CRYPTOGRAPHY_AND_NETWORK_SECURITY_HELPER_CRYPTOGRAPHY_AND_NETWORK_SECURITY_CUSTOM_ASSERT_MACRO_H
