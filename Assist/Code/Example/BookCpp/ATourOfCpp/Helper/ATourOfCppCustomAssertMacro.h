///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/26 21:33)

#ifndef A_TOUR_OF_CPP_HELPER_A_TOUR_OF_CPP_CUSTOM_ASSERT_MACRO_H
#define A_TOUR_OF_CPP_HELPER_A_TOUR_OF_CPP_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define A_TOUR_OF_CPP_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(A_TOUR_OF_CPP_ASSERT_LEVEL)
    #define A_TOUR_OF_CPP_ASSERT_LEVEL 4
#endif  // A_TOUR_OF_CPP_ASSERT_LEVEL

constexpr auto g_ATourOfCppAssert = A_TOUR_OF_CPP_ASSERT_LEVEL;

static_assert(A_TOUR_OF_CPP_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= A_TOUR_OF_CPP_ASSERT_LEVEL

    #define A_TOUR_OF_CPP_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define A_TOUR_OF_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // A_TOUR_OF_CPP_ASSERT_LEVEL < 0

    #define A_TOUR_OF_CPP_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define A_TOUR_OF_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= A_TOUR_OF_CPP_ASSERT_LEVEL

#if 1 <= A_TOUR_OF_CPP_ASSERT_LEVEL

    #define A_TOUR_OF_CPP_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define A_TOUR_OF_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // A_TOUR_OF_CPP_ASSERT_LEVEL < 1

    #define A_TOUR_OF_CPP_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define A_TOUR_OF_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= A_TOUR_OF_CPP_ASSERT_LEVEL

#if 2 <= A_TOUR_OF_CPP_ASSERT_LEVEL

    #define A_TOUR_OF_CPP_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define A_TOUR_OF_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // A_TOUR_OF_CPP_ASSERT_LEVEL < 2

    #define A_TOUR_OF_CPP_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define A_TOUR_OF_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= A_TOUR_OF_CPP_ASSERT_LEVEL

#if 3 <= A_TOUR_OF_CPP_ASSERT_LEVEL

    #define A_TOUR_OF_CPP_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define A_TOUR_OF_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // A_TOUR_OF_CPP_ASSERT_LEVEL < 3

    #define A_TOUR_OF_CPP_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define A_TOUR_OF_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= A_TOUR_OF_CPP_ASSERT_LEVEL

#if 4 <= A_TOUR_OF_CPP_ASSERT_LEVEL

    #define A_TOUR_OF_CPP_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define A_TOUR_OF_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // A_TOUR_OF_CPP_ASSERT_LEVEL < 4

    #define A_TOUR_OF_CPP_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define A_TOUR_OF_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= A_TOUR_OF_CPP_ASSERT_LEVEL

#endif  // A_TOUR_OF_CPP_HELPER_A_TOUR_OF_CPP_CUSTOM_ASSERT_MACRO_H
