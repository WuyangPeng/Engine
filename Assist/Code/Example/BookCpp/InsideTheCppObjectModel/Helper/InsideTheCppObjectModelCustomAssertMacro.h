///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:53)

#ifndef INSIDE_THE_CPP_OBJECT_MODEL_HELPER_INSIDE_THE_CPP_OBJECT_MODEL_CUSTOM_ASSERT_MACRO_H
#define INSIDE_THE_CPP_OBJECT_MODEL_HELPER_INSIDE_THE_CPP_OBJECT_MODEL_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL)
    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL 4
#endif  // INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL

constexpr auto g_InsideTheCppObjectModelAssert = INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL;

static_assert(INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL

    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL < 0

    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL

#if 1 <= INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL

    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL < 1

    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL

#if 2 <= INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL

    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL < 2

    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL

#if 3 <= INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL

    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL < 3

    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL

#if 4 <= INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL

    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL < 4

    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define INSIDE_THE_CPP_OBJECT_MODEL_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= INSIDE_THE_CPP_OBJECT_MODEL_ASSERT_LEVEL

#endif  // INSIDE_THE_CPP_OBJECT_MODEL_HELPER_INSIDE_THE_CPP_OBJECT_MODEL_CUSTOM_ASSERT_MACRO_H
