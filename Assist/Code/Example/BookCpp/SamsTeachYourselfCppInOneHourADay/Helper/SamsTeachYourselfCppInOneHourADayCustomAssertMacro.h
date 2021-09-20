///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/27 19:51)

#ifndef SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_HELPER_SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CUSTOM_ASSERT_MACRO_H
#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_HELPER_SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL)
    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL 4
#endif  // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL

constexpr auto g_SamsTeachYourselfCppInOneHourADayAssert = SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL;

static_assert(SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL

    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL < 0

    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL

#if 1 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL

    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL < 1

    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL

#if 2 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL

    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL < 2

    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL

#if 3 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL

    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL < 3

    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL

#if 4 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL

    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL < 4

    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_ASSERT_LEVEL

#endif  // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_HELPER_SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CUSTOM_ASSERT_MACRO_H
