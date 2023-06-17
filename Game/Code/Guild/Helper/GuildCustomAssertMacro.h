///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.9.0.12 (2023/06/16 16:57)

#ifndef GUILD_HELPER_CUSTOM_ASSERT_HELPER_H
#define GUILD_HELPER_CUSTOM_ASSERT_HELPER_H

#include "UserMacro.h"
#include "CoreTools/Contract/Assertion.h"
#include "CoreTools/Helper/CustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCEPTION_ASSERT)

    #define GUILD_ASSERT_LEVEL 0

#endif  // OPEN_IMPORTANT_EXCEPTION_ASSERT

#if !defined(GUILD_ASSERT_LEVEL)

    #define GUILD_ASSERT_LEVEL 4

#endif  // GUILD_ASSERT_LEVEL

static_assert(GUILD_ASSERT_LEVEL <= ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= GUILD_ASSERT_LEVEL

    #define GUILD_ASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
    #define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // GUILD_ASSERT_LEVEL < 0

    #define GUILD_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= GUILD_ASSERT_LEVEL

#if 1 <= GUILD_ASSERT_LEVEL

    #define GUILD_ASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
    #define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // GUILD_ASSERT_LEVEL < 1

    #define GUILD_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= GUILD_ASSERT_LEVEL

#if 2 <= GUILD_ASSERT_LEVEL

    #define GUILD_ASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
    #define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // GUILD_ASSERT_LEVEL < 2

    #define GUILD_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= GUILD_ASSERT_LEVEL

#if 3 <= GUILD_ASSERT_LEVEL

    #define GUILD_ASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
    #define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // GUILD_ASSERT_LEVEL < 3

    #define GUILD_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= GUILD_ASSERT_LEVEL

#if 4 <= GUILD_ASSERT_LEVEL

    #define GUILD_ASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
    #define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // GUILD_ASSERT_LEVEL < 4

    #define GUILD_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= GUILD_ASSERT_LEVEL

#endif  // GUILD_HELPER_CUSTOM_ASSERT_HELPER_H
