// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 10:11)

#ifndef CORE_TOOLS_HELPER_IMAGICS_CUSTOM_ASSERT_MACRO_H
#define CORE_TOOLS_HELPER_IMAGICS_CUSTOM_ASSERT_MACRO_H

#include "System/Helper/ConfigMacro.h"

#include "CoreTools/Assert/Assertion.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
	#define IMAGICS_ASSERT_LEVEL 0
#endif // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(IMAGICS_ASSERT_LEVEL)
	#define IMAGICS_ASSERT_LEVEL 4
#endif // IMAGICS_ASSERT_LEVEL

static_assert(IMAGICS_ASSERT_LEVEL <= ASSERT_LEVEL, "Imagics assert level definition error.");

#if 0 <= IMAGICS_ASSERT_LEVEL

	#define IMAGICS_ASSERTION_0(condition, format, ...) \
			ASSERTION_0(condition, format, __VA_ARGS__)
	#define IMAGICS_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, __VA_ARGS__)

	#define IMAGICS_ASSERTION_DEBUG(condition, format, ...) \
			ASSERTION_DEBUG(condition, format, __VA_ARGS__)
	#define IMAGICS_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, ...) \
			ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, __VA_ARGS__)

#else // IMAGICS_ASSERT_LEVEL < 0

	#define IMAGICS_ASSERTION_0(condition, format, ...) ((void)0)
	#define IMAGICS_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) ((void)0)

	#define IMAGICS_ASSERTION_DEBUG(condition, format, ...) ((void)0)
	#define IMAGICS_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, ...) ((void)0)

#endif //0 <= IMAGICS_ASSERT_LEVEL

#if 1 <= IMAGICS_ASSERT_LEVEL

	#define IMAGICS_ASSERTION_1(condition, format, ...) \
			ASSERTION_1(condition, format, __VA_ARGS__)
	#define IMAGICS_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, __VA_ARGS__)

#else // IMAGICS_ASSERT_LEVEL < 1

	#define IMAGICS_ASSERTION_1(condition, format, ...) ((void)0)
	#define IMAGICS_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) ((void)0)

#endif // 1 <= IMAGICS_ASSERT_LEVEL

#if 2 <= IMAGICS_ASSERT_LEVEL

	#define IMAGICS_ASSERTION_2(condition, format, ...) \
			ASSERTION_2(condition, format, __VA_ARGS__)
	#define IMAGICS_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, __VA_ARGS__)

#else // IMAGICS_ASSERT_LEVEL < 2

	#define IMAGICS_ASSERTION_2(condition, format, ...) ((void)0)
	#define IMAGICS_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) ((void)0)

#endif // 2 <= IMAGICS_ASSERT_LEVEL

#if 3 <= IMAGICS_ASSERT_LEVEL

	#define IMAGICS_ASSERTION_3(condition, format, ...) \
			ASSERTION_3(condition, format, __VA_ARGS__)
	#define IMAGICS_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, __VA_ARGS__)

#else // IMAGICS_ASSERT_LEVEL < 3

	#define IMAGICS_ASSERTION_3(condition, format, ...) ((void)0)
	#define IMAGICS_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) ((void)0)

#endif // 3 <= IMAGICS_ASSERT_LEVEL

#if 4 <= IMAGICS_ASSERT_LEVEL

	#define IMAGICS_ASSERTION_4(condition, format, ...) \
			ASSERTION_4(condition, format, __VA_ARGS__)
	#define IMAGICS_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED_4(condition,functionDescribed,format, __VA_ARGS__)

#else // IMAGICS_ASSERT_LEVEL < 4

	#define IMAGICS_ASSERTION_4(condition, format, ...) ((void)0)
	#define IMAGICS_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition,functionDescribed,format, ...) ((void)0)

#endif // 4 <= IMAGICS_ASSERT_LEVEL

#endif // CORE_TOOLS_HELPER_CUSTOM_ASSERT_MACRO_H
