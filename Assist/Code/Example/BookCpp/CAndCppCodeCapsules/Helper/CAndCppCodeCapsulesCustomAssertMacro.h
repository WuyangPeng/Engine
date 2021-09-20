///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/01 14:25)

#ifndef C_AND_CPP_CODE_CAPSULES_HELPER_C_AND_CPP_CODE_CAPSULES_CUSTOM_ASSERT_MACRO_H
#define C_AND_CPP_CODE_CAPSULES_HELPER_C_AND_CPP_CODE_CAPSULES_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL)
    #define C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL 4
#endif  // C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL

constexpr auto g_CAndCppCodeCapsulesAssert = C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL;

static_assert(C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL

    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL < 0

    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL

#if 1 <= C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL

    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL < 1

    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL

#if 2 <= C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL

    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL < 2

    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL

#if 3 <= C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL

    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL < 3

    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL

#if 4 <= C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL

    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL < 4

    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define C_AND_CPP_CODE_CAPSULES_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= C_AND_CPP_CODE_CAPSULES_ASSERT_LEVEL

#endif  // C_AND_CPP_CODE_CAPSULES_HELPER_C_AND_CPP_CODE_CAPSULES_CUSTOM_ASSERT_MACRO_H
