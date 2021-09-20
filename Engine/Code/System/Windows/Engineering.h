///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.6 (2021/07/03 21:40)

#ifndef SYSTEM_WINDOWS_ENGINEERING_H
#define SYSTEM_WINDOWS_ENGINEERING_H

#include "System/SystemDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace System
{
    NODISCARD String SYSTEM_DEFAULT_DECLARE GetEngineeringSuffix();
    NODISCARD String SYSTEM_DEFAULT_DECLARE GetEngineeringTypesSuffix();
    NODISCARD String SYSTEM_DEFAULT_DECLARE GetEngineeringExeSuffix();
    NODISCARD String SYSTEM_DEFAULT_DECLARE GetEngineeringDirectory();

    NODISCARD constexpr int GetEngineeringOffsetValue() noexcept
    {
#if defined(_DEBUG) || defined(BUILDING_CORE_TOOLS_STATIC) || defined(_WIN64)
        auto offsetValue = 0;
#else  // !defined(_DEBUG) && !defined(BUILDING_CORE_TOOLS_STATIC) && !defined(_WIN64)
        constexpr auto offsetValue = 0;
#endif  // defined(_DEBUG) || defined(BUILDING_CORE_TOOLS_STATIC) || defined(_WIN64)

#ifdef _DEBUG
        offsetValue += 4;
#endif  // _DEBUG

#ifdef BUILDING_CORE_TOOLS_STATIC
        offsetValue += 2;
#endif  // BUILDING_CORE_TOOLS_STATIC

#ifdef _WIN64
        offsetValue += 1;
#endif  // _WIN64

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

    // 这个模板没有定义，用来让编译器打印某个型别的类型。
    template <typename T>
    class TypeDisplayer;
}

#endif  // SYSTEM_WINDOWS_ENGINEERING_H
