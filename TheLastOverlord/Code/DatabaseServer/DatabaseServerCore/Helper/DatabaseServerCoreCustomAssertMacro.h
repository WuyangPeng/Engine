/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/18 17:09)

#ifndef DATABASE_SERVER_CORE_HELPER_DATABASE_SERVER_CORE_CUSTOM_ASSERT_MACRO_H
#define DATABASE_SERVER_CORE_HELPER_DATABASE_SERVER_CORE_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/CustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCEPTION_ASSERT)

    #define DATABASE_SERVER_CORE_ASSERT_LEVEL 0

#endif  // OPEN_IMPORTANT_EXCEPTION_ASSERT

#if !defined(DATABASE_SERVER_CORE_ASSERT_LEVEL)

    #define DATABASE_SERVER_CORE_ASSERT_LEVEL 4

#endif  // DATABASE_SERVER_CORE_ASSERT_LEVEL

static_assert(DATABASE_SERVER_CORE_ASSERT_LEVEL <= ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= DATABASE_SERVER_CORE_ASSERT_LEVEL

    #define DATABASE_SERVER_CORE_ASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
    #define DATABASE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // DATABASE_SERVER_CORE_ASSERT_LEVEL < 0

    #define DATABASE_SERVER_CORE_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define DATABASE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= DATABASE_SERVER_CORE_ASSERT_LEVEL

#if 1 <= DATABASE_SERVER_CORE_ASSERT_LEVEL

    #define DATABASE_SERVER_CORE_ASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
    #define DATABASE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // DATABASE_SERVER_CORE_ASSERT_LEVEL < 1

    #define DATABASE_SERVER_CORE_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define DATABASE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= DATABASE_SERVER_CORE_ASSERT_LEVEL

#if 2 <= DATABASE_SERVER_CORE_ASSERT_LEVEL

    #define DATABASE_SERVER_CORE_ASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
    #define DATABASE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // DATABASE_SERVER_CORE_ASSERT_LEVEL < 2

    #define DATABASE_SERVER_CORE_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define DATABASE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= DATABASE_SERVER_CORE_ASSERT_LEVEL

#if 3 <= DATABASE_SERVER_CORE_ASSERT_LEVEL

    #define DATABASE_SERVER_CORE_ASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
    #define DATABASE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // DATABASE_SERVER_CORE_ASSERT_LEVEL < 3

    #define DATABASE_SERVER_CORE_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define DATABASE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= DATABASE_SERVER_CORE_ASSERT_LEVEL

#if 4 <= DATABASE_SERVER_CORE_ASSERT_LEVEL

    #define DATABASE_SERVER_CORE_ASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
    #define DATABASE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // DATABASE_SERVER_CORE_ASSERT_LEVEL < 4

    #define DATABASE_SERVER_CORE_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define DATABASE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= DATABASE_SERVER_CORE_ASSERT_LEVEL

#endif  // DATABASE_SERVER_CORE_HELPER_DATABASE_SERVER_CORE_CUSTOM_ASSERT_MACRO_H
