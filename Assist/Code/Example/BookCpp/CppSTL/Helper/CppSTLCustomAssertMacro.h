///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/27 12:45)

#ifndef CPP_STL_HELPER_CPP_STL_CUSTOM_ASSERT_MACRO_H
#define CPP_STL_HELPER_CPP_STL_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define CPP_STL_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(CPP_STL_ASSERT_LEVEL)
    #define CPP_STL_ASSERT_LEVEL 4
#endif  // CPP_STL_ASSERT_LEVEL

constexpr auto g_CppSTLAssert = CPP_STL_ASSERT_LEVEL;

static_assert(CPP_STL_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= CPP_STL_ASSERT_LEVEL

    #define CPP_STL_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define CPP_STL_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CPP_STL_ASSERT_LEVEL < 0

    #define CPP_STL_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define CPP_STL_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= CPP_STL_ASSERT_LEVEL

#if 1 <= CPP_STL_ASSERT_LEVEL

    #define CPP_STL_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define CPP_STL_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CPP_STL_ASSERT_LEVEL < 1

    #define CPP_STL_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define CPP_STL_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= CPP_STL_ASSERT_LEVEL

#if 2 <= CPP_STL_ASSERT_LEVEL

    #define CPP_STL_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define CPP_STL_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CPP_STL_ASSERT_LEVEL < 2

    #define CPP_STL_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define CPP_STL_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= CPP_STL_ASSERT_LEVEL

#if 3 <= CPP_STL_ASSERT_LEVEL

    #define CPP_STL_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define CPP_STL_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CPP_STL_ASSERT_LEVEL < 3

    #define CPP_STL_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define CPP_STL_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= CPP_STL_ASSERT_LEVEL

#if 4 <= CPP_STL_ASSERT_LEVEL

    #define CPP_STL_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define CPP_STL_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // CPP_STL_ASSERT_LEVEL < 4

    #define CPP_STL_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define CPP_STL_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= CPP_STL_ASSERT_LEVEL

#endif  // CPP_STL_HELPER_CPP_STL_CUSTOM_ASSERT_MACRO_H
