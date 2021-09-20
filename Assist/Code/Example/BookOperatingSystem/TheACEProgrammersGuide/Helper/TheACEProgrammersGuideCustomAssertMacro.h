///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.4 (2021/06/06 21:47)

#ifndef THE_ACE_PROGRAMMERS_GUIDE_HELPER_THE_ACE_PROGRAMMERS_GUIDE_CUSTOM_ASSERT_MACRO_H
#define THE_ACE_PROGRAMMERS_GUIDE_HELPER_THE_ACE_PROGRAMMERS_GUIDE_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL)
    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL 4
#endif  // THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL

constexpr auto g_TheACEProgrammersGuideAssert = THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL;

static_assert(THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL

    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_DEBUG(condition, format, ...) \
        USER_ASSERTION_DEBUG((condition), (format), __VA_ARGS__)
    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        USER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL < 0

    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL

#if 1 <= THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL

    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL < 1

    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL

#if 2 <= THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL

    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL < 2

    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL

#if 3 <= THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL

    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL < 3

    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL

#if 4 <= THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL

    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL < 4

    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define THE_ACE_PROGRAMMERS_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= THE_ACE_PROGRAMMERS_GUIDE_ASSERT_LEVEL

#endif  // THE_ACE_PROGRAMMERS_GUIDE_HELPER_THE_ACE_PROGRAMMERS_GUIDE_CUSTOM_ASSERT_MACRO_H
