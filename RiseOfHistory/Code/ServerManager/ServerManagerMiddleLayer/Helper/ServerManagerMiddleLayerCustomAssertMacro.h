/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/06/20 15:48)

#ifndef SERVER_MANAGER_MIDDLE_LAYER_HELPER_SERVER_MANAGER_MIDDLE_LAYER_CUSTOM_ASSERT_MACRO_H
#define SERVER_MANAGER_MIDDLE_LAYER_HELPER_SERVER_MANAGER_MIDDLE_LAYER_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Contract/Assertion.h"
#include "CoreTools/Helper/CustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCEPTION_ASSERT)

    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL 0

#endif  // OPEN_IMPORTANT_EXCEPTION_ASSERT

#if !defined(SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL)

    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL 4

#endif  // SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL

static_assert(SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL <= ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL

    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL < 0

    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL

#if 1 <= SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL

    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL < 1

    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL

#if 2 <= SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL

    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL < 2

    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL

#if 3 <= SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL

    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL < 3

    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL

#if 4 <= SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL

    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL < 4

    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define SERVER_MANAGER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= SERVER_MANAGER_MIDDLE_LAYER_ASSERT_LEVEL

#endif  // SERVER_MANAGER_MIDDLE_LAYER_HELPER_SERVER_MANAGER_MIDDLE_LAYER_CUSTOM_ASSERT_MACRO_H
