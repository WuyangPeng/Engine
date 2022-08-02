///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/29 17:16)

#ifndef UPDATE_SERVER_MIDDLE_LAYER_MACRO_UPDATE_SERVER_MIDDLE_LAYER_CUSTOM_ASSERT_MACRO_H
#define UPDATE_SERVER_MIDDLE_LAYER_MACRO_UPDATE_SERVER_MIDDLE_LAYER_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Contract/Assertion.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL)
    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL 4
#endif  // UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

static_assert(UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL <= ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL < 0

    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#if 1 <= UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL < 1

    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#if 2 <= UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL < 2

    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#if 3 <= UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL < 3

    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#if 4 <= UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL < 4

    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define UPDATE_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= UPDATE_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#endif  // UPDATE_SERVER_MIDDLE_LAYER_MACRO_UPDATE_SERVER_MIDDLE_LAYER_CUSTOM_ASSERT_MACRO_H
