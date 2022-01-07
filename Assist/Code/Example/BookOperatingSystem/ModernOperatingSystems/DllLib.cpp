///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.7 (2021/12/06 21:21)

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
