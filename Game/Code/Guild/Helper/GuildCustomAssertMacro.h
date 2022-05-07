// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/05 23:12)

#ifndef GUILD_MACRO_CUSTOM_ASSERT_MACRO_H
#define GUILD_MACRO_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Contract/Assertion.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
	#define GUILD_ASSERT_LEVEL 0
#endif // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(GUILD_ASSERT_LEVEL)
	#define GUILD_ASSERT_LEVEL 4
#endif // GUILD_ASSERT_LEVEL

static_assert(GUILD_ASSERT_LEVEL <= ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= GUILD_ASSERT_LEVEL

#define GUILD_ASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
#define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition),(functionDescribed),(format), __VA_ARGS__)

#else // GUILD_ASSERT_LEVEL < 0

#define GUILD_ASSERTION_0(condition, format, ...) ((void)0)
#define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) ((void)0)

#endif // 0 <= GUILD_ASSERT_LEVEL

#if 1 <= GUILD_ASSERT_LEVEL

#define GUILD_ASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
#define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition),(functionDescribed),(format), __VA_ARGS__)

#else // GUILD_ASSERT_LEVEL < 1

#define GUILD_ASSERTION_1(condition, format, ...) ((void)0)
#define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) ((void)0)

#endif // 1 <= GUILD_ASSERT_LEVEL

#if 2 <= GUILD_ASSERT_LEVEL

#define GUILD_ASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
#define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition),(functionDescribed),(format), __VA_ARGS__)

#else // GUILD_ASSERT_LEVEL < 2

#define GUILD_ASSERTION_2(condition, format, ...) ((void)0)
#define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) ((void)0)

#endif // 2 <= GUILD_ASSERT_LEVEL

#if 3 <= GUILD_ASSERT_LEVEL

#define GUILD_ASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
#define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition),(functionDescribed),(format), __VA_ARGS__)

#else // GUILD_ASSERT_LEVEL < 3

#define GUILD_ASSERTION_3(condition, format, ...) ((void)0)
#define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) ((void)0)

#endif // 3 <= GUILD_ASSERT_LEVEL

#if 4 <= GUILD_ASSERT_LEVEL

#define GUILD_ASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
#define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition),(functionDescribed),(format), __VA_ARGS__)

#else // GUILD_ASSERT_LEVEL < 4

#define GUILD_ASSERTION_4(condition, format, ...) ((void)0)
#define GUILD_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition,functionDescribed,format, ...) ((void)0)

#endif // 4 <= GUILD_ASSERT_LEVEL

#endif // GUILD_MACRO_CUSTOM_ASSERT_MACRO_H