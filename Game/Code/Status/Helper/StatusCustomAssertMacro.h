// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/05 21:46)

#ifndef STATUSMACRO_CUSTOM_ASSERT_MACRO_H
#define STATUSMACRO_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Contract/Assertion.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
	#define STATUSASSERT_LEVEL 0
#endif // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(STATUSASSERT_LEVEL)
	#define STATUSASSERT_LEVEL 4
#endif // STATUSASSERT_LEVEL

static_assert(STATUSASSERT_LEVEL <= ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= STATUSASSERT_LEVEL

#define STATUSASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
#define STATUSASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition),(functionDescribed),(format), __VA_ARGS__)

#else // STATUSASSERT_LEVEL < 0

#define STATUSASSERTION_0(condition, format, ...) ((void)0)
#define STATUSASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) ((void)0)

#endif // 0 <= STATUSASSERT_LEVEL

#if 1 <= STATUSASSERT_LEVEL

#define STATUSASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
#define STATUSASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition),(functionDescribed),(format), __VA_ARGS__)

#else // STATUSASSERT_LEVEL < 1

#define STATUSASSERTION_1(condition, format, ...) ((void)0)
#define STATUSASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) ((void)0)

#endif // 1 <= STATUSASSERT_LEVEL

#if 2 <= STATUSASSERT_LEVEL

#define STATUSASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
#define STATUSASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition),(functionDescribed),(format), __VA_ARGS__)

#else // STATUSASSERT_LEVEL < 2

#define STATUSASSERTION_2(condition, format, ...) ((void)0)
#define STATUSASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) ((void)0)

#endif // 2 <= STATUSASSERT_LEVEL

#if 3 <= STATUSASSERT_LEVEL

#define STATUSASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
#define STATUSASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition),(functionDescribed),(format), __VA_ARGS__)

#else // STATUSASSERT_LEVEL < 3

#define STATUSASSERTION_3(condition, format, ...) ((void)0)
#define STATUSASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) ((void)0)

#endif // 3 <= STATUSASSERT_LEVEL

#if 4 <= STATUSASSERT_LEVEL

#define STATUSASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
#define STATUSASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition),(functionDescribed),(format), __VA_ARGS__)

#else // STATUSASSERT_LEVEL < 4

#define STATUSASSERTION_4(condition, format, ...) ((void)0)
#define STATUSASSERTION_USE_FUNCTION_DESCRIBED_4(condition,functionDescribed,format, ...) ((void)0)

#endif // 4 <= STATUSASSERT_LEVEL

#endif // STATUSMACRO_CUSTOM_ASSERT_MACRO_H
