/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 11:04)

#ifndef CORE_TOOLS_HELPER_CUSTOM_ASSERT_MACRO_H
#define CORE_TOOLS_HELPER_CUSTOM_ASSERT_MACRO_H

#include "FunctionDescribedMacro.h"
#include "CoreTools/Contract/ContractFwd.h"

#include <string>

/// 用来启用或禁用各种断言子系统的宏。目前断言系统只在Microsoft Visual Studio中实现。
#if defined(OPEN_ASSERT) || defined(OPEN_IMPORTANT_EXCEPTION_ASSERT)

    #if defined(SYSTEM_PLATFORM_WIN32) && defined(TCRE_USE_MSVC)

        #define CORE_TOOLS_USE_ASSERT

    #endif  // defined(WIN32) && defined(TCRE_USE_MSVC)

#endif  // defined(OPEN_ASSERT) || defined(OPEN_IMPORTANT_EXCEPTION_ASSERT)

#if defined(OPEN_IMPORTANT_EXCEPTION_ASSERT)

    #define ASSERT_LEVEL 0

#endif  // OPEN_IMPORTANT_EXCEPTION_ASSERT

/// 0：非常重要的断言。断言失败会导致程序崩溃。
/// 1：重要的断言。断言失败会导致程序抛出异常或内存泄露。
/// 2：一般的断言。断言失败会导致逻辑错误。
/// 3：不重要的断言。断言失败会导致显示或计算错误。
/// 4：可以忽略的断言。断言失败会导致数值精度不足。
#if !defined(ASSERT_LEVEL)

    #define ASSERT_LEVEL 4

#endif  // ASSERT_LEVEL

#ifdef CORE_TOOLS_USE_ASSERT

    #define ASSERTION(condition, format, ...) \
        CoreTools::Assertion{ (condition), (CORE_TOOLS_FUNCTION_DESCRIBED), (format), __VA_ARGS__ };

    #define ASSERTION_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        CoreTools::Assertion{ (condition), (functionDescribed), (format), __VA_ARGS__ };

constexpr auto gAssert = ASSERT_LEVEL;

#else  // !CORE_TOOLS_USE_ASSERT

    // 关闭断言。
    #define ASSERTION(condition, format, ...) (static_cast<void>(0))
    #define ASSERTION_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

constexpr auto gAssert = -1;

#endif  // CORE_TOOLS_USE_ASSERT

#if defined(_DEBUG) && defined(CORE_TOOLS_USE_ASSERT) && 0 <= ASSERT_LEVEL

constexpr auto gAssertDebug = true;

    #define ASSERTION_DEBUG(condition, format, ...) \
        ASSERTION(condition, format, __VA_ARGS__)
    #define ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, __VA_ARGS__)

#else  // !defined(_DEBUG) || defined(CORE_TOOLS_USE_ASSERT) || ASSERT_LEVEL < 0

constexpr auto gAssertDebug = false;

    #define ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // defined(_DEBUG) && defined(CORE_TOOLS_USE_ASSERT) && 0 <= ASSERT_LEVEL

#if 0 <= ASSERT_LEVEL

    #define ASSERTION_0(condition, format, ...) \
        ASSERTION(condition, format, __VA_ARGS__)
    #define ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, __VA_ARGS__)

#else  // ASSERT_LEVEL < 0

    #define ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 0 <= ASSERT_LEVEL

#if 1 <= ASSERT_LEVEL

    #define ASSERTION_1(condition, format, ...) \
        ASSERTION(condition, format, __VA_ARGS__)
    #define ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, __VA_ARGS__)

#else  // ASSERT_LEVEL < 1

    #define ASSERTION_1(condition, format, ...) (static_cast<void>(0))
    #define ASSERTION_USE_FUNCTION_DESCRIBED_1(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 1 <= ASSERT_LEVEL

#if 2 <= ASSERT_LEVEL

    #define ASSERTION_2(condition, format, ...) \
        ASSERTION(condition, format, __VA_ARGS__)
    #define ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, __VA_ARGS__)

#else  // ASSERT_LEVEL < 2

    #define ASSERTION_2(condition, format, ...) (static_cast<void>(0))
    #define ASSERTION_USE_FUNCTION_DESCRIBED_2(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 2 <= ASSERT_LEVEL

#if 3 <= ASSERT_LEVEL

    #define ASSERTION_3(condition, format, ...) \
        ASSERTION(condition, format, __VA_ARGS__)
    #define ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, __VA_ARGS__)

#else  // ASSERT_LEVEL < 3

    #define ASSERTION_3(condition, format, ...) (static_cast<void>(0))
    #define ASSERTION_USE_FUNCTION_DESCRIBED_3(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 3 <= ASSERT_LEVEL

#if 4 <= ASSERT_LEVEL

    #define ASSERTION_4(condition, format, ...) \
        ASSERTION(condition, format, __VA_ARGS__)
    #define ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, __VA_ARGS__)

#else  // ASSERT_LEVEL < 4

    #define ASSERTION_4(condition, format, ...) (static_cast<void>(0))
    #define ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // 4 <= ASSERT_LEVEL

template <typename... T>
void FunctionProhibitedFromCalling(MAYBE_UNUSED const char* describe, MAYBE_UNUSED T&&... value) noexcept(gAssert < 4)
{
    ASSERTION_4(false, describe);
}

#endif  // CORE_TOOLS_HELPER_CUSTOM_ASSERT_MACRO_H
