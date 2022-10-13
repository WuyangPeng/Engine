///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/09/04 20:44)

#include "Example/System/SystemExample/SystemExampleExport.h"

#include "Example/System/SystemExample/SystemExample.h"

#ifndef BUILDING_SYSTEM_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_SYSTEM_EXAMPLE_STATIC

namespace SystemExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SYSTEM_EXAMPLE_STATIC
