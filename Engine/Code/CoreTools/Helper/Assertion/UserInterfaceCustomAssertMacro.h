// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 10:12)

#ifndef CORE_TOOLS_HELPER_USER_INTERFACE_CUSTOM_ASSERT_MACRO_H
#define CORE_TOOLS_HELPER_USER_INTERFACE_CUSTOM_ASSERT_MACRO_H

#include "CoreTools/Assert/Assertion.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
	#define USER_INTERFACE_ASSERT_LEVEL 0
#endif // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(USER_INTERFACE_ASSERT_LEVEL)
	#define USER_INTERFACE_ASSERT_LEVEL 4
#endif // USER_INTERFACE_ASSERT_LEVEL

static_assert(USER_INTERFACE_ASSERT_LEVEL <= ASSERT_LEVEL, "User Interface assert level definition error.");

#if 0 <= USER_INTERFACE_ASSERT_LEVEL

	#define USER_INTERFACE_ASSERTION_0(condition, format, ...) \
			ASSERTION_0(condition, format, __VA_ARGS__)
	#define USER_INTERFACE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, __VA_ARGS__)

	#define USER_INTERFACE_ASSERTION_DEBUG(condition, format, ...) \
			ASSERTION_DEBUG(condition, format, __VA_ARGS__)
	#define USER_INTERFACE_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, ...) \
			ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, __VA_ARGS__)

#else // USER_INTERFACE_ASSERT_LEVEL < 0

	#define USER_INTERFACE_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
	#define USER_INTERFACE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) (static_cast<void>(0))

	#define USER_INTERFACE_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
	#define USER_INTERFACE_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, ...) (static_cast<void>(0))

#endif //0 <= USER_INTERFACE_ASSERT_LEVEL

#if 1 <= USER_INTERFACE_ASSERT_LEVEL

	#define USER_INTERFACE_ASSERTION_1(condition, format, ...) \
			ASSERTION_1(condition, format, __VA_ARGS__)
	#define USER_INTERFACE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, __VA_ARGS__)

#else // USER_INTERFACE_ASSERT_LEVEL < 1

	#define USER_INTERFACE_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
	#define USER_INTERFACE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) (static_cast<void>(0))

#endif // 1 <= USER_INTERFACE_ASSERT_LEVEL

#if 2 <= USER_INTERFACE_ASSERT_LEVEL

	#define USER_INTERFACE_ASSERTION_2(condition, format, ...) \
			ASSERTION_2(condition, format, __VA_ARGS__)
	#define USER_INTERFACE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, __VA_ARGS__)

#else // USER_INTERFACE_ASSERT_LEVEL < 2

	#define USER_INTERFACE_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
	#define USER_INTERFACE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) (static_cast<void>(0))

#endif // 2 <= USER_INTERFACE_ASSERT_LEVEL

#if 3 <= USER_INTERFACE_ASSERT_LEVEL

	#define USER_INTERFACE_ASSERTION_3(condition, format, ...) \
			ASSERTION_3(condition, format, __VA_ARGS__)
	#define USER_INTERFACE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, __VA_ARGS__)

#else // USER_INTERFACE_ASSERT_LEVEL < 3

	#define USER_INTERFACE_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
	#define USER_INTERFACE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) (static_cast<void>(0))

#endif // 3 <= USER_INTERFACE_ASSERT_LEVEL

#if 4 <= USER_INTERFACE_ASSERT_LEVEL

	#define USER_INTERFACE_ASSERTION_4(condition, format, ...) \
			ASSERTION_4(condition, format, __VA_ARGS__)
	#define USER_INTERFACE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED_4(condition,functionDescribed,format, __VA_ARGS__)

#else // USER_INTERFACE_ASSERT_LEVEL < 4

	#define USER_INTERFACE_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
	#define USER_INTERFACE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition,functionDescribed,format, ...) (static_cast<void>(0))

#endif // 4 <= USER_INTERFACE_ASSERT_LEVEL

#endif // CORE_TOOLS_HELPER_CUSTOM_ASSERT_MACRO_H
