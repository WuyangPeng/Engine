///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/09 14:57)

#ifndef DATA_STRUCTURES_WITH_CPP_USING_STL_HELPER_DATA_STRUCTURES_WITH_CPP_USING_STL_CUSTOM_ASSERT_MACRO_H
#define DATA_STRUCTURES_WITH_CPP_USING_STL_HELPER_DATA_STRUCTURES_WITH_CPP_USING_STL_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL)
    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL 4
#endif  // DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL

constexpr auto g_DataStructuresWithCppUsingSTLAssert = DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL;

static_assert(DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL

    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL < 0

    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL

#if 1 <= DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL

    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL < 1

    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL

#if 2 <= DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL

    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL < 2

    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL

#if 3 <= DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL

    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL < 3

    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL

#if 4 <= DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL

    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL < 4

    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= DATA_STRUCTURES_WITH_CPP_USING_STL_ASSERT_LEVEL

#endif  // DATA_STRUCTURES_WITH_CPP_USING_STL_HELPER_DATA_STRUCTURES_WITH_CPP_USING_STL_CUSTOM_ASSERT_MACRO_H
