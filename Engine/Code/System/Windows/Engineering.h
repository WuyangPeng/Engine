///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 09:24)

#ifndef SYSTEM_WINDOWS_ENGINEERING_H
#define SYSTEM_WINDOWS_ENGINEERING_H

#include "System/SystemDll.h"

#include "System/Helper/ConfigMacro.h"
#include "System/Helper/UnicodeUsing.h"

namespace System
{
    NODISCARD String SYSTEM_DEFAULT_DECLARE GetEngineeringSuffix();
    NODISCARD String SYSTEM_DEFAULT_DECLARE GetEngineeringTypesSuffix();
    NODISCARD String SYSTEM_DEFAULT_DECLARE GetEngineeringExeSuffix();
    NODISCARD String SYSTEM_DEFAULT_DECLARE GetEngineeringDirectory();

    NODISCARD size_t SYSTEM_DEFAULT_DECLARE GetLastSlashPosition(const String& path);

    NODISCARD constexpr int GetEngineeringOffsetValue() noexcept
    {
#if defined(_DEBUG) || defined(BUILDING_CORE_TOOLS_STATIC) || defined(TCRE_ARCHITECTURE_TYPE_64)

        auto offsetValue = 0;

#else  // !defined(_DEBUG) && !defined(BUILDING_CORE_TOOLS_STATIC) && !defined(TCRE_ARCHITECTURE_TYPE_64)

        constexpr auto offsetValue = 0;

#endif  // defined(_DEBUG) || defined(BUILDING_CORE_TOOLS_STATIC) || defined(TCRE_ARCHITECTURE_TYPE_64)

#ifdef _DEBUG

        offsetValue += 4;

#endif  // _DEBUG

#ifdef BUILDING_CORE_TOOLS_STATIC

        offsetValue += 2;

#endif  // BUILDING_CORE_TOOLS_STATIC

#if defined(TCRE_ARCHITECTURE_TYPE_64)

        offsetValue += 1;

#endif  // defined(TCRE_ARCHITECTURE_TYPE_64)

        return offsetValue;
    }

    NODISCARD constexpr int NumDigits(int number) noexcept
    {
        auto digitsSoFar = 1;
        while ((number /= 10) != 0)
        {
            ++digitsSoFar;
        }
        return digitsSoFar;
    }

    // ���ģ��û�ж��壬�����ñ�������ӡĳ���ͱ�����͡�
    template <typename T>
    class TypeDisplayer;
}

#endif  // SYSTEM_WINDOWS_ENGINEERING_H
