///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/26 21:33)

#ifndef CPP_FOR_THE_IMPATIENT_HELPER_CPP_FOR_THE_IMPATIENT_CUSTOM_ASSERT_MACRO_H
#define CPP_FOR_THE_IMPATIENT_HELPER_CPP_FOR_THE_IMPATIENT_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL)
    #define CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL 4
#endif  // CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL

constexpr auto g_CppForTheImpatientAssert = CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL;

static_assert(CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL

    #define CPP_FOR_THE_IMPATIENT_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define CPP_FOR_THE_IMPATIENT_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL < 0

    #define CPP_FOR_THE_IMPATIENT_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define CPP_FOR_THE_IMPATIENT_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL

#if 1 <= CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL

    #define CPP_FOR_THE_IMPATIENT_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define CPP_FOR_THE_IMPATIENT_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL < 1

    #define CPP_FOR_THE_IMPATIENT_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define CPP_FOR_THE_IMPATIENT_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL

#if 2 <= CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL

    #define CPP_FOR_THE_IMPATIENT_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define CPP_FOR_THE_IMPATIENT_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL < 2

    #define CPP_FOR_THE_IMPATIENT_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define CPP_FOR_THE_IMPATIENT_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL

#if 3 <= CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL

    #define CPP_FOR_THE_IMPATIENT_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define CPP_FOR_THE_IMPATIENT_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL < 3

    #define CPP_FOR_THE_IMPATIENT_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define CPP_FOR_THE_IMPATIENT_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL

#if 4 <= CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL

    #define CPP_FOR_THE_IMPATIENT_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define CPP_FOR_THE_IMPATIENT_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL < 4

    #define CPP_FOR_THE_IMPATIENT_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define CPP_FOR_THE_IMPATIENT_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= CPP_FOR_THE_IMPATIENT_ASSERT_LEVEL

#endif  // CPP_FOR_THE_IMPATIENT_HELPER_CPP_FOR_THE_IMPATIENT_CUSTOM_ASSERT_MACRO_H
