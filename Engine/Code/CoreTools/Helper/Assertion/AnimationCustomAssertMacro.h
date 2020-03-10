// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 10:10)

#ifndef CORE_TOOLS_HELPER_ANIMATION_CUSTOM_ASSERT_MACRO_H
#define CORE_TOOLS_HELPER_ANIMATION_CUSTOM_ASSERT_MACRO_H

#include "CoreTools/Assert/Assertion.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
	#define ANIMATION_ASSERT_LEVEL 0
#endif // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(ANIMATION_ASSERT_LEVEL)
	#define ANIMATION_ASSERT_LEVEL 4
#endif // ANIMATION_ASSERT_LEVEL

static_assert(ANIMATION_ASSERT_LEVEL <= ASSERT_LEVEL, "Animation assert level definition error.");

#if 0 <= ANIMATION_ASSERT_LEVEL

	#define ANIMATION_ASSERTION_0(condition, format, ...) \
			ASSERTION_0(condition, format, __VA_ARGS__)
	#define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, __VA_ARGS__)

#else // ANIMATION_ASSERT_LEVEL < 0

	#define ANIMATION_ASSERTION_0(condition, format, ...) ((void)0)
	#define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) ((void)0)

#endif //0 <= ANIMATION_ASSERT_LEVEL

#if 1 <= ANIMATION_ASSERT_LEVEL

	#define ANIMATION_ASSERTION_1(condition, format, ...) \
			ASSERTION_1(condition, format, __VA_ARGS__)
	#define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, __VA_ARGS__)

#else // ANIMATION_ASSERT_LEVEL < 1

	#define ANIMATION_ASSERTION_1(condition, format, ...) ((void)0)
	#define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) ((void)0)

#endif // 1 <= ANIMATION_ASSERT_LEVEL

#if 2 <= ANIMATION_ASSERT_LEVEL

	#define ANIMATION_ASSERTION_2(condition, format, ...) \
			ASSERTION_2(condition, format, __VA_ARGS__)
	#define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, __VA_ARGS__)

#else // ANIMATION_ASSERT_LEVEL < 2

	#define ANIMATION_ASSERTION_2(condition, format, ...) ((void)0)
	#define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) ((void)0)

#endif // 2 <= ANIMATION_ASSERT_LEVEL

#if 3 <= ANIMATION_ASSERT_LEVEL

	#define ANIMATION_ASSERTION_3(condition, format, ...) \
			ASSERTION_3(condition, format, __VA_ARGS__)
	#define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, __VA_ARGS__)

#else // ANIMATION_ASSERT_LEVEL < 3

	#define ANIMATION_ASSERTION_3(condition, format, ...) ((void)0)
	#define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) ((void)0)

#endif // 3 <= ANIMATION_ASSERT_LEVEL

#if 4 <= ANIMATION_ASSERT_LEVEL

	#define ANIMATION_ASSERTION_4(condition, format, ...) \
			ASSERTION_4(condition, format, __VA_ARGS__)
	#define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED_4(condition,functionDescribed,format, __VA_ARGS__)

#else // ANIMATION_ASSERT_LEVEL < 4

	#define ANIMATION_ASSERTION_4(condition, format, ...) ((void)0)
	#define ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition,functionDescribed,format, ...) ((void)0)

#endif // 4 <= ANIMATION_ASSERT_LEVEL

#endif // CORE_TOOLS_HELPER_CUSTOM_ASSERT_MACRO_H
