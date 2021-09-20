///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/26 21:33)

#ifndef PROBLEM_SOLVING_WITH_CPP_HELPER_PROBLEM_SOLVING_WITH_CPP_CUSTOM_ASSERT_MACRO_H
#define PROBLEM_SOLVING_WITH_CPP_HELPER_PROBLEM_SOLVING_WITH_CPP_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL)
    #define PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL 4
#endif  // PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL

constexpr auto g_ProblemSolvingWithCppAssert = PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL;

static_assert(PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL

    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL < 0

    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL

#if 1 <= PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL

    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL < 1

    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL

#if 2 <= PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL

    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL < 2

    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL

#if 3 <= PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL

    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL < 3

    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL

#if 4 <= PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL

    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL < 4

    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define PROBLEM_SOLVING_WITH_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= PROBLEM_SOLVING_WITH_CPP_ASSERT_LEVEL

#endif  // PROBLEM_SOLVING_WITH_CPP_HELPER_PROBLEM_SOLVING_WITH_CPP_CUSTOM_ASSERT_MACRO_H
