///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/01 19:05)

#ifndef PROGRAMMING_WINDOWS_FIFTH_EDITION_HELPER_PROGRAMMING_WINDOWS_FIFTH_EDITION_CUSTOM_ASSERT_MACRO_H
#define PROGRAMMING_WINDOWS_FIFTH_EDITION_HELPER_PROGRAMMING_WINDOWS_FIFTH_EDITION_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL)
    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL 4
#endif  // PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL

constexpr auto g_ProgrammingWindowsFifthEditionAssert = PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL;

static_assert(PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL

    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_DEBUG(condition, format, ...) \
        USER_ASSERTION_DEBUG((condition), (format), __VA_ARGS__)
    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        USER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL < 0

    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL

#if 1 <= PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL

    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL < 1

    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL

#if 2 <= PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL

    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL < 2

    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL

#if 3 <= PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL

    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL < 3

    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL

#if 4 <= PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL

    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL < 4

    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= PROGRAMMING_WINDOWS_FIFTH_EDITION_ASSERT_LEVEL

#endif  // PROGRAMMING_WINDOWS_FIFTH_EDITION_HELPER_PROGRAMMING_WINDOWS_FIFTH_EDITION_CUSTOM_ASSERT_MACRO_H
