// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.1.0 (2019/11/06 09:48)

#ifndef BOOK_GAME_PROGRAMMING_MACRO_CUSTOM_ASSERT_MACRO_H
#define BOOK_GAME_PROGRAMMING_MACRO_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Contract/Assertion.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
	#define BOOK_GAME_PROGRAMMING_ASSERT_LEVEL 0
#endif // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(BOOK_GAME_PROGRAMMING_ASSERT_LEVEL)
	#define BOOK_GAME_PROGRAMMING_ASSERT_LEVEL 4
#endif // BOOK_GAME_PROGRAMMING_ASSERT_LEVEL

static_assert(BOOK_GAME_PROGRAMMING_ASSERT_LEVEL <= ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= BOOK_GAME_PROGRAMMING_ASSERT_LEVEL

#define BOOK_GAME_PROGRAMMING_ASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
#define BOOK_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition),(functionDescribed),(format), __VA_ARGS__)

#else // BOOK_GAME_PROGRAMMING_ASSERT_LEVEL < 0

#define BOOK_GAME_PROGRAMMING_ASSERTION_0(condition, format, ...) ((void)0)
#define BOOK_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) ((void)0)

#endif // 0 <= BOOK_GAME_PROGRAMMING_ASSERT_LEVEL

#if 1 <= BOOK_GAME_PROGRAMMING_ASSERT_LEVEL

#define BOOK_GAME_PROGRAMMING_ASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
#define BOOK_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition),(functionDescribed),(format), __VA_ARGS__)

#else // BOOK_GAME_PROGRAMMING_ASSERT_LEVEL < 1

#define BOOK_GAME_PROGRAMMING_ASSERTION_1(condition, format, ...) ((void)0)
#define BOOK_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) ((void)0)

#endif // 1 <= BOOK_GAME_PROGRAMMING_ASSERT_LEVEL

#if 2 <= BOOK_GAME_PROGRAMMING_ASSERT_LEVEL

#define BOOK_GAME_PROGRAMMING_ASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
#define BOOK_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition),(functionDescribed),(format), __VA_ARGS__)

#else // BOOK_GAME_PROGRAMMING_ASSERT_LEVEL < 2

#define BOOK_GAME_PROGRAMMING_ASSERTION_2(condition, format, ...) ((void)0)
#define BOOK_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) ((void)0)

#endif // 2 <= BOOK_GAME_PROGRAMMING_ASSERT_LEVEL

#if 3 <= BOOK_GAME_PROGRAMMING_ASSERT_LEVEL

#define BOOK_GAME_PROGRAMMING_ASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
#define BOOK_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition),(functionDescribed),(format), __VA_ARGS__)

#else // BOOK_GAME_PROGRAMMING_ASSERT_LEVEL < 3

#define BOOK_GAME_PROGRAMMING_ASSERTION_3(condition, format, ...) ((void)0)
#define BOOK_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) ((void)0)

#endif // 3 <= BOOK_GAME_PROGRAMMING_ASSERT_LEVEL

#if 4 <= BOOK_GAME_PROGRAMMING_ASSERT_LEVEL

#define BOOK_GAME_PROGRAMMING_ASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
#define BOOK_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition),(functionDescribed),(format), __VA_ARGS__)

#else // BOOK_GAME_PROGRAMMING_ASSERT_LEVEL < 4

#define BOOK_GAME_PROGRAMMING_ASSERTION_4(condition, format, ...) ((void)0)
#define BOOK_GAME_PROGRAMMING_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition,functionDescribed,format, ...) ((void)0)

#endif // 4 <= BOOK_GAME_PROGRAMMING_ASSERT_LEVEL

#endif // BOOK_GAME_PROGRAMMING_MACRO_CUSTOM_ASSERT_MACRO_H
