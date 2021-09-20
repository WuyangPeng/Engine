///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:57)

#ifndef UNDERSTANDING_THE_MACHINE_HELPER_UNDERSTANDING_THE_MACHINE_CUSTOM_ASSERT_MACRO_H
#define UNDERSTANDING_THE_MACHINE_HELPER_UNDERSTANDING_THE_MACHINE_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL)
    #define UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL 4
#endif  // UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL

constexpr auto g_UnderstandingTheMachineAssert = UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL;

static_assert(UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL

    #define UNDERSTANDING_THE_MACHINE_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define UNDERSTANDING_THE_MACHINE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL < 0

    #define UNDERSTANDING_THE_MACHINE_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define UNDERSTANDING_THE_MACHINE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL

#if 1 <= UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL

    #define UNDERSTANDING_THE_MACHINE_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define UNDERSTANDING_THE_MACHINE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL < 1

    #define UNDERSTANDING_THE_MACHINE_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define UNDERSTANDING_THE_MACHINE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL

#if 2 <= UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL

    #define UNDERSTANDING_THE_MACHINE_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define UNDERSTANDING_THE_MACHINE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL < 2

    #define UNDERSTANDING_THE_MACHINE_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define UNDERSTANDING_THE_MACHINE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL

#if 3 <= UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL

    #define UNDERSTANDING_THE_MACHINE_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define UNDERSTANDING_THE_MACHINE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL < 3

    #define UNDERSTANDING_THE_MACHINE_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define UNDERSTANDING_THE_MACHINE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL

#if 4 <= UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL

    #define UNDERSTANDING_THE_MACHINE_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define UNDERSTANDING_THE_MACHINE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL < 4

    #define UNDERSTANDING_THE_MACHINE_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define UNDERSTANDING_THE_MACHINE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= UNDERSTANDING_THE_MACHINE_ASSERT_LEVEL

#endif  // UNDERSTANDING_THE_MACHINE_HELPER_UNDERSTANDING_THE_MACHINE_CUSTOM_ASSERT_MACRO_H
