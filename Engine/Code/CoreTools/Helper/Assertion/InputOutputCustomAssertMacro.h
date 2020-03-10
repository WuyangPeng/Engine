// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 10:11)

#ifndef CORE_TOOLS_HELPER_INPUT_OUTPUT_CUSTOM_ASSERT_MACRO_H
#define CORE_TOOLS_HELPER_INPUT_OUTPUT_CUSTOM_ASSERT_MACRO_H

#include "CoreTools/Assert/Assertion.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
	#define INPUT_OUTPUT_ASSERT_LEVEL 0
#endif // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(INPUT_OUTPUT_ASSERT_LEVEL)
	#define INPUT_OUTPUT_ASSERT_LEVEL 4
#endif // INPUT_OUTPUT_ASSERT_LEVEL

static_assert(INPUT_OUTPUT_ASSERT_LEVEL <= ASSERT_LEVEL, "Input Output assert level definition error.");

#if 0 <= INPUT_OUTPUT_ASSERT_LEVEL

	#define INPUT_OUTPUT_ASSERTION_0(condition, format, ...) \
			ASSERTION_0(condition, format, __VA_ARGS__)
	#define INPUT_OUTPUT_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, __VA_ARGS__)

#else // INPUT_OUTPUT_ASSERT_LEVEL < 0

	#define INPUT_OUTPUT_ASSERTION_0(condition, format, ...) ((void)0)
	#define INPUT_OUTPUT_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) ((void)0)

#endif //0 <= INPUT_OUTPUT_ASSERT_LEVEL

#if 1 <= INPUT_OUTPUT_ASSERT_LEVEL

	#define INPUT_OUTPUT_ASSERTION_1(condition, format, ...) \
			ASSERTION_1(condition, format, __VA_ARGS__)
	#define INPUT_OUTPUT_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, __VA_ARGS__)

#else // INPUT_OUTPUT_ASSERT_LEVEL < 1

	#define INPUT_OUTPUT_ASSERTION_1(condition, format, ...) ((void)0)
	#define INPUT_OUTPUT_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) ((void)0)

#endif // 1 <= INPUT_OUTPUT_ASSERT_LEVEL

#if 2 <= INPUT_OUTPUT_ASSERT_LEVEL

	#define INPUT_OUTPUT_ASSERTION_2(condition, format, ...) \
			ASSERTION_2(condition, format, __VA_ARGS__)
	#define INPUT_OUTPUT_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, __VA_ARGS__)

#else // INPUT_OUTPUT_ASSERT_LEVEL < 2

	#define INPUT_OUTPUT_ASSERTION_2(condition, format, ...) ((void)0)
	#define INPUT_OUTPUT_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) ((void)0)

#endif // 2 <= INPUT_OUTPUT_ASSERT_LEVEL

#if 3 <= INPUT_OUTPUT_ASSERT_LEVEL

	#define INPUT_OUTPUT_ASSERTION_3(condition, format, ...) \
			ASSERTION_3(condition, format, __VA_ARGS__)
	#define INPUT_OUTPUT_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, __VA_ARGS__)

#else // INPUT_OUTPUT_ASSERT_LEVEL < 3

	#define INPUT_OUTPUT_ASSERTION_3(condition, format, ...) ((void)0)
	#define INPUT_OUTPUT_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) ((void)0)

#endif // 3 <= INPUT_OUTPUT_ASSERT_LEVEL

#if 4 <= INPUT_OUTPUT_ASSERT_LEVEL

	#define INPUT_OUTPUT_ASSERTION_4(condition, format, ...) \
			ASSERTION_4(condition, format, __VA_ARGS__)
	#define INPUT_OUTPUT_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
				ASSERTION_USE_FUNCTION_DESCRIBED_4(condition,functionDescribed,format, __VA_ARGS__)

#else // INPUT_OUTPUT_ASSERT_LEVEL < 4

	#define INPUT_OUTPUT_ASSERTION_4(condition, format, ...) ((void)0)
	#define INPUT_OUTPUT_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition,functionDescribed,format, ...) ((void)0)

#endif // 4 <= INPUT_OUTPUT_ASSERT_LEVEL

#endif // CORE_TOOLS_HELPER_CUSTOM_ASSERT_MACRO_H
