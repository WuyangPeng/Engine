//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/09/28 13:26)

#ifndef CORE_TOOLS_HELPER_MATHEMATICS_CUSTOM_ASSERT_MACRO_H
#define CORE_TOOLS_HELPER_MATHEMATICS_CUSTOM_ASSERT_MACRO_H

#include "CoreTools/Contract/Assertion.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define MATHEMATICS_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(MATHEMATICS_ASSERT_LEVEL)
    #define MATHEMATICS_ASSERT_LEVEL 4
#endif  // MATHEMATICS_ASSERT_LEVEL

constexpr auto g_MathematicsAssert = MATHEMATICS_ASSERT_LEVEL;

static_assert(MATHEMATICS_ASSERT_LEVEL <= ASSERT_LEVEL, "Mathematics assert level definition error.");

#if 0 <= MATHEMATICS_ASSERT_LEVEL

    #define MATHEMATICS_ASSERTION_0(condition, format, ...) \
        ASSERTION_0(condition, format, __VA_ARGS__)
    #define MATHEMATICS_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, __VA_ARGS__)

    #define MATHEMATICS_ASSERTION_DEBUG(condition, format, ...) \
        ASSERTION_DEBUG(condition, format, __VA_ARGS__)
    #define MATHEMATICS_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, __VA_ARGS__)

#else  // MATHEMATICS_ASSERT_LEVEL < 0

    #define MATHEMATICS_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define MATHEMATICS_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define MATHEMATICS_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define MATHEMATICS_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  //0 <= MATHEMATICS_ASSERT_LEVEL

#if 1 <= MATHEMATICS_ASSERT_LEVEL

    #define MATHEMATICS_ASSERTION_1(condition, format, ...) \
        ASSERTION_1(condition, format, __VA_ARGS__)
    #define MATHEMATICS_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, __VA_ARGS__)

#else  // MATHEMATICS_ASSERT_LEVEL < 1

    #define MATHEMATICS_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define MATHEMATICS_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= MATHEMATICS_ASSERT_LEVEL

#if 2 <= MATHEMATICS_ASSERT_LEVEL

    #define MATHEMATICS_ASSERTION_2(condition, format, ...) \
        ASSERTION_2(condition, format, __VA_ARGS__)
    #define MATHEMATICS_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, __VA_ARGS__)

#else  // MATHEMATICS_ASSERT_LEVEL < 2

    #define MATHEMATICS_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define MATHEMATICS_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= MATHEMATICS_ASSERT_LEVEL

#if 3 <= MATHEMATICS_ASSERT_LEVEL

    #define MATHEMATICS_ASSERTION_3(condition, format, ...) \
        ASSERTION_3(condition, format, __VA_ARGS__)
    #define MATHEMATICS_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, __VA_ARGS__)

#else  // MATHEMATICS_ASSERT_LEVEL < 3

    #define MATHEMATICS_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define MATHEMATICS_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= MATHEMATICS_ASSERT_LEVEL

#if 4 <= MATHEMATICS_ASSERT_LEVEL

    #define MATHEMATICS_ASSERTION_4(condition, format, ...) \
        ASSERTION_4(condition, format, __VA_ARGS__)
    #define MATHEMATICS_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, __VA_ARGS__)

#else  // MATHEMATICS_ASSERT_LEVEL < 4

    #define MATHEMATICS_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define MATHEMATICS_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= MATHEMATICS_ASSERT_LEVEL

#endif  // CORE_TOOLS_HELPER_CUSTOM_ASSERT_MACRO_H
