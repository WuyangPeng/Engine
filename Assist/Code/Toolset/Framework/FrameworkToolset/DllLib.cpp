///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:21)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "Toolset/Framework/FrameworkToolset/FrameworkToolset.h"

#ifndef BUILDING_FRAMEWORK_STATIC

    #include "DllLib.h"

#else  // BUILDING_FRAMEWORK_STATIC

namespace FrameworkToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_FRAMEWORK_STATIC
