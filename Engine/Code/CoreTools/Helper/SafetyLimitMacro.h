/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/28 10:58)

#ifndef CORE_TOOLS_HELPER_SAFETY_LIMIT_MACRO_H
#define CORE_TOOLS_HELPER_SAFETY_LIMIT_MACRO_H

#include "ExceptionMacro.h"

namespace CoreTools
{
    constexpr auto gSafetyLimit100 = 100;
    constexpr auto gSafetyLimit1000 = 1000;
    constexpr auto gSafetyLimit10000 = 10000;
    constexpr auto gSafetyLimit100000 = 100000;
}

#ifdef CORE_TOOLS_USE_SAFETY_LIMIT

    #define SAFETY_WHILE_BEGIN(expression, maxCounter)                                         \
        {                                                                                      \
            auto safetyCounter = 0;                                                            \
            while (expression)                                                                 \
            {                                                                                  \
                if (SYSTEM_CONCATENATOR(CoreTools::gSafetyLimit, maxCounter) <= safetyCounter) \
                {                                                                              \
                    THROW_EXCEPTION(SYSTEM_TEXT("�ڲ�����Υ����ȫ��������"s))                \
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
