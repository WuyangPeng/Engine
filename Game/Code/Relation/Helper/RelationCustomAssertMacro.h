// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/05 21:54)

#ifndef RELATION_MACRO_CUSTOM_ASSERT_MACRO_H
#define RELATION_MACRO_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Contract/Assertion.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
	#define RELATION_ASSERT_LEVEL 0
#endif // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(RELATION_ASSERT_LEVEL)
	#define RELATION_ASSERT_LEVEL 4
#endif // RELATION_ASSERT_LEVEL

static_assert(RELATION_ASSERT_LEVEL <= ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= RELATION_ASSERT_LEVEL

#define RELATION_ASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
#define RELATION_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition),(functionDescribed),(format), __VA_ARGS__)

#else // RELATION_ASSERT_LEVEL < 0

#define RELATION_ASSERTION_0(condition, format, ...) ((void)0)
#define RELATION_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) ((void)0)

#endif // 0 <= RELATION_ASSERT_LEVEL

#if 1 <= RELATION_ASSERT_LEVEL

#define RELATION_ASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
#define RELATION_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition),(functionDescribed),(format), __VA_ARGS__)

#else // RELATION_ASSERT_LEVEL < 1

#define RELATION_ASSERTION_1(condition, format, ...) ((void)0)
#define RELATION_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) ((void)0)

#endif // 1 <= RELATION_ASSERT_LEVEL

#if 2 <= RELATION_ASSERT_LEVEL

#define RELATION_ASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
#define RELATION_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition),(functionDescribed),(format), __VA_ARGS__)

#else // RELATION_ASSERT_LEVEL < 2

#define RELATION_ASSERTION_2(condition, format, ...) ((void)0)
#define RELATION_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) ((void)0)

#endif // 2 <= RELATION_ASSERT_LEVEL

#if 3 <= RELATION_ASSERT_LEVEL

#define RELATION_ASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
#define RELATION_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition),(functionDescribed),(format), __VA_ARGS__)

#else // RELATION_ASSERT_LEVEL < 3

#define RELATION_ASSERTION_3(condition, format, ...) ((void)0)
#define RELATION_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) ((void)0)

#endif // 3 <= RELATION_ASSERT_LEVEL

#if 4 <= RELATION_ASSERT_LEVEL

#define RELATION_ASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
#define RELATION_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition),(functionDescribed),(format), __VA_ARGS__)

#else // RELATION_ASSERT_LEVEL < 4

#define RELATION_ASSERTION_4(condition, format, ...) ((void)0)
#define RELATION_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition,functionDescribed,format, ...) ((void)0)

#endif // 4 <= RELATION_ASSERT_LEVEL

#endif // RELATION_MACRO_CUSTOM_ASSERT_MACRO_H
