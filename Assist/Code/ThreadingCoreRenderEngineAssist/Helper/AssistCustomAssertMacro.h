/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/18 18:19)

#ifndef THREADING_CORE_RENDER_ENGINE_ASSIST_ASSIST_CUSTOM_ASSERT_MACRO_H
#define THREADING_CORE_RENDER_ENGINE_ASSIST_ASSIST_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCEPTION_ASSERT)

    #define ASSIST_ASSERT_LEVEL 0

#endif  // OPEN_IMPORTANT_EXCEPTION_ASSERT

#if !defined(ASSIST_ASSERT_LEVEL)

    #define ASSIST_ASSERT_LEVEL 4

#endif  // ASSIST_ASSERT_LEVEL

static_assert(ASSIST_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= ASSIST_ASSERT_LEVEL

    #define ASSIST_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define ASSIST_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

    #define ASSIST_ASSERTION_DEBUG(condition, format, ...) \
        USER_ASSERTION_DEBUG((condition), (format), __VA_ARGS__)
    #define ASSIST_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        USER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ASSIST_ASSERT_LEVEL < 0

    #define ASSIST_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define ASSIST_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define ASSIST_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define ASSIST_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= ASSIST_ASSERT_LEVEL

#if 1 <= ASSIST_ASSERT_LEVEL

    #define ASSIST_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define ASSIST_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ASSIST_ASSERT_LEVEL < 1

    #define ASSIST_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define ASSIST_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= ASSIST_ASSERT_LEVEL

#if 2 <= ASSIST_ASSERT_LEVEL

    #define ASSIST_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define ASSIST_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ASSIST_ASSERT_LEVEL < 2

    #define ASSIST_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define ASSIST_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= ASSIST_ASSERT_LEVEL

#if 3 <= ASSIST_ASSERT_LEVEL

    #define ASSIST_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define ASSIST_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ASSIST_ASSERT_LEVEL < 3

    #define ASSIST_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define ASSIST_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= ASSIST_ASSERT_LEVEL

#if 4 <= ASSIST_ASSERT_LEVEL

    #define ASSIST_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define ASSIST_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // ASSIST_ASSERT_LEVEL < 4

    #define ASSIST_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define ASSIST_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= ASSIST_ASSERT_LEVEL

#endif  // THREADING_CORE_RENDER_ENGINE_ASSIST_ASSIST_CUSTOM_ASSERT_MACRO_H
