// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/06 20:43)

#ifndef ARENA_MACRO_CUSTOM_ASSERT_MACRO_H
#define ARENA_MACRO_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Contract/Assertion.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
	#define ARENA_ASSERT_LEVEL 0
#endif // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(ARENA_ASSERT_LEVEL)
	#define ARENA_ASSERT_LEVEL 4
#endif // ARENA_ASSERT_LEVEL

static_assert(ARENA_ASSERT_LEVEL <= ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= ARENA_ASSERT_LEVEL

#define ARENA_ASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
#define ARENA_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition),(functionDescribed),(format), __VA_ARGS__)

#else // ARENA_ASSERT_LEVEL < 0

#define ARENA_ASSERTION_0(condition, format, ...) ((void)0)
#define ARENA_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) ((void)0)

#endif // 0 <= ARENA_ASSERT_LEVEL

#if 1 <= ARENA_ASSERT_LEVEL

#define ARENA_ASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
#define ARENA_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition),(functionDescribed),(format), __VA_ARGS__)

#else // ARENA_ASSERT_LEVEL < 1

#define ARENA_ASSERTION_1(condition, format, ...) ((void)0)
#define ARENA_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) ((void)0)

#endif // 1 <= ARENA_ASSERT_LEVEL

#if 2 <= ARENA_ASSERT_LEVEL

#define ARENA_ASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
#define ARENA_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition),(functionDescribed),(format), __VA_ARGS__)

#else // ARENA_ASSERT_LEVEL < 2

#define ARENA_ASSERTION_2(condition, format, ...) ((void)0)
#define ARENA_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) ((void)0)

#endif // 2 <= ARENA_ASSERT_LEVEL

#if 3 <= ARENA_ASSERT_LEVEL

#define ARENA_ASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
#define ARENA_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition),(functionDescribed),(format), __VA_ARGS__)

#else // ARENA_ASSERT_LEVEL < 3

#define ARENA_ASSERTION_3(condition, format, ...) ((void)0)
#define ARENA_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) ((void)0)

#endif // 3 <= ARENA_ASSERT_LEVEL

#if 4 <= ARENA_ASSERT_LEVEL

#define ARENA_ASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
#define ARENA_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition),(functionDescribed),(format), __VA_ARGS__)

#else // ARENA_ASSERT_LEVEL < 4

#define ARENA_ASSERTION_4(condition, format, ...) ((void)0)
#define ARENA_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition,functionDescribed,format, ...) ((void)0)

#endif // 4 <= ARENA_ASSERT_LEVEL

#endif // ARENA_MACRO_CUSTOM_ASSERT_MACRO_H
