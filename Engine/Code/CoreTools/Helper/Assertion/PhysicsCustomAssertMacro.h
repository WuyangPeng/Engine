///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.1 (2021/07/29 16:12)

#ifndef CORE_TOOLS_HELPER_PHYSICS_CUSTOM_ASSERT_MACRO_H
#define CORE_TOOLS_HELPER_PHYSICS_CUSTOM_ASSERT_MACRO_H

#include "CoreTools/Contract/AssertionDetail.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define PHYSICS_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(PHYSICS_ASSERT_LEVEL)
    #define PHYSICS_ASSERT_LEVEL 4
#endif  // PHYSICS_ASSERT_LEVEL

constexpr auto g_PhysicsAssert = PHYSICS_ASSERT_LEVEL;

static_assert(PHYSICS_ASSERT_LEVEL <= ASSERT_LEVEL, "Physics assert level definition error.");

#if 0 <= PHYSICS_ASSERT_LEVEL

    #define PHYSICS_ASSERTION_0(condition, format, ...) \
        ASSERTION_0(condition, format, __VA_ARGS__)
    #define PHYSICS_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, __VA_ARGS__)

    #define PHYSICS_ASSERTION_DEBUG(condition, format, ...) \
        ASSERTION_DEBUG(condition, format, __VA_ARGS__)
    #define PHYSICS_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, __VA_ARGS__)

#else  // PHYSICS_ASSERT_LEVEL < 0

    #define PHYSICS_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define PHYSICS_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define PHYSICS_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define PHYSICS_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  //0 <= PHYSICS_ASSERT_LEVEL

#if 1 <= PHYSICS_ASSERT_LEVEL

    #define PHYSICS_ASSERTION_1(condition, format, ...) \
        ASSERTION_1(condition, format, __VA_ARGS__)
    #define PHYSICS_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, __VA_ARGS__)

#else  // PHYSICS_ASSERT_LEVEL < 1

    #define PHYSICS_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define PHYSICS_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= PHYSICS_ASSERT_LEVEL

#if 2 <= PHYSICS_ASSERT_LEVEL

    #define PHYSICS_ASSERTION_2(condition, format, ...) \
        ASSERTION_2(condition, format, __VA_ARGS__)
    #define PHYSICS_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, __VA_ARGS__)

#else  // PHYSICS_ASSERT_LEVEL < 2

    #define PHYSICS_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define PHYSICS_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= PHYSICS_ASSERT_LEVEL

#if 3 <= PHYSICS_ASSERT_LEVEL

    #define PHYSICS_ASSERTION_3(condition, format, ...) \
        ASSERTION_3(condition, format, __VA_ARGS__)
    #define PHYSICS_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, __VA_ARGS__)

#else  // PHYSICS_ASSERT_LEVEL < 3

    #define PHYSICS_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define PHYSICS_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= PHYSICS_ASSERT_LEVEL

#if 4 <= PHYSICS_ASSERT_LEVEL

    #define PHYSICS_ASSERTION_4(condition, format, ...) \
        ASSERTION_4(condition, format, __VA_ARGS__)
    #define PHYSICS_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, __VA_ARGS__)

#else  // PHYSICS_ASSERT_LEVEL < 4

    #define PHYSICS_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define PHYSICS_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= PHYSICS_ASSERT_LEVEL

#endif  // CORE_TOOLS_HELPER_CUSTOM_ASSERT_MACRO_H
