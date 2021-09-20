///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/07/28 15:23)

#ifndef CORE_TOOLS_EXAMPLE_HELPER_CORE_TOOLS_EXAMPLE_CUSTOM_ASSERT_MACRO_H
#define CORE_TOOLS_EXAMPLE_HELPER_CORE_TOOLS_EXAMPLE_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define CORE_TOOLS_EXAMPLE_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

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
