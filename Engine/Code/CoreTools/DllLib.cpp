///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 11:21)

#include "CoreToolsExport.h"

#include "CoreTools.h"

#ifndef BUILDING_CORE_TOOLS_STATIC

    #include "DllLib.h"

#else  // !BUILDING_CORE_TOOLS_STATIC

namespace CoreTools
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // BUILDING_CORE_TOOLS_STATIC