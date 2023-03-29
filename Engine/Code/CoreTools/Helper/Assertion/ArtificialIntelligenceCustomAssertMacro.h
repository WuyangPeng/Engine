///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:42)

#ifndef CORE_TOOLS_HELPER_ARTIFICIAL_INTELLIGENCE_CUSTOM_ASSERT_MACRO_H
#define CORE_TOOLS_HELPER_ARTIFICIAL_INTELLIGENCE_CUSTOM_ASSERT_MACRO_H

#include "CoreTools/Contract/AssertionDetail.h"

#if defined(OPEN_IMPORTANT_EXCEPTION_ASSERT)

    #define ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL 0

#endif  // OPEN_IMPORTANT_EXCEPTION_ASSERT

#if !defined(ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL)

    #define ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL 4

#endif  // ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL

constexpr auto gArtificialIntellegenceAssert = ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL;

static_assert(ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL <= ASSERT_LEVEL, "Artificial Intellegence assert level definition error.");

#if 0 <= ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL

    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_0(condition, format, ...) \
        ASSERTION_0(condition, format, __VA_ARGS__)
    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, __VA_ARGS__)

    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_DEBUG(condition, format, ...) \
        ASSERTION_DEBUG(condition, format, __VA_ARGS__)
    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, __VA_ARGS__)

#else  // ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL < 0

    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  //0 <= ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL

#if 1 <= ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL

    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_1(condition, format, ...) \
        ASSERTION_1(condition, format, __VA_ARGS__)
    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, __VA_ARGS__)

#else  // ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL < 1

    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL

#if 2 <= ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL

    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_2(condition, format, ...) \
        ASSERTION_2(condition, format, __VA_ARGS__)
    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, __VA_ARGS__)

#else  // ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL < 2

    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL

#if 3 <= ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL

    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_3(condition, format, ...) \
        ASSERTION_3(condition, format, __VA_ARGS__)
    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, __VA_ARGS__)

#else  // ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL < 3

    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL

#if 4 <= ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL

    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_4(condition, format, ...) \
        ASSERTION_4(condition, format, __VA_ARGS__)
    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, __VA_ARGS__)

#else  // ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL < 4

    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define ARTIFICIAL_INTELLIGENCE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= ARTIFICIAL_INTELLIGENCE_ASSERT_LEVEL

#endif  // CORE_TOOLS_HELPER_CUSTOM_ASSERT_MACRO_H
