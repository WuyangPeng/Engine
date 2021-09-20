// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.3.0 (2020/03/24 23:26)

#ifndef DESIGN_PATTERNS_EXPLAINED_DESIGN_PATTERNS_EXPLAINED_CUSTOM_ASSERT_MACRO_H
#define DESIGN_PATTERNS_EXPLAINED_DESIGN_PATTERNS_EXPLAINED_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
	#define DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL 0
#endif // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL)
	#define DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL 4
#endif // DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL

static_assert(DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL

	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_0(condition, format, ...) \
			USER_ASSERTION_0((condition), (format), __VA_ARGS__)
	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) \
			USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition),(functionDescribed),(format), __VA_ARGS__)

	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_DEBUG(condition, format, ...) \
			USER_ASSERTION_DEBUG((condition), (format), __VA_ARGS__)
	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, ...) \
			USER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED((condition),(functionDescribed),(format), __VA_ARGS__)

#else // DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL < 0

	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_0(condition, format, ...) ((void)0)
	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) ((void)0)

	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_DEBUG(condition, format, ...) ((void)0)
	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, ...) ((void)0)

#endif // 0 <= DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL

#if 1 <= DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL

	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_1(condition, format, ...) \
			USER_ASSERTION_1((condition), (format), __VA_ARGS__)
	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) \
			USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition),(functionDescribed),(format), __VA_ARGS__)

#else // DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL < 1

	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_1(condition, format, ...) ((void)0)
	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) ((void)0)

#endif // 1 <= DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL

#if 2 <= DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL

	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_2(condition, format, ...) \
			USER_ASSERTION_2((condition), (format), __VA_ARGS__)
	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) \
			USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition),(functionDescribed),(format), __VA_ARGS__)

#else // DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL < 2

	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_2(condition, format, ...) ((void)0)
	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) ((void)0)

#endif // 2 <= DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL

#if 3 <= DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL

	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_3(condition, format, ...) \
			USER_ASSERTION_3((condition), (format), __VA_ARGS__)
	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) \
			USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition),(functionDescribed),(format), __VA_ARGS__)

#else // DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL < 3

	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_3(condition, format, ...) ((void)0)
	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) ((void)0)

#endif // 3 <= DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL

#if 4 <= DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL

	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_4(condition, format, ...) \
			USER_ASSERTION_4((condition), (format), __VA_ARGS__)
	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
			USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition),(functionDescribed),(format), __VA_ARGS__)

#else // DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL < 4

	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_4(condition, format, ...) ((void)0)
	#define DESIGN_PATTERNS_EXPLAINED_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition,functionDescribed,format, ...) ((void)0)

#endif // 4 <= DESIGN_PATTERNS_EXPLAINED_ASSERT_LEVEL

#endif // DESIGN_PATTERNS_EXPLAINED_DESIGN_PATTERNS_EXPLAINED_CUSTOM_ASSERT_MACRO_H
