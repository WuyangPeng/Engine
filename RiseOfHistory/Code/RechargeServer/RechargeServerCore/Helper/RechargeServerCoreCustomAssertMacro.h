/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/19 00:20)

#ifndef RECHARGE_SERVER_CORE_HELPER_RECHARGE_SERVER_CORE_CUSTOM_ASSERT_MACRO_H
#define RECHARGE_SERVER_CORE_HELPER_RECHARGE_SERVER_CORE_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/CustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCEPTION_ASSERT)

    #define RECHARGE_SERVER_CORE_ASSERT_LEVEL 0

#endif  // OPEN_IMPORTANT_EXCEPTION_ASSERT

#if !defined(RECHARGE_SERVER_CORE_ASSERT_LEVEL)

    #define RECHARGE_SERVER_CORE_ASSERT_LEVEL 4

#endif  // RECHARGE_SERVER_CORE_ASSERT_LEVEL

static_assert(RECHARGE_SERVER_CORE_ASSERT_LEVEL <= ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= RECHARGE_SERVER_CORE_ASSERT_LEVEL

    #define RECHARGE_SERVER_CORE_ASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
    #define RECHARGE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // RECHARGE_SERVER_CORE_ASSERT_LEVEL < 0

    #define RECHARGE_SERVER_CORE_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define RECHARGE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= RECHARGE_SERVER_CORE_ASSERT_LEVEL

#if 1 <= RECHARGE_SERVER_CORE_ASSERT_LEVEL

    #define RECHARGE_SERVER_CORE_ASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
    #define RECHARGE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // RECHARGE_SERVER_CORE_ASSERT_LEVEL < 1

    #define RECHARGE_SERVER_CORE_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define RECHARGE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= RECHARGE_SERVER_CORE_ASSERT_LEVEL

#if 2 <= RECHARGE_SERVER_CORE_ASSERT_LEVEL

    #define RECHARGE_SERVER_CORE_ASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
    #define RECHARGE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // RECHARGE_SERVER_CORE_ASSERT_LEVEL < 2

    #define RECHARGE_SERVER_CORE_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define RECHARGE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= RECHARGE_SERVER_CORE_ASSERT_LEVEL

#if 3 <= RECHARGE_SERVER_CORE_ASSERT_LEVEL

    #define RECHARGE_SERVER_CORE_ASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
    #define RECHARGE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // RECHARGE_SERVER_CORE_ASSERT_LEVEL < 3

    #define RECHARGE_SERVER_CORE_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define RECHARGE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= RECHARGE_SERVER_CORE_ASSERT_LEVEL

#if 4 <= RECHARGE_SERVER_CORE_ASSERT_LEVEL

    #define RECHARGE_SERVER_CORE_ASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
    #define RECHARGE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // RECHARGE_SERVER_CORE_ASSERT_LEVEL < 4

    #define RECHARGE_SERVER_CORE_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define RECHARGE_SERVER_CORE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= RECHARGE_SERVER_CORE_ASSERT_LEVEL

#endif  // RECHARGE_SERVER_CORE_HELPER_RECHARGE_SERVER_CORE_CUSTOM_ASSERT_MACRO_H