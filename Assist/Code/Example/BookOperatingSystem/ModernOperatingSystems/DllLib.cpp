///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/12/06 21:21)

#include "Example/BookOperatingSystem/ModernOperatingSystems/ModernOperatingSystemsExport.h"

#include "ModernOperatingSystems.h"

#ifndef BUILDING_MODERN_OPERATING_SYSTEMS_STATIC

    #include "DllLib.h"

#else  // !BUILDING_MODERN_OPERATING_SYSTEMS_STATIC

namespace ModernOperatingSystems
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_MODERN_OPERATING_SYSTEMS_STATIC
