///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.0 (2021/07/18 18:44)

#ifndef MULTIPLAYER_GAME_PROGRAMMING_HELPER_MULTIPLAYER_GAME_PROGRAMMING_CUSTOM_ASSERT_MACRO_H
#define MULTIPLAYER_GAME_PROGRAMMING_HELPER_MULTIPLAYER_GAME_PROGRAMMING_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL)
    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL 4
#endif  // MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL

constexpr auto g_MultiplayerGameProgrammingAssert = MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL;

static_assert(MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL

    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_DEBUG(condition, format, ...) \
        USER_ASSERTION_DEBUG((condition), (format), __VA_ARGS__)
    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        USER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL < 0

    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL

#if 1 <= MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL

    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL < 1

    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL

#if 2 <= MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL

    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL < 2

    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL

#if 3 <= MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL

    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL < 3

    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL

#if 4 <= MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL

    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL < 4

    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define MULTIPLAYER_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= MULTIPLAYER_GAME_PROGRAMMING_ASSERT_LEVEL

#endif  // MULTIPLAYER_GAME_PROGRAMMING_HELPER_MULTIPLAYER_GAME_PROGRAMMING_CUSTOM_ASSERT_MACRO_H
