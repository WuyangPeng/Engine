///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:57)

#ifndef HOW_TO_SOLVE_HELPER_HOW_TO_SOLVE_CUSTOM_ASSERT_MACRO_H
#define HOW_TO_SOLVE_HELPER_HOW_TO_SOLVE_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define HOW_TO_SOLVE_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(HOW_TO_SOLVE_ASSERT_LEVEL)
    #define HOW_TO_SOLVE_ASSERT_LEVEL 4
#endif  // HOW_TO_SOLVE_ASSERT_LEVEL

constexpr auto g_HowToSolveAssert = HOW_TO_SOLVE_ASSERT_LEVEL;

static_assert(HOW_TO_SOLVE_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= HOW_TO_SOLVE_ASSERT_LEVEL

    #define HOW_TO_SOLVE_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define HOW_TO_SOLVE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // HOW_TO_SOLVE_ASSERT_LEVEL < 0

    #define HOW_TO_SOLVE_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define HOW_TO_SOLVE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= HOW_TO_SOLVE_ASSERT_LEVEL

#if 1 <= HOW_TO_SOLVE_ASSERT_LEVEL

    #define HOW_TO_SOLVE_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define HOW_TO_SOLVE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // HOW_TO_SOLVE_ASSERT_LEVEL < 1

    #define HOW_TO_SOLVE_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define HOW_TO_SOLVE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= HOW_TO_SOLVE_ASSERT_LEVEL

#if 2 <= HOW_TO_SOLVE_ASSERT_LEVEL

    #define HOW_TO_SOLVE_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define HOW_TO_SOLVE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // HOW_TO_SOLVE_ASSERT_LEVEL < 2

    #define HOW_TO_SOLVE_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define HOW_TO_SOLVE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= HOW_TO_SOLVE_ASSERT_LEVEL

#if 3 <= HOW_TO_SOLVE_ASSERT_LEVEL

    #define HOW_TO_SOLVE_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define HOW_TO_SOLVE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // HOW_TO_SOLVE_ASSERT_LEVEL < 3

    #define HOW_TO_SOLVE_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define HOW_TO_SOLVE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= HOW_TO_SOLVE_ASSERT_LEVEL

#if 4 <= HOW_TO_SOLVE_ASSERT_LEVEL

    #define HOW_TO_SOLVE_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define HOW_TO_SOLVE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // HOW_TO_SOLVE_ASSERT_LEVEL < 4

    #define HOW_TO_SOLVE_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define HOW_TO_SOLVE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= HOW_TO_SOLVE_ASSERT_LEVEL

#endif  // HOW_TO_SOLVE_HELPER_HOW_TO_SOLVE_CUSTOM_ASSERT_MACRO_H
