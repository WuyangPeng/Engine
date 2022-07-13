///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 16:32)

#include "Toolset/CoreTools/CoreToolsToolset/CoreToolsToolsetExport.h"

#include "Toolset/CoreTools/CoreToolsToolset/CoreToolsToolset.h"

#ifndef BUILDING_CORE_TOOLS_STATIC

    #include "DllLib.h"

#else  // BUILDING_CORE_TOOLS_STATIC

namespace CoreToolsToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CORE_TOOLS_STATIC