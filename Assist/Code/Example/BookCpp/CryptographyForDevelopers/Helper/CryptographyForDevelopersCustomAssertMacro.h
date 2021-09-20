///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:03)

#ifndef CRYPTOGRAPHY_FOR_DEVELOPERS_HELPER_CRYPTOGRAPHY_FOR_DEVELOPERS_CUSTOM_ASSERT_MACRO_H
#define CRYPTOGRAPHY_FOR_DEVELOPERS_HELPER_CRYPTOGRAPHY_FOR_DEVELOPERS_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL)
    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL 4
#endif  // CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL

constexpr auto g_CryptographyForDevelopersAssert = CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL;

static_assert(CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL

    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL < 0

    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL

#if 1 <= CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL

    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL < 1

    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL

#if 2 <= CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL

    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL < 2

    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL

#if 3 <= CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL

    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL < 3

    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL

#if 4 <= CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL

    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL < 4

    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= CRYPTOGRAPHY_FOR_DEVELOPERS_ASSERT_LEVEL

#endif  // CRYPTOGRAPHY_FOR_DEVELOPERS_HELPER_CRYPTOGRAPHY_FOR_DEVELOPERS_CUSTOM_ASSERT_MACRO_H
