//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/09/28 13:49)

#ifndef CORE_TOOLS_HELPER_CUSTOM_ASSERT_MACRO_H
#define CORE_TOOLS_HELPER_CUSTOM_ASSERT_MACRO_H

#include "FunctionDescribedMacro.h"

// �������û���ø��ֶ�����ϵͳ�ĺꡣĿǰ����ϵͳֻ��Microsoft Visual Studio��ʵ�֡�
#if defined(OPEN_ASSERT) || defined(OPEN_IMPORTANT_EXCPTION_ASSERT)

    #if defined(SYSTEM_PLATFORM_WIN32) && defined(TCRE_USE_MSVC)
        #define CORE_TOOLS_USE_ASSERT
    #endif  // defined(WIN32) && defined(TCRE_USE_MSVC)

#endif  // defined(OPEN_ASSERT) || defined(OPEN_IMPORTANT_EXCPTION_ASSERT)

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
    #define ASSERT_LEVEL 0
#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT

// 0���ǳ���Ҫ�Ķ��ԡ�����ʧ�ܻᵼ�³��������
// 1����Ҫ�Ķ��ԡ�����ʧ�ܻᵼ�³����׳��쳣���ڴ�й¶��
// 2��һ��Ķ��ԡ�����ʧ�ܻᵼ���߼�����
// 3������Ҫ�Ķ��ԡ�����ʧ�ܻᵼ����ʾ��������
// 4�����Ժ��ԵĶ��ԡ�����ʧ�ܻᵼ����ֵ���Ȳ��㡣
#if !defined(ASSERT_LEVEL)
    #define ASSERT_LEVEL 4
#endif  // ASSERT_LEVEL

#ifdef CORE_TOOLS_USE_ASSERT

    #define ASSERTION(condition, format, ...) \
        CoreTools::Assertion{ (condition), (CORE_TOOLS_FUNCTION_DESCRIBED), (format), __VA_ARGS__ };

    #define ASSERTION_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        CoreTools::Assertion{ (condition), (functionDescribed), (format), __VA_ARGS__ };

constexpr auto g_Assert = ASSERT_LEVEL;

#else  // !CORE_TOOLS_USE_ASSERT

    // �رն��ԡ�
    #define ASSERTION(condition, format, ...) (static_cast<void>(0))
    #define ASSERTION_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

constexpr auto g_Assert = -1;

#endif  // CORE_TOOLS_USE_ASSERT

#if defined(_DEBUG) && 0 <= ASSERT_LEVEL

constexpr auto g_AssertDebug = true;

    #define ASSERTION_DEBUG(condition, format, ...) \
        ASSERTION(condition, format, __VA_ARGS__)
    #define ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, __VA_ARGS__)

#else  // !defined(_DEBUG) || ASSERT_LEVEL < 0

constexpr auto g_AssertDebug = false;

    #define ASSERTION_DEBUG(condition, format, ...) (static_cast<void>(0))
    #define ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  // defined(_DEBUG) && 0 <= ASSERT_LEVEL

#if 0 <= ASSERT_LEVEL

    #define ASSERTION_0(condition, format, ...) \
        ASSERTION(condition, format, __VA_ARGS__)
    #define ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED(condition, functionDescribed, format, __VA_ARGS__)

#else  // ASSERT_LEVEL < 0

    #define ASSERTION_0(condition, format, ...) (static_cast<void>(0))
    #define ASSERTION_USE_FUNCTION_DESCRIBED_0(condition, functionDescribed, format, ...) (static_cast<void>(0))

#endif  //0 <= ASSERT_LEVEL

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

#endif  // CORE_TOOLS_HELPER_CUSTOM_ASSERT_MACRO_H
