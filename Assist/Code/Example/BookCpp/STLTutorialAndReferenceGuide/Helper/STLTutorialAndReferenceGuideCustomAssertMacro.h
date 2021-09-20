///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/03/27 22:02)

#ifndef STL_TUTORIAL_AND_REFERENCE_GUIDE_HELPER_STL_TUTORIAL_AND_REFERENCE_GUIDE_CUSTOM_ASSERT_MACRO_H
#define STL_TUTORIAL_AND_REFERENCE_GUIDE_HELPER_STL_TUTORIAL_AND_REFERENCE_GUIDE_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/Assertion/UserCustomAssertMacro.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL)
    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL 4
#endif  // STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL

constexpr auto g_STLTutorialAndReferenceGuideAssert = STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL;

static_assert(STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL <= USER_ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL

    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_0(condition, format, ...) \
        USER_ASSERTION_0((condition), (format), __VA_ARGS__)
    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_0((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL < 0

    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL

#if 1 <= STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL

    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_1(condition, format, ...) \
        USER_ASSERTION_1((condition), (format), __VA_ARGS__)
    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_1((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL < 1

    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL

#if 2 <= STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL

    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_2(condition, format, ...) \
        USER_ASSERTION_2((condition), (format), __VA_ARGS__)
    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_2((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL < 2

    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL

#if 3 <= STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL

    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_3(condition, format, ...) \
        USER_ASSERTION_3((condition), (format), __VA_ARGS__)
    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_3((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL < 3

    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL

#if 4 <= STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL

    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_4(condition, format, ...) \
        USER_ASSERTION_4((condition), (format), __VA_ARGS__)
    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        USER_ASSERTION_USE_FUNCTION_DESCRIBED_4((condition), (functionDescribed), (format), __VA_ARGS__)

#else  // STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL < 4

    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= STL_TUTORIAL_AND_REFERENCE_GUIDE_ASSERT_LEVEL

#endif  // STL_TUTORIAL_AND_REFERENCE_GUIDE_HELPER_STL_TUTORIAL_AND_REFERENCE_GUIDE_CUSTOM_ASSERT_MACRO_H
