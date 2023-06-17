///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/12 14:34)

#include "Example/Rendering/RenderingExample/RenderingExampleExport.h"

#include "Example/Rendering/RenderingExample/RenderingExample.h"

#ifndef BUILDING_RENDERING_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_RENDERING_EXAMPLE_STATIC

namespace RenderingExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_RENDERING_EXAMPLE_STATIC
