///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/11/30 21:54)

#ifndef THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_HELPER_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CUSTOM_ASSERT_MACRO_H
#define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_HELPER_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL)
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL 4
#endif  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL

constexpr auto g_ThrivingInACrowdedAndChangingWorldAssert = THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL;

static_assert(THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL < 0

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL

#if 1 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL < 1

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL

#if 2 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL < 2

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL

#if 3 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL < 3

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL

#if 4 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL < 4

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ASSERT_LEVEL

#endif  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_HELPER_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CUSTOM_ASSERT_MACRO_H
