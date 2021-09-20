// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/06 20:19)

#ifndef CHAT_MACRO_CUSTOM_ASSERT_MACRO_H
#define CHAT_MACRO_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Contract/Assertion.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
	#define CHAT_ASSERT_LEVEL 0
#endif // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(CHAT_ASSERT_LEVEL)
	#define CHAT_ASSERT_LEVEL 4
#endif // CHAT_ASSERT_LEVEL

static_assert(CHAT_ASSERT_LEVEL <= ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= CHAT_ASSERT_LEVEL

#define CHAT_ASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
#define CHAT_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition),(functionDescribed),(format), __VA_ARGS__)

#else // CHAT_ASSERT_LEVEL < 0

#define CHAT_ASSERTION_0(condition, format, ...) ((void)0)
#define CHAT_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) ((void)0)

#endif // 0 <= CHAT_ASSERT_LEVEL

#if 1 <= CHAT_ASSERT_LEVEL

#define CHAT_ASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
#define CHAT_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition),(functionDescribed),(format), __VA_ARGS__)

#else // CHAT_ASSERT_LEVEL < 1

#define CHAT_ASSERTION_1(condition, format, ...) ((void)0)
#define CHAT_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) ((void)0)

#endif // 1 <= CHAT_ASSERT_LEVEL

#if 2 <= CHAT_ASSERT_LEVEL

#define CHAT_ASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
#define CHAT_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition),(functionDescribed),(format), __VA_ARGS__)

#else // CHAT_ASSERT_LEVEL < 2

#define CHAT_ASSERTION_2(condition, format, ...) ((void)0)
#define CHAT_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) ((void)0)

#endif // 2 <= CHAT_ASSERT_LEVEL

#if 3 <= CHAT_ASSERT_LEVEL

#define CHAT_ASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
#define CHAT_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition),(functionDescribed),(format), __VA_ARGS__)

#else // CHAT_ASSERT_LEVEL < 3

#define CHAT_ASSERTION_3(condition, format, ...) ((void)0)
#define CHAT_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) ((void)0)

#endif // 3 <= CHAT_ASSERT_LEVEL

#if 4 <= CHAT_ASSERT_LEVEL

#define CHAT_ASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
#define CHAT_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition),(functionDescribed),(format), __VA_ARGS__)

#else // CHAT_ASSERT_LEVEL < 4

#define CHAT_ASSERTION_4(condition, format, ...) ((void)0)
#define CHAT_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition,functionDescribed,format, ...) ((void)0)

#endif // 4 <= CHAT_ASSERT_LEVEL

#endif // CHAT_MACRO_CUSTOM_ASSERT_MACRO_H
