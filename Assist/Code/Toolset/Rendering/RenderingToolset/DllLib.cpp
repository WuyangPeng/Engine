///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:35)

#include "Toolset/Rendering/RenderingToolset/RenderingToolsetExport.h"

#include "Toolset/Rendering/RenderingToolset/RenderingToolset.h"

#ifndef BUILDING_RENDERING_STATIC

    #include "DllLib.h"

#else  // BUILDING_RENDERING_STATIC

namespace RenderingToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_RENDERING_STATIC
