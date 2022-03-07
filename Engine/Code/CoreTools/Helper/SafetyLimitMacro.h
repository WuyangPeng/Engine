///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/08 0:52)

#ifndef CORE_TOOLS_HELPER_SAFETY_LIMIT_MACRO_H
#define CORE_TOOLS_HELPER_SAFETY_LIMIT_MACRO_H

#include "ExceptionMacro.h"

namespace CoreTools
{
    constexpr auto g_SafetyLimit100 = 100;
    constexpr auto g_SafetyLimit1000 = 1000;
    constexpr auto g_SafetyLimit10000 = 10000;
    constexpr auto g_SafetyLimit100000 = 100000;
}

#ifdef CORE_TOOLS_USE_SAFETY_LIMIT

    #define SAFETY_WHILE_BEGIN(expression, maxCounter)                                          \
        {                                                                                       \
            auto safetyCounter = 0;                                                             \
            while (expression)                                                                  \
            {                                                                                   \
                if (SYSTEM_CONCATENATOR(CoreTools::g_SafetyLimit, maxCounter) <= safetyCounter) \
                {                                                                               \
                    THROW_EXCEPTION(SYSTEM_TEXT("�ڲ�����Υ����ȫ��������"s));                \
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
