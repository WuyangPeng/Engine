///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/23 16:06)

#ifndef PROFESSIONAL_CPP_HELPER_PROFESSIONAL_CPP_CUSTOM_ASSERT_MACRO_H
#define PROFESSIONAL_CPP_HELPER_PROFESSIONAL_CPP_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define PROFESSIONAL_CPP_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(PROFESSIONAL_CPP_ASSERT_LEVEL)
    #define PROFESSIONAL_CPP_ASSERT_LEVEL 4
#endif  // PROFESSIONAL_CPP_ASSERT_LEVEL

constexpr auto g_ProfessionalCppAssert = PROFESSIONAL_CPP_ASSERT_LEVEL;

static_assert(PROFESSIONAL_CPP_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= PROFESSIONAL_CPP_ASSERT_LEVEL

    #define PROFESSIONAL_CPP_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define PROFESSIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // PROFESSIONAL_CPP_ASSERT_LEVEL < 0

    #define PROFESSIONAL_CPP_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define PROFESSIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= PROFESSIONAL_CPP_ASSERT_LEVEL

#if 1 <= PROFESSIONAL_CPP_ASSERT_LEVEL

    #define PROFESSIONAL_CPP_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define PROFESSIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // PROFESSIONAL_CPP_ASSERT_LEVEL < 1

    #define PROFESSIONAL_CPP_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define PROFESSIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= PROFESSIONAL_CPP_ASSERT_LEVEL

#if 2 <= PROFESSIONAL_CPP_ASSERT_LEVEL

    #define PROFESSIONAL_CPP_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define PROFESSIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // PROFESSIONAL_CPP_ASSERT_LEVEL < 2

    #define PROFESSIONAL_CPP_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define PROFESSIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= PROFESSIONAL_CPP_ASSERT_LEVEL

#if 3 <= PROFESSIONAL_CPP_ASSERT_LEVEL

    #define PROFESSIONAL_CPP_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define PROFESSIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // PROFESSIONAL_CPP_ASSERT_LEVEL < 3

    #define PROFESSIONAL_CPP_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define PROFESSIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= PROFESSIONAL_CPP_ASSERT_LEVEL

#if 4 <= PROFESSIONAL_CPP_ASSERT_LEVEL

    #define PROFESSIONAL_CPP_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define PROFESSIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // PROFESSIONAL_CPP_ASSERT_LEVEL < 4

    #define PROFESSIONAL_CPP_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define PROFESSIONAL_CPP_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= PROFESSIONAL_CPP_ASSERT_LEVEL

#endif  // PROFESSIONAL_CPP_HELPER_PROFESSIONAL_CPP_CUSTOM_ASSERT_MACRO_H
