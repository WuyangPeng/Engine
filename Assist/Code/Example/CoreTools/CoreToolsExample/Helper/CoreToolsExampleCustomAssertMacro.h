///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.4 (2023/03/14 15:49)

#ifndef CORE_TOOLS_EXAMPLE_HELPER_CORE_TOOLS_EXAMPLE_CUSTOM_ASSERT_MACRO_H
#define CORE_TOOLS_EXAMPLE_HELPER_CORE_TOOLS_EXAMPLE_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCEPTION_ASSERT)

    #define CORE_TOOLS_EXAMPLE_ASSERT_LEVEL 0

#endif  // OPEN_IMPORTANT_EXCEPTION_ASSERT

#if !defined(CORE_TOOLS_EXAMPLE_ASSERT_LEVEL)

    #define CORE_TOOLS_EXAMPLE_ASSERT_LEVEL 4

#endif  // CORE_TOOLS_EXAMPLE_ASSERT_LEVEL

constexpr auto g_CoreToolsExampleAssert = CORE_TOOLS_EXAMPLE_ASSERT_LEVEL;

static_assert(CORE_TOOLS_EXAMPLE_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= CORE_TOOLS_EXAMPLE_ASSERT_LEVEL

    #define CORE_TOOLS_EXAMPLE_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define CORE_TOOLS_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CORE_TOOLS_EXAMPLE_ASSERT_LEVEL < 0

    #define CORE_TOOLS_EXAMPLE_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define CORE_TOOLS_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= CORE_TOOLS_EXAMPLE_ASSERT_LEVEL

#if 1 <= CORE_TOOLS_EXAMPLE_ASSERT_LEVEL

    #define CORE_TOOLS_EXAMPLE_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define CORE_TOOLS_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CORE_TOOLS_EXAMPLE_ASSERT_LEVEL < 1

    #define CORE_TOOLS_EXAMPLE_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define CORE_TOOLS_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= CORE_TOOLS_EXAMPLE_ASSERT_LEVEL

#if 2 <= CORE_TOOLS_EXAMPLE_ASSERT_LEVEL

    #define CORE_TOOLS_EXAMPLE_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define CORE_TOOLS_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CORE_TOOLS_EXAMPLE_ASSERT_LEVEL < 2

    #define CORE_TOOLS_EXAMPLE_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define CORE_TOOLS_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= CORE_TOOLS_EXAMPLE_ASSERT_LEVEL

#if 3 <= CORE_TOOLS_EXAMPLE_ASSERT_LEVEL

    #define CORE_TOOLS_EXAMPLE_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define CORE_TOOLS_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CORE_TOOLS_EXAMPLE_ASSERT_LEVEL < 3

    #define CORE_TOOLS_EXAMPLE_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define CORE_TOOLS_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= CORE_TOOLS_EXAMPLE_ASSERT_LEVEL

#if 4 <= CORE_TOOLS_EXAMPLE_ASSERT_LEVEL

    #define CORE_TOOLS_EXAMPLE_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define CORE_TOOLS_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CORE_TOOLS_EXAMPLE_ASSERT_LEVEL < 4

    #define CORE_TOOLS_EXAMPLE_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define CORE_TOOLS_EXAMPLE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= CORE_TOOLS_EXAMPLE_ASSERT_LEVEL

#endif  // CORE_TOOLS_EXAMPLE_HELPER_CORE_TOOLS_EXAMPLE_CUSTOM_ASSERT_MACRO_H
