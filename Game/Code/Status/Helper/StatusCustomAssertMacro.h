///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/18 14:35)

#ifndef STATUSHELPER_CUSTOM_ASSERT_HELPER_H
#define STATUSHELPER_CUSTOM_ASSERT_HELPER_H

#include "UserMacro.h"
#include "CoreTools/Contract/Assertion.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define STATUSASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(STATUSASSERT_LEVEL)
    #define STATUSASSERT_LEVEL 4
#endif  // STATUSASSERT_LEVEL

static_assert(STATUSASSERT_LEVEL <= ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= STATUSASSERT_LEVEL

    #define STATUSASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
    #define STATUSASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // STATUSASSERT_LEVEL < 0

    #define STATUSASSERTION_0(condition, format, ...) ((void)0)
    #define STATUSASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) ((void)0)

#endif  // 0 <= STATUSASSERT_LEVEL

#if 1 <= STATUSASSERT_LEVEL

    #define STATUSASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
    #define STATUSASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // STATUSASSERT_LEVEL < 1

    #define STATUSASSERTION_1(condition, format, ...) ((void)0)
    #define STATUSASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) ((void)0)

#endif  // 1 <= STATUSASSERT_LEVEL

#if 2 <= STATUSASSERT_LEVEL

    #define STATUSASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
    #define STATUSASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // STATUSASSERT_LEVEL < 2

    #define STATUSASSERTION_2(condition, format, ...) ((void)0)
    #define STATUSASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) ((void)0)

#endif  // 2 <= STATUSASSERT_LEVEL

#if 3 <= STATUSASSERT_LEVEL

    #define STATUSASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
    #define STATUSASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // STATUSASSERT_LEVEL < 3

    #define STATUSASSERTION_3(condition, format, ...) ((void)0)
    #define STATUSASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) ((void)0)

#endif  // 3 <= STATUSASSERT_LEVEL

#if 4 <= STATUSASSERT_LEVEL

    #define STATUSASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
    #define STATUSASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // STATUSASSERT_LEVEL < 4

    #define STATUSASSERTION_4(condition, format, ...) ((void)0)
    #define STATUSASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) ((void)0)

#endif  // 4 <= STATUSASSERT_LEVEL

#endif  // STATUSHELPER_CUSTOM_ASSERT_HELPER_H
