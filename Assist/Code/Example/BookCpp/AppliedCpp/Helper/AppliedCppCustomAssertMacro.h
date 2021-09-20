///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/08 21:29)

#ifndef APPLIED_CPP_HELPER_APPLIED_CPP_CUSTOM_ASSERT_MACRO_H
#define APPLIED_CPP_HELPER_APPLIED_CPP_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define APPLIED_CPP_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(APPLIED_CPP_ASSERT_LEVEL)
    #define APPLIED_CPP_ASSERT_LEVEL 4
#endif  // APPLIED_CPP_ASSERT_LEVEL

constexpr auto g_AppliedCppAssert = APPLIED_CPP_ASSERT_LEVEL;

static_assert(APPLIED_CPP_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= APPLIED_CPP_ASSERT_LEVEL

    #define APPLIED_CPP_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define APPLIED_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // APPLIED_CPP_ASSERT_LEVEL < 0

    #define APPLIED_CPP_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define APPLIED_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= APPLIED_CPP_ASSERT_LEVEL

#if 1 <= APPLIED_CPP_ASSERT_LEVEL

    #define APPLIED_CPP_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define APPLIED_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // APPLIED_CPP_ASSERT_LEVEL < 1

    #define APPLIED_CPP_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define APPLIED_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= APPLIED_CPP_ASSERT_LEVEL

#if 2 <= APPLIED_CPP_ASSERT_LEVEL

    #define APPLIED_CPP_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define APPLIED_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // APPLIED_CPP_ASSERT_LEVEL < 2

    #define APPLIED_CPP_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define APPLIED_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= APPLIED_CPP_ASSERT_LEVEL

#if 3 <= APPLIED_CPP_ASSERT_LEVEL

    #define APPLIED_CPP_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define APPLIED_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // APPLIED_CPP_ASSERT_LEVEL < 3

    #define APPLIED_CPP_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define APPLIED_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= APPLIED_CPP_ASSERT_LEVEL

#if 4 <= APPLIED_CPP_ASSERT_LEVEL

    #define APPLIED_CPP_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define APPLIED_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // APPLIED_CPP_ASSERT_LEVEL < 4

    #define APPLIED_CPP_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define APPLIED_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= APPLIED_CPP_ASSERT_LEVEL

#endif  // APPLIED_CPP_HELPER_APPLIED_CPP_CUSTOM_ASSERT_MACRO_H
