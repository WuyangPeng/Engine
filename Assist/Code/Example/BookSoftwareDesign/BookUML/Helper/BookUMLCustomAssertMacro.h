// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.1.0.1 (2020/04/05 17:52)

#ifndef BOOK_UML_HELPER_BOOK_UML_CUSTOM_ASSERT_MACRO_H
#define BOOK_UML_HELPER_BOOK_UML_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
	#define BOOK_UML_ASSERT_LEVEL 0
#endif // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(BOOK_UML_ASSERT_LEVEL)
	#define BOOK_UML_ASSERT_LEVEL 4
#endif // BOOK_UML_ASSERT_LEVEL

static_assert(BOOK_UML_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= BOOK_UML_ASSERT_LEVEL

	#define BOOK_UML_ASSERTION_0(condition, format, ...) \
			USER_ASSERTION_0((condition), (format), __VA_ARGS__)
	#define BOOK_UML_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) \
			USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition),(functionDescribed),(format), __VA_ARGS__)

	#define BOOK_UML_ASSERTION_DEBUG(condition, format, ...) \
			USER_ASSERTION_DEBUG((condition), (format), __VA_ARGS__)
	#define BOOK_UML_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, ...) \
			USER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED((condition),(functionDescribed),(format), __VA_ARGS__)

#else // BOOK_UML_ASSERT_LEVEL < 0

	#define BOOK_UML_ASSERTION_0(condition, format, ...) ((void)0)
	#define BOOK_UML_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) ((void)0)

	#define BOOK_UML_ASSERTION_DEBUG(condition, format, ...) ((void)0)
	#define BOOK_UML_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, ...) ((void)0)

#endif // 0 <= BOOK_UML_ASSERT_LEVEL

#if 1 <= BOOK_UML_ASSERT_LEVEL

	#define BOOK_UML_ASSERTION_1(condition, format, ...) \
			USER_ASSERTION_1((condition), (format), __VA_ARGS__)
	#define BOOK_UML_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) \
			USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition),(functionDescribed),(format), __VA_ARGS__)

#else // BOOK_UML_ASSERT_LEVEL < 1

	#define BOOK_UML_ASSERTION_1(condition, format, ...) ((void)0)
	#define BOOK_UML_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) ((void)0)

#endif // 1 <= BOOK_UML_ASSERT_LEVEL

#if 2 <= BOOK_UML_ASSERT_LEVEL

	#define BOOK_UML_ASSERTION_2(condition, format, ...) \
			USER_ASSERTION_2((condition), (format), __VA_ARGS__)
	#define BOOK_UML_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) \
			USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition),(functionDescribed),(format), __VA_ARGS__)

#else // BOOK_UML_ASSERT_LEVEL < 2

	#define BOOK_UML_ASSERTION_2(condition, format, ...) ((void)0)
	#define BOOK_UML_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) ((void)0)

#endif // 2 <= BOOK_UML_ASSERT_LEVEL

#if 3 <= BOOK_UML_ASSERT_LEVEL

	#define BOOK_UML_ASSERTION_3(condition, format, ...) \
			USER_ASSERTION_3((condition), (format), __VA_ARGS__)
	#define BOOK_UML_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) \
			USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition),(functionDescribed),(format), __VA_ARGS__)

#else // BOOK_UML_ASSERT_LEVEL < 3

	#define BOOK_UML_ASSERTION_3(condition, format, ...) ((void)0)
	#define BOOK_UML_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) ((void)0)

#endif // 3 <= BOOK_UML_ASSERT_LEVEL

#if 4 <= BOOK_UML_ASSERT_LEVEL

	#define BOOK_UML_ASSERTION_4(condition, format, ...) \
			USER_ASSERTION_4((condition), (format), __VA_ARGS__)
	#define BOOK_UML_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
			USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition),(functionDescribed),(format), __VA_ARGS__)

#else // BOOK_UML_ASSERT_LEVEL < 4

	#define BOOK_UML_ASSERTION_4(condition, format, ...) ((void)0)
	#define BOOK_UML_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition,functionDescribed,format, ...) ((void)0)

#endif // 4 <= BOOK_UML_ASSERT_LEVEL

#endif // BOOK_UML_HELPER_BOOK_UML_CUSTOM_ASSERT_MACRO_H
