//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/07 19:03)

#ifndef CORE_TOOLS_HELPER_SAFETY_LIMIT_MACRO_H
#define CORE_TOOLS_HELPER_SAFETY_LIMIT_MACRO_H

#include "ExceptionMacro.h"

namespace System
{
    constexpr auto g_SafetyLimit100 = 100;
    constexpr auto g_SafetyLimit1000 = 1000;
    constexpr auto g_SafetyLimit10000 = 10000;
    constexpr auto g_SafetyLimit100000 = 100000;
}

#ifdef CORE_TOOLS_USE_SAFETY_LIMIT

    #define SAFETY_WHILE_BEGIN(expression��maxCounter)                            \
        {                                                                         \
            auto safetyCounter = 0;                                               \
            while (expression)                                                    \
            {                                                                     \
                if (SYSTEM_STRINGIZE(g_SafetyLimit, maxCounter) <= safetyCounter) \
                {                                                                 \
                    THROW_EXCEPTION(SYSTEM_TEXT("�ڲ�����Υ����ȫ��������"s));  \
                }

    #define SAFETY_WHILE_END \
        ++safetyCounter;     \
        }                    \
        }

#else  // !CORE_TOOLS_USE_SAFETY_LIMIT

    #define SAFETY_WHILE_BEGIN(expression��maxCounter) \
        while (expression)                             \
        {
    #define SAFETY_WHILE_END }

#endif  // CORE_TOOLS_USE_SAFETY_LIMIT

#endif  // CORE_TOOLS_HELPER_SAFETY_LIMIT_MACRO_H
