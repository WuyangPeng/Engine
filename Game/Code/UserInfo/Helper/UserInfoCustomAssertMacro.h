///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/14 14:09)

#ifndef USER_INFO_HELPER_CUSTOM_ASSERT_HELPER_H
#define USER_INFO_HELPER_CUSTOM_ASSERT_HELPER_H

#include "UserMacro.h"
#include "CoreTools/Contract/Assertion.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define USER_INFO_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(USER_INFO_ASSERT_LEVEL)
    #define USER_INFO_ASSERT_LEVEL 4
#endif  // USER_INFO_ASSERT_LEVEL

static_assert(USER_INFO_ASSERT_LEVEL <= ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= USER_INFO_ASSERT_LEVEL

    #define USER_INFO_ASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
    #define USER_INFO_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // USER_INFO_ASSERT_LEVEL < 0

    #define USER_INFO_ASSERTION_0(condition, format, ...) ((void)0)
    #define USER_INFO_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) ((void)0)

#endif  // 0 <= USER_INFO_ASSERT_LEVEL

#if 1 <= USER_INFO_ASSERT_LEVEL

    #define USER_INFO_ASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
    #define USER_INFO_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // USER_INFO_ASSERT_LEVEL < 1

    #define USER_INFO_ASSERTION_1(condition, format, ...) ((void)0)
    #define USER_INFO_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) ((void)0)

#endif  // 1 <= USER_INFO_ASSERT_LEVEL

#if 2 <= USER_INFO_ASSERT_LEVEL

    #define USER_INFO_ASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
    #define USER_INFO_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // USER_INFO_ASSERT_LEVEL < 2

    #define USER_INFO_ASSERTION_2(condition, format, ...) ((void)0)
    #define USER_INFO_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) ((void)0)

#endif  // 2 <= USER_INFO_ASSERT_LEVEL

#if 3 <= USER_INFO_ASSERT_LEVEL

    #define USER_INFO_ASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
    #define USER_INFO_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // USER_INFO_ASSERT_LEVEL < 3

    #define USER_INFO_ASSERTION_3(condition, format, ...) ((void)0)
    #define USER_INFO_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) ((void)0)

#endif  // 3 <= USER_INFO_ASSERT_LEVEL

#if 4 <= USER_INFO_ASSERT_LEVEL

    #define USER_INFO_ASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
    #define USER_INFO_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // USER_INFO_ASSERT_LEVEL < 4

    #define USER_INFO_ASSERTION_4(condition, format, ...) ((void)0)
    #define USER_INFO_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) ((void)0)

#endif  // 4 <= USER_INFO_ASSERT_LEVEL

#endif  // USER_INFO_HELPER_CUSTOM_ASSERT_HELPER_H
