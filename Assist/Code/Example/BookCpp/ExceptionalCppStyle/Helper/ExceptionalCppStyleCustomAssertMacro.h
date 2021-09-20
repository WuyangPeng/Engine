///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/20 0:15)

#ifndef EXCEPTIONAL_CPP_STYLE_HELPER_EXCEPTIONAL_CPP_STYLE_CUSTOM_ASSERT_MACRO_H
#define EXCEPTIONAL_CPP_STYLE_HELPER_EXCEPTIONAL_CPP_STYLE_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL)
    #define EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL 4
#endif  // EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL

constexpr auto g_ExceptionalCppStyleAssert = EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL;

static_assert(EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL

    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL < 0

    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL

#if 1 <= EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL

    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL < 1

    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL

#if 2 <= EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL

    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL < 2

    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL

#if 3 <= EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL

    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL < 3

    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL

#if 4 <= EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL

    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL < 4

    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define EXCEPTIONAL_CPP_STYLE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= EXCEPTIONAL_CPP_STYLE_ASSERT_LEVEL

#endif  // EXCEPTIONAL_CPP_STYLE_HELPER_EXCEPTIONAL_CPP_STYLE_CUSTOM_ASSERT_MACRO_H
