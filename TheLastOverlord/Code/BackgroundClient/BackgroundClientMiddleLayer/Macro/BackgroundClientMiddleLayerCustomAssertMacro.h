///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/22 23:08)

#ifndef BACKGROUND_CLIENT_MIDDLE_LAYER_MACRO_BACKGROUND_CLIENT_MIDDLE_LAYER_CUSTOM_ASSERT_MACRO_H
#define BACKGROUND_CLIENT_MIDDLE_LAYER_MACRO_BACKGROUND_CLIENT_MIDDLE_LAYER_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Contract/Assertion.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL)
    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL 4
#endif  // BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL

static_assert(BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL <= ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL

    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL < 0

    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL

#if 1 <= BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL

    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL < 1

    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL

#if 2 <= BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL

    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL < 2

    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL

#if 3 <= BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL

    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL < 3

    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL

#if 4 <= BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL

    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL < 4

    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= BACKGROUND_CLIENT_MIDDLE_LAYER_ASSERT_LEVEL

#endif  // BACKGROUND_CLIENT_MIDDLE_LAYER_MACRO_BACKGROUND_CLIENT_MIDDLE_LAYER_CUSTOM_ASSERT_MACRO_H
