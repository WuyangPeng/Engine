///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/20 0:15)

#ifndef MORE_EXCEPTIONAL_CPP_HELPER_MORE_EXCEPTIONAL_CPP_CUSTOM_ASSERT_MACRO_H
#define MORE_EXCEPTIONAL_CPP_HELPER_MORE_EXCEPTIONAL_CPP_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL)
    #define MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL 4
#endif  // MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL

constexpr auto g_MoreExceptionalCppAssert = MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL;

static_assert(MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL

    #define MORE_EXCEPTIONAL_CPP_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define MORE_EXCEPTIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL < 0

    #define MORE_EXCEPTIONAL_CPP_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define MORE_EXCEPTIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL

#if 1 <= MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL

    #define MORE_EXCEPTIONAL_CPP_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define MORE_EXCEPTIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL < 1

    #define MORE_EXCEPTIONAL_CPP_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define MORE_EXCEPTIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL

#if 2 <= MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL

    #define MORE_EXCEPTIONAL_CPP_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define MORE_EXCEPTIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL < 2

    #define MORE_EXCEPTIONAL_CPP_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define MORE_EXCEPTIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL

#if 3 <= MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL

    #define MORE_EXCEPTIONAL_CPP_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define MORE_EXCEPTIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL < 3

    #define MORE_EXCEPTIONAL_CPP_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define MORE_EXCEPTIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL

#if 4 <= MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL

    #define MORE_EXCEPTIONAL_CPP_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define MORE_EXCEPTIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL < 4

    #define MORE_EXCEPTIONAL_CPP_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define MORE_EXCEPTIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= MORE_EXCEPTIONAL_CPP_ASSERT_LEVEL

#endif  // MORE_EXCEPTIONAL_CPP_HELPER_MORE_EXCEPTIONAL_CPP_CUSTOM_ASSERT_MACRO_H
