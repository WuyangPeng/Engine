///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/20 14:20)

#include "Rendering/RenderingExport.h"

#include "Rendering/Rendering.h"

#ifndef BUILDING_RENDERING_STATIC

    #include "DllLib.h"

#else  // BUILDING_RENDERING_STATIC

namespace Rendering
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_RENDERING_STATIC
