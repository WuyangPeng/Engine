///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.1.3 (2022/10/24 22:42)

#ifndef SYSTEM_TOOLSET_HELPER_SYSTEM_TOOLSET_CUSTOM_ASSERT_MACRO_H
#define SYSTEM_TOOLSET_HELPER_SYSTEM_TOOLSET_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCEPTION_ASSERT)
    #define SYSTEM_TOOLSET_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCEPTION_ASSERT

#if !defined(SYSTEM_TOOLSET_ASSERT_LEVEL)
    #define SYSTEM_TOOLSET_ASSERT_LEVEL 4
#endif  // SYSTEM_TOOLSET_ASSERT_LEVEL

constexpr auto g_SystemToolsetAssert = SYSTEM_TOOLSET_ASSERT_LEVEL;

static_assert(SYSTEM_TOOLSET_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= SYSTEM_TOOLSET_ASSERT_LEVEL

    #define SYSTEM_TOOLSET_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define SYSTEM_TOOLSET_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SYSTEM_TOOLSET_ASSERT_LEVEL < 0

    #define SYSTEM_TOOLSET_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define SYSTEM_TOOLSET_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= SYSTEM_TOOLSET_ASSERT_LEVEL

#if 1 <= SYSTEM_TOOLSET_ASSERT_LEVEL

    #define SYSTEM_TOOLSET_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define SYSTEM_TOOLSET_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SYSTEM_TOOLSET_ASSERT_LEVEL < 1

    #define SYSTEM_TOOLSET_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define SYSTEM_TOOLSET_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= SYSTEM_TOOLSET_ASSERT_LEVEL

#if 2 <= SYSTEM_TOOLSET_ASSERT_LEVEL

    #define SYSTEM_TOOLSET_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define SYSTEM_TOOLSET_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SYSTEM_TOOLSET_ASSERT_LEVEL < 2

    #define SYSTEM_TOOLSET_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define SYSTEM_TOOLSET_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= SYSTEM_TOOLSET_ASSERT_LEVEL

#if 3 <= SYSTEM_TOOLSET_ASSERT_LEVEL

    #define SYSTEM_TOOLSET_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define SYSTEM_TOOLSET_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SYSTEM_TOOLSET_ASSERT_LEVEL < 3

    #define SYSTEM_TOOLSET_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define SYSTEM_TOOLSET_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= SYSTEM_TOOLSET_ASSERT_LEVEL

#if 4 <= SYSTEM_TOOLSET_ASSERT_LEVEL

    #define SYSTEM_TOOLSET_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define SYSTEM_TOOLSET_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SYSTEM_TOOLSET_ASSERT_LEVEL < 4

    #define SYSTEM_TOOLSET_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define SYSTEM_TOOLSET_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= SYSTEM_TOOLSET_ASSERT_LEVEL

#endif  // SYSTEM_TOOLSET_HELPER_SYSTEM_TOOLSET_CUSTOM_ASSERT_MACRO_H
