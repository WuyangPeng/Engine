///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/27 22:16)

#ifndef RECHARGE_SERVER_MIDDLE_LAYER_MACRO_RECHARGE_SERVER_MIDDLE_LAYER_CUSTOM_ASSERT_MACRO_H
#define RECHARGE_SERVER_MIDDLE_LAYER_MACRO_RECHARGE_SERVER_MIDDLE_LAYER_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/CustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCEPTION_ASSERT)
    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCEPTION_ASSERT

#if !defined(RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL)
    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL 4
#endif  // RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

static_assert(RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL <= ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL < 0

    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#if 1 <= RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL < 1

    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#if 2 <= RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL < 2

    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#if 3 <= RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL < 3

    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#if 4 <= RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL < 4

    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define RECHARGE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= RECHARGE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#endif  // RECHARGE_SERVER_MIDDLE_LAYER_MACRO_RECHARGE_SERVER_MIDDLE_LAYER_CUSTOM_ASSERT_MACRO_H
