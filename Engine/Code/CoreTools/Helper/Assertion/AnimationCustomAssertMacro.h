/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 11:08)

#ifndef CORE_TOOLS_HELPER_ANIMATION_CUSTOM_ASSERT_MACRO_H
#define CORE_TOOLS_HELPER_ANIMATION_CUSTOM_ASSERT_MACRO_H

#include "CoreTools/Contract/AssertionDetail.h"

#if defined(OPEN_IMPORTANT_EXCEPTION_ASSERT)

    #define ANIMATION_ASSERT_LEVEL 0

#endif  // OPEN_IMPORTANT_EXCEPTION_ASSERT

#if !defined(ANIMATION_ASSERT_LEVEL)

    #define ANIMATION_ASSERT_LEVEL 4

#endif  // ANIMATION_ASSERT_LEVEL

constexpr auto gAnimationAssert = ANIMATION_ASSERT_LEVEL;

static_assert(ANIMATION_ASSERT_LEVEL <= ASSERT_LEVEL, "Animation assert level definition error.");

#if 0 <= ANIMATION_ASSERT_LEVEL

    #define ANIMATION_ASSERTION_0(condition, format, ...) \
        ASSERTION_0(condition, format, __VA_ARGS__)
    #define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, __VA_ARGS__)

    #define ANIMATION_ASSERTION_DEBUG(condition, format, ...) \
        ASSERTION_DEBUG(condition, format, __VA_ARGS__)
    #define ANIMATION_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, __VA_ARGS__)

#else  // ANIMATION_ASSERT_LEVEL < 0

    #define ANIMATION_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define ANIMATION_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define ANIMATION_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= ANIMATION_ASSERT_LEVEL

#if 1 <= ANIMATION_ASSERT_LEVEL

    #define ANIMATION_ASSERTION_1(condition, format, ...) \
        ASSERTION_1(condition, format, __VA_ARGS__)
    #define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, __VA_ARGS__)

#else  // ANIMATION_ASSERT_LEVEL < 1

    #define ANIMATION_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= ANIMATION_ASSERT_LEVEL

#if 2 <= ANIMATION_ASSERT_LEVEL

    #define ANIMATION_ASSERTION_2(condition, format, ...) \
        ASSERTION_2(condition, format, __VA_ARGS__)
    #define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, __VA_ARGS__)

#else  // ANIMATION_ASSERT_LEVEL < 2

    #define ANIMATION_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= ANIMATION_ASSERT_LEVEL

#if 3 <= ANIMATION_ASSERT_LEVEL

    #define ANIMATION_ASSERTION_3(condition, format, ...) \
        ASSERTION_3(condition, format, __VA_ARGS__)
    #define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, __VA_ARGS__)

#else  // ANIMATION_ASSERT_LEVEL < 3

    #define ANIMATION_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= ANIMATION_ASSERT_LEVEL

#if 4 <= ANIMATION_ASSERT_LEVEL

    #define ANIMATION_ASSERTION_4(condition, format, ...) \
        ASSERTION_4(condition, format, __VA_ARGS__)
    #define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, __VA_ARGS__)

#else  // ANIMATION_ASSERT_LEVEL < 4

    #define ANIMATION_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= ANIMATION_ASSERT_LEVEL

#endif  // CORE_TOOLS_HELPER_CUSTOM_ASSERT_MACRO_H
