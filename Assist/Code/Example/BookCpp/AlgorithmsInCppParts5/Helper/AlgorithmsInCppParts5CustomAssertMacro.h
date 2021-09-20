///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/07 0:27)

#ifndef ALGORITHMS_IN_CPP_PARTS_5_HELPER_ALGORITHMS_IN_CPP_PARTS_5_CUSTOM_ASSERT_MACRO_H
#define ALGORITHMS_IN_CPP_PARTS_5_HELPER_ALGORITHMS_IN_CPP_PARTS_5_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL)
    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL 4
#endif  // ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL

constexpr auto g_AlgorithmsInCppParts5Assert = ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL;

static_assert(ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL

    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL < 0

    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL

#if 1 <= ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL

    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL < 1

    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL

#if 2 <= ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL

    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL < 2

    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL

#if 3 <= ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL

    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL < 3

    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL

#if 4 <= ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL

    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL < 4

    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define ALGORITHMS_IN_CPP_PARTS_5_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= ALGORITHMS_IN_CPP_PARTS_5_ASSERT_LEVEL

#endif  // ALGORITHMS_IN_CPP_PARTS_5_HELPER_ALGORITHMS_IN_CPP_PARTS_5_CUSTOM_ASSERT_MACRO_H
