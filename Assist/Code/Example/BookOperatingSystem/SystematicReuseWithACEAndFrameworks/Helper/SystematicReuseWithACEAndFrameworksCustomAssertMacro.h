///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.4 (2021/06/06 21:47)

#ifndef SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_HELPER_SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_CUSTOM_ASSERT_MACRO_H
#define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_HELPER_SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL)
    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL 4
#endif  // SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL

constexpr auto g_SystematicReuseWithACEAndFrameworksAssert = SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL;

static_assert(SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL

    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_DEBUG(condition, format, ...) \
        USER_ASSERTION_DEBUG((condition), (format), __VA_ARGS__)
    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        USER_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL < 0

    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL

#if 1 <= SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL

    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL < 1

    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL

#if 2 <= SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL

    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL < 2

    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL

#if 3 <= SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL

    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL < 3

    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL

#if 4 <= SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL

    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL < 4

    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_ASSERT_LEVEL

#endif  // SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_HELPER_SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_CUSTOM_ASSERT_MACRO_H
