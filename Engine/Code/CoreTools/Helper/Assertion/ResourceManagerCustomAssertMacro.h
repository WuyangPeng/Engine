///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.2 (2023/02/19 20:04)

#ifndef CORE_TOOLS_HELPER_RESOURCE_MANAGER_CUSTOM_ASSERT_MACRO_H
#define CORE_TOOLS_HELPER_RESOURCE_MANAGER_CUSTOM_ASSERT_MACRO_H

#include "CoreTools/Contract/AssertionDetail.h"

#if defined(OPEN_IMPORTANT_EXCEPTION_ASSERT)

    #define RESOURCE_MANAGER_ASSERT_LEVEL 0

#endif  // OPEN_IMPORTANT_EXCEPTION_ASSERT

#if !defined(RESOURCE_MANAGER_ASSERT_LEVEL)

    #define RESOURCE_MANAGER_ASSERT_LEVEL 4

#endif  // RESOURCE_MANAGER_ASSERT_LEVEL

constexpr auto gResourceManagerAssert = RESOURCE_MANAGER_ASSERT_LEVEL;

static_assert(RESOURCE_MANAGER_ASSERT_LEVEL <= ASSERT_LEVEL, "Resource Manager assert level definition error.");

#if 0 <= RESOURCE_MANAGER_ASSERT_LEVEL

    #define RESOURCE_MANAGER_ASSERTION_0(condition, format, ...) \
        ASSERTION_0(condition, format, __VA_ARGS__)
    #define RESOURCE_MANAGER_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, __VA_ARGS__)

    #define RESOURCE_MANAGER_ASSERTION_DEBUG(condition, format, ...) \
        ASSERTION_DEBUG(condition, format, __VA_ARGS__)
    #define RESOURCE_MANAGER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, __VA_ARGS__)

#else  // RESOURCE_MANAGER_ASSERT_LEVEL < 0

    #define RESOURCE_MANAGER_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define RESOURCE_MANAGER_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define RESOURCE_MANAGER_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define RESOURCE_MANAGER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  //0 <= RESOURCE_MANAGER_ASSERT_LEVEL

#if 1 <= RESOURCE_MANAGER_ASSERT_LEVEL

    #define RESOURCE_MANAGER_ASSERTION_1(condition, format, ...) \
        ASSERTION_1(condition, format, __VA_ARGS__)
    #define RESOURCE_MANAGER_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, __VA_ARGS__)

#else  // RESOURCE_MANAGER_ASSERT_LEVEL < 1

    #define RESOURCE_MANAGER_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define RESOURCE_MANAGER_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= RESOURCE_MANAGER_ASSERT_LEVEL

#if 2 <= RESOURCE_MANAGER_ASSERT_LEVEL

    #define RESOURCE_MANAGER_ASSERTION_2(condition, format, ...) \
        ASSERTION_2(condition, format, __VA_ARGS__)
    #define RESOURCE_MANAGER_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, __VA_ARGS__)

#else  // RESOURCE_MANAGER_ASSERT_LEVEL < 2

    #define RESOURCE_MANAGER_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define RESOURCE_MANAGER_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= RESOURCE_MANAGER_ASSERT_LEVEL

#if 3 <= RESOURCE_MANAGER_ASSERT_LEVEL

    #define RESOURCE_MANAGER_ASSERTION_3(condition, format, ...) \
        ASSERTION_3(condition, format, __VA_ARGS__)
    #define RESOURCE_MANAGER_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, __VA_ARGS__)

#else  // RESOURCE_MANAGER_ASSERT_LEVEL < 3

    #define RESOURCE_MANAGER_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define RESOURCE_MANAGER_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= RESOURCE_MANAGER_ASSERT_LEVEL

#if 4 <= RESOURCE_MANAGER_ASSERT_LEVEL

    #define RESOURCE_MANAGER_ASSERTION_4(condition, format, ...) \
        ASSERTION_4(condition, format, __VA_ARGS__)
    #define RESOURCE_MANAGER_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, __VA_ARGS__)

#else  // RESOURCE_MANAGER_ASSERT_LEVEL < 4

    #define RESOURCE_MANAGER_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define RESOURCE_MANAGER_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= RESOURCE_MANAGER_ASSERT_LEVEL

#endif  // CORE_TOOLS_HELPER_CUSTOM_ASSERT_MACRO_H
