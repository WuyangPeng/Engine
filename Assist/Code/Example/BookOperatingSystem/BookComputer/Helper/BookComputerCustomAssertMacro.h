///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/12/05 10:36)

#ifndef BOOK_COMPUTER_HELPER_BOOK_COMPUTER_CUSTOM_ASSERT_MACRO_H
#define BOOK_COMPUTER_HELPER_BOOK_COMPUTER_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define BOOK_COMPUTER_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(BOOK_COMPUTER_ASSERT_LEVEL)
    #define BOOK_COMPUTER_ASSERT_LEVEL 4
#endif  // BOOK_COMPUTER_ASSERT_LEVEL

constexpr auto g_BookComputerAssert = BOOK_COMPUTER_ASSERT_LEVEL;

static_assert(BOOK_COMPUTER_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= BOOK_COMPUTER_ASSERT_LEVEL

    #define BOOK_COMPUTER_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define BOOK_COMPUTER_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

    #define BOOK_COMPUTER_ASSERTION_DEBUG(condition, format, ...) \
        USER_ASSERTION_DEBUG((condition), (format), __VA_ARGS__)
    #define BOOK_COMPUTER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        USER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // BOOK_COMPUTER_ASSERT_LEVEL < 0

    #define BOOK_COMPUTER_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define BOOK_COMPUTER_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define BOOK_COMPUTER_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define BOOK_COMPUTER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= BOOK_COMPUTER_ASSERT_LEVEL

#if 1 <= BOOK_COMPUTER_ASSERT_LEVEL

    #define BOOK_COMPUTER_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define BOOK_COMPUTER_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // BOOK_COMPUTER_ASSERT_LEVEL < 1

    #define BOOK_COMPUTER_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define BOOK_COMPUTER_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= BOOK_COMPUTER_ASSERT_LEVEL

#if 2 <= BOOK_COMPUTER_ASSERT_LEVEL

    #define BOOK_COMPUTER_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define BOOK_COMPUTER_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // BOOK_COMPUTER_ASSERT_LEVEL < 2

    #define BOOK_COMPUTER_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define BOOK_COMPUTER_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= BOOK_COMPUTER_ASSERT_LEVEL

#if 3 <= BOOK_COMPUTER_ASSERT_LEVEL

    #define BOOK_COMPUTER_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define BOOK_COMPUTER_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // BOOK_COMPUTER_ASSERT_LEVEL < 3

    #define BOOK_COMPUTER_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define BOOK_COMPUTER_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= BOOK_COMPUTER_ASSERT_LEVEL

#if 4 <= BOOK_COMPUTER_ASSERT_LEVEL

    #define BOOK_COMPUTER_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define BOOK_COMPUTER_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // BOOK_COMPUTER_ASSERT_LEVEL < 4

    #define BOOK_COMPUTER_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define BOOK_COMPUTER_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= BOOK_COMPUTER_ASSERT_LEVEL

#endif  // BOOK_COMPUTER_HELPER_BOOK_COMPUTER_CUSTOM_ASSERT_MACRO_H
